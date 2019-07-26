#include "Grafo.h"

void CrearGrafo(Grafo &G)
{
    for(int i = 0; i < CANT_CIUDADES; i++)
        for(int j = 0; j < CANT_CIUDADES; j++)
            G[i][j] = 0;
}

boolean ExisteTramo(Grafo G, int numeroCiudad1, int numeroCiudad2)
{
    boolean pertenece = FALSE;
    if(G[numeroCiudad1][numeroCiudad2] == 1)
        pertenece = TRUE;

    return pertenece;
}

void InsertarArista(Grafo &G, int numeroCiudad1, int numeroCiudad2)//agregar Tramo
{
    G[numeroCiudad1][numeroCiudad2] = 1;
    if(numeroCiudad1 != numeroCiudad2)
        G[numeroCiudad2][numeroCiudad1] = 1;
}

boolean ExisteSecuenciaDeTramoEntreDosCiudades(Grafo G, int codigoCiudad, int codigoCiudad2)
{
    boolean visitado[CANT_CIUDADES];
    for(int i=0; i < CANT_CIUDADES; i++)
    {
        visitado[i] = FALSE;
    }

    DFS(G,codigoCiudad,codigoCiudad2,visitado);

    return visitado[codigoCiudad2];
}

void DFS(Grafo G, int verticeActual, int destino, boolean visitado[CANT_CIUDADES])
{
    visitado[verticeActual] = TRUE;
    int i = 0;
    while(i < CANT_CIUDADES && !visitado[destino])
    {
        if (G[verticeActual][i] == 1)
        {
            if (!visitado[i])
                DFS(G,i,destino,visitado);
        }
        i++;
    }
}

boolean ExiteAlMenosUnTramo(Grafo g)
{
    boolean hay = FALSE;
    int i = 0;
    while(i < CANT_CIUDADES && !hay)
    {
        int j = 0;
        while(j< CANT_CIUDADES && !hay)
        {
            if(g[i][j] == 1)
                hay = TRUE;
            else
                j++;
        }
        i++;
    }
    return hay;
}
