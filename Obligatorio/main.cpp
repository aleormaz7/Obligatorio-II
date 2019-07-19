#include "Menu.h"
#include "Grafo.h" ///este include va en el menu o aca????
#include "Ciudades.h"
#include "Ciudad.h"
#include "Lineas.h"


/*cantidad de cubetas la funcion de disperion te puede tirar mas*/


int main()
{
    Grafo G;
    CrearGrafo(G);

    Lineas lineasEmpresa;
    MakeLineas(lineasEmpresa);

    Ciudades ciudades;
    MakeCiudades(ciudades);



    printf(" Registre las %d ciudades del sistema.\n",CANT_CIUDADES);
    printf("\nCargar nombre de todas las ciudades: \n");
    for(int i = 0; i < CANT_CIUDADES; i++)
    {
        Ciudad c;
        CargarCiudad(c,i);
        Insert(ciudades,c);
    }

    /* BORRAR */
    printf("\n");
    MostrarHash(ciudades);
    printf("\n");
    MostrarGrafo(G);
    /* FIN BORRAR */

    int opc;
    do
    {
        MostrarMenu(opc);

        switch(opc)
        {
        case 1:
            printf("\n.: Agregar nuevo Tramo \n");
            String nom1,nom2;
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
                        ciu1 = FindCiudad(ciudades,nom1);
                        ciu2 = FindCiudad(ciudades,nom2);

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
        case 2:
            printf("\n Dados los nombres de dos ciudades, saber si existe alguna secuencia de tramos que las una. ");
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
                   printf("\nSe ingreso la misma ciudad para origen/destino.");
                else
                {
                    if(Member(ciudades,nom2))//si existe los dos nombres ingresados
                    {
                        Ciudad ciu1,ciu2;
                        ciu1 = FindCiudad(ciudades,nom1);
                        ciu2 = FindCiudad(ciudades,nom2);

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
                        printf("\n No existe ciudad con ese nombre en el sistema");
                }
            }
            else
                printf("\n No existe ciudad con ese nombre en el sistema");
            break;
        case 3:
            Linea linea;
            CargarLinea(linea);
            InsertLinea(lineasEmpresa,linea);
            ListarLineas(lineasEmpresa);
            break;
        case 4:
            ListarLineas(lineasEmpresa);
            break;
        case 5:
            {
                String nombLinea;
                strcrear(nombLinea);
                printf("\nIngrese linea: ");
                scan(nombLinea);
                StringAMayusculas(nombLinea);
                if(MemberLinea(lineasEmpresa,nombLinea))
                {
                    Linea l = FindLinea(lineasEmpresa,nombLinea);
                    Recorrido r = DarRecorrido(l);
                    if(LargoRecorrido(r) == 0)
                    {
                        printf("\nIndique el origen del recorrido: ");
                        String ciudAux;
                        strcrear(ciudAux);
                        scan(ciudAux);
                        StringAMayusculas(ciudAux);
                        if(Member(ciudades,ciudAux))
                        {
                            Ciudad ciudadParada = FindCiudad(ciudades,ciudAux);
                            Parada p;
                            CargarParada(p,1,ciudadParada);
                            InsBackRecorrido(r,p);
                        }
                        else
                            printf("\n No existe ciudad con ese nombre en el sistema");

                    }
                    if(!ExiteAlMenosUnTramo(G))
                        printf("\nNo es posible agregar paradas, ya que esta linea tiene asignado un origen y aun no se han registrados tramos entre ciudades.");
                }
                else
                    printf("\nNo existe Linea con ese nombre.");
            }
            break;
        case 6:
                String nombLinea;
                strcrear(nombLinea);
                printf("\nIngrese linea: ");
                scan(nombLinea);
                StringAMayusculas(nombLinea);
                if(MemberLinea(lineasEmpresa,nombLinea))
                {
                    Linea l = FindLinea(lineasEmpresa,nombLinea);
                    ListarParadasDeRecorridoEnLinea(l);
                }
                else
                    printf("\nNo existe Linea con ese nombre.");
            break;
        default:
            printf("\nOpcion invalida.\n");
            break;
        }
    }
    while (opc != 7);
}
