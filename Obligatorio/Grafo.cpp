#include "Grafo.h"

void Crear(Grafo &G)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
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
   G[numeroCiudad2][numeroCiudad1] = 1;
}

boolean ExisteTramoEntreDosCiudades(Grafo G, String nom1, String nom2)///
{
    ///hacer funcion convertir nombre ciudad a string

    ///Lamar a DFS()

    return TRUE;
}

void DFS(Grafo G, int verticeActual, boolean visitado[N])
{

}


///---------------------------------**
///solo para pruebas despues se borran
void MostrarGrafo(Grafo G)
{
     for(int i = 0; i < N; i++)
     {
        for(int j = 0; j < N; j++)
        {
            printf("|%d",G[i][j]);
        }
        printf("\n");
     }
}
///---------------------------------**


