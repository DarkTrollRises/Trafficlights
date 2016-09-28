// Includes
#include <InputPin.h>
#include <RoadLight.h>
#include <PedestrianLight.h>
#include <NormalRegulation.h>
#include <MorningRegulation.h>
#include <EveningRegulation.h>
#include <NightRegulation.h>

// Declaring objects
// Trafficlights
RoadLight mrLights, srLights;
PedestrianLight mrPdLights, srPdLights;

// Pointers to trafficlights
RoadLight *mrLightsPtr, *srLightsPtr;
PedestrianLight *mrPdLightsPtr, *srPdLightsPtr;

// Buttons
InputPin mrPdButton, srPdButton, srButton, s1, s2, s3, s4;

// Pointers to buttons
InputPin *mrPdButtonPtr, *srPdButtonPtr, *srButtonPtr, *s1Ptr, *s2Ptr, *s3Ptr, *s4Ptr;

// Regulations
NormalRegulation normalReg;
MorningRegulation morningReg;
EveningRegulation eveningReg;
NightRegulation nightReg;

// Pointer to regulation
NormalRegulation *normRegPtr;

int tries;

// Initializing objects
void setup() 
{
  mrLights = RoadLight(22, 23, 24);
  srLights = RoadLight(33, 34, 42);
  mrPdLights = PedestrianLight(25, 26);
  srPdLights = PedestrianLight(29, 30);

  mrLightsPtr = &mrLights;
  srLightsPtr = &srLights;
  mrPdLightsPtr = &mrPdLights;
  srPdLightsPtr = &srPdLights;
  
  mrPdButton = InputPin(28);
  srPdButton = InputPin(31);
  srButton = InputPin(40);
  
  srButton.addInterrupt(sideInterrupt, FALLING);

  mrPdButtonPtr = &mrPdButton;
  srPdButtonPtr = &srPdButton;
  srButtonPtr = &srButton;

  s1 = InputPin(36);
  s2 = InputPin(37);
  s3 = InputPin(38);
  s4 = InputPin(39);
  
  s1Ptr = &s1;
  s2Ptr = &s2;
  s3Ptr = &s3;
  s4Ptr = &s4;

  normalReg = NormalRegulation(mrLightsPtr, srLightsPtr, mrPdLightsPtr, srPdLightsPtr, mrPdButtonPtr, srPdButtonPtr, srButtonPtr, s1Ptr, 
                               s2Ptr, s3Ptr, s4Ptr);
  normRegPtr = &normalReg;
  morningReg = MorningRegulation(mrLightsPtr, srLightsPtr, mrPdLightsPtr, srPdLightsPtr, s2Ptr, s3Ptr, s4Ptr);
  eveningReg = EveningRegulation(mrLightsPtr, srLightsPtr, mrPdLightsPtr, srPdLightsPtr, s2Ptr, s3Ptr, s4Ptr);
  nightReg = NightRegulation(mrLightsPtr, srLightsPtr, mrPdLightsPtr, srPdLightsPtr, s1Ptr, s2Ptr, s3Ptr, s4Ptr, normRegPtr);
  
  noInterrupts();

  tries = 0;
}

// Main loop
void loop() 
{
  if(s2.getState() == HIGH)
  {
    if(tries >= 5)
      normalReg.allLightsRed();
    morningReg.runRegulation();
    tries = 0;
  }
  else if(s3.getState() == HIGH)
  {
    if(tries >= 5)
      normalReg.allLightsRed();
    eveningReg.runRegulation();
    tries = 0;
  }
  else if(s4.getState() == HIGH)
  {
    if(tries >= 5)
      normalReg.allLightsRed();
    nightReg.runRegulation();
    tries = 0;
  }
  else if(s1.getState() == HIGH)
  {
    if(tries >= 5)
      normalReg.allLightsRed();
    normalReg.runRegulation();
    tries = 0;
  }
  else
    tries++;

  delayMicroseconds(1000000);
  if(tries >= 5)
  {
    mrLights.lightsOff();
    srLights.lightsOff();
    mrPdLights.lightsOff();
    srPdLights.lightsOff();
  }
}

// Side road interrupt
void sideInterrupt()
{
  normalReg.addCar();
}

