#include "PedestrianLight.h"

// Standard Constructor
PedestrianLight::PedestrianLight()
{
}

// Constructor
PedestrianLight::PedestrianLight(int redPin, int greenPin) :
    TrafficLight(redPin, greenPin)
{
}

// Turn all lights off
void PedestrianLight::lightsOff()
{
    red.setState(LOW);
    green.setState(LOW);
}

// Turn the light to red
void PedestrianLight::turnRed()
{
    if(active > 0)
        green.setState(LOW);
    active = 1;
    red.setState(HIGH);
}

// Turn the light to green
void PedestrianLight::turnGreen()
{
    if(active > 0)
        red.setState(LOW);
    active = 2;
    green.setState(HIGH);
}

// Make the light blink
void PedestrianLight::blink()
{
    active = 2;
    for(int i=0; i<12; i++)
    {
        green.setState(HIGH);
        delayMicroseconds(125000);  // 0,125 seconds
        green.setState(LOW);
        delayMicroseconds(125000);  // 0,125 seconds
    }
}
