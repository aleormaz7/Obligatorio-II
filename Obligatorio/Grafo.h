#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


#include "String.h"

const int N = 4;/*cantidad ciudades*/

typedef String Grafo[N][N];/* Statico */


void Crear(Grafo &G);///Crear Grafo(Matriz) vacio

///2. Dados los nombres de dos ciudades, agregar un nuevo tramo entre ellas. Dicho tramo
///   podr� luego ser incluido en alguna de las l�neas que la empresa posee.
boolean PerteneceArista(Grafo G, int codigoCiudad1, int codigoCiudad2);

///Inserta el nuevo v�rtice al grafo.//Precondici�n: el v�rtice no pertenece al grafo.
void InsertarVertice(Grafo &G,int coidgoCiudad);

///Inserta la nueva arista al grafo.//Precondici�n: la arista no pertenece al grafo.
void InsertarArista(Grafo &G, int codigoCiuadad1, int codigoCiuadad2);

///3. Dados los nombres de dos ciudades, saber si existe alguna secuencia de tramos que las
///   una. Esta operaci�n le servir� a la directiva de la empresa a la hora de idear recorridos para nuevas l�neas.
boolean ExisteTramoEntreDosCiudades(Grafo G, String nom1, String nom2);

void DFS(Grafo G, int verticeActual, boolean visitado[N]);


#endif // GRAFO_H_INCLUDED
