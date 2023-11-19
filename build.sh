#!/bin/bash

# Build script for read_resistance.cpp

# Set the pin configuration (assuming pin P9_39 is used for AIN0)
config-pin P9_39 ain

# Compile the C++ program
g++ read_resistance.cpp AnalogIn.cpp -o read_resistance

# Run the program
./read_resistance

# Reset pin configuration
config-pin P9_39 gpio

