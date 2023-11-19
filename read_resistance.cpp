// read_resistance.cpp

#include <iostream>
#include <cmath>
#include "AnalogIn.h"  // Include your AnalogIn class header file

using namespace std;

int main() {
    // Instantiate an object of the AnalogIn class
    AnalogIn analogIn(0);  // Assuming AIN0 is the pin connected to the voltage divider

    // Define the values for the voltage divider
    const double vcc = 1.8;   // Voltage across both resistors
    const double rTop = 10000; // 10kΩ top resistor

    // Read analog value from the voltage divider
    cout << "Using AIN0 to read analog value." << endl;
    cout << "Measuring resistance ..." << endl;
    int adcValue = analogIn.readADC();

    // Calculate the resistance using the voltage divider formula
    double voltageAcrossR = vcc * (static_cast<double>(adcValue) / 4095); // Assuming 12-bit ADC
    double rBottom = (rTop * voltageAcrossR) / (vcc - voltageAcrossR);

    // Print the resistance value to the nearest Ohm
    if (rBottom < 1000) {
        cout << "ADC value is: " << adcValue << endl;
        cout << "Resistance: " << round(rBottom) << " Ohms" << endl;
    } else {
        cout << "ADC value is: " << adcValue << endl;
        cout << "Resistance: " << round(rBottom / 1000) << "K Ohms" << endl;
    }

    return 0;
}

