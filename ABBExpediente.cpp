#include "ABBExpediente.h"



///Operaciones Basicas:
///Crear
void CrearABB(ABBExpediente &a)
{
    a = NULL;
}
///Pertenece
///Saber si un elemento pertenece al ABB, versión iterativa
boolean Pertenece(ABBExpediente a, long int e)
{
    boolean encontre = FALSE;
    while (a != NULL && !encontre)
    {
        if (e == darCodigoExpediente(a->info))
            encontre = TRUE;
        else
            if (e < darCodigoExpediente(a -> info))
                a = a -> hizq;
            else
                a = a -> hder;
    }
    return encontre;
}

///Insert
///PRECONDICION: el valor no existía previamente en el ABB
void Insert(ABBExpediente &a, Expediente e)
{
    if (a == NULL)
    {
        a = new nodoA;
        a -> info = e;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else
    {
        if (e.codigoExpediente < (darCodigoExpediente(a->info)))
            Insert (a -> hizq, e);
        else
            Insert (a -> hder, e);
    }
}
