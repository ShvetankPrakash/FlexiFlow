#include "sample_data.h"

volatile char correct_result = -1;

// Helper function to calculate sine using a lookup table
int sine_lookup(int angle) {
    angle = angle % 360;
    return sine_wave_lookup[angle];
}

// Simple DFT function (not an optimized FFT) with integer math
void discrete_fourier_transform(const int* signal, int* real, int* imag) {
    for (int n = 0; n < (Samples_Per_Symbol >> 1); n++) {
        real[n] = 0;
        imag[n] = 0;
        for (int k = 0; k < Samples_Per_Symbol; k++) {
            int angle = (360 * n * k / Samples_Per_Symbol) % 360;
            real[n] += signal[k] * sine_lookup(360 - angle);
            imag[n] += signal[k] * sine_lookup(angle);
        }
    }
}

// Demodulate FSK signal to binary sequence
unsigned char demodulate_fsk_signal(const int* fsk_signal) {
    unsigned char decoded_bits = 0;
    int real[Samples_Per_Symbol >> 1], imag[Samples_Per_Symbol >> 1];
    for (int i = 0; i < Message_Bits; ++i) {
        discrete_fourier_transform(fsk_signal + i*Samples_Per_Symbol, real, imag);
        int index_1 = FREQUENCY_1 * Samples_Per_Symbol / SAMPLE_RATE;
        int index_2 = FREQUENCY_2 * Samples_Per_Symbol / SAMPLE_RATE;
        int power_1 = real[index_1] * real[index_1] + imag[index_1] * imag[index_1];
        int power_2 = real[index_2] * real[index_2] + imag[index_2] * imag[index_2];
        decoded_bits |= (power_1 > power_2) << i; // Set i'th bit
    }
    return decoded_bits;
}

char Read_Input_Signal_Respond() {
    char GPIO = 0; // Represents if a response was sent
    unsigned char decoded_sequence = demodulate_fsk_signal(RFID_Input_Signal);

    if (VERIFICATION == decoded_sequence) {
        GPIO = 1;
    } else {
        GPIO = 0;
    }
    return GPIO;
}

int main() {
    correct_result = Read_Input_Signal_Respond();

    return 0;
}
