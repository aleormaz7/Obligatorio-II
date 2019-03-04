#include "ProcesadorComandos.h"

void comandoCrear(ABBPolinomio &abb, ListaString ls)
{
    if(LargoListaString(ls) > 2)
    {
        if(esAlfanumerico(ls->Sig->info))
        {
            if(!ABBPolinomioExiste(abb,ls->Sig->info))
            {
                ///ya que nombre es alfanumerico, copio nombre de polinomio en variable aux para tenerlo por separado
                String nombrePoli;
                strcrear(nombrePoli);
                strcop(nombrePoli,ls->Sig->info);

                ListaString LsAux = ls->Sig->Sig;
                if(CoeficientesEnteros(LsAux))
                {
                    if(LargoListaString(LsAux) > 1 && streq("0",LsAux->info))
                        printf("Resultado:\t Error: si ingresea 2 o mas coeficientes, el de coeficiente de mayor grado no puede ser cero.");
                    else
                    {
                        ListaTerminos ListaTermPoli;
                        listaTerminosCrear(ListaTermPoli);
                        ListaStringAListaTerminos(ls,ListaTermPoli);
                        Polinomio Poli;
                        crearPolinomioResultante(Poli,nombrePoli,ListaTermPoli);
                        ABBPolinomioInsertar(abb,Poli);
                        printf("Resultado:\t ");
                        mostrarPolinomio(Poli);
                    }
                }
                else
                    printf("Resultado:\t Error: alguno de los coeficientes ingresados, no representan un valor entero.");
                destruirListaString(LsAux);
                strdestruir(nombrePoli);
            }
            else
            {
                printf("Resultado:\t Error: ya existe en el sistema, un Poliomio con el nombre ingresado. Nombre ingresado: ");
                print(ls->Sig->info);
            }
        }
        else
        {
            printf("Resultado:\t Error: el nombre ingresado para indentificar al Polinomio no es alfanumerico.\n\t\t Nombre ingresado: ");
            print(ls->Sig->info);
        }
    }
    else
    {
        if(LargoListaString(ls) == 1)
            printf("Resultado:\t Error: no se ingresaron parametros luego del comando -crear-");
        else
        {
            printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando -crear-, ");
            printf("\n\t\t para el mismo se esperan como minimo 2 parametros(nombre del Polinomio y sus coeficientes),\n\t\t en su lugar fueron ingresados %d",LargoListaString(ls)- 1);
        }
    }
}


void comandoSumar(ABBPolinomio &abb, ListaString ls)
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
                                    printf("Resultado : ");
                                    mostrarPolinomio(PoliResultante);
                                    ///Destruir lista??? es necesario apuntarlas A y B a NULL?
                                    destuirListaTerminos(LstResultado);
                                    LstPoliA = NULL;
                                    LstPoliB = NULL;
                             }
                             else
                             {
                                printf("Resultado:\t Error: el segundo Polinomio a sumar, indicado con el nombre ");
                                print(ls->Sig->Sig->Sig->info);
                                printf("\nno existe en memoria.");
                             }
                        }
                        else
                        {
                            printf("Resultado:\t Error: el primer Polinomio a sumar, indicado con el nombre ");
                            print(ls->Sig->Sig->info);
                            printf("\nno existe en memoria.");
                        }
                    }
                    else
                    {
                        printf("Resultado:\t Error: el nombre ingresado para el segundo Polinomio a sumar - ");
                        print(ls->Sig->Sig->Sig->info);
                        printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                    }
                }
                else
                {
                    printf("Resultado:\t Error: el nombre ingresado para el primer Polinomio a sumar- ");
                    print(ls->Sig->Sig->info);
                    printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                }
            }
            else
            {
                printf("Resultado:\t Error: en el sistema ya existe un Polinomio con el nombre ingresado para indeficiar al resulatante, nombre ingresado: ");
                print(ls->Sig->info);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado para identificar al Polinimio resultante - ");
           print(ls->Sig->info);
           printf(" - , no es un alfanumerico.");
        }
    }
    else
        printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando,\n se esperan 3 parametros y fueron ingresados %d",LargoListaString(ls)- 1);
}

