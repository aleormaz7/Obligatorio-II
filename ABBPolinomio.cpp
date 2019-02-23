#include "ABBPolinomio.h"

void Crear(ABBPolinomio &a)
{
    a = NULL;
}

boolean esVacio(ABBPolinomio a)
{
    boolean resu = FALSE;
    if (a==NULL)
    {
        resu = TRUE;
    }
    return resu;
}

//Precondici�n: Arbol NO vac�o
Polinomio darRaiz(ABBPolinomio a)
{
    return a->info;
}

//Precondici�n: Arbol NO vac�o
ABBPolinomio darHijoIzq(ABBPolinomio a)
{
    return a->hizq;
}

//Precondici�n: Arbol NO vac�o
ABBPolinomio darHijoDer(ABBPolinomio a)
{
    return a->hder;
}

//Precondici�n: �rbol no sea vac�o
/// void ListarOrdenado(ABBPolinomios a)
void ListarABB(ABBPolinomio a)
{
     if (a != NULL)
     {
         printf (" %d ", a -> info);
         ListarABB(a -> hizq); ///ListarOrdenado(a -> hizq);
         ListarABB(a -> hder); ///ListarOrdenado(a -> hder);
     }
}

boolean existe(ABBPolinomio a, String nombrePolinomio)
{
    String straux;
    if (a == NULL)
        return FALSE;
    else
    {
        darNombrePolinomio(a->info,straux);
        if (streq(straux,nombrePolinomio))
            return TRUE;
        else
        {
            if (strmen(nombrePolinomio,straux))
            {
                existe(a->hizq,nombrePolinomio);
            }
            else
            {
                existe(a->hder,nombrePolinomio);
            }
        }
    }
}

//void insertar(ABBPolinomio &a, Polinomio p)
//{

//}
//Precondici�n: polinomio no debe existir en el �rbol

//boolean existeEnArbol(ABBPolinomio a, String s)
//{

//}

//Polinomio obtenerPolinomio(ABBPolinomio a, String s)
//{

//}
//Precondici�n: s existe en el �rbol

//void Eliminar (ABBPolinomio &a)
//{

//}
//Precondicion: a no sea vacio

