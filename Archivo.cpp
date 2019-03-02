#include "archivo.h"

boolean ExisteArchivo(String nomArch)
{
    boolean existe = TRUE;
    if(fopen(nomArch,"rb") == NULL)
    {
        existe = FALSE;
    }

    return existe;
}
