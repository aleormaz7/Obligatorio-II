#include "Ciudades.h"

int Dispersion(String nombreCiudad)
{
    return (SumaAscii(nombreCiudad) % B);
}

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
    //int cubeta = Dispersion(DarNombre(c,auxNom));
    //Insfront(H[cubeta],ciu);
}

Ciudad Find(Ciudades C, String nomCiudad)
{


}

///1. Registrar los nombres de todas las ciudades que visita la empresa. Esta operación se ejecutará solamente una vez.
void AltaCiudad(String nombre)
{

}


///-------------------------------------------------------------/
///Auxiliares lista

void CrearLista(ListaCiudades &L)
{
    L = NULL;
}

boolean PerteneceLista(ListaCiudades L,String valor)
{
    /*if(L == NULL)
    {
        return FALSE;
    }
    else
    {
        if(darNumeroAsistente(L->info) == valor)
        {
            return TRUE;
        }
        else
        {
            return PerteneceLista(L->sig,valor);
        }
    }*/
    return FALSE;
}

void Insfront(ListaCiudades &L, Ciudad c)
{
    ListaCiudades aux = new Nodo;
    aux->info = c;
    aux->sig = L;
    L = aux;
}

Ciudad ObtenerEnLista(ListaCiudades L, int codigoCiudad)/*clave=numero sorteo asistente otorgado*/
{
    ListaCiudades aux;
    Ciudad c;
    aux = L;
    /*
    while(darNumeroAsistente(aux->info) != clave)
    {
        aux = aux->sig;
    }
    */
    c = aux->info;
    return c;
}

