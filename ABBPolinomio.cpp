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

//Precondición: Arbol NO vacío
Polinomio darRaiz(ABBPolinomio a)
{
    return a->info;
}

//Precondición: Arbol NO vacío
ABBPolinomio darHijoIzq(ABBPolinomio a)
{
    return a->hizq;
}

//Precondición: Arbol NO vacío
ABBPolinomio darHijoDer(ABBPolinomio a)
{
    return a->hder;
}

//Precondición: árbol no sea vacío
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
//Precondición: polinomio no debe existir en el árbol

//boolean existeEnArbol(ABBPolinomio a, String s)
//{

//}

//Polinomio obtenerPolinomio(ABBPolinomio a, String s)
//{

//}
//Precondición: s existe en el Árbol

//void Eliminar (ABBPolinomio &a)
//{

//}
//Precondicion: a no sea vacio

