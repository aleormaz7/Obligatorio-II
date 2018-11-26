#include "ABBExpediente.h"

int main()
{

    /// Pruebas para Expediente /////

    int continuar;
    long int codEpxAux;
    Expediente exp;
    String s;
    strcrear(s);

    ABBExpediente abbe;
    CrearABB(abbe);

    printf("\nCargar Expediente             - 1 -");
    printf("\nEliminar Expediente           - 2 -");
    printf("\nListar Expedientes ordenados  - 3 -");
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
        ListarExpientesOrdenados(abbe);
        printf("\n**************\n");
        break;

    }

    printf("\nContinuar?");
    scanf("%d",&continuar);

} while(continuar != 0codEpxAux);

    printf("\n\n");

/*
printf("\nCod: %ld",darCodigoExpediente(exp));

printf("\nCarat");
    darCaratula(exp,s);
print(s);
    printf("\nCod: %ld",darCntPaginas(exp));

    printf("\nNom Esc");
    darNombreEscribano(exp,s);
    print(s);
    printf("\nApe Esc");
    darApellidoEscribano(exp,s);
    print(s);

*/






}
