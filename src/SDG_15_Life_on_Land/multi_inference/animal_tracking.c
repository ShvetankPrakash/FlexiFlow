#include "sample_data.h"
// #include <stdio.h>

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
    char parity_with_python = 1; // Represents if a response was sent
    unsigned char decoded_sequence, VERIFICATION;
    char Golden_Reference;
    const int *RFID_Input_Signal;
    
    for (int i = 0; i < Num_Data_Samples; ++i) {
        RFID_Input_Signal = &RFID_Input_Signal_Vector[i][0];
        decoded_sequence = demodulate_fsk_signal(RFID_Input_Signal);
        VERIFICATION = Verification_Vector[i];
        Golden_Reference = Golden_Reference_Prediction_Vector[i];
        if ((VERIFICATION == decoded_sequence) != Golden_Reference)
            parity_with_python = 0;
    }
    return parity_with_python;
}

int main() {
    correct_result = Read_Input_Signal_Respond();
    // printf("%d\n", correct_result);

    return 0;
}
