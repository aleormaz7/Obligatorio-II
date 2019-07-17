#include "Boolean.h"

void CargarBoolean(boolean &b)
{
    int x;
    printf("Ingrese 0-FALSE, 1-TRUE");
    scanf("%d",&x);

    if(x == 1)
        b = TRUE;
    else
        b = FALSE;
}

void MostrarBoolean(boolean b)
{
    if(b == FALSE)
        printf("FALSE");
    else
        printf("TRUE");
}


