#include "ListaRevision.h"

void MostrarLista(Lista L)
{
    while(L != NULL)
    {
        printf(" %d",L->info);
        L = L->sig;
    }
}

void Crear(Lista &L)
{
    L = NULL;
}

boolean EsVacia(Lista L)
{
    boolean es = FALSE;

    if(L == NULL)
    {
        es = TRUE;
    }

    return es;
}

void InsFront(Lista &L, int e)
{
    Lista aux = new nodo;
    aux-> info = e;
    aux->sig = L;
    L = aux;
}


int Primero(Lista L)
{
    return (L->info);
}


void Resto(Lista &L)
{
    Lista aux = L;
    L = L->sig;
    delete(aux);
}

int LargoRecu(Lista L)
{
    if(L == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + LargoRecu(L->sig);
    }
}


int UltimoRecu(Lista L)
{
    if(L->sig == NULL)
        return L->info;
    else
        UltimoRecu(L->sig);
}


int ContarRecu(Lista L, int valor)
{
    if(L == NULL)
    {
        return 0;
    }
    else
    {
        if(L->info == valor)
        {
            return 1 + ContarRecu(L->sig,valor);
        }
        else
        {
            return ContarRecu(L->sig,valor);
        }
    }
}


boolean PerteneceRecu(Lista L, int valor)
{
    if(L == NULL)
    {
        return FALSE;
    }
    else
    {
        if(L->info == valor)
        {
            return TRUE;
        }
        else
        {
            PerteneceRecu(L->sig,valor);
        }
    }
}


void SustituirRecu(Lista &L, int num1,int num2)
{
    if(L != NULL)
    {
        if(L->info == num1)
        {
            L->info = num2;
        }

        SustituirRecu(L->sig,num1,num2);
    }
}



int MaximoRecu(Lista L)
{
    if(L->sig == NULL)
    {
        return L->info;
    }
    else
    {
        int aux = MaximoRecu(L->sig);
        if(L->info > aux)
        {
            return L->info;
        }
        else
        {
            return aux;
        }
    }
}


void ParesImparesRecu(Lista L, Lista &LPares, Lista &LImpares)
{
    if(L != NULL)
    {
        if((L->info % 2) == 0)
        {
            InsFront(LPares,L->info);
        }
        else
        {
            InsFront(LImpares,L->info);
        }

        ParesImparesRecu(L->sig, LPares, LImpares);
    }
}

void InsBackRecu(Lista &L, int valor)
{
    if(L == NULL)
    {
        L = new nodo;
        L->info = valor;
        L->sig = NULL;
    }
    else
    {
        InsBackRecu(L->sig,valor);
    }
}
