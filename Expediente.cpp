#include "Expediente.h"



void cargarExpediente(Expediente &e)
{
    printf("\nCodigo del expediente: ");
    scanf("%ld",&e.codigoExpediente);

    printf("\nCaratula: ");
    scan(e.caratula);

    printf("\nNombre del escribano: ");
    scan(e.nombreEscribano);

    printf("\nApellido del escribano: ");
    scan(e.apellidoEscribano);

    printf("\nCantidad de paginas: ");
    scanf("%d",&e.cantPaginas);

}

void mostrarExpediente(Expediente e)
{

    printf("\nCodigo del expediente: %ld",e.codigoExpediente);

    printf("\nCaratula: ");
    print(e.caratula);

    printf("\nNombre del escribano: ");
    print(e.nombreEscribano);

    printf("\nApellido del escribano: ");
    print(e.apellidoEscribano);

    printf("\nCantidad de paginas: %d",e.cantPaginas);

}

long int darCodigoExpediente(Expediente e)
{
    return e.codigoExpediente;
}

void darCaratula(Expediente e, String &s)
{
    strcop(s,e.caratula);
}

void darNombreEscribano(Expediente e, String &s)
{
        strcop(s,e.nombreEscribano);
}

void darApellidoEscribano(Expediente e, String &s)
{
        strcop(s,e.apellidoEscribano);
}

int darCntPaginas(Expediente e)
{
    return e.cantPaginas;
}
