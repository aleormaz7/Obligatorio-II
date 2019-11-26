#include "Camion.h"

Camion :: Camion() : matricula(), marca()
{
    cantViajesAnuales = 0;
    camionero = NULL;
}

Camion :: Camion(String mat,String mar,int cant) : matricula(mat),marca(mar)
{
    cantViajesAnuales = cant;
    camionero = NULL;
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

Camionero * Camion :: getCamionero()
{
    return camionero;
}

void Camion :: setCamionero(Camionero * c)
{
    camionero = c;
}
