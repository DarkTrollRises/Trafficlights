#include "GeneralPin.h"

// Standard Constructor
GeneralPin::GeneralPin()
{
}

// Constructor
GeneralPin::GeneralPin(int pin)
{
    _pin = pin;
}

// Get the state of the pin
byte GeneralPin::getState()
{
    return(digitalRead(_pin));
}

// Get the pin number
int GeneralPin::getPin()
{
    return(_pin);
}
