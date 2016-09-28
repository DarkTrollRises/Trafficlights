#include "Regulation.h"

// Standard Constructor
Regulation::Regulation()
{
}

// Constructor
Regulation::Regulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                       PedestrianLight *sideRoadPedestrianLights, InputPin *switch2, InputPin *switch3, InputPin *switch4)
{
    mrLights = mainRoadLights;
    srLights = sideRoadLights;
    mrPdLights = mainRoadPedestrianLights;
    srPdLights = sideRoadPedestrianLights;

    s2 = switch2;
    s3 = switch3;
    s4 = switch4;

    runReg = false;
}

// Stop the current regulation
void Regulation::stopRegulation()
{
    runReg = false;
}

// Make all pedestrian lights blink for 3 seconds
void Regulation::allPlBlink()
{
    for(int i=0; i<12; i++)
    {
        mrPdLights->turnGreen();
        srPdLights->turnGreen();
        delayMicroseconds(125000);  // 0,125 seconds
        mrPdLights->lightsOff();
        srPdLights->lightsOff();
        delayMicroseconds(125000);  // 0,125 seconds
    }
}
