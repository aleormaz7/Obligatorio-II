#include "ABBExpediente.h"

#include "ListaRevision.h"

int main()
{

    /// Pruebas para Expediente /////
    int continuar;
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
                    printf("\nlista es vacia");
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




}
