#ifndef EVENINGREGULATION_H
#define EVENINGREGULATION_H

#include <Regulation.h>

class EveningRegulation : public Regulation
{
    public:
        EveningRegulation();
        EveningRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                          PedestrianLight *sideRoadPedestrianLights, InputPin *switch2, InputPin *switch3, InputPin *switch4);
        virtual void runRegulation();
};

#endif
