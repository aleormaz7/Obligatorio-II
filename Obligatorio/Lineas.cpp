#include "Lineas.h"


void MakeLineas(Lineas &l)
{
    l = NULL;
}

boolean MemberLinea(Lineas l,String codigoLinea) //Determina si en el diccionario existe un elemento con la clave especificada
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
            if(strmen(cod,codigoLinea))
                return MemberLinea(l->hIzq,codigoLinea);
            else
                return MemberLinea(l->hDer,codigoLinea);
        }
    }
}


void InsertLinea(Lineas &lineas, Linea l) /*Precondici�n: que no exista previamente codigoalfanumerico*/
{
    if(lineas == NULL)
    {
        lineas = new NodoLineaABB;
        lineas->linea = l;
        lineas->hIzq = NULL;
        lineas->hDer = NULL;
    }
    else
    {
        String cod, cod2;
        strcrear(cod);//preguntar si es necesario
        strcrear(cod2);
        DarCodigoLinea(lineas->linea,cod);
        DarCodigoLinea(l,cod2);

        if(strmen(cod,cod2))
            InsertLinea(lineas->hIzq,l);
        else
            InsertLinea(lineas->hDer,l);
    }
}

Linea FindLinea(Lineas l, String codigoLinea) //Precondici�n: el elemento es miembro del diccionario.
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
        if(strmen(cod,codigoLinea))
            return FindLinea(l->hIzq,codigoLinea);
        else
            return FindLinea(l->hDer,codigoLinea);
    }
}

///5. Listar los datos b�sicos de todas las l�neas de la empresa (c�digo, origen, destino y
///    cantidad de paradas), ordenados por c�digo alfanum�rico de menor a mayor.
void ListarLineas(Lineas l)
{
    if(l != NULL)
    {
        ListarLineas(l->hIzq);
        MostrarLinea(l->linea);
        ListarLineas(l->hDer);
    }
}
