#include "Camion.h"

Camion :: Camion() : matricula(), marca()
{
    cantViajesAnuales = 0;
    camionero = NULL;
}

Camion :: Camion(String mat,String mar,int cant,Camionero * c) : matricula(mat),marca(mar)
{
    cantViajesAnuales = cant;
    camionero = c;
}

Camion :: Camion(const Camion &c) : matricula(c.matricula), marca(c.marca)
{
    cantViajesAnuales = c.cantViajesAnuales;
    camionero = c.camionero;
}

Camion :: ~Camion()
{
    ///deberia borrar camionero?
}

String Camion :: getMatricula()
{
    return matricula;
}

String Camion :: getMarca()
{
    return marca;
}

int Camion :: getCantViajesAnuales()
{
    return cantViajesAnuales;
}

void Camion :: setCantViajesAnuales(int cant)
{
    cantViajesAnuales = cant;
}
