#include "Menu.h"


void mostrarMenu(int &opcion)
{
    printf("\n\n********************");
    printf("\n** Menu principal **\n");
    printf("********************\n\n");
    printf("1. Altas y Bajas \n");
    printf("2. Listados \n");
    printf("3. Consultas \n");
    printf("4. Salir del programa \n");
    printf("Opcion: ");
    scanf("%d",&opcion);
}

void mostrarSubMenuAltasyBajas(int &opcion)
{
    printf("\n\n***************************");
    printf("\n** Menu de Altas y Bajas **\n");
    printf("***************************\n\n");
    printf("1. Alta Expediente \n");
    printf("2. Alta Revision \n");
    printf("3. Baja de expediente por codigo \n");
    printf("4. Volver al menu principal \n");
    printf("Opcion: ");
    scanf("%d",&opcion);
}


void mostrarSubMenuListados(int &opcion)
{
    printf("\n\n*******************");
    printf("\n** Menu Listados **\n");
    printf("*******************\n\n");
    printf("1. Listar expedientes ordenados por su codigo\n");
    printf("2. Listar revisiones cronologicamnete \n");
    printf("3. Lista datos de los expedientes con mayor y menor codigo \n");
    printf("4. Lista revisiones de un expediente \n");
    printf("5. Volver al menu principal \n");
    printf("Opcion: ");
    scanf("%d",&opcion);
}

void mostrarSubMenuConsultas(int &opcion)
{
    printf("\n\n********************");
    printf("\n** Menu Consultas **\n");
    printf("\********************\n");
    printf("1. Cantidad expediente por apellido de escribano \n");
    printf("2. Codigo del expediente con mayor cantidad revisiones \n");
    printf("3. Cantidad de revisiones entre fechas \n");
    printf("4. Cantidad de revisiones de cada tipo \n");
    printf("5. Volver al menu principal \n");
    printf("Opcion: ");
    scanf("%d",&opcion);
}

