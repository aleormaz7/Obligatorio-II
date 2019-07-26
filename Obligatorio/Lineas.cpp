#include "Lineas.h"

void MakeLineas(Lineas &l)
{
    l = NULL;
}

boolean MemberLinea(Lineas l,String codigoLinea)
{
    if(l == NULL)
    {
        return FALSE;
    }
    else
    {
        String cod;
        strcrear(cod);
        DarCodigoLinea(l->linea,cod);
        if(streq(cod,codigoLinea))
        {
            return TRUE;
        }
        else
        {
            if(strmen(codigoLinea,cod))
                return MemberLinea(l->hIzq,codigoLinea);
            else
                return MemberLinea(l->hDer,codigoLinea);
        }
    }
}

void InsertLinea(Lineas &lineas, Linea l)
{
    String codLineaABB,codLineaInserta;
    strcrear(codLineaABB);
    strcrear(codLineaInserta);

    if(lineas == NULL)
    {
        lineas = new NodoLineaABB;
        lineas->linea = l;
        lineas->hIzq = NULL;
        lineas->hDer = NULL;
    }
    else
    {
        DarCodigoLinea(lineas->linea,codLineaABB);
        DarCodigoLinea(l,codLineaInserta);

        if(strmen(codLineaInserta,codLineaABB))
            InsertLinea(lineas->hIzq,l);
        else
            InsertLinea(lineas->hDer,l);
    }
}

Linea FindLinea(Lineas l, String codigoLinea)
{
    String cod;
    strcrear(cod);
    DarCodigoLinea(l->linea,cod);
    if(streq(cod,codigoLinea))
    {
        return l->linea;
    }
    else
    {
        if(strmen(codigoLinea,cod))
            return FindLinea(l->hIzq,codigoLinea);
        else
            return FindLinea(l->hDer,codigoLinea);
    }
}

void ModifyLinea(Lineas &l,Linea linea)
{
    String codLineaOriginal,codModifica;
    strcrear(codLineaOriginal);
    strcrear(codModifica);
    DarCodigoLinea(l->linea,codLineaOriginal);
    DarCodigoLinea(linea,codModifica);
    if(streq(codLineaOriginal,codModifica))
    {
        l->linea = linea;
    }
    else
    {
        if(strmen(codModifica,codLineaOriginal))
             ModifyLinea(l->hIzq,linea);
        else
             ModifyLinea(l->hDer,linea);
    }
}

void ListarLineas(Lineas l)
{
    if(l != NULL)
    {
        ListarLineas(l->hIzq);
        MostrarLinea(l->linea);
        ListarLineas(l->hDer);
    }
}

boolean lineasVacia(Lineas l)
{
    boolean resu = FALSE;
    if (l == NULL)
        resu = TRUE;
    return resu;
}
