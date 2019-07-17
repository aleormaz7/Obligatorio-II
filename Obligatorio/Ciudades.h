#ifndef CIUDADES_H_INCLUDED
#define CIUDADES_H_INCLUDED

#include "Ciudad.h"

const int B = 5;/*cant cubetas*/

typedef struct nodoL {  Ciudad info;
                        nodoL * sig;
                     } Nodo;

typedef Nodo * ListaCiudades;

typedef ListaCiudades Ciudades[B];


void MakeCiudades(Ciudades &C);

boolean Member(Ciudades C,int clave); ///Determina si en el diccionario existe un elemento con la clave especificada

void Insert(Ciudades &C, Ciudad ciu);///Agrega la ciudad en el hash

Ciudad Find(Ciudades C,String nomCiudad); ///Precondición: el elemento es miembro del diccionario.

///1. Registrar los nombres de todas las ciudades que visita la empresa. Esta operación se ejecutará solamente una vez.
void AltaCiudad(String nombre);


/**/
/*Auxiliares lista*/
void CrearLista(ListaCiudades &L);

boolean PerteneceLista(ListaCiudades L,String valor);

void Insfront(ListaCiudades &L,Ciudad ciudad);

Ciudad ObtenerEnLista(ListaCiudades L, int coidgoCiudad);/*clave=numero sorteo asistente otorgado*/




#endif // CIUDADES_H_INCLUDED
