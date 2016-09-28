#ifndef NIGHTREGULATION_H
#define NIGHTREGULATION_H

#include <NormalRegulation.h>

class NightRegulation : public Regulation
{
    public:
        NightRegulation();
        NightRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                        PedestrianLight *sideRoadPedestrianLights, InputPin *switch1, InputPin *switch2, InputPin *switch3,
                        InputPin *switch4, NormalRegulation *normalReg);
        virtual void runRegulation();
    private:
        InputPin *s1;
        void allRlBlink();
        NormalRegulation *normReg;
};

#endif
