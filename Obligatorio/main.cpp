#include "Menu.h"
#include "Grafo.h" ///este include va en el menu o aca????
#include "Ciudades.h"
#include "Ciudad.h"
#include "Lineas.h"


/*cantidad de cubetas la funcion de disperion te puede tirar mas*/


int main()
{
    Grafo G;
    Lineas lineasABB;
    MakeLineas(lineasABB);
    CrearGrafo(G);
    MostrarGrafo(G);
    Ciudades ciudades;
    MakeCiudades(ciudades);

    String nom1,nom2;

    int opc;
    do
    {
        MostrarMenu(opc);

        switch(opc)
        {
        case 1:
            printf("\n.Cargar nombre de todas las ciudades: \n");
            for(int i = 0; i < CANT_CIUDADES; i++)
            {
                Ciudad c;
                CargarCiudad(c,i);
                Insert(ciudades,c);
            }
            MostrarHash(ciudades);
            break;
        case 2:
            printf("\n.: Agregar nuevo Tramo \n");

            strcrear(nom1);
            strcrear(nom2);
            printf("\n Ingrese nombre 1er ciudad: ");
            scan(nom1);
            StringAMayusculas(nom1);
            if(Member(ciudades,nom1))
            {
                printf("\n Ingrese nombre 2da ciudad: ");
                scan(nom2);
                StringAMayusculas(nom2);
                if(streq(nom1,nom2))
                    printf("\nNo se puede agregar un tramo para la misma ciudad origen/destino.");
                else
                {
                    if(Member(ciudades,nom2))//si existe los dos nombres ingresados
                    {
                        Ciudad ciu1,ciu2;
                        ciu1 = Find(ciudades,nom1);
                        ciu2 = Find(ciudades,nom2);

                        if(!PerteneceArista(G,DarCodigo(ciu1),DarCodigo(ciu2)))
                            InsertarArista(G,DarCodigo(ciu1),DarCodigo(ciu2));
                        else
                            printf("\nYa existe un tramos entre estas ciudades.");
                        MostrarGrafo(G);
                    }
                    else
                    {
                        printf("\n No existe una ciudad con ese nombre en la agencia.");
                    }
                }
            }
            else
            {
                printf("\n No existe una ciudad con ese nombre en la agencia.");
            }
            break;
        case 3:
            printf("\n Dados los nombres de dos ciudades, saber si existe alguna secuencia de tramos que las una. ");
            strcrear(nom1);
            strcrear(nom2);
            printf("\n Ingrese nombre 1er ciudad: ");
            scan(nom1);
            if(Member(ciudades,nom1))
            {
                printf("\n Ingrese nombre 2da ciudad: ");
                scan(nom2);
                if(Member(ciudades,nom2))//si existe los dos nombres ingresados
                {
                    Ciudad ciu1,ciu2;
                    ciu1 = Find(ciudades,nom1);
                    ciu2 = Find(ciudades,nom2);

                    if(ExisteSecuenciaDeTramoEntreDosCiudades(G,DarCodigo(ciu1),DarCodigo(ciu2)))
                    {
                        printf("\nExiste tramo");
                    }
                    else
                    {
                        printf("\nNo existe tramo");
                    }
                }
                else
                {
                    printf("\n No existe ciudad con ese nombre en el grafo");
                }

            }
            else
            {
                printf("\n No existe ciudad con ese nombre en el grafo");
            }
            break;
        case 4:
            printf("\n Ingresar una nueva línea a la empresa: ");
            Linea linea;
            printf("\nIngrese linea: ");
            CargarLinea(linea);
            ///4. Ingresar una nueva línea a la empresa, chequeando que no existiera previamente otra
            ///   línea con el mismo código alfanumérico.
            InsertLinea(lineasABB,linea);
            ListarLineas(lineasABB);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;

        default:
            printf("\nOpcion invalida.\n");
            break;
        }
    }
    while (opc != 8);   // Si la opcion seleccionada del menu principal es 4 , salir del programa.
}
