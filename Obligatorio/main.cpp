#include "Pruebas.h"
#include "Menu.h"
#include "Controlador.h"

#include "Fachada.h"

int main()
{
   // CamionerosPruebas();

    Fachada fachada;// = Fachada();

    ///Menu   PREGUNTAR: El Menu y Controlador lo hacemos con archivo o lo hacermos como una clase?
    int opc,opcAltasModif;
    do
    {
        mostrarMenu(opc);
        if(opc == 1)
        {
            do
            {
                mostrarSubMenuAltasyModificaciones(opcAltasModif);
                switch(opcAltasModif)
                {
                    case 1:
                        altaCamionero(fachada);
                        break;
                    case 2:
                        altaCamion(fachada);
                        break;
                    case 3:
                        modificarViajesAnuales(fachada);
                        break;
                    case 4:
                        break;
                    default:  cout << "\nOpcion invalida.\n";
                        break;
                }
            }while(opcAltasModif != 4);
        }
        else if(opc == 2)
        {
            do
            {
                mostrarSubMenuListadosConsultas(opc);
                switch(opc)
                {
                    case 1:
                        listadoCamiones(fachada);
                        break;
                    case 2:
                        detalleCamion(fachada);
                        break;
                    case 3:
                        listadoCamioneros(fachada);
                        break;
                    case 4:
                        totalMetrosCubicosAnuales(fachada);
                        break;
                    case 5:
                        obtenerCamionesPorTipo(fachada);
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    default:
                        cout << "\nOpcion invalida.\n";
                        break;
                }
            }while(opc != 8);
        }
    }while(opc != 3);

}





