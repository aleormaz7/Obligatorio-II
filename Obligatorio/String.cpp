#include "String.h"

String :: String ()
{
    cadena = new char[1];
    cadena[0] = '\0';
}

String :: String (char * cad)
{
    int largo = strlen(cad); // cantidad de caracteres de la cadena
    cadena = new char[largo + 1]; // un lugar mas para el '\0'.
    strcpy(cadena, cad); // se copian los caracteres de la cadena
}

String :: String (const String &copia)
{
    int largo = strlen(copia.cadena); // cantidad de caracteres de la cadena
    cadena = new char[largo + 1]; // un lugar mas para el '\0'.
    strcpy(cadena, copia.cadena); // se copian los caracteres de la cadena
}

String :: ~String()
{
    delete[] cadena;
}

String String :: operator=(const String &otro)
{
    if (this != &otro)
    {
        delete [] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char [largo + 1];
        strcpy (cadena, otro.cadena);
    }
    return (*this);
}



int String :: operator==(String aux)
{
    return (strcmp(cadena,aux.cadena) == 0);
}

int String :: operator!=(String aux)
{
    return (strcmp(cadena,aux.cadena) != 0);
}

bool String :: operator<(String aux)
{
    int x,y;
    y = strncmp(cadena,aux.cadena,x);
    if(y < 0)
        return true;
    else
        return false;

}

String String :: operator+(String aux)
{
    strcat(cadena,aux.cadena);
    return (*this);
}

void String :: scan()
{
    int i = 0;
    char c;
    //cout << "\nIngrese una cadena de caracteres: " << endl;
    c = cin.get();
    while((c != '\n') && (i < MAX - 1))
    {
        cadena[i] = c;
        i++;
        c = cin.get();
    }
    cadena[i] = '\0';
}

void String :: print()
{
    int i = 0;
    while(cadena[i] !='\0')
    {
        cout << cadena[i];
        i++;
    }
}

int String :: SumaAscii(String matricula)
{
    int i = 0;
    int suma = 0;
    while(matricula.cadena[i] != '\0')
    {
        suma = suma + matricula.cadena[i];
        i++;
    }
    return suma;
}

bool String :: esEntero()
{
	bool entero = true;
	int i = 0;
	while(cadena[i] != '\0' && entero)
    {
        if (cadena[i] < 48 || cadena[i] > 57)
        {
            if(i == 0 && strlen(cadena) > 1 && cadena[i] == 45) ///considero el valor negativo
                i++;
            else
                entero = false;
        }
        else
            i++;
    }
    return entero;
}

long String :: convertirStringAEntero()
{
    int i = (strlen(cadena)-1);
    int exponente = 0;
    int largoString = strlen(cadena);
    long EnteroResultante = 0;

    while (i >= 0)
    {
      switch(cadena[i])
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
        case 45:
                EnteroResultante = EnteroResultante * -1;
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

int String :: largo()
{
    return strlen(cadena);
}
