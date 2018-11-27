#include "Menu.h"
#include "ABBExpediente.h"
#include "ListaRevision.h"
#include "Archivo.h"

int main()
{
    /* Se crean los .Dat en caso que no existan */
    //inicializarDat("Expedientes.dat");
    //inicializarDat("Revisiones.dat");

    ABBExpediente abbe;
    CrearABB(abbe);


    levantarExpedientes(abbe,"Expedientes.dat");


    /// Pruebas para Expediente /////
    //int continuar;
    long int codEpxAux, codigoExpediente;
    Expediente exp;
    String s;
    strcrear(s);
    Revision r;
    Fecha f,fini,ffin;
    listaRevision lr;

    int cant1,cant2,cant3;


    Crear(lr);





    ///Menu
    int opc,opcAltasBajas;
    do
    {
        mostrarMenu(opc);
        if(opc == 1)
        {
            do
            {
                mostrarSubMenuAltasyBajas(opcAltasBajas);
                switch(opcAltasBajas)
                {
                    case 1:
                        printf("\n1-: Cargar Expediente \n");
                        printf("\nCodigo del expediente: ");
                        scanf("%ld",&codigoExpediente);
                        if(PerteneceExpPorCod(abbe,codigoExpediente))
                            printf("\nError! Ya existe un expediente con ese codigo");
                        else
                            cargarExpediente(exp,codigoExpediente);
                            InsertABBExp(abbe,exp);
                        break;

                    case 2:
                        printf("\n2-: Cargar Revision \n");
                        printf("\nIngrese Codigo Expediente:");
                        scanf("%ld",&codigoExpediente);
                        if(PerteneceExpPorCod(abbe,codigoExpediente))
                        {
                            printf("\nIngrese Fecha expediente");
                            cargarFecha(f);
                            if(EsVacia(lr))
                            {
                                if(fechaValida(f))
                                {
                                    cargarRevision(r,codigoExpediente,f);
                                    InsFront(lr,r);
                                }
                                else
                                  printf("\nFehca invalida");
                            }
                            else
                            {
                                ///buscar fecha mas reciente en lista revision
                                Revision auxRev = Primero(lr);
                                if(fechaValida(f) && fechaMayor(f,darFechaRev(auxRev)))
                                {
                                    cargarRevision(r,codigoExpediente,f);
                                    InsFront(lr,r);
                                }
                                else
                                    printf("\nFehca invalida");
                            }
                        }
                        else
                            printf("\nNo existe revision con dicho codigo de expediente");
                        break;

                    case 3:
                        printf("\n3-: Eliminar Expediente \n");
                        printf("\nCodigo del expediente a eliminar: ");
                        scanf("%ld",&codEpxAux);
                        if(PerteneceExpPorCod(abbe,codEpxAux))
                        {
                            borrarABBExpedientePorCodigo(codEpxAux,abbe);
                            ///borrar las revisiones del expediente
                            EliminarRevisionesPorExpediente(lr,codEpxAux);

                        }
                        else
                            printf("\nError! No existe un expediente con el codigo ingresado");
                        break;
                    case 4: break;
                    default: printf("\nOpcion invalida.\n");
                        break;

                }
            }while(opcAltasBajas != 4);
        }
        else if(opc == 2)
        {
            do
            {
                mostrarSubMenuListados(opc);
                switch(opc)
                {
                    case 1:
                         printf("\n1-: Listado de expedientes almacenados en el sistemas, ordenados por su codigo \n");
                         ListarExpedientesOrdenados(abbe);
                        break;
                    case 2:
                        printf("\n2-: Listar Todas las Revisiones \n");
                        ListarRevisiones(lr);
                        break;
                    case 3:
                        printf("\nExpediente con el menor codigo: ");
                        exp = minimoExpediente(abbe);
                        mostrarExpediente(exp);
                        printf("\nExpediente con el mayor Codigo: ");
                        exp = maximoExpediente(abbe);
                        mostrarExpediente(exp);
                        break;
                    case 4:
                         printf("\n4-: Listar Revisiones Por Codigo Expediente \n");
                         printf("\nIngrese Codigo Expediente:");
                         scanf("%ld",&codigoExpediente);
                         ListarRevisionesPorCodigoExpediente(lr,codigoExpediente);
                        break;
                    case 5:
                        break;
                    default: printf("\nOpcion invalida.\n");
                        break;
                }
            }while(opc != 5);
        }
        else if(opc == 3)
        {
            do
            {
                mostrarSubMenuConsultas(opc);
                switch(opc)
                {
                    case 1: printf("\nInrese el apellido del escribano: ");
                        scan(s);
                        printf("\nEl escribano ");
                        print(s);
                        printf(" tiene un total de %d expedientes coordinados.",cntExpedientesEscribano(abbe,s));
                        break;
                    case 2:
                         //printf("\nObtener codigo expediente con mayor cantidad revisiones: ");
                         //printf("%ld",);
                        break;
                    case 3:
                         printf("\nCantidad revisiones entre fechas: ");
                         cargarFecha(fini);
                         cargarFecha(ffin);
                         if(fechaValida(fini) && fechaValida(ffin))
                            printf("\nCantidad = %d",cantRevisonesEntreFechas(lr,fini,ffin));
                         else
                            printf("\nCargar fechas validas");
                        break;
                    case 4:
                        printf("\nCantidad revisiones cada tipo: ");
                        cantRevisionesCadaTipo(lr,cant1,cant2,cant3);
                        printf("\nSATISFACTORIO = %d",cant1);
                        printf("\nINCOMPLETA = %d",cant2);
                        printf("\nPENDIENTE = %d",cant3);
                        break;
                    case 5:
                        break;
                    default: printf("\nOpcion invalida.\n");
                        break;
                }
            }while(opc != 5);
        }
    }while(opc != 4);

    bajarExpedientes(abbe,"Expedientes.dat");




}
