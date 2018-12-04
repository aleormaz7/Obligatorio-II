#include "Menu.h"
#include "ABBExpediente.h"
#include "Archivo.h"

int main()
{
    /* Se crean los .Dat en caso que no existan */
    if(!existeArchivo("Expedientes.dat"))
        inicializarDat("Expedientes.dat");

    if(!existeArchivo("Revisiones.dat"))
        inicializarDat("Revisiones.dat");

    ABBExpediente abbe;
    CrearABB(abbe);

    listaRevision lr;
    Crear(lr);

    levantarExpedientes(abbe,"Expedientes.dat");
    levantarRevisiones(lr,"Revisiones.dat");

    /// Pruebas para Expediente /////
    long int codEpxAux, codigoExpediente;
    Expediente exp;
    String s;
    strcrear(s);
    Revision r;
    Fecha f,fini,ffin;


    int cant1,cant2,cant3, cntAux = 0;


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
                        printf("\n ** Cargar Expediente **\n");
                        printf("\nCodigo del expediente: ");
                        scanf("%ld",&codigoExpediente);
                        if(PerteneceExpPorCod(abbe,codigoExpediente))
                            printf("\nError! Ya existe un expediente con ese codigo");
                        else
                        {
                            cargarExpediente(exp,codigoExpediente);
                            InsertABBExp(abbe,exp);
                            printf("\nSe ha ingresado el expediente en el sistema. ");
                        }
                        break;

                    case 2:
                        printf("\n ** Cargar Revision **\n");
                        printf("\nIngrese Codigo Expediente:");
                        scanf("%ld",&codigoExpediente);
                        if(PerteneceExpPorCod(abbe,codigoExpediente))
                        {
                            printf("\nIngrese Fecha de la revision");
                            cargarFecha(f);
                            if(listaRevisionesEsVacia(lr))
                            {
                                if(fechaValida(f))
                                {
                                    cargarRevision(r,codigoExpediente,f);
                                    InsFront(lr,r);
                                    printf("\nSe ha registrado la revision del expediente.");
                                }
                                else
                                    printf("\nFecha invalida");
                            }
                            else
                            {
                                ///buscar fecha mas reciente en lista revision
                                Revision auxRev = Primero(lr);
                                if(fechaValida(f))
                                   {
                                       if(fechaIgual(f,darFechaRev(auxRev)) || (fechaMayor(f,darFechaRev(auxRev))))
                                          {
                                                cargarRevision(r,codigoExpediente,f);
                                                InsFront(lr,r);
                                                printf("\nSe ha registrado la revision del expediente.");
                                          }
                                          else
                                            printf("\nLa fecha de revision debe ser mayor o igual a la ultima registrada en el sistema");
                                   }
                                else
                                    printf("\nFecha invalida");
                            }
                        }
                        else
                            printf("\nError! No existe un expediente con el codigo ingresado");
                        break;

                    case 3:
                        printf("\n ** Eliminar Expediente **\n");
                        printf("\nCodigo del expediente a eliminar: ");
                        scanf("%ld",&codEpxAux);
                        if(PerteneceExpPorCod(abbe,codEpxAux))
                        {
                            borrarABBExpedientePorCodigo(codEpxAux,abbe);
                            ///borrar las revisiones del expediente
                            EliminarRevisionesPorExpediente(lr,codEpxAux);
                            printf("\nSe ha eliminado la informacion del sistema.");
                        }
                        else
                            printf("\nError! No existe un expediente con el codigo ingresado");
                        break;
                    case 4:
                        break;
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
                         if(!AbbExpientesEsVacio(abbe))
                            ListarExpedientesOrdenados(abbe);
                         else
                            printf("\nNo existen expedientes ingresados en el sistema");

                        break;
                    case 2:

                        printf("\n2-: Listar Todas las Revisiones \n");
                        if(!listaRevisionesEsVacia(lr))
                            ListarRevisiones(lr);
                        else
                            printf("\nNo existen revisiones en el sistema");
                        break;
                    case 3:
                        if(!AbbExpientesEsVacio(abbe))
                        {
                            printf("\nExpediente con el menor codigo: ");
                            exp = minimoExpediente(abbe);
                            mostrarExpediente(exp);
                            printf("\n\nExpediente con el mayor Codigo: ");
                            exp = maximoExpediente(abbe);
                            mostrarExpediente(exp);
                        }
                        else
                            printf("\nNo se puedo procesar la consulta, no hay expedientes en el sistema");

                        break;
                    case 4:
                         if(!listaRevisionesEsVacia(lr))
                         {
                             printf("\n4-: Listado de Revisiones de un expediente \n");
                             printf("\nIngrese Codigo Expediente:");
                             scanf("%ld",&codigoExpediente);
                             if(PerteneceExpPorCod(abbe,codigoExpediente))
                                ListarRevisionesPorCodigoExpediente(lr,codigoExpediente);
                            else
                                printf("\nEn el sistema no existe un expediente con el codigo ingresado");

                         }
                         else
                             printf("\nNo se puedo procesar la consulta, no hay revisiones en el sistema");

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
                        if(!AbbExpientesEsVacio(abbe))
                        {
                            if(!listaRevisionesEsVacia(lr))
                            {
                                cntAux = 0;
                                codExpMasRevisiones(abbe,lr,codEpxAux,cntAux);
                                printf("\nEl expediente con mas revisiones es el expediente con codigo: %ld, con %d revisiones.",codEpxAux,cntAux);
                            }
                            else
                                printf("\nNo se puede procesar la consulta ya que no existen revisiones en el sistema.");
                        }
                        else
                           printf("\nNo se puede procesar la consulta ya que no existen expedientes en el sistema.");
                        break;
                    case 3:
                         printf("\nCantidad revisiones entre fechas: ");
                         printf("\nFecha desde: ");
                         cargarFecha(fini);
                         if(fechaValida(fini))
                         {
                             printf("\nFecha hasta: ");
                             cargarFecha(ffin);
                             if(fechaValida(ffin))
                                {
                                    if(!fechaMayor(fini,ffin) || (fechaIgual(fini,ffin)))
                                        printf("\nCantidad = %d",cantRevisonesEntreFechas(lr,fini,ffin));
                                    else
                                        printf("\nError! La fecha desde no puede ser mayor que la fecha hasta");
                                }
                                else
                                    printf("\nError! Fecha no valida");
                         }
                         else
                            printf("\nError! Fecha no valida");
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
    bajarRevisiones(lr,"Revisiones.dat");
}
