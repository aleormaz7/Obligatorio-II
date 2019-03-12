#include "ProcesadorComandos.h"

void comandoCrear(ABBPolinomio &abb, ListaString ls)
{
    if(LargoListaString(ls) > 2)
    {
        String nombrePoli;
        strcrear(nombrePoli);
        obtenerString(ls,1,nombrePoli);
        if(esAlfanumerico(nombrePoli))
        {
            if(!ABBPolinomioExiste(abb,nombrePoli))
            {
                ListaString LsAux;
                CrearListaString(LsAux);
                ListaStringAvanza(ls,LsAux);

                if(CoeficientesEnteros(LsAux))
                {
                    String coefStringAux;
                    strcrear(coefStringAux);
                    obtenerString(LsAux,0,coefStringAux);
                    if(LargoListaString(LsAux) > 1 && streq("0",coefStringAux))
                        printf("Resultado:\t Error: si ingresea 2 o mas coeficientes, el de coeficiente de mayor grado no puede ser cero.");
                    else
                    {
                        ListaTerminos ListaTermPoli;
                        listaTerminosCrear(ListaTermPoli);
                        ListaStringAListaTerminos(LsAux,ListaTermPoli);
                        Polinomio Poli;
                        crearPolinomio(Poli,nombrePoli,ListaTermPoli);
                        ABBPolinomioInsertar(abb,Poli);
                        printf("Resultado:\t ");
                        mostrarPolinomio(Poli);
                    }
                }
                else
                    printf("Resultado:\t Error: alguno de los coeficientes ingresados, no representan un valor entero.");
            }
            else
            {
                printf("Resultado:\t Error: ya existe en el sistema, un Poliomio con el nombre ingresado. Nombre ingresado: ");
                print(nombrePoli);
            }
        }
        else
        {
            printf("Resultado:\t Error: el nombre ingresado para indentificar al Polinomio no es alfanumerico.\n\t\t Nombre ingresado: ");
            print(nombrePoli);
        }
        strdestruir(nombrePoli);
    }
    else
    {
        if(LargoListaString(ls) == 1)
            printf("Resultado:\t Error: no se ingresaron parametros luego del comando -crear-");
        else
        {
            printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando -crear-, ");
            printf("\n\t\t para el mismo se espera como minimo 2 parametros(nombre del Polinomio y sus coeficientes),\n\t\t en su lugar fueron ingresados %d",LargoListaString(ls)- 1);
        }
    }
}

