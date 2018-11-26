#include "ABBExpediente.h"

void CrearABB(ABBExpediente &a)
///Crear
{
    a = NULL;
}

boolean PerteneceExp(ABBExpediente a, Expediente e)
///Saber si Expediente pertenece al ABB
{
    if (a == NULL)
        return FALSE;
    else
        if (darCodigoExpediente(a -> info) == darCodigoExpediente(e))
            return TRUE;
        else
            if (darCodigoExpediente(e) < (darCodigoExpediente(a -> info)) )
                return PerteneceExp(a -> hizq,e);
           else
                return PerteneceExp(a -> hder,e);
}

boolean PerteneceExpPorCod(ABBExpediente a, long int cod)
///Saber si Expediente pertenece al ABB, por su codigo de expediente
{
    if (a == NULL)
        return FALSE;
    else
        if (darCodigoExpediente(a -> info) == cod)
            return TRUE;
        else
            if (cod < (darCodigoExpediente(a -> info)) )
                return PerteneceExpPorCod(a -> hizq,cod);
           else
                return PerteneceExpPorCod(a -> hder,cod);
}

void InsertABBExp(ABBExpediente &a, Expediente e)
///PRECONDICION: el expediente no existe previamente en el ABB
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
            InsertABBExp (a -> hizq, e);
        else
            InsertABBExp (a -> hder, e);
    }
}

Expediente minimoExpediente (ABBExpediente a)
/// Precondici�n : el �rbol a  NO est� vac�o
{
    if (a -> hizq == NULL)
        return (a->info);
    else
        return minimoExpediente (a -> hizq);
}


void borrarMinimoExpedienete (ABBExpediente &a)
/// Precondici�n : el �rbol a  NO est� vac�o
{
    ABBExpediente aux;
    if (a -> hizq == NULL)
    {
        aux = a -> hder;
        delete a;
        a = aux;
    }
    else
        borrarMinimoExpedienete (a -> hizq);
 }

void borrarABBExpediente (Expediente e , ABBExpediente &a)
/// Precondici�n : el Expediente est� en el �rbol
{
    ABBExpediente aux;
    if (darCodigoExpediente(e) == darCodigoExpediente(a -> info))
    {
        if (a -> hder == NULL)
        {
            aux = a -> hizq;
            delete a;
            a = aux;
        }
        else
        {
            if (a -> hizq == NULL)
            {
                aux = a -> hder;
                delete a;
                a = aux;
            }
            else
            {
                a -> info = minimoExpediente(a -> hder);
                borrarMinimoExpedienete (a ->hder);
            }
        }
     }
        else
        {
            if (darCodigoExpediente(e) < darCodigoExpediente(a -> info))
                borrarABBExpediente (e, a -> hizq);
            else
                borrarABBExpediente (e, a -> hder);
        }
}

void borrarABBExpedientePorCodigo (long int cod , ABBExpediente &a)
/// Precondici�n : el Expediente est� en el �rbol
{
    ABBExpediente aux;
    if (cod == darCodigoExpediente(a -> info))
    {
        if (a -> hder == NULL)
        {
            aux = a -> hizq;
            delete a;
            a = aux;
        }
        else
        {
            if (a -> hizq == NULL)
            {
                aux = a -> hder;
                delete a;
                a = aux;
            }
            else
            {
                a -> info = minimoExpediente(a -> hder);
                borrarMinimoExpedienete (a ->hder);
            }
        }
     }
        else
        {
            if (cod < darCodigoExpediente(a -> info))
                borrarABBExpedientePorCodigo(cod, a -> hizq);
            else
                borrarABBExpedientePorCodigo(cod, a -> hder);
        }
}

 void ListarExpedientesOrdenados (ABBExpediente a)
{
    if (a != NULL)
    {
        ListarExpedientesOrdenados (a -> hizq);
        printf (" %d ", darCodigoExpediente(a -> info));
        ListarExpedientesOrdenados (a -> hder);
     }
}


