#include <stdio.h>

#define AMPLITUDE 127  // Amplitude of the sine wave
#define SAMPLE_RATE 6  // in Hz
#define FREQUENCY_1 1  // Frequency for '1'
#define FREQUENCY_2 2  // Frequency for '0'
#define SYMBOL_DURATION 1  // Duration of each symbol in seconds
#define USER_ID "11110000"  // Example reader query
#define VERIFICATION "11000101"

// Precomputed sine wave lookup table (scaled to 8-bit integer range)
int sine_wave_lookup[360] = {
      0,    2,    4,    6,    8,   11,   13,   15,   17,   19,
     22,   24,   26,   28,   30,   32,   35,   37,   39,   41,
     43,   45,   47,   49,   51,   53,   55,   57,   59,   61,
     63,   65,   67,   69,   71,   72,   74,   76,   78,   79,
     81,   83,   84,   86,   88,   89,   91,   92,   94,   95,
     97,   98,  100,  101,  102,  104,  105,  106,  107,  108,
    109,  111,  112,  113,  114,  115,  116,  116,  117,  118,
    119,  120,  120,  121,  122,  122,  123,  123,  124,  124,
    125,  125,  125,  126,  126,  126,  126,  126,  126,  126,
    127,  126,  126,  126,  126,  126,  126,  126,  125,  125,
    125,  124,  124,  123,  123,  122,  122,  121,  120,  120,
    119,  118,  117,  116,  116,  115,  114,  113,  112,  111,
    109,  108,  107,  106,  105,  104,  102,  101,  100,   98,
     97,   95,   94,   92,   91,   89,   88,   86,   84,   83,
     81,   79,   78,   76,   74,   72,   71,   69,   67,   65,
     63,   61,   59,   57,   55,   53,   51,   49,   47,   45,
     43,   41,   39,   37,   35,   32,   30,   28,   26,   24,
     22,   19,   17,   15,   13,   11,    8,    6,    4,    2,
      0,   -2,   -4,   -6,   -8,  -11,  -13,  -15,  -17,  -19,
    -22,  -24,  -26,  -28,  -30,  -32,  -35,  -37,  -39,  -41,
    -43,  -45,  -47,  -49,  -51,  -53,  -55,  -57,  -59,  -61,
    -63,  -65,  -67,  -69,  -71,  -72,  -74,  -76,  -78,  -79,
    -81,  -83,  -84,  -86,  -88,  -89,  -91,  -92,  -94,  -95,
    -97,  -98, -100, -101, -102, -104, -105, -106, -107, -108,
   -109, -111, -112, -113, -114, -115, -116, -116, -117, -118,
   -119, -120, -120, -121, -122, -122, -123, -123, -124, -124,
   -125, -125, -125, -126, -126, -126, -126, -126, -126, -126,
   -127, -126, -126, -126, -126, -126, -126, -126, -125, -125,
   -125, -124, -124, -123, -123, -122, -122, -121, -120, -120,
   -119, -118, -117, -116, -116, -115, -114, -113, -112, -111,
   -109, -108, -107, -106, -105, -104, -102, -101, -100,  -98,
    -97,  -95,  -94,  -92,  -91,  -89,  -88,  -86,  -84,  -83,
    -81,  -79,  -78,  -76,  -74,  -72,  -71,  -69,  -67,  -65,
    -63,  -61,  -59,  -57,  -55,  -53,  -51,  -49,  -47,  -45,
    -43,  -41,  -39,  -37,  -35,  -32,  -30,  -28,  -26,  -24,
    -22,  -19,  -17,  -15,  -13,  -11,   -8,   -6,   -4,   -2,
};

// Helper function to calculate sine using a lookup table
int sine_lookup(int angle) {
    angle = angle % 360;
    return sine_wave_lookup[angle];
}

// Helper function to generate sine waves as integers
void generate_sine_wave(int* wave, int freq, int duration, int sample_rate, int phase) {
    int N = duration * sample_rate;
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
    int samples_per_symbol = symbol_duration * sample_rate;
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
    int samples_per_symbol = symbol_duration * sample_rate;
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

int main() {
    // Test data generation
    const char* binary_sequence = "11000101";
    int signal_length = string_length(binary_sequence) * SYMBOL_DURATION * SAMPLE_RATE;
    int generated_signal[signal_length];
    modulate_binary_sequence(binary_sequence, generated_signal, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE);

    // Simulate receiving and demodulating the signal at the reader
    char decoded_sequence[string_length(binary_sequence) + 1];
    demodulate_fsk_signal(generated_signal, decoded_sequence, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE, signal_length);

    // Gate the signal based on the reader's query
    int output_signal[signal_length];
    if (string_compare(VERIFICATION, decoded_sequence) == 0) {
        modulate_binary_sequence(USER_ID, output_signal, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE);
    } else {
        for (int i = 0; i < signal_length; i++) {
            output_signal[i] = 0;
        }
    }

    // Modulate the output signal to send out
    char check_output[string_length(binary_sequence) + 1];
    demodulate_fsk_signal(output_signal, check_output, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE, signal_length);

    // Outputs for verification
    printf("Original Binary Sequence: %s\n", binary_sequence);
    printf("Demodulated Binary Sequence on tag: %s\n", decoded_sequence);
    printf("Transmitter received Binary Sequence: %s\n", check_output);

    return 0;
}
