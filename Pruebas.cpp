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

    ///SI el 1º String es “crear”
    if(streq(listaS->info,"crear"))
    {
        ///SI luego del 1º String No hay Por lo menos 2 strings más(3)(osea si hay 2 o menos)
        if(LargoListaString(listaS) <= 2)
        {
            printf("\nError: cantidad de parámetros incorrecta, debe indicar nombre de Polinomio y Por lo menos un coeficiente");
        }
        ///SINO
        else
        {
            ///avanzar en listaS a 2do string
            listaS = listaS->Sig;

            ///SI el 2º String no representa sólo caracteres alfanuméricos
            if(!esAlfanumerico(listaS->info))
            {
                printf("\nError: el nombre de Polinomio debe ser alfanumérico");
            }
            else///SINO
            {

                ///ya que nombre es alfanumerico, copio nombre de polinomio en variable aux para tenerlo por separado
                strcrear(p.nombre);
                strcop(p.nombre,listaS->info);


                //if(ABBPolinomioExiste(a,listaS))
                //{
                //    printf("Error: Ya existe un polinomio con el nombre ingresado");
                //}
                //else
                //{
                    ///avanzar en listaS a 3er string
                    listaS = listaS->Sig;

                    ///SI a partir del 3º String no son todos numéricos (*1C*)
                    int largo = LargoListaString(listaS) + 2;///mas 2 de los dos que me movi

                    ///TODO: revisar aca xq esta funcion empieza en 2 y yo ya estoy parado en 2, entonces aca empezaria en 4 ??
                    if(!CoeficientesEnteros(listaS))
                    {
                        printf("\nError: los coeficientes deben ser numéricos.");
                    }
                    else
                    {
                        //printf("\nSon coef numericos");
                        crearPolinomio(p,listaS);
                    }
                //}
            }
        }
    }

    printf("\n Polinomio: ");


    if(p.listaTerminos == NULL)
    {
        p.listaTerminos->info.coef = 0;
        p.listaTerminos->info.grado = 0;
        printf("Polinomio es nulo");
    }

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

void mainSumarPolinomios()
{
    ///Creo los polinomios a Sumar
    Polinomio PoliA,PoliB;
    ListaTerminos LtA,LtB,ListaResultado;
    listaTerminosCrear(LtA);
    listaTerminosCrear(LtB);
    listaTerminosCrear(ListaResultado);
    ABBPolinomio abb;
    ABBPolinomioCrear(abb);

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

    PoliA.nombre = "pepe";
    PoliA.listaTerminos = LtA;
    ABBPolinomioInsertar(abb,PoliA);

    tB1.coef  = 3;
    tB1.grado = 2;
    listaTerminosInsertarOrdenado(LtB,tB1);

    tB2.coef  = 1;
    tB2.grado = 1;
    listaTerminosInsertarOrdenado(LtB,tB2);

    tB3.coef  = 1;
    tB3.grado = 0;
    listaTerminosInsertarOrdenado(LtB,tB3);

    PoliB.nombre = "lolo";
    PoliB.listaTerminos = LtB;
    ABBPolinomioInsertar(abb,PoliB);

/////////////
    String s;
    ListaString ls;


    do
    {
        strcrear(s);
        CrearListaString(ls);

        printf("\nIngrese comando: ");
        scan(s);
        partirString(s,ls);

        if(streq("sumar",ls->info))
        {
            if(LargoListaString(ls) == 4)
            {
                if(esAlfanumerico(ls->Sig->info)) ///Nombre del Poli resultante
                {
                    if(!ABBPolinomioExiste(abb,ls->Sig->info)) ///Si existe un Poli con en nombre del resultante
                    {
                        if(esAlfanumerico(ls->Sig->Sig->info)) ///Nombre del primer Poli
                        {
                            if(esAlfanumerico(ls->Sig->Sig->Sig->info)) ///Nombre del segundo Poli
                            {
                                if(ABBPolinomioExiste(abb,ls->Sig->Sig->info))
                                {
                                    if(ABBPolinomioExiste(abb,ls->Sig->Sig->Sig->info))
                                     {
                                            ListaTerminos LstResultado,LstPoliA,LstPoliB;
                                            listaTerminosCrear(LstResultado);
                                            listaTerminosCrear(LstPoliA);
                                            listaTerminosCrear(LstPoliB);

                                            Polinomio PoliA = darPolinomio(abb,ls->Sig->Sig->info);
                                            Polinomio PoliB = darPolinomio(abb,ls->Sig->Sig->Sig->info);
                                            Polinomio PoliResultante;

                                            darListaTerminosPolinomio(PoliA,LstPoliA);
                                            darListaTerminosPolinomio(PoliB,LstPoliB);

                                            sumarPolinomios(LstPoliA,LstPoliB,LstResultado);
                                            crearPolinomioResultante(PoliResultante,ls->Sig->info,LstResultado);
                                            ABBPolinomioInsertar(abb,PoliResultante);
                                            listaTerminosMostrar(LstResultado);
                                            mostrarPolinomio(PoliResultante);
                                     }
                                     else
                                     {
                                        printf("\nError: el segundo Polinomio a sumar, indicado con el nombre ");
                                        print(ls->Sig->Sig->Sig->info);
                                        printf("\nno existe en memoria.");
                                     }
                                }
                                else
                                {
                                    printf("\nError: el primer Polinomio a sumar, indicado con el nombre ");
                                    print(ls->Sig->Sig->info);
                                    printf("\nno existe en memoria.");
                                }
                            }
                            else
                            {
                                printf("\nError: el nombre ingresado para el segundo Polinomio a sumar - ");
                                print(ls->Sig->Sig->Sig->info);
                                printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                            }
                        }
                        else
                        {
                            printf("\nError: el nombre ingresado para el primer Polinomio a sumar- ");
                            print(ls->Sig->Sig->info);
                            printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                        }
                    }
                    else
                    {
                        printf("\nError: en el sistema ya existe un Polinomio con el nombre ingresado para indeficiar al resulatante, nombre ingresado: ");
                        print(ls->Sig->info);
                    }
                }
                else
                {
                   printf("\nError: el nombre ingresado para identificar al Polinimio resultante - ");
                   print(ls->Sig->info);
                   printf(" - , no es un alfanumerico.");
                }
            }
            else
                printf("\nError: la cantidad de parametros no es correcta para el comando,\n se esperan 3 parametros y fueron ingresados %d",LargoListaString(ls)- 1);
        }
        else
        {
            printf("\nError: no se reconoce el comando: ");
            print(ls->info);
        }
    }while(!streq("salir",ls->info));
}

