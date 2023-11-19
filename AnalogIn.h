// AnalogIn.h

#ifndef ANALOGIN_H
#define ANALOGIN_H

class AnalogIn {
public:
    AnalogIn(unsigned int pin);
    int readADC();
    // Add any other necessary methods or members here
private:
    unsigned int pinNumber;
};

#endif

