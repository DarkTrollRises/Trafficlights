#ifndef PEDESTRIANLIGHT_H
#define PEDESTRIANLIGHT_H

#include <TrafficLight.h>

class PedestrianLight : public TrafficLight
{
    public:
        PedestrianLight();
        PedestrianLight(int redPin, int greenPin);
        virtual void lightsOff();
        virtual void turnRed();
        virtual void turnGreen();
        void blink();
};

#endif
