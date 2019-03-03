#include "Termino.h"

void CrearTermino(Termino &t, long int coef, int grado)
{
    t.coef = coef;
    t.grado = grado;
}

void MostrarTermino(Termino t)
{
    ///No guardamos 0, salvo en el termino independiente para representar el Polinomio nulo
    if(t.grado > 1)
    {
        if(t.coef > 1)
         {
                printf(" +%ld",t.coef);
                printf("x%d",t.grado);
         }
        else
         {
             if(t.coef == 1 || t.coef == -1)
             {
                 if(t.coef == 1)
                    printf(" +x%d",t.grado);
                 else
                    printf(" -x%d",t.grado);
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
        if(t.grado == 1)
        {
            if(t.coef == 1 || t.coef == -1)
            {
                if(t.coef == 1)
                    printf(" +x");
                else
                    printf(" -x");
            }
            else
                if(t.coef > 0)
                    printf(" +%ldx",t.coef);

                else
                    printf(" %ldx",t.coef);
        }
        else
        {
            if(t.coef > 0)
                printf(" +%ld",t.coef);
            else
            {
                if(t.coef == 0)
                    printf(" 0");
                else
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
