#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED

#include "Fecha.h"

class Objeto
{
    public:
        Objeto();
        virtual String getTipo() = 0;
};
#endif // OBJETO_H_INCLUDED
