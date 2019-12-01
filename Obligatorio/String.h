#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <string.h>

#include <iostream>
using namespace std;

const int MAX = 80;

class String
{
    private:
        char * cadena;
    public:
        String(); ///Constructor por defecto
        String(char *); ///Constructor común
        String (const String &);///Construcor de copia
        ~String(); /// Destructor
        String operator=(const String &);///Asignacion
        int operator==(String);///Iguales
        int operator!=(String);///No Iguales
        bool operator<(String);///Menor
        String operator+(String);///Concatenar
        void scan();///Leer
        void print();///Mostrar
        int SumaAscii(String matricula);
        bool esEntero();
        long convertirStringAEntero();
        int largo();
};


#endif // STRING_H_INCLUDED
