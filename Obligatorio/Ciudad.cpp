#include "Ciudad.h"

void DarNombre(Ciudad c, String &nombre)
{
    strcop(nombre,c.nombreCiudad);
}

int DarCodigo(Ciudad c)
{
    return c.codigoCiudad;
}

void MostrarCiudad(Ciudad c)
{
    printf("\nCiudad: ");
    print(c.nombreCiudad);
}

void CargarCiudad(Ciudad &c, int codigoCiudad)
{
    c.codigoCiudad = codigoCiudad;
    printf("\nNombre de la ciudad: ");
    strcrear(c.nombreCiudad);
    scan(c.nombreCiudad);
    StringAMayusculas(c.nombreCiudad);
}
