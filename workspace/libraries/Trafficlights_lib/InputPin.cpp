#include "InputPin.h"

// Standard Constructor
InputPin::InputPin()
{
}

// Constructor
InputPin::InputPin(int pin) :
    GeneralPin(pin)
{
    pinMode(_pin, INPUT);
}

// Add an interrupt to the pin
void InputPin::addInterrupt(void (*func)(), int mode)
{
    attachInterrupt(_pin, func, mode);
}

// Remove the current interrupt from the pin
void InputPin::removeInterrupt()
{
    detachInterrupt(_pin);
}