void mainMultiplicarPolinomios()
{
    ///Creo los polinomios a Multiplicar
    Polinomio PoliA,PoliB;
    ListaTerminos LtA,LtB,ListaResultado;
    listaTerminosCrear(LtA);
    listaTerminosCrear(LtB);
    listaTerminosCrear(ListaResultado);
    ABBPolinomio abb;
    ABBPolinomioCrear(abb);

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

    PoliA.nombre = "pepe";
    PoliA.listaTerminos = LtA;
    ABBPolinomioInsertar(abb,PoliA);

    tB1.coef  = 3;
    tB1.grado = 2;
    listaTerminosInsertarOrdenado(LtB,tB1);

    tB2.coef  = 1;
    tB2.grado = 1;
    listaTerminosInsertarOrdenado(LtB,tB2);

    tB3.coef  = 1;
    tB3.grado = 0;
    listaTerminosInsertarOrdenado(LtB,tB3);

    PoliB.nombre = "lolo";
    PoliB.listaTerminos = LtB;
    ABBPolinomioInsertar(abb,PoliB);

/////////////
    String s;
    ListaString ls;


    do
    {
        strcrear(s);
        CrearListaString(ls);

        printf("\nIngrese comando: ");
        scan(s);
        partirString(s,ls);

        if(streq("multiplicar",ls->info))
        {
            if(LargoListaString(ls) == 4)
            {
                if(esAlfanumerico(ls->Sig->info)) ///Nombre del Poli resultante
                {
                    if(!ABBPolinomioExiste(abb,ls->Sig->info)) ///Si existe un Poli con en nombre del resultante
                    {
                        if(esAlfanumerico(ls->Sig->Sig->info)) ///Nombre del primer Poli
                        {
                            if(esAlfanumerico(ls->Sig->Sig->Sig->info)) ///Nombre del segundo Poli
                            {
                                if(ABBPolinomioExiste(abb,ls->Sig->Sig->info))
                                {
                                    if(ABBPolinomioExiste(abb,ls->Sig->Sig->Sig->info))
                                     {
                                             printf("\nTodo en orden......");
                                     }
                                     else
                                     {
                                        printf("\nError: el segundo Polinomio a multiplicar, indicado con el nombre ");
                                        print(ls->Sig->Sig->Sig->info);
                                        printf("\nno existe en memoria.");
                                     }
                                }
                                else
                                {
                                    printf("\nError: el primer Polinomio a multiplicar, indicado con el nombre ");
                                    print(ls->Sig->Sig->info);
                                    printf("\nno existe en memoria.");
                                }
                            }
                            else
                            {
                                printf("\nError: el nombre ingresado para el segundo Polinomio a multiplicar - ");
                                print(ls->Sig->Sig->Sig->info);
                                printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                            }
                        }
                        else
                        {
                            printf("\nError: el nombre ingresado para el primer Polinomio a multiplicar- ");
                            print(ls->Sig->Sig->info);
                            printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                        }
                    }
                    else
                    {
                        printf("\nError: en el sistema ya existe un Polinomio con el nombre ingresado para indeficiar al resulatante, nombre ingresado: ");
                        print(ls->Sig->info);
                    }
                }
                else
                {
                   printf("\nError: el nombre ingresado para identificar al Polinimio resultante - ");
                   print(ls->Sig->info);
                   printf(" - , no es un alfanumerico.");
                }
            }
            else
                printf("\nError: la cantidad de parametros no es correcta para el comando,\n se esperan 3 parametros y fueron ingresados %d",LargoListaString(ls)- 1);
        }
        else
        {
            printf("\nError: no se reconoce el comando: ");
            print(ls->info);
        }
    }while(!streq("salir",ls->info));
}

void pruebaStringAEnteroYEsNumero()
{
    String s;
    strcrear(s);
    long int numero;
    scan(s);

    if(esEntero(s))
        printf("\nValor es entero");
    else
        printf("\nValor NOO es entero");

    numero = convertirStringAEntero(s);
    printf("\nValor convertido: %li",numero);


}

