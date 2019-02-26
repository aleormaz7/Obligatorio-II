#include "Pruebas.h"

void pruebaStringAlfanumerico()
{

    ///Pruebas Strinf alfanumerico
    String s;
    strcrear(s);
    printf("\nIngrese String: ");
    scan(s);
    printf("\nString cargado: ");
    print(s);

    if(esAlfanumerico(s))
        printf("\n El String es alfanumerico");
    else
        printf("\n El String NOOOO es alfanumerico");

}

void pruebaDarExtencion()
{
     ///Pruebas dar extencion
    String s,extencion;
    strcrear(s);
    strcrear(extencion);
    printf("\nIngrese String: ");
    scan(s);
    printf("\nString cargado: ");
    print(s);
    retornaExtension(s,extencion);
    printf("\nExtencion: ");
    print(extencion);

}

void pruebaControlPunto()
{
     ///Pruebas controlar que tenga solo un punto
    String s;
    strcrear(s);
    printf("\nIngrese String: ");
    scan(s);
    printf("\nString cargado: ");
    print(s);

    printf("\nEl String tiene %d puntos",cntPuntos(s));

}


void pruebaListaStrings()
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
    ListaTerminos LtA,LtB,ListaResultado;
    listaTerminosCrear(LtA);
    listaTerminosCrear(LtB);
    listaTerminosCrear(ListaResultado);

    Termino tA1,tA2,tA3,tB1,tB2,tB3;
    tA1.coef  = 3;
    tA1.grado = 6;
    listaTerminosInsertarOrdenado(LtA,tA1);

    tA2.coef  = 2;
    tA2.grado = 2;
    listaTerminosInsertarOrdenado(LtA,tA2);

    tA2.coef  = -4;
    tA2.grado = 1;
    listaTerminosInsertarOrdenado(LtA,tA2);

    tA3.coef  = 3;
    tA3.grado = 0;
    listaTerminosInsertarOrdenado(LtA,tA3);

    tB1.coef  = 3;
    tB1.grado = 2;
    listaTerminosInsertarOrdenado(LtB,tB1);

    tB2.coef  = 1;
    tB2.grado = 1;
    listaTerminosInsertarOrdenado(LtB,tB2);

    tB3.coef  = 1;
    tB3.grado = 0;
    listaTerminosInsertarOrdenado(LtB,tB3);


    sumarPolinomios(LtA,LtB,ListaResultado);
    listaTerminosMostrar(ListaResultado);
}


void pruebasSumarPolinomiosMain()
{
    String s;
    ListaString ls;
    strcrear(s);
    CrearListaString(ls);
    printf("\nIngrese comando: ");
    scan(s);
    partirString(s,ls);


}


void pruebasEvaluarPolinomio()
{
    ListaTerminos lista;
    listaTerminosCrear(lista);
    int valor;

    Termino tA1,tA2,tA3,tB1,tB2,tB3;

    tA1.coef  = 3;
    tA1.grado = 6;
    listaTerminosInsertarOrdenado(lista,tA1);

    tA2.coef  = 2;
    tA2.grado = 2;
    listaTerminosInsertarOrdenado(lista,tA2);

    tA2.coef  = -4;
    tA2.grado = 1;
    listaTerminosInsertarOrdenado(lista,tA2);

    tA3.coef  = 3;
    tA3.grado = 0;
    listaTerminosInsertarOrdenado(lista,tA3);

    printf("Valor a evaluar: ");
    scanf("%d",&valor);
    printf("\nResultado de la evaluacion:  %li",evaluarPolinomio(lista,valor));

}


void pruebasEsRaiz()
{
    ListaTerminos lista;
    listaTerminosCrear(lista);
    int valor;

    Termino tA1,tA2,tA3,tB1,tB2,tB3;

    tA1.coef  = 1;
    tA1.grado = 2;
    listaTerminosInsertarOrdenado(lista,tA1);

    tA2.coef  = -1;
    tA2.grado = 0;
    listaTerminosInsertarOrdenado(lista,tA2);

    printf("Valor a evaluar: ");
    scanf("%d",&valor);

    if(esRaiz(lista,valor))
        printf("\nEs Raiz");
    else
        printf("\nNOO Es Raiz");

}

void pruebasMultiplicarPolinomio()
{
    ListaTerminos LtA,LtB,ListaResultado;
    listaTerminosCrear(LtA);
    listaTerminosCrear(LtB);
    listaTerminosCrear(ListaResultado);

    Termino tA1,tA2,tA3,tB1,tB2,tB3;
    tA1.coef  = 1;
    tA1.grado = 2;
    listaTerminosInsertarOrdenado(LtA,tA1);

    tA2.coef  = 1;
    tA2.grado = 0;
    listaTerminosInsertarOrdenado(LtA,tA2);
/*
    tA3.coef  = 16;
    tA3.grado = 0;
    listaTerminosInsertarOrdenado(LtA,tA3);
*/
    tB1.coef  = 1;
    tB1.grado = 2;
    listaTerminosInsertarOrdenado(LtB,tB1);

    tB2.coef  = 1;
    tB2.grado = 0;
    listaTerminosInsertarOrdenado(LtB,tB2);
/*
    tB3.coef  = 2;
    tB3.grado = 0;
    listaTerminosInsertarOrdenado(LtB,tB3);
*/

    multiplicarPolinomios(LtA,LtB,ListaResultado);
    listaTerminosMostrar(ListaResultado);
}

