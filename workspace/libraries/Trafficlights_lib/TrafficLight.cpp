#include "TrafficLight.h"

// Standard Constructor
TrafficLight::TrafficLight()
{
}

// Constructor
TrafficLight::TrafficLight(int redPin, int greenPin)
{
    active = 0;
    red = Light(redPin);
    green = Light(greenPin);
}
