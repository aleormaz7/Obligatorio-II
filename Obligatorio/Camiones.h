#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED

#include "Iterador.h"
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
        ///indica si existe un camion con la matricula ingresada
        void insFrontEnLista (Nodo * &, Camion *);
        ///inserta el puntero al camion, al principio de la lista
        Camion * obtenerEnLista (Nodo *, String);
        ///obtiene el puntero del camion con la matricula ingresada
        void cargarIterador(Iterador &);

    public:
        Camiones();
        ///constructor por defecto
        ~ Camiones();
        ///destructor
        bool Member(String);
        ///indica si el camion con el número de matricula ingresado es miembro
        void Insert(Camion *);
        ///inserta el puntero del nuevo camion
        ///precondición: el camion no es miembro de la colección
        Camion * Find(String);
        ///retorna el puntero al camion cuya matricula es ingresada
        ///precondición: el camion es miembro de la colección

        Iterador listarCamiones();

        float totalMetrosCubicosAnuales();

        void CantidadCamionesPorTipo(int &cantSimple,int &cantGrande,int &cantRemolque);

        void CantidadCamionesGrandesFechaAdquisicion(int &cant,Fecha &f);
};
#endif // CAMIONES_H_INCLUDED
