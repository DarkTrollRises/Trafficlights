#include "NightRegulation.h"

// Standard Constructor
NightRegulation::NightRegulation()
{
}

// Constructor
NightRegulation::NightRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                                 PedestrianLight *sideRoadPedestrianLights, InputPin *switch1, InputPin *switch2, InputPin *switch3,
                                 InputPin *switch4, NormalRegulation *normalReg) :
    Regulation(mainRoadLights, sideRoadLights, mainRoadPedestrianLights, sideRoadPedestrianLights, switch2, switch3, switch4)
{
    s1 = switch1;
    normReg = normalReg;
}

// Run the regulation
void NightRegulation::runRegulation()
{
    runReg = true;
    while(runReg)
    {
        allRlBlink();

        if(s1->getState() == HIGH || s2->getState() == HIGH || s3->getState() == HIGH || s4->getState() == LOW)
            stopRegulation();
    }
    if(s1->getState() == HIGH)
        normReg->runRegulation();
}

// Make all road lights blink
void NightRegulation::allRlBlink()
{
    mrLights->turnOrange();
    srLights->turnOrange();
    delayMicroseconds(1000000); // 1 second
    mrLights->lightsOff();
    srLights->lightsOff();
    delayMicroseconds(1000000); // 1 second
}
