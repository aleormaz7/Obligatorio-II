#include "Resultante.h"

void CargarResultante(Resultante &r)
{
    int x;
    printf("\nIngrese 1-SATISFACTORIO,2-INCOMPLETA,3-PENDIENTE ");
    scanf("%d",&x);

    if(x == 1)
        r = SATISFACTORIO;
    else if(x == 2)
        r = INCOMPLETA;
    else if(x == 3)
        r = PENDIENTE;
    else
        printf("\nOpcion incorrecta");

}

void MostrarResultante(Resultante r)
{
    if(r == SATISFACTORIO)
    {
        printf("SATISFACTORIO");
    }
    else if(r == INCOMPLETA)
    {
        printf("INCOMPLETA");
    }
    else
    {
         printf("PENDIENTE");
    }
}
