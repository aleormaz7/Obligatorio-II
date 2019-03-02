#include "Polinomio.h"

void crearPolinomio(Polinomio &p, ListaString listaS)
{
    int largo = LargoListaString(listaS) + 2;///mas 2 de los dos que me movi
    Termino auxT;
    ///Inicializo Grado
    int grado = largo-3;///largo - 3(dos menos por crear y nombrePol y otro menos por el termino independiente grado cero)

    ///SI largo de listaString == 3
    if(largo == 3)
    {
        ///Paso 3er String a entero
        int coef1 = convertirStringAEntero(listaS->info);

        ///si el coef del termino independiente no es cero inserto termino en polinomio
        if(coef1 != 0)
        {
            CrearTermino(auxT,coef1,0);
            listaTerminosInsertarOrdenado(p.listaTerminos,auxT);///(polinomio con un solo termino)
        }
        else
        {
            ///Si coef es 0 creo termino nulo(0,0)
            CrearTermino(auxT,0,0);
            listaTerminosInsertarOrdenado(p.listaTerminos,auxT);
        }

    }
    else///SINO
    {

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
                }
                listaS = listaS->Sig;
                grado--;
                i--;
            }
        }
    }
}

void crearPolinomioResultante(Polinomio &p,String nombre, ListaTerminos lst)
{
    strcop(p.nombre,nombre);
    listaTerminosCopiar(lst,p.listaTerminos);
}

void darListaTerminosPolinomio(Polinomio p, ListaTerminos &listaT)
{
    listaTerminosCrear(listaT);
    listaT = p.listaTerminos;
}

void mostrarPolinomio(Polinomio p)
{
    print(p.nombre);
    printf(":");
    listaTerminosMostrar(p.listaTerminos);
}


void darNombrePolinomio(Polinomio p, String &s)
{
    strcrear(s);
    strcop(s,p.nombre);
}

void borrarPolinomio(Polinomio &p)
{
    strdestruir(p.nombre);
    destuirListaTerminos(p.listaTerminos);
}
