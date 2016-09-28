#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <Light.h>

class TrafficLight
{
    public:
        TrafficLight();
        TrafficLight(int redPin, int greenPin);
        virtual void lightsOff() =0;
        virtual void turnRed() =0;
        virtual void turnGreen() =0;
    protected:
        Light red;
        Light green;
        volatile int active;
};

#endif
