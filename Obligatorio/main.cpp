#include "Menu.h"
#include "Grafo.h"
#include "Ciudades.h"
#include "Lineas.h"


///TODO:ver cantidad de ciudades a ingresar y cantidad de cubetas

int main()
{
    Grafo G;
    CrearGrafo(G);

    Lineas lineasEmpresa;
    MakeLineas(lineasEmpresa);

    Ciudades ciudades;
    MakeCiudades(ciudades);

    printf(" Bienvenido, para comenzar debe registrar las %d ciudades del sistema.\n",CANT_CIUDADES);

    ///Se hace la iteracion con while para asegurarnos de no cargar ciudades repetidas
    int i = 0;

    do
    {
        printf("\nCiudad numero %d",i + 1);
        Ciudad c;
        CargarCiudad(c,i);
        String nombCiudAux;
        strcrear(nombCiudAux);
        DarNombre(c,nombCiudAux);
        if(!Member(ciudades, nombCiudAux))
        {
            Insert(ciudades,c);
            i++;
        }
        else
        {
            printf("\nYa se cargo una ciudad con el nombre: ");
            print(nombCiudAux);
            printf("\n");
        }
    }while(i < CANT_CIUDADES);

    /* BORRAR */
    //printf("\n");
    //MostrarHash(ciudades);
    //printf("\n");
    //MostrarGrafo(G);
    /* FIN BORRAR */

    int opc;
    do
    {
        MostrarMenu(opc);

        switch(opc)
        {
        case 1:
            printf("\n.: Agregar nuevo Tramo :.\n");
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
                    if(Member(ciudades,nom2))///si existe los dos nombres ingresados
                    {
                        Ciudad ciu1,ciu2;
                        ciu1 = FindCiudad(ciudades,nom1);
                        ciu2 = FindCiudad(ciudades,nom2);

                        if(!ExisteTramo(G,DarCodigo(ciu1),DarCodigo(ciu2)))
                        {
                            InsertarArista(G,DarCodigo(ciu1),DarCodigo(ciu2));
                            printf("\nSe registro exitosamente el tramo entre ");
                            print(nom1);
                            printf(" y ");
                            print(nom2);
                        }
                        else
                        {
                            printf("\n Error: ya existe un tramo entre ");
                            print(nom1);
                            printf(" y ");
                            print(nom2);
                        }
                    }
                    else
                    {
                        printf("\n Error: en el sistema no existe la ciudad: ");
                        print(nom2);
                    }
                }
            }
            else
            {
                printf("\n Error: en el sistema no existe la ciudad: ");
                print(nom1);
            }
            strdestruir(nom1);
            strdestruir(nom2);
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
                   printf("\nError: ee ingreso la misma ciudad para origen/destino.");
                else
                {
                    if(Member(ciudades,nom2))//si existe los dos nombres ingresados
                    {
                        Ciudad ciu1,ciu2;
                        ciu1 = FindCiudad(ciudades,nom1);
                        ciu2 = FindCiudad(ciudades,nom2);

                        if(ExisteSecuenciaDeTramoEntreDosCiudades(G,DarCodigo(ciu1),DarCodigo(ciu2)))
                        {
                            printf("\nExiste una secuencia de tramos entre la ciudad ");
                            print(nom1);
                            printf(" y la ciudad ");
                            print(nom2);
                        }
                        else
                        {
                            printf("\nLamentablemente no existe una secuencia de tramos entre la ciudad ");
                            print(nom1);
                            printf(" y la ciudad ");
                            print(nom2);
                        }
                    }
                    else
                    {
                        printf("\n Error: en el sistema no existe la ciudad: ");
                        print(nom2);
                    }
                }
            }
            else
            {
                printf("\n Error: en el sistema no existe la ciudad: ");
                print(nom1);
            }
            strdestruir(nom1);
            strdestruir(nom2);
            break;
        case 3:
            Linea linea;
            CargarLinea(linea);
            String nomLineaInserta;
            strcrear(nomLineaInserta);
            DarCodigoLinea(linea,nomLineaInserta);
            if(strlar(nomLineaInserta) > 0)
            {
                 if(!MemberLinea(lineasEmpresa,nomLineaInserta))
                {
                    InsertLinea(lineasEmpresa,linea);
                    printf("\nLa linea ");
                    print(nomLineaInserta);
                    printf(" se registro exitosamente");
                }
                else
                {
                    printf("\nError: ya existe el registro de una linea con el codigo ");
                    print(nomLineaInserta);
                }
            }
            else
                printf("\nError: el numero de linea no puede ser vacio.");
            strdestruir(nomLineaInserta);
            break;
        case 4:
            if(!lineasVacia(lineasEmpresa))
            {
                printf("\n .: Listado de lineas registradas en el sistema :.");
                ListarLineas(lineasEmpresa);
            }
            else
                printf("\n .: Aun no se han registrado lineas en el sistema :.");

            break;
        case 5:
                String nombLinea;
                strcrear(nombLinea);
                printf("\nIngrese linea: ");
                scan(nombLinea);
                StringAMayusculas(nombLinea);
                if(MemberLinea(lineasEmpresa,nombLinea))
                {
                    Linea l = FindLinea(lineasEmpresa,nombLinea);
                    Recorrido r = DarRecorrido(l);

                    boolean SePuedeIngresarRecorrido = FALSE;
                    if(RecorridoVacio(r))
                    {
                        printf("\nEsta linea aun no tiene seteado un recorrido, ");
                        printf("\nindique la ciudad de origen del mismo: ");
                        SePuedeIngresarRecorrido = TRUE;
                    }
                    else
                    {
                        if(!ExiteAlMenosUnTramo(G))
                            printf("\nError: no es posible agregar paradas, ya que esta linea tiene asignado un origen y en el sistema aun no se han registrados tramos entre ciudades.");
                        else
                        {
                            printf("\nIndique parada(ciudad) en el recorrido: ");
                            SePuedeIngresarRecorrido = TRUE;
                        }
                    }
                    if(SePuedeIngresarRecorrido)
                    {
                        String ciudAux;
                        strcrear(ciudAux);
                        scan(ciudAux);
                        StringAMayusculas(ciudAux);
                        if(Member(ciudades,ciudAux))
                        {
                            if(!RecorridoVacio(r))
                            {
                                Parada paradaDestino = Destino(r);
                                Ciudad ciudaDestinoActual  = DarCiudad(paradaDestino);
                                Ciudad ciudadNuevoDestino = FindCiudad(ciudades,ciudAux);
                                if(ExisteTramo(G,DarCodigo(ciudaDestinoActual),DarCodigo(ciudadNuevoDestino)))
                                {
                                    Parada p;
                                    CargarParada(p,(LargoRecorrido(r)+1),ciudadNuevoDestino);
                                    AgregarParadaARecorridoDeLinea(l,p);
                                    ModifyLinea(lineasEmpresa,l);
                                    printf("\nSe agrego exitosamente la parada al recorrido.");
                                }
                                else
                                {
                                    printf("\nError: no se puede agregar la parada, ya que no se ha defindo un tramo entre ");
                                    String nomCiudaDestino;
                                    strcrear(nomCiudaDestino);
                                    DarNombre(ciudaDestinoActual,nomCiudaDestino);
                                    print(nomCiudaDestino);
                                    printf(" y ");
                                    print(ciudAux);
                                    strdestruir(nomCiudaDestino);
                                }
                            }
                            else
                            {
                                Ciudad ciudadParada = FindCiudad(ciudades,ciudAux);
                                Parada p;
                                CargarParada(p,(LargoRecorrido(r)+1),ciudadParada);
                                AgregarParadaARecorridoDeLinea(l,p);
                                ModifyLinea(lineasEmpresa,l);
                            }
                        }
                        else
                        {
                            printf("\n Error: en el sistema no existe la ciudad: ");
                            print(ciudAux);
                        }
                        strdestruir(ciudAux);
                    }
                }
                else
                {
                    printf("\nError: en el sistema no existe la linea:");
                    print(nombLinea);
                }

                strdestruir(nombLinea);
            break;
        case 6:
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
                {
                    printf("\nError: no el sistema no existe la linea: ");
                    print(nombLinea);
                }
                strdestruir(nombLinea);
            break;
        default:
            printf("\nOpcion invalida.\n");
            break;
        }
    }
    while (opc != 7);
}
