#include "ListaString.h"

void CrearListaString(ListaString &L)
{
    L = NULL;
}

void InsBackListaString(ListaString &L, String s)
{
    if(L == NULL)
    {
        L = new nodoS;
        L->info = s;
        L->Sig = NULL;
    }
    else
    {
        InsBackListaString(L->Sig,s);
    }
}

void partirString(String s, ListaString &ls)
{
    int i=0,j=0;
    String aux;
    aux = new char[MAX];
    boolean Primer = TRUE;

    while(s[i] != '\0')
    {
        if(s[i] != ' ')
        {
            Primer = FALSE;
            aux[j] = s[i];
            i++;
            j++;
        }
        else
        {
            while(s[i+1] == ' ')
            {
                i++;
            }
            if(Primer)
            {
                i++;
            }
            else
            {
                if(s[i+1] != '\0')
                {
                    aux[j] = '\0';
                    String auxStringLista;
                    auxStringLista = new char[MAX];
                    strcop(auxStringLista,aux);
                    InsBackListaString(ls,auxStringLista);
                    i++;
                    j=0;
                }else{i++;}
            }
        }
    }

    aux[j] = '\0';
    String auxStringLista;
    auxStringLista = new char[MAX];
    strcop(auxStringLista,aux);
    InsBackListaString(ls,auxStringLista);
    llevoAMinusculas(ls->info);
    strdestruir(aux);
}

int LargoListaString (ListaString L)
{
    if (L == NULL)
        return 0;
    else
    {
         return 1 + LargoListaString(L ->Sig);
    }

}

void destruirListaString(ListaString &L)
{
    if(L -> Sig == NULL)
    {
        strdestruir(L->info);
        delete L;
    }
    else
    {
        destruirListaString(L->Sig);
        strdestruir(L->info);
        delete L;
    }
}

boolean CoeficientesEnteros(ListaString L)
{
    boolean todosEnteros = TRUE;
    int i = 1;
    int largoLista = LargoListaString(L);

    while ((todosEnteros && i <= largoLista) && L != NULL)
    {
        if (!esEntero(L -> info))
            todosEnteros = FALSE;
		else
            L = L->Sig;
        i++;
    }
    return todosEnteros;
}

void obtenerString(ListaString L, int pos, String &s)
{
    int i = 0;
    while(i < pos)
    {
        i++;
        L = L->Sig;
    }
    strcop(s,L->info);
}

void ListaStringAListaTerminos(ListaString ls, ListaTerminos &Lst)
{
    int largo = LargoListaString(ls);
    Termino auxT;
    ///Inicializo Grado
    int grado = largo - 1;

    if(largo == 1)
    {
        ///Paso 1er String a entero
        int coef1 = convertirStringAEntero(ls->info);

        ///si el coef del termino independiente no es cero inserto termino en polinomio
        if(coef1 != 0)
        {
            CrearTermino(auxT,coef1,0);
            listaTerminosInsertarOrdenado(Lst,auxT);
        }
        else
        {
            ///Si coef es 0 creo termino nulo(0,0)
            CrearTermino(auxT,0,0);
            listaTerminosInsertarOrdenado(Lst,auxT);
        }
    }
    else
    {
        ///PARA CADA NodoLista en Lista String
        while(ls != NULL)
        {
            int coefAux = convertirStringAEntero(ls->info);
            if(coefAux != 0)
            {
                CrearTermino(auxT,coefAux,grado);
                listaTerminosInsertarOrdenado(Lst,auxT);
            }
            ls = ls->Sig;
            grado--;
        }
    }
}

void ListaStringAvanza(ListaString ls, ListaString &lsSoloTerminos)
{
    lsSoloTerminos = ls->Sig->Sig;
}
