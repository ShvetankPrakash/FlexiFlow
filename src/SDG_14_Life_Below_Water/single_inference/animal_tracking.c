#include "sample_data.h"

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  

#define AMPLITUDE 127  // Amplitude of the sine wave
#define SAMPLE_RATE 120000  // in Hz
#define FREQUENCY_1 100  // Frequency for '1'
#define FREQUENCY_2 200  // Frequency for '0'
#define SYMBOL_DURATION 1  // Duration of each symbol in seconds, actually 0.01
#define USER_ID "11110000"  // Example reader query
#define VERIFICATION "11000101"

// Helper function to calculate sine using a lookup table
int sine_lookup(int angle) {
    angle = angle % 360;
    return sine_wave_lookup[angle];
}

// Helper function to generate sine waves as integers
void generate_sine_wave(int* wave, int freq, int duration, int sample_rate, int phase) {
    //int N = duration * sample_rate;
    int N = 1200;
    for (int i = 0; i < N; i++) {
        int angle = ((360 * freq * i / sample_rate) + phase) % 360;
        wave[i] = sine_lookup(angle);
    }
}

// Helper function to compute the length of a string
int string_length(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
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
void discrete_fourier_transform(int* signal, int N, int* real, int* imag) {
    for (int n = 0; n < N / 2; n++) {
        real[n] = 0;
        imag[n] = 0;
        for (int k = 0; k < N; k++) {
            int angle = (360 * n * k / N) % 360;
            real[n] += signal[k] * sine_lookup(360 - angle);
            imag[n] += signal[k] * sine_lookup(angle);
        }
    }
}

// Generate a sample FSK signal for a given binary sequence
void modulate_binary_sequence(const char* binary_sequence, int* fsk_signal, int frequency_1, int frequency_2, int symbol_duration, int sample_rate) {
    //int samples_per_symbol = symbol_duration * sample_rate;
    int samples_per_symbol = 1200;
    int wave[samples_per_symbol];
    int index = 0;
    for (int i = 0; binary_sequence[i] != '\0'; i++) {
        int freq = (binary_sequence[i] == '1') ? frequency_1 : frequency_2;
        generate_sine_wave(wave, freq, symbol_duration, sample_rate, 0);
        for (int j = 0; j < samples_per_symbol; j++) {
            fsk_signal[index++] = wave[j];
        }
    }
}

// Demodulate FSK signal to binary sequence
void demodulate_fsk_signal(int* fsk_signal, char* decoded_bits, int frequency_1, int frequency_2, int symbol_duration, int sample_rate, int len) {
    //int samples_per_symbol = symbol_duration * sample_rate;
    int samples_per_symbol = 1200;
    int real[samples_per_symbol / 2], imag[samples_per_symbol / 2];
    for (int i = 0; i < len; i += samples_per_symbol) {
        discrete_fourier_transform(fsk_signal + i, samples_per_symbol, real, imag);
        int index_1 = frequency_1 * samples_per_symbol / sample_rate;
        int index_2 = frequency_2 * samples_per_symbol / sample_rate;
        int power_1 = real[index_1] * real[index_1] + imag[index_1] * imag[index_1];
        int power_2 = real[index_2] * real[index_2] + imag[index_2] * imag[index_2];
        decoded_bits[i / samples_per_symbol] = (power_1 > power_2) ? '1' : '0';
    }
    decoded_bits[len / samples_per_symbol] = '\0';
}

char run_animal_tracking() {
    char GPIO;

    // Test data generation
    const char* binary_sequence = "11000101";
    //int signal_length = string_length(binary_sequence) * SYMBOL_DURATION * SAMPLE_RATE;
    int signal_length = string_length(binary_sequence) * 1200;
    //int generated_signal[signal_length];
    //modulate_binary_sequence(binary_sequence, generated_signal, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE);

    // Simulate receiving and demodulating the signal at the reader
    char decoded_sequence[string_length(binary_sequence) + 1];
    demodulate_fsk_signal(RFID_Input_Signal, decoded_sequence, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE, signal_length);

    // Gate the signal based on the reader's query
    int output_signal[signal_length];
    if (string_compare(VERIFICATION, decoded_sequence) == 0) {
        modulate_binary_sequence(USER_ID, output_signal, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE);
    } else {
        for (int i = 0; i < signal_length; i++) {
            output_signal[i] = 0;
        }
    }

    if (binary_sequence != decoded_sequence) {
        GPIO = 0;
        return GPIO;
    }
    else return GPIO = 1;
}

int main() {
  correct_result = run_animal_tracking();
  return 0;
}