void comandoSumar(ABBPolinomio &abb, ListaString ls)
{
    if(LargoListaString(ls) == 4)
    {
        String nomPoliResultante;
        strcrear(nomPoliResultante);
        obtenerString(ls,1,nomPoliResultante);
        if(esAlfanumerico(nomPoliResultante)) ///Nombre del Poli resultante
        {
            if(!ABBPolinomioExiste(abb,nomPoliResultante)) ///Si existe un Poli con en nombre del resultante
            {
                String nomPoliA;
                strcrear(nomPoliA);
                obtenerString(ls,2,nomPoliA);
                if(esAlfanumerico(nomPoliA)) ///Nombre del primer Poli
                {
                    String nomPoliB;
                    strcrear(nomPoliB);
                    obtenerString(ls,3,nomPoliB);
                    if(esAlfanumerico(nomPoliB)) ///Nombre del segundo Poli
                    {
                        if(ABBPolinomioExiste(abb,nomPoliA))
                        {
                            if(ABBPolinomioExiste(abb,nomPoliB))
                             {
                                    ListaTerminos LstResultado,LstPoliA,LstPoliB;
                                    listaTerminosCrear(LstResultado);
                                    listaTerminosCrear(LstPoliA);
                                    listaTerminosCrear(LstPoliB);

                                    Polinomio PoliA = darPolinomio(abb,nomPoliA);
                                    Polinomio PoliB = darPolinomio(abb,nomPoliB);
                                    Polinomio PoliResultante;

                                    darListaTerminosPolinomio(PoliA,LstPoliA);
                                    darListaTerminosPolinomio(PoliB,LstPoliB);

                                    sumarPolinomios(LstPoliA,LstPoliB,LstResultado);
                                    crearPolinomio(PoliResultante,nomPoliResultante,LstResultado);
                                    ABBPolinomioInsertar(abb,PoliResultante);
                                    printf("Resultado : ");
                                    mostrarPolinomio(PoliResultante);

                                    destuirListaTerminos(LstResultado);
                                    LstPoliA = NULL;
                                    LstPoliB = NULL;
                             }
                             else
                             {
                                printf("Resultado:\t Error: el segundo Polinomio a sumar, indicado con el nombre ");
                                print(nomPoliB);
                                printf("\nno existe en memoria.");
                             }
                        }
                        else
                        {
                            printf("Resultado:\t Error: el primer Polinomio a sumar, indicado con el nombre ");
                            print(nomPoliA);
                            printf("\nno existe en memoria.");
                        }
                    }
                    else
                    {
                        printf("Resultado:\t Error: el nombre ingresado para el segundo Polinomio a sumar -");
                        print(nomPoliB);
                        printf("-, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                    }
                    strdestruir(nomPoliB);
                }
                else
                {
                    printf("Resultado:\t Error: el nombre ingresado para el primer Polinomio a sumar -");
                    print(nomPoliA);
                    printf("-, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                }
                strdestruir(nomPoliA);
            }
            else
            {
                printf("Resultado:\t Error: en el sistema ya existe un Polinomio con el nombre ingresado para indeficiar al resulatante, nombre ingresado: ");
                print(nomPoliResultante);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado para identificar al Polinimio resultante -");
           print(nomPoliResultante);
           printf("- , no es un alfanumerico.");
        }
        strdestruir(nomPoliResultante);
    }
    else
        printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando,\n\t\t se esperan 3 parametros y fueron ingresados %d",LargoListaString(ls)- 1);
}

void comandoMultiplicar(ABBPolinomio &abb, ListaString ls)
{
    if(LargoListaString(ls) == 4)
    {
        String nomPoliResultante;
        strcrear(nomPoliResultante);
        obtenerString(ls,1,nomPoliResultante);
        if(esAlfanumerico(nomPoliResultante)) ///Nombre del Poli resultante
        {
            if(!ABBPolinomioExiste(abb,nomPoliResultante)) ///Si existe un Poli con en nombre del resultante
            {
                String nomPoliA;
                strcrear(nomPoliA);
                obtenerString(ls,2,nomPoliA);
                if(esAlfanumerico(nomPoliA)) ///Nombre del primer Poli
                {
                    String nomPoliB;
                    strcrear(nomPoliB);
                    obtenerString(ls,3,nomPoliB);
                    if(esAlfanumerico(nomPoliB)) ///Nombre del segundo Poli
                    {
                        if(ABBPolinomioExiste(abb,nomPoliA))
                        {
                            if(ABBPolinomioExiste(abb,nomPoliB))
                            {

                                    ListaTerminos LstResultado,LstPoliA,LstPoliB;
                                    listaTerminosCrear(LstResultado);
                                    listaTerminosCrear(LstPoliA);
                                    listaTerminosCrear(LstPoliB);

                                    Polinomio PoliA = darPolinomio(abb,nomPoliA);
                                    Polinomio PoliB = darPolinomio(abb,nomPoliB);
                                    Polinomio PoliResultante;

                                    darListaTerminosPolinomio(PoliA,LstPoliA);
                                    darListaTerminosPolinomio(PoliB,LstPoliB);

                                    multiplicarPolinomios(LstPoliA,LstPoliB,LstResultado);
                                    crearPolinomio(PoliResultante,nomPoliResultante,LstResultado);
                                    ABBPolinomioInsertar(abb,PoliResultante);
                                    printf("Resultado : ");
                                    mostrarPolinomio(PoliResultante);

                                    destuirListaTerminos(LstResultado);
                                    LstPoliA = NULL;
                                    LstPoliB = NULL;
                             }
                             else
                             {
                                printf("Resultado:\t Error: el segundo Polinomio a multiplicar, indicado con el nombre ");
                                print(nomPoliB);
                                printf("\nno existe en memoria.");
                             }
                        }
                        else
                        {
                            printf("Resultado:\t Error: el primer Polinomio a multiplicar, indicado con el nombre ");
                            print(nomPoliA);
                            printf("\nno existe en memoria.");
                        }
                    }
                    else
                    {
                        printf("Resultado:\t Error: el nombre ingresado para el segundo Polinomio a multiplicar -");
                        print(nomPoliB);
                        printf("-, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                    }
                    strdestruir(nomPoliB);
                }
                else
                {
                    printf("Resultado:\t Error: el nombre ingresado para el primer Polinomio a multiplicar -");
                    print(nomPoliA);
                    printf("-, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                }
                strdestruir(nomPoliA);
            }
            else
            {
                printf("Resultado:\t Error: en el sistema ya existe un Polinomio con el nombre ingresado para indeficiar al resulatante, nombre ingresado: ");
                print(nomPoliResultante);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado para identificar al Polinimio resultante -");
           print(nomPoliResultante);
           printf("- , no es un alfanumerico.");
        }
        strdestruir(nomPoliResultante);
    }
    else
        printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando,\n se esperan 3 parametros y fueron ingresados %d",LargoListaString(ls)- 1);
}

void comandoEvaluar(ABBPolinomio abb, ListaString ls)
{
    if(LargoListaString(ls) == 3)
    {
        String nombPoliEvaluar;
        strcrear(nombPoliEvaluar);
        obtenerString(ls,1,nombPoliEvaluar);
        if(esAlfanumerico(nombPoliEvaluar)) ///Nombre del Poli a evaluar
        {
            if(ABBPolinomioExiste(abb,nombPoliEvaluar)) ///Si existe el Poli a evaluar
            {
                String valorSEvaluar;
                strcrear(valorSEvaluar);
                obtenerString(ls,2,valorSEvaluar);
                if(esEntero(valorSEvaluar)) ///valor a evaluar
                {
                    long int e = convertirStringAEntero(valorSEvaluar);
                    ListaTerminos LstPoliEvaluar;
                    listaTerminosCrear(LstPoliEvaluar);
                    Polinomio PoliEvaluar = darPolinomio(abb,nombPoliEvaluar);
                    darListaTerminosPolinomio(PoliEvaluar,LstPoliEvaluar);

                    printf("Resultado : %li",evaluarPolinomio(LstPoliEvaluar,e));
                }
                else
                {
                    printf("Resultado:\t Error: el parametro correspondiente con el valor a evaluar -");
                    print(valorSEvaluar);
                    printf("-, no representa un numero entero. No es posible evaluar el Polinimio.");
                }
                strdestruir(valorSEvaluar);
            }
            else
            {
                printf("Resultado:\t Error: en el sistema no existe un Polinomio con el nombre: ");
                print(nombPoliEvaluar);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado del Polinimio a evaluar -");
           print(nombPoliEvaluar);
           printf("- , no es un alfanumerico, es imposible identificarlo en el sistema.");
        }
        strdestruir(nombPoliEvaluar);
    }
    else
    {
        printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando - evaluar - ");
        printf(", para el mismo se esperan 2 parametros(nombre Polinomio y valor a evaluar) y fueron ingresados %d",LargoListaString(ls)- 1);
    }
}

void comandoEsRaiz(ABBPolinomio abb, ListaString ls)
{
    if(LargoListaString(ls) == 3)
    {
        String nombPoliEvaluar;
        strcrear(nombPoliEvaluar);
        obtenerString(ls,1,nombPoliEvaluar);
        if(esAlfanumerico(nombPoliEvaluar)) ///Nombre del Poli a evaluar si es raiz
        {
            if(ABBPolinomioExiste(abb,nombPoliEvaluar)) ///Si existe el Poli a evaluar si es raiz
            {
                String valorSEvaluar;
                strcrear(valorSEvaluar);
                obtenerString(ls,2,valorSEvaluar);
                if(esEntero(valorSEvaluar)) ///valor a evaluar si es raiz
                {
                    long int e = convertirStringAEntero(valorSEvaluar);
                    ListaTerminos LstPoliEvaluar;
                    listaTerminosCrear(LstPoliEvaluar);
                    Polinomio PoliEvaluar = darPolinomio(abb,nombPoliEvaluar);
                    darListaTerminosPolinomio(PoliEvaluar,LstPoliEvaluar);

                    if(evaluarPolinomio(LstPoliEvaluar,e)== 0 )
                        printf("Resultado : es raiz");
                    else
                        printf("Resultado : No es raiz");
                }
                else
                {
                    printf("Resultado:\t Error: el parametro correspondiente con el valor a evaluar si es raiz del Polinomio -");
                    print(valorSEvaluar);
                    printf("-, no representa un numero entero. No es posible evaluar si es raiz del Polinimio.");
                }
                strdestruir(valorSEvaluar);
            }
            else
            {
                printf("Resultado:\t Error: en el sistema no existe un Polinomio con el nombre: ");
                print(nombPoliEvaluar);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado del Polinimio a evaluar si es raiz -");
           print(nombPoliEvaluar);
           printf("- , no es un alfanumerico, es imposible identificarlo en el sistema.");
        }
        strdestruir(nombPoliEvaluar);
    }
    else
    {
        printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando - es raiz - ");
        printf("\n, para el mismo se esperan 2 parametros(nombre Polinomio y valor a evaluar) y fueron ingresados %d",LargoListaString(ls)- 1);
    }
}

void comandoMostrar(ABBPolinomio abb, ListaString ls)
{
    if(LargoListaString(ls) == 1)
    {
        if(!ABBPolinomioEsVacio(abb)) /// Controlo que el abb no este vacio.
        {
            printf("Resultado   : \n\t");
            ABBPolinomioListar(abb);
        }
        else
           printf("Resultado:\t No existen polinomios en memoria, no hay nada para listar.");
    }
    else
         printf("Resultado:\t Error: El comando -mostrar- no acepta parametros.");
}

void comandoGuardar(ABBPolinomio abb, ListaString ls)
{
    if(LargoListaString(ls) == 3)
    {
        String nombPoliGuarda;
        strcrear(nombPoliGuarda);
        obtenerString(ls,1,nombPoliGuarda);
        if(esAlfanumerico(nombPoliGuarda)) ///Nombre del Poli a guardar
        {
            if(ABBPolinomioExiste(abb,nombPoliGuarda)) ///Si existe el Poli a guardar
            {
                String nombArchLista;
                strcrear(nombArchLista);
                obtenerString(ls,2,nombArchLista);
                if(cntPuntos(nombArchLista) == 1)
                {
                    String nombreArch,extensionArch;
                    strcrear(nombreArch);
                    strcrear(extensionArch);
                    retornaExtensionNombre(nombArchLista,nombreArch,extensionArch);
                    if(strlar(nombreArch)!= 0)
                    {
                        if(esAlfanumerico(nombreArch))
                        {
                            if(streq("txt",extensionArch))
                            {
                                if(!ExisteArchivo(nombArchLista))
                                {
                                    Polinomio Poli = darPolinomio(abb,nombPoliGuarda);
                                    ListaTerminos LstAux;
                                    listaTerminosCrear(LstAux);
                                    darListaTerminosPolinomio(Poli,LstAux);
                                    bajarListaTerminos(LstAux,nombArchLista);
                                    printf("\nResultado:  Polinomio almacenado correctamente en ");
                                    print(nombArchLista);
                                }
                                else
                                {
                                    printf("\t\t Ya existen en disco un archivo con el nombre -");
                                    print(nombArchLista);
                                    printf("-\n\t\t Desea sobreescribirlo? (S - si, N - No) ");
                                    String respuesta;
                                    strcrear(respuesta);
                                    scan(respuesta);
                                    llevoAMinusculas(respuesta);
                                    if(strlar(respuesta) == 1 && (streq("s",respuesta) || streq("n",respuesta)))
                                    {
                                        if(streq("s",respuesta))
                                        {
                                            Polinomio Poli = darPolinomio(abb,nombPoliGuarda);
                                            ListaTerminos LstAux;
                                            listaTerminosCrear(LstAux);
                                            darListaTerminosPolinomio(Poli,LstAux);
                                            bajarListaTerminos(LstAux,nombArchLista);
                                            printf("\nResultado:  Polinomio almacenado correctamente en ");
                                            print(nombArchLista);
                                        }
                                        else
                                            printf("Resultado:\t no se guardo el Polinomio");
                                    }
                                    else
                                        printf("Resultado:\t Error: se esperaba S o N, no se guardo el archivo");
                                    strdestruir(respuesta);
                                }
                            }
                            else
                            {
                                printf("Resultado:\t Error: la extension del archivo a guardar no es txt. La misma es: ");
                                print(extensionArch);
                            }
                        }
                        else
                        {
                            printf("Resultado:\t Error: el nombre ingresado para el archivo en cual se desea guardar el Polinomio, no es elfanumeroco. Nombre ingresado es: ");
                            print(nombreArch);
                        }
                    }
                    else
                        printf("Resultado:\t Error: es necesario que ingrese un nombre para el archivo en cual se desea guardar el Polinomio.");

                    strdestruir(nombreArch);
                    strdestruir(extensionArch);
                }
                else
                {
                    if(cntPuntos(nombArchLista) == 0)
                    {
                        printf("Resultado:\t Error: no es posible determinar la extension del archivo a guardar,\n\t\t no se encontro ningun punto en el nombre de archivo ingresado.");
                        printf("\n\t\t Nombre de archivo ingresado: ");
                        print(nombArchLista);
                    }
                    else
                    {
                    printf("Resultado:\t Error: no es posible determinar la extension del archivo a guardar,\n\t\t se encontraron %i puntos en el nombre de archivo ingresado.",cntPuntos(nombArchLista));
                    printf("\n\t\t  Nombre de archivo ingresado: ");
                    print(nombArchLista);
                    }
                }
                strdestruir(nombArchLista);
            }
            else
            {
                printf("Resultado:\t Error: en el sistema no existe un Polinomio con el nombre: ");
                print(nombPoliGuarda);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado que identifica el Polinimio a guardar -");
           print(nombPoliGuarda);
           printf("-\n\t\t , no es un alfanumerico, es imposible identificarlo en el sistema.");
        }
        strdestruir(nombPoliGuarda);
    }
    else
    {
        if(LargoListaString(ls)- 1 == 0)
            printf("Resultado:\t Error: No se encontraron parametros, para el comando -guardar-.\n\t\t Se esperan que se ingresen 2 parametros(nombre del Polinomio y nombre del archivo).");
        else
        {
            printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando -guardar- ");
            printf("\n\t\t Para el mismo se esperan 2 parametros(nombre del Polinomio y nombre del archivo) y fueron ingresados %d",LargoListaString(ls)- 1);
        }
    }
}

void comandoRecuperar(ABBPolinomio &abb, ListaString ls)
{
    if(LargoListaString(ls) == 3)
    {
        String nombPoliRecupera;
        strcrear(nombPoliRecupera);
        obtenerString(ls,1,nombPoliRecupera);
        if(esAlfanumerico(nombPoliRecupera)) ///Nombre del Poli a guardar luego de recuperarlo
        {
            if(!ABBPolinomioExiste(abb,nombPoliRecupera)) ///Si ya existe un Poli con ese nombre
            {
                String nombArchLista;
                strcrear(nombArchLista);
                obtenerString(ls,2,nombArchLista);
                if(cntPuntos(nombArchLista) == 1)
                {
                    String nombreArch,extensionArch;
                    strcrear(nombreArch);
                    strcrear(extensionArch);
                    retornaExtensionNombre(nombArchLista,nombreArch,extensionArch);
                    if(esAlfanumerico(nombreArch))
                    {
                        if(streq("txt",extensionArch))
                        {
                            if(ExisteArchivo(nombArchLista))
                            {
                                ListaTerminos LstAux;
                                listaTerminosCrear(LstAux);

                                levantarListaTerminos(LstAux,nombArchLista);
                                if(LstAux != NULL)
                                {
                                    Polinomio Poli;
                                    crearPolinomio(Poli,nombPoliRecupera,LstAux);
                                    ABBPolinomioInsertar(abb,Poli);
                                    destuirListaTerminos(LstAux);
                                    printf("\nResultado : ");
                                    mostrarPolinomio(Poli);
                                }
                                else
                                    printf("Resultado:\t Error: ocurrio un error inesperado al recuperar la informacion del archivo.");
                            }
                            else
                            {
                                printf("Resultado:\t Error: no se encontro en el disco el archivo ");
                                print(nombArchLista);
                            }
                        }
                        else
                        {
                            printf("Resultado:\t Error: la extension del archivo del cual se desea recuperar el Polinomio no es txt. La misma es: ");
                            print(extensionArch);
                        }
                    }
                    else
                    {
                        printf("Resultado:\t Error: el nombre del archivo del cual se desea recuperar el Polinomio no es alfanumerico.\n\t\t Nombre ingresado es: ");
                        print(nombreArch);
                    }
                    strdestruir(nombreArch);
                    strdestruir(extensionArch);
                }
                else
                {
                    if(cntPuntos(nombArchLista) == 0)
                    {
                        printf("Resultado:\t Error: no es posible determinar la extension del archivo del cual se desea recuperar el Polinomio.\n\t\t No se encontro ningun punto en el nombre de archivo ingresado.");
                        printf("\n\t\t Nombre de archivo ingresado: ");
                        print(nombArchLista);
                    }
                    else
                    {
                    printf("Resultado:\t Error: no es posible determinar la extencion del archivo del cual se desea recuperar el Polinomio,\n\t\t se encontraron %i puntos en el nombre de archivo ingresado.",cntPuntos(nombArchLista));
                    printf("\n\t\t Nombre de archivo ingresado: ");
                    print(nombArchLista);
                    }
                }
                strdestruir(nombArchLista);
            }
            else
            {
                printf("Resultado:\t Error: ya existe en el sistema un Polinomio con el nombre: ");
                print(nombPoliRecupera);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado para el Polinimio que se desea recuperar -");
           print(nombPoliRecupera);
           printf("- , no es un alfanumerico.");
        }
        strdestruir(nombPoliRecupera);
    }
    else
    {
        if(LargoListaString(ls)- 1 == 0)
            printf("Resultado:\t Error: No se encontraron parametros, para el comando -recuperar-,\n\t\t se esperan que se ingresen 2 parametros(nombre del Polinomio y nombre del archivo).");
        else
        {
            printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando -recuperar- ");
            printf("\n\t\t Para el mismo se esperan 2 parametros(nombre del Polinomio y nombre del archivo) y fueron ingresados %d",LargoListaString(ls)- 1);
        }
    }
}

void comandoSalir(ABBPolinomio &abb, boolean &fin, ListaString ls)
{
    if(LargoListaString(ls) == 1)
    {
        ABBPolinomioEliminar(abb);
        printf("Resultado:\t hasta la proxima.\n");
        fin = TRUE;
    }
    else
         printf("Resultado:\t Error: El comando -salir- no acepta parametros.");
}
