#include "Resultante.h"

void CargarResultante(Resultante &r)
{
    int x;
    printf("\n 1-SATISFACTORIO, 2-INCOMPLETA, 3-PENDIENTE : " );
    scanf("%d",&x);
    do{
            switch(x)
            {
            case 1: r = SATISFACTORIO;
                break;
            case 2: r = INCOMPLETA;
                break;
            case 3: r = PENDIENTE;
                break;
            default: printf("\nOpcion incorrecta");
                printf("\n 1-SATISFACTORIO, 2-INCOMPLETA, 3-PENDIENTE : " );
                scanf("%d",&x);
                break;
            }
        }while(x <1 || x > 3);
}

void MostrarResultante(Resultante r)
{
    switch(r)
    {
    case SATISFACTORIO: printf("SATISFACTORIO");
        break;
    case INCOMPLETA: printf("INCOMPLETA");
        break;
    case PENDIENTE: printf("PENDIENTE");
        break;
    }
}
