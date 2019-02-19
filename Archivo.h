#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "String.h"

///Determina si existe o no un archivo con el nombre recibido por parámetro
boolean ExisteArchivo(String nomArch);

///Determina si el archivo está vacío o no. Precondición: El archivo existe
boolean ArchivoEsVacio(String nomArch);

///Determina si el entero recibido está en el archivo. Precondición: El archivo existe
boolean EnteroPertenecArchivo(String nomArch, int valor);


#endif // ARCHIVO_H_INCLUDED
