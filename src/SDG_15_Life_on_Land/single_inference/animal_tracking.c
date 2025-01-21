#include "static_data.h"

volatile char correct_result = -1;

// Helper function to calculate sine using a lookup table
int sine_lookup(int angle) {
    angle = angle % 360;
    return sine_wave_lookup[angle];
}

// Helper function to generate sine waves as integers
void generate_sine_wave(int* wave, int freq, int phase) {
    int N = Samples_Per_Symbol;
    for (int i = 0; i < N; i++) {
        int angle = ((360 * freq * i / SAMPLE_RATE) + phase) % 360;
        wave[i] = sine_lookup(angle);
    }
}

// Helper function to compare two strings
int string_compare(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Simple DFT function (not an optimized FFT) with integer math
void discrete_fourier_transform(int* signal, int* real, int* imag) {
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

// Generate a sample FSK signal for a given binary sequence
void modulate_binary_sequence(const char* binary_sequence, int* fsk_signal) {
    int wave[Samples_Per_Symbol];
    int index = 0;
    for (int i = 0; binary_sequence[i] != '\0'; i++) {
        int freq = (binary_sequence[i] == '1') ? FREQUENCY_1 : FREQUENCY_2;
        generate_sine_wave(wave, freq, 0);
        for (int j = 0; j < Samples_Per_Symbol; j++) {
            fsk_signal[index++] = wave[j];
        }
    }
}

// Demodulate FSK signal to binary sequence
void demodulate_fsk_signal(int* fsk_signal, char* decoded_bits) {
    int real[Samples_Per_Symbol >> 1], imag[Samples_Per_Symbol >> 1];
    for (int i = 0; i < Message_Bits; ++i) {
        discrete_fourier_transform(fsk_signal + i*Samples_Per_Symbol, real, imag);
        int index_1 = FREQUENCY_1 * Samples_Per_Symbol / SAMPLE_RATE;
        int index_2 = FREQUENCY_2 * Samples_Per_Symbol / SAMPLE_RATE;
        int power_1 = real[index_1] * real[index_1] + imag[index_1] * imag[index_1];
        int power_2 = real[index_2] * real[index_2] + imag[index_2] * imag[index_2];
        decoded_bits[i] = (power_1 > power_2) ? '1' : '0';
    }
    decoded_bits[Message_Bits] = '\0';
}

char Read_Input_Signal_Respond() {
    char GPIO = 0; // Represents if a response was sent
    char decoded_sequence[Num_Data_Samples + 1];
    demodulate_fsk_signal((int *) RFID_Input_Signal, decoded_sequence);

    int output_signal[Num_Output_Samples];
    if (string_compare(VERIFICATION, decoded_sequence) == 0) {
        // Input verified, modulate USER_ID as response
        modulate_binary_sequence(USER_ID, output_signal);
        GPIO = 1;
    } else {
        for (int i = 0; i < Num_Output_Samples; i++) {
            output_signal[i] = 0;
        }
        GPIO = 0;
    }
    return GPIO;
}

int main() {
    correct_result = Read_Input_Signal_Respond();
    return 0;
}
