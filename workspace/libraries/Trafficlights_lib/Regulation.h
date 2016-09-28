#ifndef REGULATION_H
#define REGULATION_H

#include <RoadLight.h>
#include <PedestrianLight.h>
#include <InputPin.h>

class Regulation
{
    public:
        Regulation();
        Regulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                   PedestrianLight *sideRoadPedestrianLights, InputPin *switch2, InputPin *switch3, InputPin *switch4);
        virtual void runRegulation() =0;
        void stopRegulation();
        void allPlBlink();
    protected:
        RoadLight *mrLights, *srLights;
        PedestrianLight *mrPdLights, *srPdLights;
        InputPin *s2, *s3, *s4;
        bool runReg;
};

#endif
