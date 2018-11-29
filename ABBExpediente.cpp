#include "ABBExpediente.h"

void CrearABB(ABBExpediente &a)
///Crear
{
    a = NULL;
}

boolean AbbExpientesEsVacio(ABBExpediente a)
{
    boolean es = FALSE;
    if(a == NULL)
        es = TRUE;
    return es;
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
/// Precondición : el árbol a  NO está vacío
{
    if (a -> hizq == NULL)
        return (a->info);
    else
        return minimoExpediente (a -> hizq);
}

Expediente maximoExpediente (ABBExpediente a)
/// Precondición : el árbol a  NO está vacío
{
    if (a -> hder == NULL)
        return (a->info);
    else
        return maximoExpediente (a -> hder);
}

void borrarMinimoExpedienete (ABBExpediente &a)
/// Precondición : el árbol a  NO está vacío
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

void borrarABBExpedientePorCodigo (long int cod , ABBExpediente &a)
/// Precondición : el Expediente está en el árbol
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
        mostrarExpedienteConsultaOrdenados(a -> info);
        ListarExpedientesOrdenados (a -> hder);
     }
}

int cntExpedientesEscribano(ABBExpediente a, String apellido)
{
    if (a == NULL)
        return 0;
    else
    {
        String ApeAux;
        strcrear(ApeAux);
        darApellidoEscribano((a->info),ApeAux);
        if(streq(ApeAux,apellido))
            return 1 + cntExpedientesEscribano(a -> hizq,apellido) + cntExpedientesEscribano (a -> hder,apellido);
        else
            return cntExpedientesEscribano(a -> hizq,apellido) + cntExpedientesEscribano(a -> hder,apellido);
    }
}

void bajarExpedientes(ABBExpediente a, String nomArch)
{
    FILE * f = fopen(nomArch,"wb");
    bajarExpedientesRec(a,f);
    fclose(f);
}

void bajarExpedientesRec(ABBExpediente a,FILE * f)
{
    if (a != NULL)
    {
        bajarExpedienteArchivo(a->info,f);
        bajarExpedientesRec(a->hizq,f);
        bajarExpedientesRec(a ->hder,f);
    }
}

void levantarExpedientes(ABBExpediente &a,String nomArch)
{
    FILE * f = fopen(nomArch,"rb");
    Expediente auxExp;
    levantarExpedienteArchivo(auxExp,f);
    while(!feof(f))
    {
        InsertABBExp(a,auxExp);
        levantarExpedienteArchivo(auxExp,f);
    }
    fclose(f);
}

void codExpMasRevisiones(ABBExpediente a, listaRevision lr,long int &codExp, int &cntRev)
{
    if(a != NULL)
    {
        if(cntRev < (cntRevisionesCodigoExp(lr,darCodigoExpediente(a->info))))
        {
            cntRev = cntRevisionesCodigoExp(lr,darCodigoExpediente(a->info));
            codExp = darCodigoExpediente(a->info);
        }
        codExpMasRevisiones(a->hizq,lr,codExp,cntRev);
        codExpMasRevisiones(a->hder,lr,codExp,cntRev);
    }
 }
