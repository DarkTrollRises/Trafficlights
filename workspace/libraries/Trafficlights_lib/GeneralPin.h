#ifndef GENERALPIN_H
#define GENERALPIN_H

#include "Arduino.h"

class GeneralPin
{
    public:
        GeneralPin();
        GeneralPin(int pin);
        byte getState();
        int getPin();
    protected:
        int _pin;
};

#endif
