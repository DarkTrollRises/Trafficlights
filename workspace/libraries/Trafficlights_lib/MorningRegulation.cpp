#include "MorningRegulation.h"

// Standard Constructor
MorningRegulation::MorningRegulation()
{
}

// Constructor
MorningRegulation::MorningRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                                     PedestrianLight *sideRoadPedestrianLights, InputPin *switch2, InputPin *switch3,
                                     InputPin *switch4) :
    Regulation(mainRoadLights, sideRoadLights, mainRoadPedestrianLights, sideRoadPedestrianLights, switch2, switch3, switch4)
{
}

// Run the regulation
void MorningRegulation::runRegulation()
{
    runReg = true;
    while(runReg)
    {
        mrLights->turnGreen();
        delayMicroseconds(10000000);// 10 seconds
        mrLights->turnOrange();
        delayMicroseconds(3000000); // 3 seconds
        mrLights->turnRed();
        delayMicroseconds(2000000); // 2 seconds
        mrPdLights->turnGreen();
        srPdLights->turnGreen();
        delayMicroseconds(4000000); // 4 seconds
        allPlBlink();               // 3 seconds
        mrPdLights->turnRed();
        srPdLights->turnRed();
        delayMicroseconds(2000000); // 2 seconds
        srLights->turnGreen();
        delayMicroseconds(12000000);// 12 seconds
        srLights->turnOrange();
        delayMicroseconds(3000000); // 3 seconds
        srLights->turnRed();
        delayMicroseconds(2000000); // 2 seconds

        if(s2->getState() == LOW || s3->getState() == HIGH || s4->getState() == HIGH)
            stopRegulation();
    }
}
