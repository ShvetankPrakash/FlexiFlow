import math

AMPLITUDE = 127  # Amplitude of the sine wave (8-bit range)

# Generate sine wave lookup table
sine_wave_lookup = []
for i in range(360):
    value = int(AMPLITUDE * math.sin(math.radians(i)))
    sine_wave_lookup.append(value)

# Print the lookup table
print("{")
for i in range(0, 360, 10):
    print("   " + ", ".join(f"{v:4}" for v in sine_wave_lookup[i:i+10]) + ",")
print("};")