void comandoMultiplicar(ABBPolinomio &abb, ListaString ls)
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

                                    multiplicarPolinomios(LstPoliA,LstPoliB,LstResultado);
                                    crearPolinomioResultante(PoliResultante,ls->Sig->info,LstResultado);
                                    ABBPolinomioInsertar(abb,PoliResultante);
                                    printf("Resultado : ");
                                    mostrarPolinomio(PoliResultante);

                                    ///Destruir lista??? es necesario apuntarlas A y B a NULL?
                                    destuirListaTerminos(LstResultado);
                                    LstPoliA = NULL;
                                    LstPoliB = NULL;
                             }
                             else
                             {
                                printf("Resultado:\t Error: el segundo Polinomio a multiplicar, indicado con el nombre ");
                                print(ls->Sig->Sig->Sig->info);
                                printf("\nno existe en memoria.");
                             }
                        }
                        else
                        {
                            printf("Resultado:\t Error: el primer Polinomio a multiplicar, indicado con el nombre ");
                            print(ls->Sig->Sig->info);
                            printf("\nno existe en memoria.");
                        }
                    }
                    else
                    {
                        printf("Resultado:\t Error: el nombre ingresado para el segundo Polinomio a multiplicar - ");
                        print(ls->Sig->Sig->Sig->info);
                        printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                    }
                }
                else
                {
                    printf("Resultado:\t Error: el nombre ingresado para el primer Polinomio a multiplicar- ");
                    print(ls->Sig->Sig->info);
                    printf(" -, no es un alfanumerico, y es imposible encontrarlo en el sistema.");
                }
            }
            else
            {
                printf("Resultado:\t Error: en el sistema ya existe un Polinomio con el nombre ingresado para indeficiar al resulatante, nombre ingresado: ");
                print(ls->Sig->info);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado para identificar al Polinimio resultante - ");
           print(ls->Sig->info);
           printf(" - , no es un alfanumerico.");
        }
    }
    else
        printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando,\n se esperan 3 parametros y fueron ingresados %d",LargoListaString(ls)- 1);
}

