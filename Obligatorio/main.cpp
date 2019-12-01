#include "Pruebas.h"
#include "Menu.h"
#include "Controlador.h"

#include "Fachada.h"

int main()
{

    Controlador c;


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
                        c.altaCamionero();
                        break;
                    case 2:
                        c.altaCamion();
                        break;
                    case 3:
                        c.modificarViajesAnuales();
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
                        c.listadoCamiones();
                        break;
                    case 2:
                        c.detalleCamion();
                        break;
                    case 3:
                        c.listadoCamioneros();
                        break;
                    case 4:
                        c.totalMetrosCubicosAnuales();
                        break;
                    case 5:
                        c.obtenerCamionesPorTipo();
                        break;
                    case 6:
                        c.camioneroConMayorCntTatuajes();
                        break;
                    case 7:
                        c.cantidadCamionesGrandesFechaAdq();
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





