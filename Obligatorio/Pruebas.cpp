#include "Pruebas.h"




void CamionerosPruebas()
{
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
    Camionero * c1 = new Camionero(cedula,nombre,cntT,fchNac);
    cout << "\nCamionero: ";
    cout << "\nCedula: " << c1->getCedula();
    cout << "\nNombre: ";
    c1->getNombre().print();
    cout << "\nCantidad Tatuajes: " << c1->getCantTatuajes();
    cout << "\nFecha Nacimiento: ";
    c1->getFechaNacimiento().MostrarFecha();
    ///--------------------------------------------------------------------------------------
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

    cin.clear();///
    cin.ignore(numeric_limits <streamsize>::max(), '\n' );///


    cout << "Ingrese Nombre del Camionero 2: ";
    nombre.scan();
    cntT = 4;
    fchNac = Fecha(22,11,2019);
    Camionero * c2 = new Camionero(cedula,nombre,cntT,fchNac);
    cout << "\nCamionero: ";
    cout << "\nCedula: " << c2->getCedula();
    cout << "\nNombre: ";
    c2->getNombre().print();
    cout << "\nCantidad Tatuajes: " << c2->getCantTatuajes();
    cout << "\nFecha Nacimiento: ";
    c2->getFechaNacimiento().MostrarFecha();
    ///-------------------------------------------------------------------------------------

    Camioneros diccioCamioneros = Camioneros();

    diccioCamioneros.Insert(c1);
    diccioCamioneros.Insert(c2);


    /*if(diccioCamioneros.Empty())
        cout << "\nEs vacio";
    else
        cout << "\nNo es vacio";
    */

    if(diccioCamioneros.Member(1))///
        cout << "\nExiste c1";
    else
        cout << "\nNo existe c1";

    if(diccioCamioneros.Member(2))///
        cout << "\nExiste c2";
    else
        cout << "\nNo existe c2";


    ///---------------------------------------------------------------------------
    ///ITERADOR:
    cout << "\n ITERADOR:" << endl;
    Iterador * iterador = new Iterador();
    iterador->insertarObjeto(c1);
    iterador->insertarObjeto(c2);

    while(iterador->hayMasObjetos())
    {
        Objeto * objAux = iterador->proximoObjeto();
        cout << "\nObjeto: ";
        cout << "\nTipo = ";
        String tipo = objAux->getTipo();
        tipo.print();

        Camionero * aux = (Camionero*) objAux;///casteo
        cout << "\nNom";
        aux->getNombre().print();
        cout << "\n";
    }
    ///---------------------------------------------------------------




}


