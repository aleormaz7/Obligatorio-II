#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 80;
typedef char * String;

/// strcrear crea un string vacío (solo con el carácter ‘\0’)
void strcrear(String &s);

/// strdestruir libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(String &s);

/// strlar devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del carácter nulo.
int strlar(String s);

/// strcop recibe dos strings y copia el segundo en el primero.
void strcop(String &s1, String s2);

/// scan lee un string desde el teclado. Se tomarán en cuenta los primeros 79 caracteres
///   significativos en caso de que el largo del string sea mayor o igual a 80. Un string
///   finaliza cuando se lea un carácter ‘nueva línea’ el cual se sustituirá por uno nulo.
void scan(String &s);

/// print despliega un string por pantalla.
void print(String s);

/// strmen recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden
/// alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(String s1, String s2);

///streq reciba dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(String s1, String s2);

///Retorna True si el String representa un valor numerico entero
boolean esEntero(String s);

///Retorna True si todos los caracteres del String son alfanumericos
boolean esAlfanumerico(String s);
/*Precondicion: largo Sting > 0*/

///Retorna el valor numeroco entero, representado por el String
long int convertirStringAEntero(String s);
/* Precondición largo String > 0  && esEntero(s) == TRUE*/

///Dado un String que es el nombre de un archivo, retorna el nombre y la extension del mismo
void retornaExtensionNombre(String s,  String &sNombre, String &sExtension);
/* Precondición: cntPuntos(s) ==  1*/

///Retorna la cantidad de puntos en el String
int cntPuntos(String s);

///Pasa el contenido del String a minusculas, los caracteres que no se corresponden con Letras quedan iguales
void llevoAMinusculas(String &s);

#endif // STRING_H_INCLUDED
