#include "Pruebas.h"
#include "Menu.h"

#include "Fachada.h"

int main()
{


    int opc;
    mostrarMenu(opc);

    //CamioneroPruebas();

    //CamionerosPruebas();


    ///-----------------------------------------------------------------------
    ///CAMIONERO
    //long cedula = 48136851;
    cout << "Ingrese Cedula del Camionero: ";
    int cedula;
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

    String nombre;
    cout << "Ingrese Nombre del Camionero: ";
    nombre.scan();
    int cntT = 2;
    Fecha fchNac = Fecha(20,11,2019);
    Camionero * c = new Camionero(cedula,nombre,cntT,fchNac);
    cout << "\nCamionero: ";
    cout << "\nCedula: " << c->getCedula();
    cout << "\nNombre: ";
    c->getNombre().print();
    cout << "\nCantidad Tatuajes: " << c->getCantTatuajes();
    cout << "\nFecha Nacimiento: ";
    c->getFechaNacimiento().MostrarFecha();
    ///--------------------------------------------------------
    ///-----------------------------------------------------------------------
    ///CAMIONERO
    //long cedula = 48136851;
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

    cout << "Ingrese Nombre del Camionero: ";
    nombre.scan();
    cntT = 4;
    fchNac = Fecha(23,11,2019);
    Camionero * c2 = new Camionero(cedula,nombre,cntT,fchNac);
    cout << "\nCamionero: ";
    cout << "\nCedula: " << c2->getCedula();
    cout << "\nNombre: ";
    c2->getNombre().print();
    cout << "\nCantidad Tatuajes: " << c2->getCantTatuajes();
    cout << "\nFecha Nacimiento: ";
    c2->getFechaNacimiento().MostrarFecha();
    ///--------------------------------------------------------
     ///-----------------------------------------------------------------------
    ///CAMIONERO
    //long cedula = 48136851;
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

    cout << "Ingrese Nombre del Camionero: ";
    nombre.scan();
    cntT = 6;
    fchNac = Fecha(26,11,2019);
    Camionero * c3 = new Camionero(cedula,nombre,cntT,fchNac);
    cout << "\nCamionero: ";
    cout << "\nCedula: " << c3->getCedula();
    cout << "\nNombre: ";
    c3->getNombre().print();
    cout << "\nCantidad Tatuajes: " << c3->getCantTatuajes();
    cout << "\nFecha Nacimiento: ";
    c3->getFechaNacimiento().MostrarFecha();
    ///--------------------------------------------------------



    tipoError error1;
    Fachada fachada = Fachada();

    fachada.AltaCamionero(c,error1);
    fachada.AltaCamionero(c2,error1);
    fachada.AltaCamionero(c3,error1);

    if(error1 == SIN_ERROR)
    {
        cout << "\nCamionero Ingresado en el Sistema";
    }
    else
    {
         cout << "\nYa exise camionero con dicha cedula";
    }

    Iterador iterador = Iterador();

    fachada.ListadoCamioneros(iterador);

    while(iterador.hayMasObjetos())
    {
        Objeto * objAux = iterador.proximoObjeto();
        Camionero * aux = (Camionero*) objAux;///casteo
        cout << "\nCedula ";
        cout << aux->getCedula();
        cout << " - Nombre ";
        aux->getNombre().print();
        cout << " - Cantidad de Tatuajes " << aux->getCantTatuajes();
        cout << " - Fecha Nacimineto ";
        aux->getFechaNacimiento().MostrarFecha();
        cout << "\n";
    }


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






}





