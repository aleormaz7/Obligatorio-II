#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 80;

typedef char * String;

///crea un string vacío (solo con el carácter ‘\0’)
void strcrear(String &s);

///   Libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(String &s);

///  Strlar devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del carácter nulo.
int strlar(String s);

///  Recibe dos strings y copia el segundo en el primero.
void strcop(String &s1, String s2);

///   Lee un string desde el teclado. Tomando en cuenta los primeros 79 caracteres
///   significativos en caso de que el largo del string sea mayor o igual a 80. Un string
///   finaliza cuando se lea un carácter ‘nueva línea’ el cual se sustituirá por uno nulo.
void scan(String &s);

///  Despliega un string por pantalla.
void print(String s);

///   Recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden
///   alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(String s1, String s2);

///   Recibe dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(String s1, String s2);

/// Retorna el resultado de sumar los valores de los caracteres
int SumaAscii(String nombreCiudad);

/// Pasa el String a mayusculas
void StringAMayusculas(String &s);

#endif // STRING_H_INCLUDED
