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

//4. Ingresar una nueva línea a la empresa, chequeando que no existiera previamente otra
//   línea con el mismo código alfanumérico.
void Insert(Lineas &lineas, Linea l); /*Precondición: que no exista previamente codigoalfanumerico*/

Linea Find(Lineas l, String codigoalfa); //Precondición: el elemento es miembro del diccionario.

//5. Listar los datos básicos de todas las líneas de la empresa (código, origen, destino y
//    cantidad de paradas), ordenados por código alfanumérico de menor a mayor.
void ListarLineas(Lineas l);


#endif // LINEAS_H_INCLUDED
