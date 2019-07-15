#include "Pruebas.h"



void PruebasGrafo()
{
    Grafo G;
    Crear(G);

    /*String ciudad1,ciudad2,ciudad3,ciudad4;
    strcrear(ciudad1);
    strcrear(ciudad2);
    strcrear(ciudad3);
    strcrear(ciudad4);

    for(int i = 0; i < N; i++)
    {

    }*/

    InsertarArista(G,0,1); //O-----1
    InsertarArista(G,1,3); //|     |
    InsertarArista(G,2,3); //|     |
    InsertarArista(G,0,2); //2-----3

    MostrarGrafo(G);

    printf("\nArrayBoolenesInit");
    ArrayBooleanos arreBoleanos;
    CargarArrayBooleanosEnFalse(arreBoleanos);
    MostrarArrayBooleanos(arreBoleanos);

    printf("\nDFS:");
    DFS(G,0,arreBoleanos);
    MostrarArrayBooleanos(arreBoleanos);


}