void pruebasReducirPolinomio()
{
    ListaTerminos LtA,ListaResultado;
    listaTerminosCrear(LtA);
    listaTerminosCrear(ListaResultado);

    Termino tA1,tA2,tA3,tA4,tA5,tA6;
    tA1.coef  = 32;
    tA1.grado = 4;
    listaTerminosInsertarOrdenado(LtA,tA1);

    tA2.coef  = 11;
    tA2.grado = 1;
    listaTerminosInsertarOrdenado(LtA,tA2);

    tA3.coef  = 8;
    tA3.grado = 0;
    listaTerminosInsertarOrdenado(LtA,tA3);

    tA4.coef  = -12;
    tA4.grado = 4;
    listaTerminosInsertarOrdenado(LtA,tA4);

    tA5.coef  = 1;
    tA5.grado = 1;
    listaTerminosInsertarOrdenado(LtA,tA5);

    tA6.coef  = 8;
    tA6.grado = 0;
    listaTerminosInsertarOrdenado(LtA,tA6);

    reduceListaTerminos(LtA,ListaResultado);
    listaTerminosMostrar(ListaResultado);
}

void pruebasControlTerminoIndependienteNoNulo()
{
    ListaTerminos LtA;
    listaTerminosCrear(LtA);

    Termino tA1,tA2,tA3,tA4,tA5,tA6;
    tA1.coef  = 32;
    tA1.grado = 4;
    listaTerminosInsertarOrdenado(LtA,tA1);

    tA2.coef  = 11;
    tA2.grado = 1;
    listaTerminosInsertarOrdenado(LtA,tA2);

    tA3.coef  = 0;
    tA3.grado = 0;
    listaTerminosInsertarOrdenado(LtA,tA3);

    controlTerminoIndependienteNoNulo(LtA);
    listaTerminosMostrar(LtA);
}
void pruebasModuloTermino()
{
    ///MODULO TERMINO:
    //Termino t1,t2,t3;

    //CrearTermino(t1,1,3);
    //CrearTermino(t2,2,2);

    /*
    printf("\n Termino1: ");
    MostrarTermino(t1);
    printf("\ncoef: %ld",DarCoefTermino(t1));
    printf("\ngrado: %d",DarGradoTermino(t1));
    */

    /*
    printf("\n Termino2: ");
    MostrarTermino(t2);
    printf("\ncoef: %ld",DarCoefTermino(t2));
    printf("\ngrado: %d",DarGradoTermino(t2));
    */

    //String nomArch;

    ///Bajar Termino 1
    //Crear Archivo
    //printf("\nNombre Archivo: ");
    //strcrear(nomArch);
    //fflush(stdin);
    //scan(nomArch);
    //FILE * f = fopen("termino2.txt","wb");

    ///Bajar Termino
    //BajarTermino(t1,f);
    //fclose(f);

    //BajarTermino(t2,f);

    ///Levantar termino
    /*
    f = fopen("termino2.txt","rb");
    printf("\n Levantar Termino: ");
    LevantarTermino(t3,f);
    MostrarTermino(t3);
    fclose(f);
    */
}

void pruebasModuloArchivo()
{
    ///MODULO ARCHIVO:
    /*if(ExisteArchivo("termino.txt"))
        printf("| Existe");
    else
        printf("| No Existe");

    if(ArchivoEsVacio("termino.txt"))
        printf("| Es vacio");
    else
        printf("| No es vacio");

    if(EnteroPertenecArchivo("termino.txt",1))
        printf("| Pertenece");
    else
        printf("| No Pertenece");
    */
}

void pruebasModuloPolinomio()
{
    Polinomio p;
    String lineaComando;
    ListaString listaS;
    ListaTerminos lt;

    strcrear(lineaComando);

    strcrear(lineaComando);
    printf("\ningrese toda la linea del comando con sus parametros: ");
    scan(lineaComando);


    CrearListaString(listaS);

    ///Partir el String en una lista de strings
    partirString(lineaComando,listaS);
    listaTerminosCrear(p.listaTerminos);

    crearPolinomio(p,listaS);
    printf("\n Polinomio: ");
    mostrarPolinomio(p);

    printf("\nPruebaDarLista");
    darListaTerminosPolinomio(p,lt);
    listaTerminosMostrar(lt);

}

void PruebasABBPolinomio()
{
    ABBPolinomio a;
    ABBPolinomioCrear(a);

    Polinomio p;

    String lineaComando;
    ListaString listaS;

    CrearListaString(listaS);

    strcrear(lineaComando);

    strcrear(lineaComando);
    printf("\ningrese toda la linea del comando con sus parametros: ");
    scan(lineaComando);


    ///Partir el String en una lista de strings
    partirString(lineaComando,listaS);
    listaTerminosCrear(p.listaTerminos);


    crearPolinomio(p,listaS);

    ABBPolinomioInsertar(a,p);

    if(ABBPolinomioExiste(a,"pepe"))
        printf("existe");
    else
        printf("no existe");



    if(ABBPolinomioEsVacio(a))
        printf("es vacio");
    else
        printf("No es vacio");

    printf("\nMostrar Polinomio");
    mostrarPolinomio(darPolinomio(a,"pepe"));

    ABBPolinomioEliminar(a);

    if(ABBPolinomioExiste(a,"pepe"))
        printf("existe");
    else
        printf("no existe");



}

void pruebasListaTermino()
{
    Termino t1,t2,t3;

    CrearTermino(t1,3,2);
    CrearTermino(t2,2,1);
    CrearTermino(t3,1,0);

    ListaTerminos listaT;
    listaTerminosCrear(listaT);


    InsBackListaTermino(listaT,t1);
    InsBackListaTermino(listaT,t2);
    InsBackListaTermino(listaT,t3);


    bajarListaTerminos(listaT,"listaTerminos.txt");


    levantarListaTerminos(listaT,"listaTerminos.txt");


    listaTerminosMostrar(listaT);

}

void pruebasPasoMinusculas()
{
    String s;
    strcrear(s);
    scan(s);
    llevoAMinusculas(s);
    print(s);
}

