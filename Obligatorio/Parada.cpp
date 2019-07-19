#include "Parada.h"


int DarNumero(Parada p)
{
    return p.numero;
}

Ciudad DarCiudad(Parada p)
{
    return p.ciudad;
}

void MostrarParada(Parada p)
{
    printf("\nParada: ");
    printf("%d",p.numero);
    printf(" - ");
    MostrarCiudad(p.ciudad);
}

void CargarParada(Parada &p)
{
    printf("\nCargar Parada: ");


}
