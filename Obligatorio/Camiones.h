#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED

#include "Camion.h"
#include "CamionSimple.h"
#include "CamionGrande.h"
#include "CamionConRemolque.h"

const int B = 100;

class Camiones
{
    private:
        struct Nodo
        {
            Camion * info;
            Nodo * sig;
        };
        Nodo * Hash[B];

        int dispersion(String);
        ///funci�n de dispersi�n
        void crearLista (Nodo * &);
        ///crea una lista vac�a
        void destruirLista (Nodo * &);
        ///destruye todo el contenido de la lista
        bool perteneceLista (Nodo *, String);
        ///indica si existe una mascota con el n�mero ingresado
        void insFrontEnLista (Nodo * &, Camion *);
        ///inserta la mascota al principio de la lista
        Camion * obtenerEnLista (Nodo *, String);
        ///obtiene la mascota con el n�mero ingresado

    public:
        Camiones();
        ///constructor por defecto
        ~ Camiones();
        ///destructor
        bool Member(String);
        ///indica si la mascota con el n�mero ingresado es miembro de
        ///a colecci�n
        void Insert(Camion *);
        ///inserta la nueva mascota a la colecci�n
        ///recondici�n: la mascota no es miembro de la colecci�n
        Camion * Find(String);
        ///retorna la mascota cuyo n�mero es el ingresado
        ///precondici�n: la mascota es miembro de la colecci�n



};



#endif // CAMIONES_H_INCLUDED
