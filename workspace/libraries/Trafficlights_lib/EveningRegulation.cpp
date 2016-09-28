#include "EveningRegulation.h"

// Standard Constructor
EveningRegulation::EveningRegulation()
{
}

// Constructor
EveningRegulation::EveningRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                                     PedestrianLight *sideRoadPedestrianLights, InputPin *switch2, InputPin *switch3,
                                     InputPin *switch4) :
    Regulation(mainRoadLights, sideRoadLights, mainRoadPedestrianLights, sideRoadPedestrianLights, switch2, switch3, switch4)
{
}

// Run the regulation
void EveningRegulation::runRegulation()
{
    runReg = true;
    while(runReg)
    {
        mrLights->turnGreen();
        delayMicroseconds(16000000);// 16 seconds
        mrLights->turnOrange();
        delayMicroseconds(3000000); // 3 seconds
        mrLights->turnRed();
        delayMicroseconds(2000000); // 2 seconds
        mrPdLights->turnGreen();
        srPdLights->turnGreen();
        delayMicroseconds(5000000); // 5 seconds
        allPlBlink();               // 3 seconds
        mrPdLights->turnRed();
        srPdLights->turnRed();
        delayMicroseconds(2000000); // 2 seconds
        srLights->turnGreen();
        delayMicroseconds(6000000); // 6 seconds
        srLights->turnOrange();
        delayMicroseconds(3000000); // 3 seconds
        srLights->turnRed();
        delayMicroseconds(2000000); // 2 seconds

        if(s2->getState() == HIGH || s3->getState() == LOW || s4->getState() == HIGH)
            stopRegulation();
    }
}
