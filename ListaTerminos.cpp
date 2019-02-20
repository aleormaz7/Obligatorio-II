#include "ListaTerminos.h"

boolean listaTerminosEsVacia(ListaTerminos listaT)
{
    boolean EsVacia = FALSE;
    if (listaT == NULL)
        EsVacia = TRUE;
    return EsVacia;
}

void listaTerminosResto(ListaTerminos &listaT)
{

}

void listaTerminosCrear(ListaTerminos &listaT)
{
    listaT = NULL;
}

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t)
{
    if(listaT == NULL)
    {
        listaT = new nodoT;
        listaT->info = t;
        listaT->Sig = NULL;
    }
    else
    {
        if(DarGradoTermino(t) >= DarGradoTermino(listaT ->info))
        {
            ListaTerminos aux = new nodoT;
            aux->info = t;
            aux->Sig = listaT;
            listaT = aux;
        }
        else
            listaTerminosInsertarOrdenado(listaT->Sig,t);
    }
}


void listaTerminosMostrar(ListaTerminos listaT)
{
    while (listaT != NULL)
    {
        MostrarTermino(listaT->info);
        listaT = listaT->Sig;
    }
}

long int evaluarPolinomio(ListaTerminos listaT, int valor)
{
    long int resultado  = 0;
    return resultado;
    int i;

	while(listaT != NULL)
    {
        if((DarGradoTermino(listaT->info)) > 1)
        {
            for(i = 1; i = DarGradoTermino(listaT->info);i++)
                resultado = valor * valor;
            resultado = resultado * (DarCoefTermino(listaT->info));
        }
        else
        {
            if((DarGradoTermino(listaT->info)) == 1)
                resultado = resultado * DarCoefTermino(listaT->info);
            else
                resultado = resultado + DarCoefTermino(listaT->info);
		}
		listaT = listaT->Sig;
    }
    return resultado;
}

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado)
{
    while(listaA != NULL || listaB != NULL)
    {
        Termino terminoAux;
        if(DarGradoTermino(listaA->info)== DarGradoTermino(listaB->info))
           {
                if(DarGradoTermino(listaA->info) == 0)
                   {
                        CrearTermino(terminoAux,((DarCoefTermino(listaA->info) + DarCoefTermino(listaB->info))),0);
                        listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                   }
                   else
                   {
                       if((DarCoefTermino(listaA->info) + DarCoefTermino(listaB->info))!= 0)
                          {
                            CrearTermino(terminoAux,((DarCoefTermino(listaA->info) + DarCoefTermino(listaB->info))),DarGradoTermino(listaA->info));
                            listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                          }
                   }
                   listaA = listaA->Sig;
                   listaB = listaB->Sig;
           }
           else
           {
               if(DarGradoTermino(listaA->info) > DarGradoTermino(listaB->info))
               {
                    CrearTermino(terminoAux,((DarCoefTermino(listaA->info))),DarGradoTermino(listaA->info));
                    listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                    listaA = listaA->Sig;
               }
               else
               {
                    CrearTermino(terminoAux,((DarCoefTermino(listaB->info))),DarGradoTermino(listaB->info));
                    listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                    listaB = listaB->Sig;
               }
           }
    }
}

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado)
{

}
/*
void levantarTerminos(file * f, ListaTerminos &listaT)
{

}

void bajarTerminos(file * f, ListaTerminos listaTerminos);
*/

boolean representaPolinomioNulo(ListaTerminos listaT)
{
    boolean esNulo = FALSE;
	if (DarGradoTermino(listaT->info) == 0 && DarCoefTermino(listaT->info) == 0)
		boolean esNulo = TRUE;
    return esNulo;
}

void reduceListaTerminos(ListaTerminos listaT, ListaTerminos &listaResultante)
{/*
	long int coefAux = DarCoefTermino(listaT->info);
	int gradoAux = DarGradoTermino(listaT->info);
	Termino tAux;
	while (listaT->Sig != NULL)
	{
		if(DarGradoTermino(listaT->info) == DarGradoTermino(listaT->Sig->info))
		{
			coefAux  = DarCoefTermino(listaT->info);
			gradoAux = DarGradoTermino(listaT->info);
			marcoTerminoProcesado(listaT->info);
			if(listaT->Sig == NULL)
            {
                if(gradoAux == 0)
                {
                    CrearTermino(tAux,coefAux,gradoAux);
                    listaTerminosInsertarOrdenado(listaResultante,tAux);
                }
                else
                {
                    if(coefAux == 0)
                    {
                        CrearTermino(tAux,coefAux,gradoAux);
                        listaTerminosInsertarOrdenado(listaResultante,tAux);
                    }
                }
            }
            else
            {
                listaT = listaT->Sig;
                while(DarGradoTermino(listaT->info) == gradoAux)
                {
                    marcoTerminoProcesado(listaT->info);
                    coefAux = coefAux + DarCoefTermino(listaT->info);
                    listaT = listaT->Sig;
                }
                if(gradoAux == 0)
                {
                    CrearTermino(tAux,coefAux,gradoAux);
                    listaTerminosInsertarOrdenado(listaResultante,tAux);
                }
                else
                {
                    if(coefAux == 0)
                    {
                        CrearTermino(tAux,coefAux,gradoAux);
                        listaTerminosInsertarOrdenado(listaResultante,tAux);
                    }
                }
            }
        }
    }*/
}

int mayorGradoListaTerminos(ListaTerminos listaT)
{
    return DarGradoTermino(listaT->info);
}

ListaTerminos listaTerminosCopiar(ListaTerminos listaT)
{
    ListaTerminos listaRetorno;
    listaTerminosCrear(listaRetorno);

    while(listaT != NULL)
    {
        Termino tAux;
        CrearTermino(tAux,DarCoefTermino(listaT->info),DarGradoTermino(listaT->info));
        listaTerminosInsertarOrdenado(listaRetorno,tAux);
    }
    return listaRetorno;
}
