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
        ///función de dispersión
        void crearLista (Nodo * &);
        ///crea una lista vacía
        void destruirLista (Nodo * &);
        ///destruye todo el contenido de la lista
        bool perteneceLista (Nodo *, String);
        ///indica si existe una mascota con el número ingresado
        void insFrontEnLista (Nodo * &, Camion *);
        ///inserta la mascota al principio de la lista
        Camion * obtenerEnLista (Nodo *, String);
        ///obtiene la mascota con el número ingresado

    public:
        Camiones();
        ///constructor por defecto
        ~ Camiones();
        ///destructor
        bool Member(String);
        ///indica si la mascota con el número ingresado es miembro de
        ///a colección
        void Insert(Camion *);
        ///inserta la nueva mascota a la colección
        ///recondición: la mascota no es miembro de la colección
        Camion * Find(String);
        ///retorna la mascota cuyo número es el ingresado
        ///precondición: la mascota es miembro de la colección



};



#endif // CAMIONES_H_INCLUDED
