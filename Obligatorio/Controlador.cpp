#include "Controlador.h"


void altaCamionero(Fachada &f)
{
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

    tipoError error;
    f.AltaCamionero(c,error);

    if(error == SIN_ERROR)
    {
        cout << "\nCamionero Ingresado en el Sistema";
    }
    else
    {
        cout << "\nYa exise camionero con dicha cedula";
    }
}


void altaCamion()
{

}

void listadoCamioneros(Fachada f)
{
    Iterador iterador = Iterador();
    f.ListadoCamioneros(iterador);
    if (iterador.hayMasObjetos())
    {
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
    }
    else
        cout << "\nNo hay camioneros registrados en el sistema.";
}
