#include "Camion.h"

Camion :: Camion() : matricula(), marca()
{
    cantViajesAnuales = 0;
}

Camion :: Camion(String mat,String mar,int cant) : matricula(mat),marca(mar)
{
    cantViajesAnuales = cant;
}

Camion :: Camion(const Camion &c) : matricula(c.matricula), marca(c.marca)
{
    cantViajesAnuales = c.cantViajesAnuales;
}

Camion :: ~Camion()
{

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
