#ifndef ROADLIGHT_H
#define ROADLIGHT_H

#include <TrafficLight.h>

class RoadLight : public TrafficLight
{
    public:
        RoadLight();
        RoadLight(int redPin, int orangePin, int greenPin);
        virtual void lightsOff();
        virtual void turnRed();
        void turnOrange();
        virtual void turnGreen();
        void blink();
    protected:
        Light orange;
};

#endif
