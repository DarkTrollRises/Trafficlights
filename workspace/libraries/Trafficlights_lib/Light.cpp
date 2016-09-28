#include "Light.h"

// Standard Constructor
Light::Light()
{
}

// Constructor
Light::Light(int pin) :
    GeneralPin(pin)
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

// Set the state of the pin
void Light::setState(int state)
{
    digitalWrite(_pin, state);
}
