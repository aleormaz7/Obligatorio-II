#include "String.h"

void MostrarString(String s)
{
    int i = 0;
    while(s[i] !='\0')
    {
        printf("%c",s[i]);
        i++;
    }
}

void CargarString(String &s)
{
    int i = 0;
    char c;
    fflush(stdin);
    scanf("%c",&c);
    while((c != '\n') && (i < MAX - 1))
    {
        s[i] = c;
        i++;
        scanf("%c",&c);
    }
    s[i] = '\0';
}


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
    int i = 0;
    int largo = strlar(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
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
    //printf("Ingrese una cadena de caracteres: ");
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

void strcon(String &s1, String s2)
{
    String aux;
    aux = new char[MAX];

    int largoS1 = strlar(s1);
    int largoS2 = strlar(s2);
    //int largoTotal = largoS1 + largoS2 + 1;

    int i = 0, j = 0;
    while(i < largoS1)
    {
        aux[i] = s1[i];
        i++;
    }
    while(j < largoS2)
    {
        aux[i] = s2[j];
        i++;
        j++;
    }

    strdestruir(s1);
    strcop(s1,aux);
}

void strswp(String &s1, String &s2)
{
    String aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
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

int SumaAscii(String nombreCiudad)
{
    int i = 0;
    int suma = 0;
    while(nombreCiudad[i] != '\0')
    {
        suma = suma + nombreCiudad[i];
        i++;
    }
    return suma;
}
