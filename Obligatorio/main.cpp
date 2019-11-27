#include "Pruebas.h"
#include "Menu.h"
#include "Controlador.h"

#include "Fachada.h"

int main()
{
    Fachada fachada = Fachada();
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
                        break;
                    case 2:
                        detalleCamion(fachada);
                        break;
                    case 3:
                        listadoCamioneros(fachada);
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    default: cout << "\nOpcion invalida.\n";
                        break;
                }
            }while(opc != 8);
        }
    }while(opc != 3);



/*
    ///------------------------------------------------------------------
    ///CAMION:
    String mat,mar;
    int cantViajes;

    int opcion = 3;///

    if(opcion == 1)
    {

        ///------------------------------------------------------------------

        cout << "Ingrese Matricula del Camion: ";
        mat.scan();
        cout << "Ingrese Marca del Camion: ";
        mar.scan();
        cout << "Ingrese Cant viajes anuales del Camion: ";
        cin >> cantViajes;
        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        cout << "Ingrese Cedula del Camionero: ";
        cin >> cedula;
        if(!cin.fail())
            cout << cedula << endl;
        else
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n' );
            cout << "Ingreso invalido, debe ingresar solo numeros" << endl;
        }

        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///
        String depto;
        cout << "Ingrese Departamento del Camion Simple: ";
        depto.scan();

        ///-------------------------------------------------------------------------
        //cin.clear();///
        //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///
        //cedula = 1;

        Camion * auxSimple1 = new CamionSimple(mat,mar,cantViajes,depto);

        fachada.AltaCamion(auxSimple1,cedula,error1);

        if(error1 == SIN_ERROR)
        {
            cout << "\nCamion ingresado en el Sistema";
        }
        else
        {
            cout << "\nYa exise camion con dicha matricula";
        }


        ///------------------------------------------------------------------
        //cin.clear();///
        //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///


        cout << "Ingrese Matricula del Camion: ";
        mat.scan();
        cout << "Ingrese Marca del Camion: ";
        mar.scan();
        cout << "Ingrese Cant viajes anuales del Camion: ";
        cin >> cantViajes;
        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        cout << "Ingrese Cedula del Camionero 2: ";
        cin >> cedula;
        if(!cin.fail())
            cout << cedula << endl;
        else
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n' );
            cout << "Ingreso invalido, debe ingresar solo numeros" << endl;
        }

        cout << "Ingrese Departamento del Camion Simple: ";
        depto.scan();
        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        ///-------------------------------------------------------------------------
        Camion * auxSimple2 = new CamionSimple(mat,mar,cantViajes,depto);
        //cedula = 2;

        fachada.AltaCamion(auxSimple2,cedula,error1);

        if(error1 == SIN_ERROR)
        {
            cout << "\nCamion ingresado en el Sistema";
        }
        else
        {
            cout << "\nYa exise camion con dicha matricula";
        }
    }
    else if(opcion == 2)
    {

        ///CAMION GRANDE
        cout << "Ingrese Matricula del Camion: ";
        mat.scan();
        cout << "Ingrese Marca del Camion: ";
        mar.scan();
        cout << "Ingrese Cant viajes anuales del Camion: ";
        cin >> cantViajes;
        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        cout << "Ingrese Cedula del Camionero: ";
        cin >> cedula;
        if(!cin.fail())
            cout << cedula << endl;
        else
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n' );
            cout << "Ingreso invalido, debe ingresar solo numeros" << endl;
        }

        ///-------------------------------------------------------------------------
        float vol = 50;///pedir volumen
        Fecha fchAdq = Fecha(26,11,2019);///pedir fecha
        ///TODO: CargarFecha() hacer...........
        Camion * auxGrande1 = new CamionGrande(mat,mar,cantViajes,vol,fchAdq);
        fachada.AltaCamion(auxGrande1,cedula,error1);

        if(error1 == SIN_ERROR)
        {
            cout << "\nCamion Grnade ingresado en el Sistema";
        }
        else
        {
            cout << "\nYa exise camion con dicha matricula";
        }
    }
    else if(opcion == 3)
    {

         ///CAMION Remolque
        cout << "Ingrese Matricula del Camion: ";
        mat.scan();
        cout << "Ingrese Marca del Camion: ";
        mar.scan();
        cout << "Ingrese Cant viajes anuales del Camion: ";
        cin >> cantViajes;
        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        cout << "Ingrese Cedula del Camionero: ";
        cin >> cedula;
        if(!cin.fail())
            cout << cedula << endl;
        else
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n' );
            cout << "Ingreso invalido, debe ingresar solo numeros" << endl;
        }

        ///-------------------------------------------------------------------------
        float vol = 50;///pedir volumen
        Fecha fchAdq = Fecha(26,11,2019);///pedir fecha
        float capacidad = 10;///pedir capacidad
        Camion * auxRemolque1 = new CamionConRemolque(mat,mar,cantViajes,vol,fchAdq,capacidad);
        fachada.AltaCamion(auxRemolque1,cedula,error1);

        if(error1 == SIN_ERROR)
        {
            cout << "\nCamion Con Remolque ingresado en el Sistema";
        }
        else
        {
            cout << "\nYa exise camion con dicha matricula";
        }
    }
*/
}





