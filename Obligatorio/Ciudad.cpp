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
    printf("\nCodigo de la ciudad: %d", c.codigoCiudad);
    printf("\nNombre: ");
    print(c.nombreCiudad);
}

void CargarCiudad(Ciudad &c, int codCiud)
{
    c.codigoCiudad = codCiud;
    printf("\nNombre de la ciudad: ");
    strcrear(c.nombreCiudad);
    scan(c.nombreCiudad);
}
