#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 80;
typedef char * String;

/// strcrear crea un string vac�o (solo con el car�cter �\0�)
void strcrear(String &s);

/// strdestruir libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(String &s);

/// strlar devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del car�cter nulo.
int strlar(String s);

/// strcop recibe dos strings y copia el segundo en el primero.
void strcop(String &s1, String s2);

/// scan lee un string desde el teclado. Se tomar�n en cuenta los primeros 79 caracteres
///   significativos en caso de que el largo del string sea mayor o igual a 80. Un string
///   finaliza cuando se lea un car�cter �nueva l�nea� el cual se sustituir� por uno nulo.
void scan(String &s);

/// strcon recibe dos strings y concatena el segundo string al final del primero, la concatenaci�n
///   deber� quedar sobre el primero de los dos. En caso de que el largo de los strings
///   exceda los 79 caracteres, no se tomar�n los caracteres excedentes del segundo string.
void strcon(String &s1, String s2);

/// strswp recibe dos strings y devuelve el primero en el segundo y viceversa.
void strswp(String &s1, String &s2);

/// print despliega un string por pantalla.
void print(String s);

/// strmen recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden
///   alfab�tico) que el segundo, o FALSE en caso contrario.
boolean strmen(String s1, String s2);

///streq reciba dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(String s1, String s2);

void Bajar_String (String s, FILE * f);
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondici�n: El archivo viene abierto para escritura.

void Levantar_String (String &s, FILE * f);
// Lee desde el archivo los caracteres del string s.
// Precondici�n: El archivo viene abierto para lectura.


#endif // STRING_H_INCLUDED
