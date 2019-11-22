#include "Iterador.h"

Iterador :: Iterador()
{
    lista = NULL;
}

void Iterador :: insertarObjeto(Objeto * obj)
{
    Nodo * aux = new Nodo;
    aux->info = obj;
    aux->sig = lista;
    lista = aux;
}

bool Iterador :: hayMasObjetos()
{
    return (bool)(lista != NULL);
}

Objeto * Iterador :: proximoObjeto()
{
    Objeto * objAux = lista->info;
    lista = lista->sig;
    return objAux;
}

Iterador :: ~Iterador()
{
    Nodo * aux = lista;
    while (aux != NULL)
    {
        lista = lista->sig;
        delete aux;
        aux = lista;
    }
}

