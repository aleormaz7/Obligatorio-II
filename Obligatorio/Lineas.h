#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED

#include "Linea.h"

typedef struct nodoA { Linea linea;
                nodoA * hIzq;
               nodoA * hDer;
            } NodoLineaABB;

typedef NodoLineaABB * Lineas;

void Make(Lineas &l);

boolean Member(Lineas l,int codigo); //Determina si en el diccionario existe un elemento con la clave especificada

//4. Ingresar una nueva l�nea a la empresa, chequeando que no existiera previamente otra
//   l�nea con el mismo c�digo alfanum�rico.
void Insert(Lineas &lineas, Linea l); /*Precondici�n: que no exista previamente codigoalfanumerico*/

Linea Find(Lineas l, String codigoalfa); //Precondici�n: el elemento es miembro del diccionario.

//5. Listar los datos b�sicos de todas las l�neas de la empresa (c�digo, origen, destino y
//    cantidad de paradas), ordenados por c�digo alfanum�rico de menor a mayor.
void ListarLineas(Lineas l);


#endif // LINEAS_H_INCLUDED
