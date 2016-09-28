#ifndef INPUTPIN_H
#define INPUTPIN_H

#include <GeneralPin.h>

class InputPin : public GeneralPin
{
    public:
        InputPin();
        InputPin(int pin);
        void addInterrupt(void (*func)(), int mode);
        void removeInterrupt();
};

#endif
