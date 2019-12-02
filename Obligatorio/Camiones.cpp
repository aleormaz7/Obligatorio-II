#include "Camiones.h"

int Camiones :: dispersion(String mat)
{
    String aux;
    int num = aux.SumaAscii(mat);
    return (num % B);
}

void Camiones :: crearLista(Nodo * &L)
{
    L = NULL;
}

void Camiones :: destruirLista (Nodo * &L)
{
    Nodo * aux = L;
    while (aux != NULL)
    {
        L = aux->sig;
        delete(aux);
        aux = L;
    }
    L = aux;
}

bool Camiones :: perteneceLista (Nodo * L, String mat)
{
    bool existe = false;
    while (!existe && L != NULL)
    {
        if (L->info->getMatricula() == mat)
            existe = true;
        else
            L = L->sig;
    }
    return existe;
}

void Camiones :: insFrontEnLista (Nodo * &L, Camion * c)
{
    Nodo * aux = new Nodo;
    aux->info = c;
    aux->sig = L;
    L = aux;
}

Camion * Camiones :: obtenerEnLista(Nodo * L, String mat)
{
    while(L->info->getMatricula() != mat)
        L = L->sig;
    return (L->info);
}

Camiones :: Camiones()
{
    for (int i=0; i < B; i++)
        crearLista(Hash[i]);
}

Camiones :: ~Camiones()
{
    for(int i=0; i < B; i++)
        destruirLista(Hash[i]);
}

bool Camiones :: Member(String mat)
{
    int cubeta = dispersion(mat);
    return perteneceLista(Hash[cubeta], mat);
}

void Camiones :: Insert(Camion * c)
{
    String mat = c->getMatricula();
    int cubeta = dispersion(mat);
    insFrontEnLista(Hash[cubeta],c);
}

Camion * Camiones :: Find(String mat)
{
    int cubeta = dispersion(mat);
    return obtenerEnLista(Hash[cubeta], mat);
}

void Camiones :: cargarIterador(Iterador &iter)
{
    for(int i = 0; i < B;i++)
    {
        Nodo * aux = Hash[i];
        while (aux != NULL)
        {
            iter.insertarObjeto(aux->info);
            aux = aux->sig;
        }
    }
}

Iterador Camiones :: listarCamiones()
{
    Iterador iter;
    cargarIterador(iter);
    return iter;

}

float Camiones :: totalMetrosCubicosAnuales()
{
    float total = 0;
    for(int i = 0; i < B; i++)
    {
        Nodo * aux = Hash[i];
        while (aux != NULL)
        {
            total = total + aux->info->calcularMetrosCubicosAnuales();
            aux = aux->sig;
        }
    }
    return total;
}

void Camiones :: CantidadCamionesPorTipo(int &cantSimple,int &cantGrande,int &cantRemolque)
{
    cantSimple = 0;
    cantGrande = 0;
    cantRemolque = 0;

    for(int i = 0; i < B; i++)
    {
        Nodo * aux = Hash[i];
        while (aux != NULL)
        {
            if(aux->info->getTipo() == "CAMION SIMPLE")
                cantSimple++;
            else if(aux->info->getTipo() == "CAMION GRANDE")
                cantGrande++;
            else
                cantRemolque++;

            aux = aux->sig;
        }
    }
}

void Camiones :: CantidadCamionesGrandesFechaAdquisicion(int &cant,Fecha &f)
{
    cant = 0;
    for(int i = 0; i < B; i++)
    {
        Nodo * aux = Hash[i];
        while (aux != NULL)
        {
            if(aux->info->getTipo() == "CAMION GRANDE")
            {
                CamionGrande * auxGrande = (CamionGrande *) aux->info;///casteo
                if(auxGrande->getFechaAdquirido() > f)
                    cant++;
            }
            else if(aux->info->getTipo() == "CAMION CON REMOLQUE")
            {
                CamionConRemolque * auxRemolque = (CamionConRemolque *) aux->info;///casteo
                if(auxRemolque->getFechaAdquirido() > f)
                    cant++;
            }
            aux = aux->sig;
        }
    }
}
