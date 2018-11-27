#include "Menu.h"
#include "ABBExpediente.h"
#include "ListaRevision.h"

int main()
{

    /// Pruebas para Expediente /////
    //int continuar;
    long int codEpxAux, codigoExpediente;
    Expediente exp;
    String s;
    strcrear(s);
    Revision r;
    Fecha f;
    listaRevision lr;

    Crear(lr);

    ABBExpediente abbe;
    CrearABB(abbe);

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
                            borrarABBExpedientePorCodigo(codEpxAux,abbe);
                        else
                            printf("\nNo existe un expediente con ese codigo");
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
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default: printf("\nOpcion invalida.\n");
                        break;
                }
            }while(opc != 5);
        }
    }while(opc != 4);






/////////////////////////////////////////////////
///lo que estaba antes x las dudas no lo borre
/*
    printf("\nCargar Expediente             - 1 -");
    printf("\nEliminar Expediente           - 2 -");
    printf("\nListar Expedientes ordenados  - 3 -");
    printf("\nCargar Revision               - 4 -");
    printf("\nListar todas las Revisiones   - 5 -");
    printf("\nSalir                         - 0 -");
    printf("\n");
    scanf("%d",&continuar);

do
{
    switch(continuar)
    {
        case 1:
             cargarExpediente(exp);
             if(PerteneceExp(abbe,exp))
                printf("\nYa esta cardado");
            else
                 InsertABBExp(abbe,exp);
            break;
        case 2:
            printf("\nCodigo del expediente a eliminar: ");
            scanf("%ld",&codEpxAux);

            if(PerteneceExpPorCod(abbe,codEpxAux))
                borrarABBExpedientePorCodigo(codEpxAux,abbe);
            else
                printf("\nNo existe un expediente con ese codigo");
            break;

        case 3:
            printf("\n\n **************");
            ListarExpedientesOrdenados(abbe);
            printf("\n**************\n");
            break;
        case 4:
            printf("\n\n **************");
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
                printf("\nNo existe expediente con dicho codigo");

            printf("\n**************\n");
            break;
        case 5:
            printf("\n\n **************");
            printf("\nLista Revisiones: ");
            ListarRevisiones(lr);
            printf("\n**************\n");
            break;


    }

    printf("\nContinuar?");
    scanf("%d",&continuar);

} while(continuar != codEpxAux);

    printf("\n\n");
*/

}
