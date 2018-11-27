#include "Archivo.h"

void inicializarDat(String s)
{
    FILE * f = fopen(s,"wb");
    fclose(f);
}

