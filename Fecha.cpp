#include "Fecha.h"

void cargarFecha(fecha &f)
{
    printf("\nIngrese un dia: ");
    scanf("%d",&f.dia);

    printf("\nIngrese un mes: ");
    scanf("%d",&f.mes);

    printf("\nIngrese un anio: ");
    scanf("%d",&f.anio);
}

void mostrarFecha(fecha f)
{
    printf(" %d",f.dia);
    printf("/%d",f.mes);
    printf("/%d",f.anio);
}

boolean fechaValida(fecha f)
{
    boolean valida;

    switch (f.mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: if (f.dia >= 1 && f.dia <= 31)
                    valida = TRUE;
                else
                    valida = FALSE;
            break;
        case 4:
        case 6:
        case 9:
        case 11: if (f.dia >= 1 && f.dia <= 30)
                    valida = TRUE;
                else
                    valida = FALSE;
            break;
        case 2: if (f.anio % 4 == 0)
                {
                    if (f.dia >= 1 && f.dia <= 29)
                        valida = TRUE;
                    else
                        valida = FALSE;
                }
                else
                {
                    if (f.dia >= 1 && f.dia <= 28)
                        valida = TRUE;
                    else
                        valida = FALSE;
                }
            break;

        default: valida = FALSE;
    }

    return valida;
}

int darDia(fecha f)
{
    return f.dia;
}

int darMes(fecha f)
{
    return f.mes;
}

int darAnio(fecha f)
{
    return f.anio;
}
