#ifndef MORNINGREGULATION_H
#define MORNINGREGULATION_H

#include <Regulation.h>

class MorningRegulation : public Regulation
{
    public:
        MorningRegulation();
        MorningRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                          PedestrianLight *sideRoadPedestrianLights, InputPin *switch2, InputPin *switch3, InputPin *switch4);
        virtual void runRegulation();
};

#endif
