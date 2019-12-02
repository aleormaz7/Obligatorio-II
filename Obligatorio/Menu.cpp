#include "Menu.h"

void mostrarMenu(int &opcion)
{
    cout <<("\n\n********************");
    cout <<("\n** Menu principal **\n");
    cout <<("********************\n\n");
    cout <<("1. Altas y Modificacion de datos \n");
    cout <<("2. Listados y Consultas \n");
    cout <<("3. Salir del programa \n");
    cout <<("Opcion: ");
    cin.sync();
    String auxOpcion;
    auxOpcion.scan();
    while(!auxOpcion.esEntero())
    {
        cout << "\nOpcion invalida,ingrese nuevamente";
        cout <<("\nOpcion: ");
        auxOpcion.scan();
    }
    opcion = int(auxOpcion.convertirStringAEntero());
}

void mostrarSubMenuAltasyModificaciones(int &opcion)
{
    cout <<("\n\n***************************");
    cout <<("\n** Menu de Altas y modificacion de datos **\n");
    cout <<("***************************\n\n");
    cout <<("1. Alta de camionero \n");
    cout <<("2. Alta de camion \n");
    cout <<("3. Modificar viajes anuales de un camion \n");
    cout <<("4. Volver al menu principal \n");
    cout <<("Opcion: ");
    cin.sync();
    String auxOpcion;
    auxOpcion.scan();
    while(!auxOpcion.esEntero())
    {
        cout << "\nOpcion invalida,ingrese nuevamente";
        cout <<("\nOpcion: ");
        auxOpcion.scan();
    }
    opcion = int(auxOpcion.convertirStringAEntero());
}

void mostrarSubMenuListadosConsultas(int &opcion)
{
    cout <<("\n\n*******************");
    cout <<("\n** Menu Listados y Consultas **\n");
    cout <<("*******************\n\n");
    cout <<("1. Listado de camiones registrados\n");
    cout <<("2. Detalle de un camion\n");
    cout <<("3. Listado de camioneros registrados\n");
    cout <<("4. Cantidad de metros cubicos anuales de toda la flota\n");
    cout <<("5. Cantidad de camiones por tipo\n");
    cout <<("6. Datos camionero con mayor cantidad de tatuajes\n");
    cout <<("7. Cantidad de camiones grandes registrados, con fecha de adquisicion posterior\n");
    cout <<("8. Volver al menu principal \n");
    cout <<("Opcion: ");
    cin.sync();
    String auxOpcion;
    auxOpcion.scan();
    while(!auxOpcion.esEntero())
    {
        cout << "\nOpcion invalida,ingrese nuevamente";
        cout <<("\nOpcion: ");
        auxOpcion.scan();
    }
    opcion = int(auxOpcion.convertirStringAEntero());
}
