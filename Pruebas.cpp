#include "Pruebas.h"


void pruebaListaStrings ()
{
    ListaString Ls;
    CrearListaString(Ls);
    String s;
    strcrear(s);
    int pos;
    long int intString;

    printf("\nIngrese String: ");
    scan(s);
    printf("\nString cargado: ");
    print(s);

    intString = convertirStringAEntero(s);

    printf("\nString convertido es....: %li",intString);

    partirString(s,Ls);
    printf("\nLargo de lista es: %d ", LargoListaString(Ls));
    printf("\n");
    MostrarListaString(Ls);

    if(CoeficientesEnteros(Ls))
        printf("\nTodos numericos");
    else
        printf("\nNO son Todos numericos");


    printf("\nPosicion:");
    scanf("%d",&pos);
    obtenerString(Ls,pos,s);
    printf("\nEl String el la posicion: %d es: ",pos);
    print(s);

    destruirListaString(Ls);
}

void pruebasSumarPolinomios()
{
    ListaTerminos LtA,LtB;
    listaTerminosCrear(LtA);
    listaTerminosCrear(LtB);

    Termino tA1,tA2,tA3,tB1,tB2,tB3;
    tA1.coef  = 5;
    tA1.grado = 3;
    listaTerminosInsertarOrdenado(LtA,tA1);

    tA2.coef  = -2;
    tA2.grado = 1;
    listaTerminosInsertarOrdenado(LtA,tA2);

    tA3.coef  = 10;
    tA3.grado = 0;
    listaTerminosInsertarOrdenado(LtA,tA3);

    tB1.coef  = 15;
    tB1.grado = 3;
    listaTerminosInsertarOrdenado(LtB,tB1);

    tB2.coef  = 4;
    tB2.grado = 1;
    listaTerminosInsertarOrdenado(LtB,tB2);

    tB3.coef  = -2;
    tB3.grado = 0;
    listaTerminosInsertarOrdenado(LtB,tB3);

}
