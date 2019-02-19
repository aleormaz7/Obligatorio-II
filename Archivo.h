#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "String.h"

///Determina si existe o no un archivo con el nombre recibido por par�metro
boolean ExisteArchivo(String nomArch);

///Determina si el archivo est� vac�o o no. Precondici�n: El archivo existe
boolean ArchivoEsVacio(String nomArch);

///Determina si el entero recibido est� en el archivo. Precondici�n: El archivo existe
boolean EnteroPertenecArchivo(String nomArch, int valor);


#endif // ARCHIVO_H_INCLUDED
