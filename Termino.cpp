#include "Termino.h"

void CrearTermino(Termino &t, long int coef, int grado)
{
    t.coef = coef;
    t.grado = grado;
}

void MostrarTermino(Termino t)
{
    if(t.grado > 0)
    {
        if(t.coef > 0)
        {
            printf(" +%ld",t.coef);
            printf("x%d",t.grado);
        }
        else
        {
            if(t.coef == 0)
            {
                ///No mostrar nada ej 0x2
            }
            else
            {
                printf(" %ld",t.coef);
                printf("x%d",t.grado);
            }
        }
    }
    else
    {
        if(t.grado == 0)
        {
            if(t.coef == 0)
            {
                ///No muestro nada ej 0x0
            }
            else ///Termino independiente
            {
                printf(" %ld",t.coef);
            }
        }
    }
}


long int DarCoefTermino(Termino t)
{
    return t.coef;
}

int DarGradoTermino(Termino t)
{
    return t.grado;
}

void BajarTermino(Termino t, FILE * f)
{
    fwrite(&t.coef,sizeof(long int),1,f);
    fwrite(&t.grado,sizeof(int),1,f);
}

void LevantarTermino(Termino &t, FILE * f)
{
    fread(&t.coef, sizeof(long int), 1, f);
    fread(&t.grado, sizeof(int), 1, f);
}

///Esto habria que ver cuando se Levante o Baje cada termino a la lista de Terminos
/*
    while(!feof(f))
    {
        ///TODO: Agregar/Insertar termino en ListaTerminos(y despues en el ABB).
        fread(&t.coef, sizeof(long int), 1, f);
        fread(&t.grado, sizeof(long int), 1, f);
    }
    fclose(f);
*/
