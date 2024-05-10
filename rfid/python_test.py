import math

# Constants
AMPLITUDE = 127  # Amplitude of the sine wave (8-bit range)
SAMPLE_RATE = 120000  # in Hz
FREQUENCY_1 = 100  # Frequency for '1'
FREQUENCY_2 = 200  # Frequency for '0'
SYMBOL_DURATION = 0.01  # Duration of each symbol in seconds
USER_ID = '11110000'  # Example reader query, expecting this to be the correct signal to respond to
VERIFICATION = '11000101'

# Precomputed sine wave lookup table (scaled to 8-bit integer range)
sine_wave_lookup = [
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
]

# Helper function to calculate sine using a lookup table
def sine_lookup(angle):
    angle = angle % 360
    return sine_wave_lookup[angle]

# Helper function to generate sine waves as integers
def generate_sine_wave(freq, duration, sample_rate, phase=0):
    N = int(duration * sample_rate)
    wave = []
    for i in range(N):
        angle = (360 * freq * i // sample_rate + phase) % 360
        wave.append(sine_lookup(angle))
    return wave

# Simple DFT function (not an optimized FFT) with integer math
def discrete_fourier_transform(signal):
    N = len(signal)
    real = [0] * (N // 2)
    imag = [0] * (N // 2)
    for n in range(N // 2):
        for k in range(N):
            angle = (360 * n * k // N) % 360
            real[n] += signal[k] * sine_lookup(360 - angle)
            imag[n] += signal[k] * sine_lookup(angle)
    return real, imag

# Generate a sample FSK signal for a given binary sequence
def modulate_binary_sequence(binary_sequence, frequency_1, frequency_2, symbol_duration, sample_rate):
    fsk_signal = []
    for bit in binary_sequence:
        freq = frequency_1 if bit == '1' else frequency_2
        fsk_signal.extend(generate_sine_wave(freq, symbol_duration, sample_rate))
    return fsk_signal

# Demodulate FSK signal to binary sequence
def demodulate_fsk_signal(fsk_signal, frequency_1, frequency_2, symbol_duration, sample_rate):
    samples_per_symbol = int(symbol_duration * sample_rate)
    decoded_bits = []
    for i in range(0, len(fsk_signal), samples_per_symbol):
        symbol_data = fsk_signal[i:i + samples_per_symbol]
        real, imag = discrete_fourier_transform(symbol_data)
        index_1 = frequency_1 * samples_per_symbol // sample_rate
        index_2 = frequency_2 * samples_per_symbol // sample_rate
        power_1 = real[index_1] ** 2 + imag[index_1] ** 2
        power_2 = real[index_2] ** 2 + imag[index_2] ** 2
        decoded_bits.append('1' if power_1 > power_2 else '0')
    return ''.join(decoded_bits)

# Test data generation
binary_sequence = '11000101'  # RFID Tag's data
generated_signal = modulate_binary_sequence(binary_sequence, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE)

# Write generated_signal to output.txt with 10 elements per line
with open("output.txt", "w") as file:
    for i in range(0, len(generated_signal), 10):
        file.write(", ".join(map(str, generated_signal[i:i + 10])) + ", \n")
