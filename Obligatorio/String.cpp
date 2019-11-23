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
    cout << "\nIngrese una cadena de caracteres: " << endl;
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
