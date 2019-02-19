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


void listaTerminosMostrar(ListaTerminos t)
{
    while (t->Sig != NULL)
    {
        MostrarTermino(t->info);
        t = t->Sig;
    }
}

long int evaluarPolinomio(ListaTerminos listaT, int valor)
{/*
    long int resultado  = 0;
    return resultado;

	while(listaT != NULL)
		switch(DarGradoTermino(listaT->info))
		{
			case DarGradoTermino(listaT->info) > 1:
							for(i = 1; i = DarGradoTermino(listaT->info);i++)
								resultado = valor * valor;
							resultado = resultado * DarCoefTermino(listaA->info);
							break;
			case DarGradoTermino(listaT->info) == 1:
							resultado = resultado * DarCoefTermino(listaA->info);
							break;
			case DarGradoTermino(listaT->info) == 0:
							resultado = resultado + DarCoefTermino(listaA->info);
							break;
		}*/
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
                            CrearTermino(terminoAux,((DarCoefTermino(listaA->info) + DarCoefTermino(listaB->info))),DarCoefTermino(listaA->info));
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
                    CrearTermino(terminoAux,((DarCoefTermino(listaA->info))),DarCoefTermino(listaA->info));
                    listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                    listaA = listaA->Sig;
               }
               else
               {
                    CrearTermino(terminoAux,((DarCoefTermino(listaB->info))),DarCoefTermino(listaB->info));
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
{/*
    boolean esNulo = FALSE;
	if (DarGradoTermino(listaT->info) == 0 && DarCoefTermino(listaA->info) == 0)
		boolean esNulo = TRUE;
    return esNulo;*/
}

ListaTerminos reduceListaTerminos(ListaTerminos listaT, ListaTerminos &listaResultante)
{/*
	long int coefAux = DarCoefTermino(listaT->info);
	int gradoAux = DarGradoTermino(listaT->info);
	Termino tAux;
	while (listaT != NULL)
	{
		if(DarGradoTermino(listaT->info) != -1)
		{
			coefAux  = DarCoefTermino(listaT->info);
			gradoAux = DarGradoTermino(listaT->info);
			marcoTerminoProcesado(listaT->info);
			ListaT = ListaT->Sig;
			while(DarGradoTermino(listaT->info) == gradoAux)
			{
				marcoTerminoProcesado(listaT->info);
				coefAux = coefAux + DarCoefTermino(listaT->info);
				listaT = listaT->Sig;
			}
			if(gradoAux == 0)
			{
				creoTermino(tAux,coefAux,gradoAux);
				listaTerminosInsertarOrdenado(listaResultante,tAux);
			}
			else
			{
				if(coefAux == 0)
				{
					creoTermino(tAux,coefAux,gradoAux);
					listaTerminosInsertarOrdenado(listaResultante,tAux);
				}
			}
		}
	}

    ListaTerminos aux;
    return aux;*/
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
