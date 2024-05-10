import math

# Define constants for scaling
AMPLITUDE = 127  # Amplitude of the sine wave
SAMPLE_RATE = 6  # in Hz
FREQUENCY_1 = 1  # Frequency for '1'
FREQUENCY_2 = 2  # Frequency for '0'
SYMBOL_DURATION = 1  # Duration of each symbol in seconds
USER_ID = '11110000'  # Example reader query, expecting this to be the correct signal to respond to
VERIFICATION = '11000101'

# Helper function to generate sine waves as integers
def generate_sine_wave(freq, duration, sample_rate, phase=0):
    return [int(AMPLITUDE * math.sin(2 * math.pi * freq * (i / sample_rate) + phase)) for i in range(int(duration * sample_rate))]

# Simple DFT function (not an optimized FFT) with integer math
def discrete_fourier_transform(signal, sample_rate):
    N = len(signal)
    dft_result = []
    for n in range(N // 2):
        real = sum(signal[k] * int(AMPLITUDE * math.cos(-2 * math.pi * n * k / N)) for k in range(N))
        imag = sum(signal[k] * int(AMPLITUDE * math.sin(-2 * math.pi * n * k / N)) for k in range(N))
        dft_result.append(complex(real, imag))
    return dft_result

# Generate a sample FSK signal for a given binary sequence
def modulate_binary_sequence(binary_sequence, frequency_1, frequency_2, symbol_duration, sample_rate):
    fsk_signal = []
    for bit in binary_sequence:
        if bit == '1':
            fsk_signal.extend(generate_sine_wave(frequency_1, symbol_duration, sample_rate))
        else:
            fsk_signal.extend(generate_sine_wave(frequency_2, symbol_duration, sample_rate))
    return fsk_signal

# Demodulate FSK signal to binary sequence
def demodulate_fsk_signal(fsk_signal, frequency_1, frequency_2, symbol_duration, sample_rate):
    samples_per_symbol = int(symbol_duration * sample_rate)
    decoded_bits = []
    for i in range(0, len(fsk_signal), samples_per_symbol):
        symbol_data = fsk_signal[i:i+samples_per_symbol]
        dft_result = discrete_fourier_transform(symbol_data, sample_rate)
        index_1 = int(frequency_1 * samples_per_symbol / sample_rate)
        index_2 = int(frequency_2 * samples_per_symbol / sample_rate)
        power_1 = abs(dft_result[index_1]) ** 2
        power_2 = abs(dft_result[index_2]) ** 2
        decoded_bits.append('1' if power_1 > power_2 else '0')
    return ''.join(decoded_bits)

# Invert binary sequence
def invert_bits(binary_sequence):
    return ''.join('1' if x == '0' else '0' for x in binary_sequence)

# Test data generation
binary_sequence = '11000101'  # RFID Tag's data
generated_signal = modulate_binary_sequence(binary_sequence, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE)

# Simulate receiving and demodulating the signal at the reader
decoded_sequence = demodulate_fsk_signal(generated_signal, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE)

# Gate the signal based on the reader's query
output_signal = []
if VERIFICATION == decoded_sequence:
    output_signal = modulate_binary_sequence(USER_ID, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE)
else:
    output_signal = [0] * len(generated_signal)  # The tag gates the signal, sending nothing

# Modulate the output signal to send out
check_output = demodulate_fsk_signal(output_signal, FREQUENCY_1, FREQUENCY_2, SYMBOL_DURATION, SAMPLE_RATE)

# Outputs for verification
print("Original Binary Sequence:", binary_sequence)
print("Decoded Binary Sequence:", decoded_sequence)
print("Inverted Binary Sequence:", check_output)