void comandoEvaluar(ABBPolinomio abb, ListaString ls)
{
    if(LargoListaString(ls) == 3)
    {
        if(esAlfanumerico(ls->Sig->info)) ///Nombre del Poli a evaluar
        {
            if(ABBPolinomioExiste(abb,ls->Sig->info)) ///Si existe el Poli a evaluar
            {
                if(esEntero(ls->Sig->Sig->info)) ///valor a evaluar
                {
                    long int e = convertirStringAEntero(ls->Sig->Sig->info);
                    ListaTerminos LstPoliEvaluar;
                    listaTerminosCrear(LstPoliEvaluar);
                    Polinomio PoliEvaluar = darPolinomio(abb,ls->Sig->info);
                    darListaTerminosPolinomio(PoliEvaluar,LstPoliEvaluar);

                    printf("Resultado : %li",evaluarPolinomio(LstPoliEvaluar,e));
                }
                else
                {
                    printf("Resultado:\t Error: el parametro correspondiente con el valor a evaluar - ");
                    print(ls->Sig->Sig->info);
                    printf(" -, no representa un numero entero. No es posible evaluar el Polinimio.");
                }
            }
            else
            {
                printf("Resultado:\t Error: en el sistema no existe un Polinomio con el nombre: ");
                print(ls->Sig->info);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado del Polinimio a evaluar - ");
           print(ls->Sig->info);
           printf(" - , no es un alfanumerico, es imposible identificarlo en el sistema.");
        }
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
        if(esAlfanumerico(ls->Sig->info)) ///Nombre del Poli a evaluar si es raiz
        {
            if(ABBPolinomioExiste(abb,ls->Sig->info)) ///Si existe el Poli a evaluar si es raiz
            {
                if(esEntero(ls->Sig->Sig->info)) ///valor a evaluar si es raiz
                {
                    long int e = convertirStringAEntero(ls->Sig->Sig->info);
                    ListaTerminos LstPoliEvaluar;
                    listaTerminosCrear(LstPoliEvaluar);
                    Polinomio PoliEvaluar = darPolinomio(abb,ls->Sig->info);
                    darListaTerminosPolinomio(PoliEvaluar,LstPoliEvaluar);

                    if(evaluarPolinomio(LstPoliEvaluar,e)== 0 )
                        printf("Resultado : es raiz");
                    else
                        printf("Resultado : No es raiz");
                }
                else
                {
                    printf("Resultado:\t Error: el parametro correspondiente con el valor a evaluar si es raiz del Polinomio - ");
                    print(ls->Sig->Sig->info);
                    printf(" -, no representa un numero entero. No es posible evaluar si es raiz del Polinimio.");
                }
            }
            else
            {
                printf("Resultado:\t Error: en el sistema no existe un Polinomio con el nombre: ");
                print(ls->Sig->info);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado del Polinimio a evaluar si es raiz - ");
           print(ls->Sig->info);
           printf(" - , no es un alfanumerico, es imposible identificarlo en el sistema.");
        }
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
            printf("Resultado   : ");
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
        if(esAlfanumerico(ls->Sig->info)) ///Nombre del Poli a guardar
        {
            if(ABBPolinomioExiste(abb,ls->Sig->info)) ///Si existe el Poli a guardar
            {
                if(cntPuntos(ls->Sig->Sig->info) == 1)
                {
                    String nombreArch,extensionArch;
                    strcrear(nombreArch);
                    strcrear(extensionArch);
                    retornaExtensionNombre(ls->Sig->Sig->info,nombreArch,extensionArch);
                    if(esAlfanumerico(nombreArch))
                    {
                        if(streq("txt",extensionArch))
                        {
                            if(!ExisteArchivo(ls->Sig->Sig->info))
                            {
                                Polinomio Poli = darPolinomio(abb,ls->Sig->info);
                                ListaTerminos LstAux;
                                listaTerminosCrear(LstAux);
                                darListaTerminosPolinomio(Poli,LstAux);
                                bajarListaTerminos(LstAux,ls->Sig->Sig->info);
                                printf("\nResultado:  Polinomio almacenado correctamente en ");
                                print(ls->Sig->Sig->info);
                            }
                            else
                            {
                                printf("\nYa existen en disco un archivo con el nombre -");
                                print(ls->Sig->Sig->info);
                                printf("- \n\tDesea sobreescribirlo? (S - si, N - No) ");
                                char respuesta;
                                scanf("%c",&respuesta);
                                if(respuesta == 's' || respuesta == 'S')
                                {
                                    Polinomio Poli = darPolinomio(abb,ls->Sig->info);
                                    ListaTerminos LstAux;
                                    listaTerminosCrear(LstAux);
                                    darListaTerminosPolinomio(Poli,LstAux);
                                    bajarListaTerminos(LstAux,ls->Sig->Sig->info);
                                    printf("\nResultado:  Polinomio almacenado correctamente en ");
                                    print(ls->Sig->Sig->info);
                                }
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
                {
                    if(cntPuntos(ls->Sig->Sig->info) == 0)
                    {
                        printf("Resultado:\t Error: no es posible determinar la extencion del archivo a guardar, no se encontro ningun punto en el nombre de archivo ingresado.",cntPuntos(ls->Sig->Sig->info));
                        printf(" Nombre de archivo ingresado: ");
                        print(ls->Sig->Sig->info);
                    }
                    else
                    {
                    printf("Resultado:\t Error: no es posible determinar la extencion del archivo a guardar, se encontraron %i puntos en el nombre de archivo ingresado.",cntPuntos(ls->Sig->Sig->info));
                    printf(" Nombre de archivo ingresado: ");
                    print(ls->Sig->Sig->info);
                    }
                }
            }
            else
            {
                printf("Resultado:\t Error: en el sistema no existe un Polinomio con el nombre: ");
                print(ls->Sig->info);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado para el Polinimio a guardar - ");
           print(ls->Sig->info);
           printf(" - , no es un alfanumerico, es imposible identificarlo en el sistema.");
        }
    }
    else
    {
        if(LargoListaString(ls)- 1 == 0)
            printf("Resultado:\t Error: No se encontraron parametros, para el comando -guardar-, se esperan que se ingresen 2 parametros(nombre del Polinomio y nombre del archivo).");
        else
        {
            printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando -guardar- ");
            printf("\n, para el mismo se esperan 2 parametros(nombre del Polinomio y nombre del archivo) y fueron ingresados %d",LargoListaString(ls)- 1);
        }
    }
}

void comandoRecuperar(ABBPolinomio &abb, ListaString ls)
{
    if(LargoListaString(ls) == 3)
    {
        if(esAlfanumerico(ls->Sig->info)) ///Nombre del Poli a guardar luego de recuperarlo
        {
            if(!ABBPolinomioExiste(abb,ls->Sig->info)) ///Si ya existe un Poli con ese nombre
            {
                if(cntPuntos(ls->Sig->Sig->info) == 1)
                {
                    String nombreArch,extensionArch;
                    strcrear(nombreArch);
                    strcrear(extensionArch);
                    retornaExtensionNombre(ls->Sig->Sig->info,nombreArch,extensionArch);
                    if(esAlfanumerico(nombreArch))
                    {
                         if(streq("txt",extensionArch))
                        {
                            if(ExisteArchivo(ls->Sig->Sig->info))
                            {
                                ListaTerminos LstAux;
                                listaTerminosCrear(LstAux);

                                levantarListaTerminos(LstAux,ls->Sig->Sig->info);
                                if(LstAux != NULL)
                                {
                                    Polinomio Poli;
                                    crearPolinomioResultante(Poli,ls->Sig->info,LstAux);
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
                                print(ls->Sig->Sig->info);
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
                        printf("Resultado:\t Error: el nombre del archivo del cual se desea recuperar el Polinomio no es alfanumerico. Nombre ingresado es: ");
                        print(nombreArch);
                    }
                }
                else
                {
                    if(cntPuntos(ls->Sig->Sig->info) == 0)
                    {
                        printf("Resultado:\t Error: no es posible determinar la extension del archivo del cual se desea recuperar el Polinomio, no se encontro ningun punto en el nombre de archivo ingresado.",cntPuntos(ls->Sig->Sig->info));
                        printf(" Nombre de archivo ingresado: ");
                        print(ls->Sig->Sig->info);
                    }
                    else
                    {
                    printf("Resultado:\t Error: no es posible determinar la extencion del archivo del cual se desea recuperar el Polinomio, se encontraron %i puntos en el nombre de archivo ingresado.",cntPuntos(ls->Sig->Sig->info));
                    printf(" Nombre de archivo ingresado: ");
                    print(ls->Sig->Sig->info);
                    }
                }
            }
            else
            {
                printf("Resultado:\t Error: ya existe en el sistema un Polinomio con el nombre: ");
                print(ls->Sig->info);
            }
        }
        else
        {
           printf("Resultado:\t Error: el nombre ingresado para el Polinimio que se desea recuperar -");
           print(ls->Sig->info);
           printf("- , no es un alfanumerico.");
        }
    }
    else
    {
        if(LargoListaString(ls)- 1 == 0)
            printf("Resultado:\t Error: No se encontraron parametros, para el comando -recuperar-, se esperan que se ingresen 2 parametros(nombre del Polinomio y nombre del archivo).");
        else
        {
            printf("Resultado:\t Error: la cantidad de parametros no es correcta para el comando -recuperar- ");
            printf("\n, para el mismo se esperan 2 parametros(nombre del Polinomio y nombre del archivo) y fueron ingresados %d",LargoListaString(ls)- 1);
        }
    }
}

void comandoSalir(ABBPolinomio &abb, ListaString ls)
{
    ABBPolinomioEliminar(abb);
    printf("Resultado:\t hasta la proxima.\n");
}
