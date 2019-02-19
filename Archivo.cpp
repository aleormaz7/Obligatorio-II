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

boolean ArchivoEsVacio(String nomArch)
{
    boolean esVacio = FALSE;
    FILE * f = fopen(nomArch,"rb");
    fseek(f,0,SEEK_END);
    if(ftell(f) == 0)
    {
        esVacio = TRUE;
    }
    fclose(f);
    return esVacio;
}

boolean EnteroPertenecArchivo(String nomArch, int valor)
{
    int aux;
    boolean pertenece = FALSE;
    FILE * f = fopen(nomArch,"rb");
    fread(&aux,sizeof(int),1,f);
    while(!feof(f) && pertenece != TRUE)
    {
        if(valor == aux)
        {
            pertenece = TRUE;
        }
        fread(&aux,sizeof(int),1,f);
    }
    fclose(f);
    return pertenece;
}



