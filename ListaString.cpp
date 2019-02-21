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
    boolean Primer = TRUE,Ultimo = FALSE;
  //  String auxStringLista;

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
                    //strdestruir(aux);
                    //aux = new char[MAX];
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
    strdestruir(aux);
}


int LargoListaString (ListaString L)
{
    if (L == NULL)
        return 0;
    else
        return 1 + LargoListaString(L ->Sig);
}

void MostrarListaString (ListaString L)
{
    printf(" - ");
    if (L != NULL)
    {
        print(L->info);
        MostrarListaString(L ->Sig);

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
    int i = 2;
    int largoLista = LargoListaString(L);
    L = L->Sig->Sig;

    while (todosEnteros && i < largoLista)
    {
        if (!esEntero(L -> info))
            todosEnteros = FALSE;
		else
            L = L->Sig;
            i++; /// ojo que esto sin querer esta fuera del else. Es lo que quieren?
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

