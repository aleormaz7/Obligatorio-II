#include "Expediente.h"



void cargarExpediente(Expediente &e, long int CodExpediente)
{

    e.codigoExpediente = CodExpediente;

    printf("\nCaratula: ");
    strcrear(e.caratula);
    scan(e.caratula);

    printf("\nNombre del escribano: ");
    strcrear(e.nombreEscribano);
    scan(e.nombreEscribano);

    printf("\nApellido del escribano: ");
    strcrear(e.apellidoEscribano);
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

void mostrarExpedienteConsultaOrdenados(Expediente e)
{

    printf("\nCodigo: %ld",e.codigoExpediente);

    printf(" || Caratula: ");
    print(e.caratula);

    printf(" || Escribano: ");
    print(e.nombreEscribano);

    printf(" ");
    print(e.apellidoEscribano);

    printf(" || Cantidad de paginas: %d",e.cantPaginas);

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

void bajarExpedienteArchivo(Expediente e, FILE * f)
{
    fwrite(&e.codigoExpediente,sizeof(long int),1,f);
    Bajar_String(e.caratula,f);
    Bajar_String(e.nombreEscribano,f);
    Bajar_String(e.apellidoEscribano,f);
    fwrite(&e.cantPaginas,sizeof(int),1,f);
}
