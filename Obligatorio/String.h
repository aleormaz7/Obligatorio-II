#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 80;

typedef char * String;

///a) strcrear crea un string vacío (solo con el carácter ‘\0’)
void strcrear(String &s);

///b) strdestruir libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(String &s);

///c) strlar devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del carácter nulo.
int strlar(String s);

///d) strcop recibe dos strings y copia el segundo en el primero.
void strcop(String &s1, String s2);

///e) scan lee un string desde el teclado. Se tomarán en cuenta los primeros 79 caracteres
///   significativos en caso de que el largo del string sea mayor o igual a 80. Un string
///   finaliza cuando se lea un carácter ‘nueva línea’ el cual se sustituirá por uno nulo.
void scan(String &s);

///f) strcon recibe dos strings y concatena el segundo string al final del primero, la concatenación
///   deberá quedar sobre el primero de los dos. En caso de que el largo de los strings
///   exceda los 79 caracteres, no se tomarán los caracteres excedentes del segundo string.
void strcon(String &s1, String s2);

///g) strswp recibe dos strings y devuelve el primero en el segundo y viceversa.
void strswp(String &s1, String &s2);

///h) print despliega un string por pantalla.
void print(String s);

///i) strmen recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden
///   alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(String s1, String s2);

///j) streq reciba dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(String s1, String s2);


#endif // STRING_H_INCLUDED
