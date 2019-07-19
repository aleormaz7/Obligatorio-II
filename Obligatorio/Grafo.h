#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


#include "String.h"

const int CANT_CIUDADES = 4;/*cantidad ciudades*/

typedef int Grafo[CANT_CIUDADES][CANT_CIUDADES];/* Statico */


void CrearGrafo(Grafo &G);///Crear Grafo(Matriz) vacio

///2. Dados los nombres de dos ciudades, agregar un nuevo tramo entre ellas. Dicho tramo
///   podrá luego ser incluido en alguna de las líneas que la empresa posee.
boolean PerteneceArista(Grafo G, int codigoCiudad1, int codigoCiudad2);///ExisteTramo()

///(InsertarTramo) = Inserta la nueva arista al grafo.//Precondición: la arista no pertenece al grafo.
void InsertarArista(Grafo &G, int codigoCiuadad1, int codigoCiuadad2);

///3. Dados los nombres de dos ciudades, saber si existe alguna secuencia de tramos que las
///   una. Esta operación le servirá a la directiva de la empresa a la hora de idear recorridos para nuevas líneas.
boolean ExisteSecuenciaDeTramoEntreDosCiudades(Grafo G, int codigoCiudad, int codigoCiudad2);

void DFS(Grafo G, int verticeActual, int destino, boolean visitado[CANT_CIUDADES]);


///---------------------------------**
///solo para pruebas despues se borran
void MostrarGrafo(Grafo G);

boolean ExiteAlMenosUnTramo(Grafo g);

///---------------------------------**
#endif // GRAFO_H_INCLUDED
