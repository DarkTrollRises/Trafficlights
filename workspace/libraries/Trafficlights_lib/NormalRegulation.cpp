#include "NormalRegulation.h"

// Standard Constructor
NormalRegulation::NormalRegulation()
{
}

// Constructor
NormalRegulation::NormalRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                                   PedestrianLight *sideRoadPedestrianLights, InputPin *mainRoadPedestrianButton,
                                   InputPin *sideRoadPedestrianButton, InputPin *sideRoadButton, InputPin *switch1,
                                   InputPin *switch2, InputPin *switch3, InputPin *switch4) :
    Regulation(mainRoadLights, sideRoadLights, mainRoadPedestrianLights, sideRoadPedestrianLights, switch2, switch3, switch4)
{
    mrPdButton = mainRoadPedestrianButton;
    srPdButton = sideRoadPedestrianButton;
    srButton = sideRoadButton;
    s1 = switch1;

    _mrGreen = false;
}

// Run the regulation
void NormalRegulation::runRegulation()
{
    runReg = true;
    turnMainRoadGreen();
    while(runReg)
    {
        if(!_mrGreen)
        {
            allLightsRed();
            delayMicroseconds(2000000); // 2 seconds
            mrLights->turnGreen();
            _mrGreen = true;
        }

        if(mrPdButton->getState() == HIGH || srPdButton->getState() == HIGH)
        {
            pedestrian();
        }
        else if(srButton->getState() == HIGH)
        {
            sideRoad();
        }

        if(s1->getState() == LOW || s2->getState() == HIGH || s3->getState() == HIGH || s4->getState() == HIGH)
        {
            stopRegulation();
        }
    }
    delayMicroseconds(5000000); // 5 seconds
    mrLights->turnOrange();
    delayMicroseconds(3000000); // 3 seconds
    mrLights->turnRed();
    delayMicroseconds(2000000); // 2 seconds
}

// Run the main road pedestrian regulation
void NormalRegulation::pedestrian()
{
    delayMicroseconds(5000000); // 5 seconds
    mrLights->turnOrange();
    delayMicroseconds(3000000); // 3 seconds
    mrLights->turnRed();
    delayMicroseconds(2000000); // 2 seconds
    mrPdLights->turnGreen();
    srPdLights->turnGreen();
    delayMicroseconds(8000000); // 8 seconds
    allPlBlink();               // 3 seconds
    mrPdLights->turnRed();
    srPdLights->turnRed();
    delayMicroseconds(4000000); // 4 seconds
    mrLights->turnGreen();
    delayMicroseconds(20000000);// 20 seconds
}

// Run the side road regulation
void NormalRegulation::sideRoad()
{
    delayMicroseconds(5000000); // 5 seconds
    mrLights->turnOrange();
    delayMicroseconds(3000000); // 3 seconds
    mrLights->turnRed();
    delayMicroseconds(2000000); // 2 seconds
    srLights->turnGreen();
    _amount = 0;
    _runs = 1;
    interrupts();
    while(_runs <= _amount)
    {
        delayMicroseconds(5000000); // 5 seconds
        _runs++;
    }
    noInterrupts();
    srLights->turnOrange();
    delayMicroseconds(3000000); // 3 seconds
    srLights->turnRed();
    delayMicroseconds(2000000); // 2 seconds
    mrLights->turnGreen();
    delayMicroseconds(20000000);// 20 seconds
}

// Add another 5 seconds to the countdown
void NormalRegulation::addCar()
{
    if(_amount <= 3)
        _amount++;
}

// Set all traffic lights to red
void NormalRegulation::allLightsRed()
{
    mrLights->turnRed();
    srLights->turnRed();
    mrPdLights->turnRed();
    srPdLights->turnRed();
}

// Run the start of the regulation again
void NormalRegulation::turnMainRoadGreen()
{
    _mrGreen = false;
}
