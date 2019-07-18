#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED

#include "Linea.h"

typedef struct nodoA { Linea linea;
                nodoA * hIzq;
               nodoA * hDer;
            } NodoLineaABB;

typedef NodoLineaABB * Lineas;

void MakeLineas(Lineas &l);

boolean MemberLinea(Lineas l,String codigoLinea); //Determina si en el diccionario existe un elemento con la clave especificada

//4. Ingresar una nueva l�nea a la empresa, chequeando que no existiera previamente otra
//   l�nea con el mismo c�digo alfanum�rico.
void InsertLinea(Lineas &lineas, Linea l); /*Precondici�n: que no exista previamente codigoalfanumerico*/

Linea FindLinea(Lineas l, String codigoLinea); //Precondici�n: el elemento es miembro del diccionario.

//5. Listar los datos b�sicos de todas las l�neas de la empresa (c�digo, origen, destino y
//    cantidad de paradas), ordenados por c�digo alfanum�rico de menor a mayor.
void ListarLineas(Lineas l);


#endif // LINEAS_H_INCLUDED
