#ifndef CAMIONEROS_H_INCLUDED
#define CAMIONEROS_H_INCLUDED

#include "Camionero.h"
#include "Iterador.h"

class Camioneros
{
    private:
        struct NodoABB
        {
            Camionero * info;
            NodoABB * hizq;
            NodoABB * hder;
        };
        NodoABB * abb;

        ///Auxiliares:
        void DestruirArbol(NodoABB * &);
        bool PerteneceEnArbol(NodoABB *,long);
        void InsertarEnArbol(NodoABB * &, Camionero *);
        Camionero * ObtenerEnArbol(NodoABB *,long);
        void cargarIterador(NodoABB *, Iterador &);
        void CamioneroMayorCantTatuajes(NodoABB *, Camionero * &);

    public:
        Camioneros();
        bool Member(long);
        ///indica si el camionero con la CI ingresada es miembro
        void Insert(Camionero *);
        ///inserta el puntero del nuevo camionero
        ///precondici�n: el camionero no es miembro de la colecci�n
        bool Empty();
        Camionero * Find(long);
        ///retorna el puntero al camionero cuya CI es ingresada
        ///precondici�n: el camionero es miembro de la colecci�n
        Iterador listarCamioneros();
        Camionero * CamioneroMaxTatuajes();
        ~Camioneros();
};

#endif // CAMIONEROS_H_INCLUDED
