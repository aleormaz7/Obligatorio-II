#include "Revision.h"

void cargarRevision(Revision &r)
{
    printf("\nIngrese Fecha realizado: ");
    cargarFecha(r.fechaRealizado);

    strcrear(r.descripcion);
    printf("\nIngrese descripion: ");
    scan(r.descripcion);

    printf("\nIngrese codigo expediente: ");
    scanf("%ld",r.codigoExpediente);

    printf("\nIngrese resultado revision: ");
    CargarResultante(r.resultadoRev);
}

void mostrarRevision(Revision r)
{
    printf("\nFecha realizado");
    mostrarFecha(r.fechaRealizado);

    printf("\nDescripion: ");
    print(r.descripcion);

    printf("\nCodigo expediente: %ld", r.codigoExpediente);

    printf("\nResultado Revision: ");
    MostrarResultante(r.resultadoRev);

}

Fecha darFechaRev(Revision r)
{
   return r.fechaRealizado;
}

void darDescripcion(Revision r, String &s)
{
    strcop(s,r.descripcion);
}

Resultante darResultanteRevision(Revision r)
{
    return r.resultadoRev;
}
