#include "Ciudades.h"

/* Funciones solo del Modulo Ciudades */

void CrearLista(ListaCiudades &L)
{
    L = NULL;
}

boolean PerteneceLista(ListaCiudades L, String valor)
{
    if(L == NULL)
    {
        return FALSE;
    }
    else
    {
        String auxNom;
        strcrear(auxNom);
        DarNombre(L->info,auxNom);
        if(streq(auxNom,valor))
        {
            return TRUE;
        }
        else
        {
            return PerteneceLista(L->sig,valor);
        }
    }
    return FALSE;
}

void Insfront(ListaCiudades &L, Ciudad c)
{
    ListaCiudades aux = new NodoCiudades;
    aux->info = c;
    aux->sig = L;
    L = aux;
}

Ciudad ObtenerEnLista(ListaCiudades L, String nombreCiudad)
{
    ListaCiudades aux;
    Ciudad c;
    aux = L;
    String auxNom;
    strcrear(auxNom);
    DarNombre(L->info,auxNom);

    while(!streq(auxNom,nombreCiudad))
    {
        aux = aux->sig;
        DarNombre(aux->info,auxNom);
    }
    c = aux->info;
    return c;
}

void MostrarLista(ListaCiudades L)
{
    while(L != NULL)
    {
        MostrarCiudad(L->info);
        L = L->sig;
    }
}

int Dispersion(String nombreCiudad)
{
    return (SumaAscii(nombreCiudad) % B);
}
/* FIN: Funciones solo del Modulo Ciudades */

void MakeCiudades(Ciudades &C)
{
    for(int i = 0; i < B; i++)
        CrearLista(C[i]);
}

boolean Member(Ciudades C, String nombreCiudad)
{
    int cubeta = Dispersion(nombreCiudad);
    return PerteneceLista(C[cubeta],nombreCiudad);
}

void Insert(Ciudades &C, Ciudad ciu)
{
    String auxNom;
    strcrear(auxNom);
    DarNombre(ciu,auxNom);
    int cubeta = Dispersion(auxNom);
    Insfront(C[cubeta],ciu);
}

Ciudad FindCiudad(Ciudades C, String nomCiudad)
{
    int cubeta = Dispersion(nomCiudad);

    return ObtenerEnLista(C[cubeta],nomCiudad);
}
