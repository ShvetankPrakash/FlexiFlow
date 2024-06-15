import numpy as np

# Define FSK modulation and demodulation parameters
sampling_rate = 1000  # Sampling rate in Hz
frequency_1 = 10  # Frequency of the '1' FSK symbol in Hz
frequency_2 = 20  # Frequency of the '0' FSK symbol in Hz
symbol_duration = 1  # Duration of each FSK symbol in seconds
samples_per_symbol = int(symbol_duration * sampling_rate)
binary_sequence = '11000101'

# Generate a sample FSK signal for the given binary sequence
fsk_signal = []
for bit in binary_sequence:
    t = np.linspace(0, symbol_duration, samples_per_symbol, endpoint=False)
    if bit == '1':
        fsk_signal.append(np.sin(2 * np.pi * frequency_1 * t))
    else:
        fsk_signal.append(np.sin(2 * np.pi * frequency_2 * t))
fsk_signal = np.concatenate(fsk_signal)

# Perform FSK demodulation using a simpler envelope detection in the time domain
decoded_bits = []
for i in range(0, len(fsk_signal), samples_per_symbol):
    symbol_data = fsk_signal[i:i+samples_per_symbol]
    # Compute power at frequency_1
    freq_1_response = np.abs(np.fft.fft(symbol_data * np.cos(2 * np.pi * frequency_1 * t)))[:samples_per_symbol//2]
    power_1 = np.sum(freq_1_response)
    # Compute power at frequency_2
    freq_2_response = np.abs(np.fft.fft(symbol_data * np.cos(2 * np.pi * frequency_2 * t)))[:samples_per_symbol//2]
    power_2 = np.sum(freq_2_response)
    # Decode based on which frequency had higher power
    if power_1 > power_2:
        decoded_bits.append('0')
    else:
        decoded_bits.append('1')

decoded_sequence = ''.join(decoded_bits)
print("Extracted bit string:", decoded_sequence)
