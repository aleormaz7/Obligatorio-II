#include "String.h"

void strcrear(String &s)
{
    s = new char[1];
    s[0] = '\0';

}

void strdestruir(String &s)
{
    delete[] s;
    s = NULL;
}


int strlar(String s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }

    return i;
}

void strcop(String &s1, String s2)
{
    int largo = strlar(s2);
    strdestruir(s1);
    s1 = new char[largo+1];
    int i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}



void scan(String &s)
{
    String aux;
    aux = new char[MAX];
    int i = 0;
    char c;
    fflush(stdin);
    scanf("%c",&c);
    while((c != '\n') && (i < MAX - 1))
    {
        aux[i] = c;
        i++;
        scanf("%c",&c);
    }
    aux[i] = '\0';

    strcop(s,aux);

    strdestruir(aux);
}

void print(String s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        printf("%c",s[i]);
        i++;
    }
}

boolean strmen(String s1, String s2)
{
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
        menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;

    return menor;
}

boolean streq(String s1, String s2)
{
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;

    return iguales;
}

boolean esEntero(String s)
{
	boolean entero = TRUE;
	int i = 0;
	while(s[i] != '\0' && entero)
    {
        if (s[i] < 48 || s[i] > 57)
            entero = FALSE;
        else
            i++;
    }
    return entero;
}


long int convertirStringAEntero(String s)
{
    int i = (strlar(s)-1),exponente = 0, largoString = strlar(s);
    long int EnteroResultante = 0;


    while (i >= 0)
    {
      switch(s[i])
      {
        case 49:
            if(i == largoString - 1)
                EnteroResultante = 1;
            else
                EnteroResultante = EnteroResultante + 1 * exponente;
            break;
        case 50:
            if(i == largoString - 1)
                EnteroResultante = 2;
            else
                EnteroResultante = EnteroResultante + 2 * exponente;
            break;
        case 51:
            if(i == largoString - 1)
                EnteroResultante = 3;
            else
                EnteroResultante = EnteroResultante + 3 * exponente;
            break;
        case 52:
            if(i == largoString - 1)
                EnteroResultante = 4;
            else
                EnteroResultante = EnteroResultante + 4 * exponente;
            break;
        case 53:
            if(i == largoString - 1)
                EnteroResultante = 5;
            else
                EnteroResultante = EnteroResultante + 5 * exponente;
            break;
        case 54:
            if(i == largoString - 1)
                EnteroResultante = 6;
            else
                EnteroResultante = EnteroResultante + 6 * exponente;
            break;
        case 55:
            if(i == largoString - 1)
                EnteroResultante = 7;
            else
                EnteroResultante = EnteroResultante + 7 * exponente;
            break;
        case 56:
            if(i == largoString - 1)
                EnteroResultante = 8;
            else
                EnteroResultante = EnteroResultante + 8 * exponente;
            break;
        case 57:
            if(i == largoString - 1)
                EnteroResultante = 9;
            else
                EnteroResultante = EnteroResultante + 9 * exponente;
            break;
      }

      if(exponente == 0)
        exponente = 10;
      else
        exponente = exponente * 10;
      i--;
    }
    return EnteroResultante;
}

boolean esAlfanumerico(String s)
{
	boolean alfanumerico = TRUE;
	int i = 0;
	while(s[i] != '\0' && alfanumerico)
    {
        if(s[i] < 48 || s[i] > 122)
            alfanumerico = FALSE;
        else
        {
            if(s[i] > 57 && s[i] < 65)
                alfanumerico = FALSE;
            else
                {
                    if(s[i] > 90 && s[i] < 97)
                        alfanumerico = FALSE;
                    else
                        i++;
                }
        }
    }
    return alfanumerico;
}

void retornaExtension(String s, String &sExtension)
{
    int i=0,j=0;
    String aux;
    aux = new char[MAX];
    boolean encontrePunto = FALSE;
  //  String auxStringLista;

    while(s[i] != '\0' && !encontrePunto)
    {
        if(s[i] == '.')
            encontrePunto = TRUE;
        else
            i++;
    }

    i++;

    while(s[i] != '\0')
    {
        aux[j] = s[i];
        i++;
        j++;
    }

    aux[j] = '\0';
    strcop(sExtension,aux);
    strdestruir(aux);
}

int cntPuntos(String s)
{
    int cntPuntos = 0,i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == '.')
            cntPuntos++;
        i++;
    }

    return cntPuntos;
}
