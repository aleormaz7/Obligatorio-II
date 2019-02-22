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
            for(i = 1; i <= DarGradoTermino(listaT->info);i++)  /// ojo, deberia ser menor o menor/igual en vez de igual
                resultado = resultado * valor;                  /// ojo, deberia ser resultado = valor * resultado;
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
    while(listaA != NULL || listaB != NULL)     /// meditar... es || o es &&?
    {                                           /// SI, pero NO con el comentario, Si quedaba como estaba daba problemas cuando uno de los polinomios no tenia termi independiente.
        Termino terminoAux;                     /// para eso se agrego una correccion al recorrer la lista
        if(listaA == NULL)
        {
            if(DarGradoTermino(listaB->info) == 0)
               {
                    CrearTermino(terminoAux,((DarCoefTermino(listaB->info))),0);
                    listaTerminosInsertarOrdenado(listaResultado,terminoAux);
               }
               else
               {
                   if((DarCoefTermino(listaB->info))!= 0)
                      {
                        CrearTermino(terminoAux,((DarCoefTermino(listaB->info) )),DarGradoTermino(listaB->info));
                        listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                      }
               }
            listaB = listaB->Sig;
        }
        else
        {
            if(listaB == NULL)
            {
                if(DarGradoTermino(listaA->info) == 0)
                {
                    CrearTermino(terminoAux,((DarCoefTermino(listaA->info))),0);
                    listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                }
                else
                {
                   if((DarCoefTermino(listaA->info))!= 0)
                    {
                        CrearTermino(terminoAux,((DarCoefTermino(listaA->info) )),DarGradoTermino(listaA->info));
                        listaTerminosInsertarOrdenado(listaResultado,terminoAux);
                    }
                }
                listaA = listaA->Sig;
            }
            else
            {
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

    }
    /// una vez hecha la suma, verificar si tiene grado mayor a 0 y termino independiente igual a 0
    /// en caso de tenerlo, ir hasta el final y elimnarlo
    /// la idea es que no queden terminos independientes nulos cuando no es el polinomio nulo
}

boolean representaPolinomioNulo(ListaTerminos listaT)
{
    boolean esNulo = FALSE;
	if (DarGradoTermino(listaT->info) == 0 && DarCoefTermino(listaT->info) == 0)
		boolean esNulo = TRUE;
    return esNulo;
}

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResuladoFinal)
{
	Termino tAux;
	ListaTerminos listaResultadoAux,ListaBAux;
	listaTerminosCrear(listaResultadoAux);


	if(representaPolinomioNulo(listaA) || representaPolinomioNulo(listaB))
	{
		CrearTermino(tAux,0,0);
		listaTerminosInsertarOrdenado(listaResultadoAux,tAux);
	}
	else
	{
		while(listaA != NULL)
		{
		    ListaBAux = listaB;
			while(ListaBAux != NULL)
			{
				CrearTermino(tAux,(DarCoefTermino(listaA->info) * DarCoefTermino(ListaBAux->info)),(DarGradoTermino(listaA->info) + DarGradoTermino(ListaBAux->info)));
				listaTerminosInsertarOrdenado(listaResultadoAux,tAux);
				ListaBAux = ListaBAux->Sig;
			}
			listaA = listaA->Sig;
		}
        reduceListaTerminos(listaResultadoAux,listaResuladoFinal);
        destuirListaTerminos(listaResultadoAux);
	}

    /// una vez hecha la multiplicacion, verificar si tiene grado mayor a 0 y termino independiente igual a 0
    /// en caso de tenerlo, ir hasta el final y elimnarlo
    /// la idea es que no queden terminos independientes nulos cuando no es el polinomio nulo
}


void reduceListaTerminos(ListaTerminos listaT, ListaTerminos &listaResultante)
{
	long int coefAux = 0;
	int gradoAux 	 = 0;
	Termino tAux;
	while (listaT->Sig != NULL) /// seguro que listaT no viene vacia??? reflexionar
	{
		coefAux  = coefAux  + DarCoefTermino(listaT->info);
		gradoAux = DarGradoTermino(listaT->info);
		if(DarGradoTermino(listaT->info) != DarGradoTermino(listaT->Sig->info))
		{
			if(gradoAux == 0)
			{
				CrearTermino(tAux,coefAux,0);
				listaTerminosInsertarOrdenado(listaResultante,tAux);
			}
			else
			{
				if(coefAux != 0)
				{
					CrearTermino(tAux,coefAux,gradoAux);
					listaTerminosInsertarOrdenado(listaResultante,tAux);
				}
			}
			coefAux  = 0;
		}
		listaT = listaT->Sig;
    }
	CrearTermino(tAux,(coefAux + DarCoefTermino(listaT->info)),0);
	listaTerminosInsertarOrdenado(listaResultante,tAux);
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

void destuirListaTerminos(ListaTerminos L) /// no deberia ir L por referencia???
{
    if(L -> Sig == NULL)
    {
        delete L;
    }
    else
    {
        destuirListaTerminos(L->Sig);
        delete L;
    }

}

void controlTerminoIndependienteNoNulo(ListaTerminos &L)
{
    /// Verificar si tiene grado mayor a 0 y termino independiente igual a 0
    /// en caso de tenerlo, ir hasta el final y elimnarlo
    /// la idea es que no queden terminos independientes nulos cuando no es el polinomio nulo
    if(DarCoefTermino(L->info) > 0)
    {
         ListaTerminos LAux = L;
         while(LAux->Sig != NULL)
         {
             LAux = LAux->Sig;
         }
         if(DarCoefTermino(LAux->info) == 0 && DarGradoTermino(LAux->info) == 0)
            delete LAux;
    }
}
/*
void levantarTerminos(file * f, ListaTerminos &listaT)
{

}

void bajarTerminos(file * f, ListaTerminos listaTerminos);
*/
