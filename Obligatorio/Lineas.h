#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED

#include "Linea.h"

typedef struct nodoA { Linea linea;
                nodoA * hIzq;
               nodoA * hDer;
            } NodoLineaABB;

typedef NodoLineaABB * Lineas;


/// Crea el ABB de lineas vacio
void MakeLineas(Lineas &l);

/// Retorna TRUE si en el ABB existe una linea con la clave especificada(codigoLinea)
boolean MemberLinea(Lineas l,String codigoLinea);

/// Inserta la linea en el ABB
void InsertLinea(Lineas &lineas, Linea l);
/*Precondición: La linea no existe en el ABB -> !MemberLinea(codigoLinea)*/


/// Retorna la linea con la clave especificada(codigoLinea)
Linea FindLinea(Lineas l, String codigoLinea);
///Precondición: La linea existe en el ABB -> MemberLinea(codigoLinea)


/// Sustituye la vieja linea en el ABB por la nueva recibida por parametro
void ModifyLinea(Lineas &l,Linea linea);
///Precondición: La linea a sustituir es miembro del ABB. -> Member(codigoLinea)

/// Listar los datos básicos de todas las líneas de la empresa (código, origen, destino y
/// cantidad de paradas), ordenados por código alfanumérico de menor a mayor.
void ListarLineas(Lineas l);

/// Retorna TRUE si el ABB es vacio
boolean lineasVacia(Lineas l);

#endif // LINEAS_H_INCLUDED
