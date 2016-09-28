#include "RoadLight.h"

// Standard Constructor
RoadLight::RoadLight()
{
}

// Constructor
RoadLight::RoadLight(int redPin, int orangePin, int greenPin) :
    TrafficLight(redPin, greenPin)
{
    orange = Light(orangePin);
}

// Turn all lights off
void RoadLight::lightsOff()
{
    red.setState(LOW);
    orange.setState(LOW);
    green.setState(LOW);
    active = 0;
}

// Turn the light to red
void RoadLight::turnRed()
{
    if(active > 0)
    {
        switch(active)
        {
        case 2:
            orange.setState(LOW);
            break;
        case 3:
            green.setState(LOW);
            break;
        default:
            break;
        }
    }
    active = 1;
    red.setState(HIGH);
}

// Turn the light to orange
void RoadLight::turnOrange()
{
    if(active > 0)
    {
        switch(active)
        {
        case 1:
            red.setState(LOW);
            break;
        case 3:
            green.setState(LOW);
            break;
        default:
            break;
        }
    }
    active = 2;
    orange.setState(HIGH);
}

// Turn the light to green
void RoadLight::turnGreen()
{
    if(active > 0)
    {
        switch(active)
        {
        case 1:
            red.setState(LOW);
            break;
        case 2:
            orange.setState(LOW);
            break;
        default:
            break;
        }
    }
    active = 3;
    green.setState(HIGH);
}

// Make the light blink
void RoadLight::blink()
{
    orange.setState(HIGH);
    delayMicroseconds(1000000); // 1 second
    orange.setState(LOW);
    delayMicroseconds(1000000); // 1 second
}
