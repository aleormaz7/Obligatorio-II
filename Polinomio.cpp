#include "Polinomio.h"

void crearPolinomio(Polinomio &p, ListaString listaS)
{
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

                ///TODO:
                ///SI el nombre del Polinomio ya se encuentra en el ABB(?) //TODO: falta esto del ABB
                ///Error: "Ya existe un polinomio con el nombre ingresado."
                ///SINO

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
                    printf("\nSon coef numericos");

                    Termino auxT;
                    ///Inicializo Grado
                    int grado = largo-3;///largo - 3(dos menos por crear y nombrePol y otro menos por el termino independiente grado cero)

                    ///SI largo de listaString == 3
                    if(largo == 3)
                    {
                        ///Paso 3er String a entero
                        int coef1 = convertirStringAEntero(listaS->info);
                        CrearTermino(auxT,coef1,grado);

                        ///si el coef del termino independiente no es cero inserto termino en polinomio
                        if(coef1 != 0)
                        {
                            listaTerminosInsertarOrdenado(p.listaTerminos,auxT);///(polinomio con un solo termino)
                        }
                    }
                    else///SINO
                    {
                        /// FEDE: Todo el codigo anterior a este es de parseo => hacerlo antes de acá
                        /// es decir, antes de invocar a crearPolinomio
                        /// decidan si acá quieren permitir al usuario crear un polinomio nulo de entrada o no

                        int coef1 = convertirStringAEntero(listaS->info);

                        ///SI 3er String entero = 0
                        if(coef1 == 0)
                        {
                            printf("\nError: Si existen 2 o más términos, el de mayor grado no puede ser cero.");
                        }
                        else///SINO
                        {
                            ///PARA CADA NodoLista en Lista String desde el final hasta el primero + 2
                            int i = largo;
                            while(i > 2)
                            {
                                ///Paso NodoLista a entero
                                int coefAux = convertirStringAEntero(listaS->info);
                                ///SI NodoLista es distinto de cero
                                if(coefAux != 0)
                                {
                                    ///Creo Término (NodoLista Entero y Grado)
                                    CrearTermino(auxT,coefAux,grado);
                                    ///Agrego Término a Lista de términos
                                    listaTerminosInsertarOrdenado(p.listaTerminos,auxT);
                                    listaS = listaS->Sig;
                                }
                                grado--;
                                i--;
                            }
                        }
                    }
                }
            }
        }
    }
}

void darListaTerminosPolinomio(Polinomio p, ListaTerminos &listaT)
{
    listaTerminosCrear(listaT);
    listaT = p.listaTerminos;
}

void mostrarPolinomio(Polinomio p)
{
    print(p.nombre);
    /// no deberiamos mostrar un guion o dos puntos o algo entre el nombre y la lista de terminos???
    listaTerminosMostrar(p.listaTerminos);
}


void darNombrePolinomio(Polinomio p, String &s)
{
    /// llamar a strcrear(s)
    strcop(s,p.nombre);
}

void borrarPolinomio(Polinomio &p)
{
    strdestruir(p.nombre);
    destuirListaTerminos(p.listaTerminos);
}
