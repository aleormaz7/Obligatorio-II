#include "Grafo.h"

void CrearGrafo(Grafo &G)
{
    for(int i = 0; i < CANT_CIUDADES; i++)
        for(int j = 0; j < CANT_CIUDADES; j++)
            G[i][j] = 0;
}

boolean PerteneceArista(Grafo G, int numeroCiudad1, int numeroCiudad2)
{
    boolean pertenece = FALSE;
    if(G[numeroCiudad1][numeroCiudad2] == 1)
        pertenece = TRUE;

    return pertenece;
}

void InsertarArista(Grafo &G, int numeroCiudad1, int numeroCiudad2)
{
    G[numeroCiudad1][numeroCiudad2] = 1;
    if(numeroCiudad1 != numeroCiudad2)
        G[numeroCiudad2][numeroCiudad1] = 1;
}

boolean ExisteTramoEntreDosCiudades(Grafo G, String nom1, String nom2)
{


    //DarNumero de String nom1
    //DarNumero de String nom2
    //DFS(G,) desde nom1
    //if DFS llego a nom2 hay tramo sino no existe

    return TRUE;
}

void DFS(Grafo G, int verticeActual, boolean visitado[CANT_CIUDADES])
{
    visitado[verticeActual] = TRUE;
    for (int j = 0; j < CANT_CIUDADES; j++)
    {
        if (G[verticeActual][j] == 1)
        {
            if (!visitado[j])
                DFS(G,j,visitado);
        }
    }
}


///---------------------------------**
///solo para pruebas despues se borran
void MostrarGrafo(Grafo G)
{
     for(int i = 0; i < CANT_CIUDADES; i++)
     {
        for(int j = 0; j < CANT_CIUDADES; j++)
        {
            printf("|%d",G[i][j]);
        }
        printf("\n");
     }
}
///---------------------------------**


