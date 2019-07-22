#ifndef CIUDADES_H_INCLUDED
#define CIUDADES_H_INCLUDED

#include "Ciudad.h"

const int B = 4;/*cant cubetas*/

typedef struct nodoL {  Ciudad info;
                        nodoL * sig;
                     } NodoCiudades;

typedef NodoCiudades * ListaCiudades;

typedef ListaCiudades Ciudades[B];


void MakeCiudades(Ciudades &C);

boolean Member(Ciudades C, String nombreCiudad); ///Determina si en el diccionario existe un elemento con la clave especificada

void Insert(Ciudades &C, Ciudad ciu);///Agrega la ciudad en el hash

Ciudad FindCiudad(Ciudades C, String nomCiudad); ///Precondición: el elemento es miembro del diccionario.



/**/
/*Auxiliares lista*/
void CrearLista(ListaCiudades &L);

boolean PerteneceLista(ListaCiudades L,String valor);

void Insfront(ListaCiudades &L,Ciudad ciudad);

Ciudad ObtenerEnLista(ListaCiudades L, String nombreCiudad);/*clave=numero sorteo asistente otorgado*/

void MostrarLista(ListaCiudades L);

///solo prueba
//void MostrarHash(Ciudades C);


#endif // CIUDADES_H_INCLUDED
