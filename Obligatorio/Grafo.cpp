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

/*
void DFS(Grafo G, int verticeActual, boolean visitado[CANT_CIUDADES])
{
    //boolean encontre = FALSE;
    visitado[verticeActual] = TRUE;
    //int i = 0;
    //while(i < CANT_CIUDADES && !encontre)
    for(int j = 0; j < CANT_CIUDADES; j++)
    {
        if (G[verticeActual][j] == 1)
        {
            if (!visitado[j])
                DFS(G,j,visitado);
        }
    }
}
*/

void DFS(Grafo G, int verticeActual, int v, boolean visitado[CANT_CIUDADES])
{
    visitado[verticeActual] = TRUE;
    int i = 0;
    while(i < CANT_CIUDADES && !visitado[v])
    {
        if (G[verticeActual][i] == 1)
        {
            if (!visitado[i])
                DFS(G,i,v,visitado);
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


