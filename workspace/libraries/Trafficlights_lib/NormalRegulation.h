#ifndef NORMALREGULATION_H
#define NORMALREGULATION_H

#include <Regulation.h>

class NormalRegulation : public Regulation
{
    public:
        NormalRegulation();
        NormalRegulation(RoadLight *mainRoadLights, RoadLight *sideRoadLights, PedestrianLight *mainRoadPedestrianLights,
                         PedestrianLight *sideRoadPedestrianLights, InputPin *mainRoadPedestrianButton,
                         InputPin *sideRoadPedestrianButton, InputPin *sideRoadButton, InputPin *switch1, InputPin *switch2,
                         InputPin *switch3, InputPin *switch4);
        virtual void runRegulation();
        void addCar();
        void turnMainRoadGreen();
        void allLightsRed();
    private:
        InputPin *mrPdButton, *srPdButton, *srButton, *s1;
        volatile int _amount, _runs;
        bool _mrGreen;
        void pedestrian();
        void sideRoad();
};

#endif
