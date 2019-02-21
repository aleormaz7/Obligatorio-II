#include "Polinomio.h"

///**********************************************
///funciona->este procedimiento(codigo) solo le va agregando al polinomio el nombre, los coef y grados (sin chequear ninguna condicion).
/*void crearPolinomio(Polinomio &p, String nombre, ListaTerminos listaT)
{
    strcop(p.nombre,nombre);
    listaTerminosCrear(p.listaTerminos);
    while(listaT != NULL)
    {
        Termino auxT;
        CrearTermino(auxT,DarCoefTermino(listaT->info),DarGradoTermino(listaT->info));
        listaTerminosInsertarOrdenado(p.listaTerminos,auxT);
        listaT = listaT->Sig;
    }
}*/
///**********************************************


///proc..(con chequeos de condiciones)
void crearPolinomio(Polinomio &p,String lineaComando)///esta hecho asi para probar
{
    ListaString listaS;
    CrearListaString(listaS);
    ListaTerminos listaTerminosAux;
    String nombrePol;

    ///Partir el String en una lista de strings
    partirString(lineaComando,listaS);
    //printf("\nLargo de lista es: %d ", LargoListaString(listaS));
    //printf("\n");
    //MostrarListaString(listaS);
    ///SI el 1º String es “crear”
    //printf("\n****");
    //print(listaS->info);///esto es lo mismo ???
    //print(listaS[0].info);/// esto es lo mismo ???
    //print(comando);
    //printf("\n****");

    if(streq(listaS->info,"crear"))///TODO: ver esto(xq el error que no deja comparar, no entra aca) y ademas el tema ej si nombre = CREAR o CrEaR ,etc.
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
            //printf("\n****");
            //print(listaS->info);
            ///SI el 2º String no representa sólo caracteres alfanuméricos
            if(!esAlfanumerico(listaS->info))
            {
                printf("\nError: el nombre de Polinomio debe ser alfanumérico");
            }
            else///SINO
            {

                ///ya que nombre es alfanumerico, copio nombre de polinomio en variable aux para tenerlo por separado

                strcop(nombrePol,listaS->info);

                ///SI el nombre del Polinomio ya se encuentra en el ABB(?) //TODO: falta esto del ABB
                ///Error: "Ya existe un polinomio con el nombre ingresado."
                ///SINO

                ///avanzar en listaS a 3er string
                listaS = listaS->Sig;

                ///SI a partir del 3º String no son todos numéricos (*1C*)
                int largo = LargoListaString(listaS) + 2;///mas 2 de los dos que me movi
                //printf("\nlargo listaS: %d",largo);


                /*if(!CoeficientesEnteros(listaS))
                {
                    printf("\nError: los coeficientes deben ser numéricos.");
                }
                else
                {*/
                    //printf("\nSon coef numericos");

                    ///Creo Lista de terminos
                    //listaTerminosCrear(p.listaTerminos);

                    listaTerminosCrear(listaTerminosAux);
                    Termino auxT;
                    ///Inicializo Grado = 0
                    int grado = largo-3;///largo - 3(dos menos por crear y nombrePol y otro menos por el termino independiente grado cero)

                    ///SI largo de listaString == 3
                    if(largo == 3)
                    {
                        //printf("\n largo = 3");
                        ///Paso 3er String a entero
                        int coef1 = convertirStringAEntero(listaS->info);
                        //printf("| coef1: %d",coef1);
                        CrearTermino(auxT,coef1,grado);
                        listaTerminosInsertarOrdenado(listaTerminosAux,auxT);///TODO: preguntar el insertar ordenado inserta igual, aunque exista un solo termino
                    }
                    else///SINO
                    {
                        //printf("\n largo>>>>> 3");

                        int coef1 = convertirStringAEntero(listaS->info);
                        //printf("| coef1: %d",coef1);
                        ///SI 3er String entero = 0
                        if(coef1 == 0)
                        {
                            printf("\nError: Si existen 2 o más términos, el de mayor grado no puede ser cero.");
                        }
                        else///SINO
                        {
                            ///PARA CADA NodoLista en Lista String desde el final hasta el primero + 2
                            //for(int i = largo; i > 2; i--)
                            int i = largo;
                            while(i > 2)
                            {
                                //printf("\n i: %d",i);
                                ///Paso NodoLista a entero
                                int coefAux = convertirStringAEntero(listaS->info);
                                //printf("| coefAux: %d",coefAux);
                                ///SI NodoLista es distinto de cero
                                if(coefAux != 0)
                                {
                                    ///Creo Término (NodoLista Entero y Grado)
                                    CrearTermino(auxT,coefAux,grado);
                                    ///Agrego Término a Lista de términos
                                    listaTerminosInsertarOrdenado(listaTerminosAux,auxT);
                                    listaS = listaS->Sig;
                                }
                                grado--;
                                i--;
                            }
                            ///InsertarPolinomio en ABB de Polinomios.
                        }
                    }
                //}
            }
        }
    }

    strcop(p.nombre,nombrePol);
    listaTerminosCrear(p.listaTerminos);
    while(listaTerminosAux != NULL)
    {
        Termino auxT;
        CrearTermino(auxT,DarCoefTermino(listaTerminosAux->info),DarGradoTermino(listaTerminosAux->info));
        listaTerminosInsertarOrdenado(p.listaTerminos,auxT);
        listaTerminosAux = listaTerminosAux->Sig;
    }

}

void darListaTerminosPolinomio(Polinomio p, ListaTerminos &listaT)
{
    listaTerminosCrear(listaT);
    while(p.listaTerminos != NULL)
    {
        Termino auxT;
        CrearTermino(auxT,DarCoefTermino(p.listaTerminos->info),DarGradoTermino(p.listaTerminos->info));
        listaTerminosInsertarOrdenado(listaT,auxT);

        p.listaTerminos = p.listaTerminos->Sig;
    }
}

void mostrarPolinomio(Polinomio p)
{
    print(p.nombre);
    listaTerminosMostrar(p.listaTerminos);
}


void darNombrePolinomio(Polinomio p, String &s)
{
    strcop(s,p.nombre);
}

void borrarPolinomio(Polinomio &p)
{
    strdestruir(p.nombre);//Eliminar nombre
    //listaTerminosBorrar(p.listaTerminos);//Eliminar lista de Terminos
}

