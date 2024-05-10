import math

# Define FSK modulation and demodulation parameters
sampling_rate = 1000  # Sampling rate in Hz
frequency_1 = 10  # Frequency of the '1' FSK symbol in Hz
frequency_2 = 20  # Frequency of the '0' FSK symbol in Hz
symbol_duration = 1  # Duration of each FSK symbol in seconds
samples_per_symbol = int(symbol_duration * sampling_rate)
binary_sequence = '11000101'

# Helper function to generate sine waves
def generate_sine_wave(freq, duration, sample_rate):
    t = [i / sample_rate for i in range(int(duration * sample_rate))]
    return [math.sin(2 * math.pi * freq * x) for x in t]

# Generate a sample FSK signal for the given binary sequence
fsk_signal = []
for bit in binary_sequence:
    if bit == '1':
        fsk_signal.extend(generate_sine_wave(frequency_1, symbol_duration, sampling_rate))
    else:
        fsk_signal.extend(generate_sine_wave(frequency_2, symbol_duration, sampling_rate))

# Simple DFT function (not an optimized FFT)
def discrete_fourier_transform(signal):
    N = len(signal)
    return [sum(signal[k] * math.cos(-2 * math.pi * n * k / N) for k in range(N)) + 
            1j * sum(signal[k] * math.sin(-2 * math.pi * n * k / N) for k in range(N)) for n in range(N//2)]

# Perform FSK demodulation using a simpler envelope detection in the time domain
decoded_bits = []
for i in range(0, len(fsk_signal), samples_per_symbol):
    symbol_data = fsk_signal[i:i+samples_per_symbol]
    # Compute DFT and then power at each frequency
    dft_result = discrete_fourier_transform(symbol_data)
    # Power calculation corrected: directly calculate the magnitude squared of the specific DFT component
    index_1 = int(frequency_1 * samples_per_symbol / sampling_rate)
    index_2 = int(frequency_2 * samples_per_symbol / sampling_rate)
    power_1 = abs(dft_result[index_1]) ** 2
    power_2 = abs(dft_result[index_2]) ** 2
    # Decode based on which frequency had higher power
    if power_1 > power_2:
        decoded_bits.append('1')
    else:
        decoded_bits.append('0')

decoded_sequence = ''.join(decoded_bits)
print("Extracted bit string:", decoded_sequence)
