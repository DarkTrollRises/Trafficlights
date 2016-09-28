#ifndef LIGHT_H
#define LIGHT_H

#include <GeneralPin.h>

class Light : public GeneralPin
{
    public:
        Light();
        Light(int pin);
        void setState(int state);
};

#endif
