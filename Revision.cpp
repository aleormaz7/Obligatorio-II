#include "Revision.h"

void cargarRevision(Revision &r, long int codigo, Fecha f)
{
    r.fechaRealizado = f;

    strcrear(r.descripcion);
    printf("\nDescripion de la revision: ");
    scan(r.descripcion);

    r.codigoExpediente = codigo;

    printf("\nResultado de la revision: ");
    CargarResultante(r.resultadoRev);
}

void mostrarRevision(Revision r)
{
    printf("\nFecha realizado: ");
    mostrarFecha(r.fechaRealizado);

    printf(" -Descripion: ");
    print(r.descripcion);

    printf(" -Codigo expediente: %ld", r.codigoExpediente);

    printf(" -Resultado Revision: ");
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

long int darCodigoExpedienteDeRevision(Revision r)
{
    return r.codigoExpediente;
}
