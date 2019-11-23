#include "Pruebas.h"
#include "String.h"

#include "Fachada.h"

int main()
{
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

    tipoError error1;
    Fachada fachada = Fachada();

    fachada.AltaCamionero(c,error1);
    fachada.AltaCamionero(c2,error1);

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
        cout << " - Cantidad de Tatuajes ";
        aux->getCantTatuajes();
        cout << " - Fecha Nacimineto ";
        aux->getFechaNacimiento().MostrarFecha();
        cout << "\n";
    }



}





