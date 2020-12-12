#include "canion_1.h"
#include <math.h>



float canion_1::getXo() const
{
    return Xo;

}

float canion_1::getYo() const
{
    return Yo;
}

float canion_1::getRad() const
{
    return rad;
}

canion_1::canion_1(float Xo_, float Yo_, float rad_)
{
    Xo=Xo_;
    Yo=Yo_;
    rad=rad_;
}
