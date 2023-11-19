// AnalogIn.cpp

#include "AnalogIn.h"
#include <fstream>
#include <iostream>  // Add this include for std::cerr
#include <sstream>

AnalogIn::AnalogIn(unsigned int pin) : pinNumber(pin) {
    // Additional setup code if needed
}

int AnalogIn::readADC() {
    std::ifstream adcFile("/sys/bus/iio/devices/iio:device0/in_voltage" + std::to_string(pinNumber) + "_raw");
    if (adcFile.fail()) {
        std::cerr << "Error: Unable to open ADC file for reading." << std::endl;
        return -1;
    }

    int adcValue;
    adcFile >> adcValue;

    return adcValue;
}

