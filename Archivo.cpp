#include "Archivo.h"

void inicializarDat(String s)
{
    FILE * f = fopen(s,"ab");
    fclose(f);
}

boolean existeArchivo(String nomArch)
{
    boolean existe = FALSE;
    FILE * f = fopen(nomArch,"rb");
    if (f != NULL)
        existe = TRUE;

    return existe;
}
