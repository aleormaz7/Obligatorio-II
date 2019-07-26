#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


#include "String.h"

const int CANT_CIUDADES = 4;/*cantidad ciudades*/

typedef int Grafo[CANT_CIUDADES][CANT_CIUDADES];


///Crea el Grafo(Matriz) vacio
void CrearGrafo(Grafo &G);

///Retorna si existe la arista, en este contexto retorna si existe un tramo entre las ciudades
boolean ExisteTramo(Grafo G, int codigoCiudad1, int codigoCiudad2);

///(InsertarTramo) = Inserta la nueva arista al grafo. En este contexto se inserta un nuevo tramo entre dos ciudades.
void InsertarArista(Grafo &G, int codigoCiuadad1, int codigoCiuadad2);
///Precondición: la arista no pertenece al grafo. -> !ExisteTramo

/// Retorna si existe alguna secuencia de tramos entre dos ciudades; si existe un camino entre dos vertices
boolean ExisteSecuenciaDeTramoEntreDosCiudades(Grafo G, int codigoCiudad, int codigoCiudad2);

/// Ejecuta DFS para saber si existe un camino entre dos vertices(ciudades)
void DFS(Grafo G, int verticeActual, int destino, boolean visitado[CANT_CIUDADES]);

/// Retorna TRUE si existe al menos una atista en el grafo.
/// en este contexto quiere decir que existe al menos un tramo definido
boolean ExiteAlMenosUnTramo(Grafo g);

#endif // GRAFO_H_INCLUDED
