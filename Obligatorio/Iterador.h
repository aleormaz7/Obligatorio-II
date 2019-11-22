#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED

#include "Objeto.h"
#include "Iterador.h"

class Iterador
{
    private:
        struct Nodo
        {
            Objeto * info;
            Nodo * sig;
        };
        Nodo * lista;

    public:
        Iterador();
        void insertarObjeto(Objeto *);
        bool hayMasObjetos();
        Objeto * proximoObjeto ();
        ~Iterador ();

};


#endif // ITERADOR_H_INCLUDED
