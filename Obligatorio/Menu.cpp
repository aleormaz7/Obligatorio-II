#include "Menu.h"
#include "String.h"

void mostrarMenu(int &opcion)
{
    cout <<("\n\n********************");
    cout <<("\n** Menu principal **\n");
    cout <<("********************\n\n");
    cout <<("1. Altas y Modificacion de datos \n");
    cout <<("2. Listados y Consultas \n");
    cout <<("3. Salir del programa \n");
    cout <<("Opcion: ");
    scanf("%d",&opcion);
}

void mostrarSubMenuAltasyBajas(int &opcion)
{
    printf("\n\n***************************");
    printf("\n** Menu de Altas y modificacion de datos **\n");
    printf("***************************\n\n");
    printf("1. Alta de camionero \n");
    printf("2. Alta de camion \n");
    printf("3. Modificar viajes anuales de un camion \n");
    printf("4. Volver al menu principal \n");
    printf("Opcion: ");
    scanf("%d",&opcion);
}


void mostrarSubMenuListados(int &opcion)
{
    printf("\n\n*******************");
    printf("\n** Menu Listados y Consultas **\n");
    printf("*******************\n\n");
    printf("1. Listado de camiones registrados\n");
    printf("2. Detalle de un camion\n");
    printf("3. Listado de camioneros registrados\n");
    printf("4. Cantidad de metros cubicos anuales de toda la flota\n");
    printf("5. Cantidad de camiones por tipo\n");
    printf("6. Datos camionero con mayor cantidad de tatuajes\n");
    printf("7. Cantidad de camiones grandes registrados, con fecha de adquisicion posterior\n");
    printf("8. Volver al menu principal \n");
    printf("Opcion: ");
    scanf("%d",&opcion);
}
