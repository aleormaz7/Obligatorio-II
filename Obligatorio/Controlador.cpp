#include "Controlador.h"


void altaCamionero(Fachada &f)
{
    cout << "\nIngrese datos del camionero: ";
    cout << "\nCedula: ";
    int cedula;
    cin >> cedula;
    if(!cin.fail())
    {
        //cout << cedula << endl;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );
        cout << "\nIngreso invalido, debe ingresar solo numeros" << endl;
    }

    ///TODO: funciona si se ingresa letras primero(ahi falla y no deja ingresar), pero al reves no
    /*bool fallo = true;
    while(fallo)
    {
        cout << "\nCedula: ";
        cin >> cedula;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n' );
            cout << "\nIngreso invalido, debe ingresar solo numeros" << endl;
            fallo = true;
        }
        else
            fallo = false;
    }*/

    cin.clear();///para que no se salte de pedir el nombre
    cin.ignore(numeric_limits <streamsize>::max(), '\n' );///para que no se salte de pedir el nombre

    String nombre;
    cout << "\nNombre: ";
    nombre.scan();

    cout << "\nCantidad de tatuajes: ";
    int cntT;
    cin >> cntT;

    cout << "\nFecha de nacimiento: ";
    Fecha fchNac = Fecha();///PREGUNTAR: si fecha deberia ser un puntero???
    do
    {
        fchNac.CargarFecha();
        if(!fchNac.esValida())
        {
            cout << "\nFecha nacimiento invalida";
        }
    }while(!fchNac.esValida());

    Camionero * c = new Camionero(cedula,nombre,cntT,fchNac);

    tipoError error;
    f.AltaCamionero(c,error);

    if(error == SIN_ERROR)
    {
        cout << "\nCamionero ingresado en el sistema";
    }
    else
    {
        cout << "\nYa exise camionero con dicha cedula en el sistema";
    }
}

void altaCamion(Fachada &f)
{

    tipoError error;
    int tipo;
    long cedula;
    do
    {
        cout << "\nIngrese el numero del tipo de camion que desea dar de alta";
        cout << "\nTipos: 1-SIMPLE, 2-GRANDE, 3-CON REMOLQUE ";
        cout << "\nIngresar tipo:";
        cin >> tipo;
        if(tipo <1 || tipo > 3)
            cout << "\nOpcion no valida.";
    }while((tipo <1 || tipo > 3));

    cin.clear();///
    cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

    cout << "Ingrese datos del camion: ";
    String mat,mar;
    int cantViajes;
    cout << "\nMatricula: ";
    mat.scan();

    cout << "\nMarca: ";
    mar.scan();
    //cin.clear();///

    cout << "\nCantidad viajes anuales: ";
    cin >> cantViajes;
    cin.clear();///
    cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

    cout << "\nIngrese cedula del camionero que lo maneja: ";
    cin >> cedula;
    if(!cin.fail())
        cout << cedula << endl;
    else
    {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );
        cout << "Ingreso invalido, debe ingresar solo numeros" << endl;
    }

    Camion * aux;
    if(tipo == 1)
    {
        cin.clear();///si pedi un numero antes hacer esto
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///si pedi un numero antes hacer esto
        String depto = String();
        cout << "\nDepartamento: ";
        depto.scan();

        aux = new CamionSimple(mat,mar,cantViajes,depto);

    }
    else if(tipo == 2)
    {
        float vol;
        cout << "\nVolumen: ";
        cin >> vol;

        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        cout << "\nFecha Adquirido: ";
        Fecha fchAdq = Fecha();///PREGUNTAR: si fecha deberia ser un puntero???
        do
        {
            fchAdq.CargarFecha();
            if(!fchAdq.esValida())
            {
                cout << "\nFecha Adquirido invalida";
            }
        }while(!fchAdq.esValida());

        aux = new CamionGrande(mat,mar,cantViajes,vol,fchAdq);
    }
    else if(tipo == 3)
    {
        float vol;
        cout << "\nVolumen: ";
        cin >> vol;

        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        cout << "\nFecha Adquirido: ";
        Fecha fchAdq = Fecha();///PREGUNTAR: si fecha deberia ser un puntero???
        do
        {
            fchAdq.CargarFecha();
            if(!fchAdq.esValida())
            {
                cout << "\nFecha Adquirido invalida";
            }
        }while(!fchAdq.esValida());

        cin.clear();///
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        float capacidad;
        cout << "\nCapacidad remolque: ";
        cin >> capacidad;

        aux = new CamionConRemolque(mat,mar,cantViajes,vol,fchAdq,capacidad);
    }

    ///NOTA: ver el tema de que si y existe camion con matricula, que no siga pidiendo los demas datos
    f.AltaCamion(aux,cedula,error);

    if(error == SIN_ERROR)
    {
        cout << "\nCamion ingresado en el Sistema";
    }
    else
    {
        cout << "\nYa existe camion con dicha matricula, y/o cedula del camionero no registrada en el sistema";
    }

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


