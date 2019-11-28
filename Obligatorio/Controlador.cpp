#include "Controlador.h"


void altaCamionero(Fachada &f)
{
    cout << "\nIngrese datos del camionero: ";
    cout << "\nCedula: ";
    int cedula;
    cin >> cedula;
    cin.sync();
    if(!cin.fail())
    {
        //cout << cedula << endl;
    }
    else
    {
        cin.sync();
        //cin.clear();
        //cin.ignore(numeric_limits <streamsize>::max(), '\n' );
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

    //cin.clear();///para que no se salte de pedir el nombre
    //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///para que no se salte de pedir el nombre

    String nombre;
    cout << "\nNombre: ";
    nombre.scan();
    cin.sync();

    cout << "\nCantidad de tatuajes: ";
    int cntT;
    cin >> cntT;
    cin.sync();

    cout << "\nFecha de nacimiento: ";
    Fecha fchNac = Fecha();///PREGUNTAR: si fecha deberia ser un puntero???
    do
    {
        fchNac.CargarFecha();
        cin.sync();
        if(!fchNac.esValida())
        {
            cout << "\nFecha nacimiento invalida";
        }
    }
    while(!fchNac.esValida());

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
        cin.sync();
        if(tipo <1 || tipo > 3)
            cout << "\nOpcion no valida.";
    }
    while((tipo <1 || tipo > 3));

    //cin.clear();///
    //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

    cout << "Ingrese datos del camion: ";
    String mat,mar;
    int cantViajes;
    cout << "\nMatricula: ";
    mat.scan();
    cin.sync();

    cout << "\nMarca: ";
    mar.scan();
    cin.sync();
    //cin.clear();///

    cout << "\nCantidad viajes anuales: ";
    cin >> cantViajes;
    cin.sync();
    //cin.clear();///
    //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

    cout << "\nIngrese cedula del camionero que lo maneja: ";
    cin >> cedula;
    if(!cin.fail())
    {
        //cout << cedula << endl;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n' );
        cout << "Ingreso invalido, debe ingresar solo numeros" << endl;
    }
    cin.sync();

    Camion * aux;

    if(tipo == 1)
    {
        String depto = String();
        cout << "\nDepartamento: ";
        depto.scan();
        cin.sync();

        aux = new CamionSimple(mat,mar,cantViajes,depto);

    }
    else if(tipo == 2)
    {
        float vol;
        cout << "\nVolumen: ";
        cin >> vol;

        cin.sync();

        //cin.clear();///
        //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        cout << "\nFecha Adquirido: ";
        Fecha fchAdq = Fecha();///PREGUNTAR: si fecha deberia ser un puntero???
        do
        {
            fchAdq.CargarFecha();
            cin.sync();
            if(!fchAdq.esValida())
            {
                cout << "\nFecha Adquirido invalida";
            }
        }
        while(!fchAdq.esValida());

        aux = new CamionGrande(mat,mar,cantViajes,vol,fchAdq);
    }
    else if(tipo == 3)
    {
        float vol;
        cout << "\nVolumen: ";
        cin >> vol;

        //cin.clear();///
        //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///
        cin.sync();


        cout << "\nFecha Adquirido: ";
        Fecha fchAdq = Fecha();///PREGUNTAR: si fecha deberia ser un puntero???
        do
        {
            fchAdq.CargarFecha();
            cin.sync();
            if(!fchAdq.esValida())
            {
                cout << "\nFecha Adquirido invalida";
            }
        }
        while(!fchAdq.esValida());

        //cin.clear();///
        //cin.ignore(numeric_limits <streamsize>::max(), '\n' );///

        float capacidad;
        cout << "\nCapacidad remolque: ";
        cin >> capacidad;
        cin.sync();


        aux = new CamionConRemolque(mat,mar,cantViajes,vol,fchAdq,capacidad);
    }

    ///NOTA: ver el tema de que si y existe camion con matricula, que no siga pidiendo los demas datos
    f.AltaCamion(aux,cedula,error);

    if(error == SIN_ERROR)
        cout << "\nCamion ingresado en el Sistema";
    else
    {
        if(error == NO_EXISTE_CAMIONERO)
            cout << "\nError: No existe un camionero con la cedula ingresada.";
        else
            cout << "\nError: Ya existe un camion con la matricula ingresada.";
    }
}

///*Nuevo*/
void modificarViajesAnuales(Fachada &f)
{
    Camion * c = NULL;
    tipoError error;
    String mat;
    int cant;
    cin.sync();

    cout << "\nIngrese matricula del camion: ";
    mat.scan();
    cin.sync();

    cout << "\nIngrese cantidad de viajes anuales: ";
    cin >> cant;
    cin.sync();

    f.ModificarViajesAnuales(cant,mat,c,error);
    if(error == SIN_ERROR)
    {
        cout << "\nCantidad viajes anuales modificada";
    }
    else
    {
        cout << "\nNo existe camion con dicha matricula";
    }
    cin.sync();
}

void listadoCamioneros(Fachada f)
{
    Iterador iterador = f.ListadoCamioneros();

    if (iterador.hayMasObjetos())
    {
       // Objeto * objAux = NULL;
        Camionero * aux = NULL;
        while(iterador.hayMasObjetos())
        {
            aux = (Camionero*)iterador.proximoObjeto();
            //= (Camionero*) objAux;///casteo
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

    cin.sync();
}


void detalleCamion(Fachada f)
{
    Camion * c = NULL;
    tipoError error;
    String mat;

    cin.sync();

    cout << "\nDetalle de un Camion";
    cout << "\nMatricula: ";
    mat.scan();
    cin.sync();

    f.DetalleCamion(mat,c,error);
    if (error == NO_EXISTE_CAMION)
        cout << "\nError: No exite un camion con la matricula ingresada";
    else
    {
        cout << "Detalle:";
        cout << "\nMatricula: ";
        c->getMatricula().print();
        cout << "\nMarca: ";
        c->getMarca().print();
        cout << "\nCantidad viajes anuales: " << c->getCantViajesAnuales();
        cout << "\nMetros cubicos anuales: " << c->calcularMetrosCubicosAnuales();
        if(c->getTipo() == "CAMION SIMPLE")
        {
            cout << "\nTipo de camion: Simple";
            cout << "\nDepartamento: ";
            ((CamionSimple *) c)->getDepto().print();
        }
        else
        {
            if(c->getTipo() == "CAMION GRANDE")
            {
                cout << "\nTipo de camion: Grande";
                cout << "\nVolumen: " << ((CamionGrande *) c)->getVolumen();
                cout << "\nFecha de adquirido: ";
                ((CamionGrande *) c)->getFechaAdquirido().MostrarFecha();
            }
            else
            {
                cout << "\nTipo de camion: Con remolque";
                cout << "\nCapacidad de remolque: " << ((CamionConRemolque *) c)->getCapRemolque();
            }
        }
    }
    cin.sync();
}

void listadoCamiones(Fachada f)
{
    Iterador iterador =  f.ListadoCamiones();

    if (iterador.hayMasObjetos())
    {
        while(iterador.hayMasObjetos())
        {
            Objeto * objAux = iterador.proximoObjeto();
            Camion * aux = (Camion *) objAux;///casteo
            cout << "\nMatricula ";
            aux->getMatricula().print();
            cout << " - Marca ";
            aux->getMarca().print();
            cout << " - Cantidad de viajes anuales " << aux->getCantViajesAnuales();
            cout << " - Tipo de camion ";
            if(aux->getTipo() == "CAMION SIMPLE")
            {
                cout << " SIMPLE ";
                cout << " - Departamento ";
                ((CamionSimple *) aux)->getDepto().print();
            }
            else
            {
                if(aux->getTipo() == "CAMION GRANDE")
                {
                    cout << " GRANDE ";
                    cout << " - Volumen: " << ((CamionGrande *) aux)->getVolumen();
                    cout << " - Fecha de adquirido: ";
                    ((CamionGrande *) aux)->getFechaAdquirido().MostrarFecha();
                }
                else
                {
                    cout << " CON REMOLQUE ";
                    cout << " - Capacidad de remolque " << ((CamionConRemolque *) aux)->getCapRemolque();
                }
            }
            cout << "\n";
        }
    }
    else
        cout << "\nNo hay camiones registrados en el sistema.";

    cin.sync();
}

void totalMetrosCubicosAnuales(Fachada f)
{
    cout << "\nTotal de metros cubicos de la flota: " << f.TotalMetrosCubicosAnuales();
    cin.sync();
}

void obtenerCamionesPorTipo(Fachada f)
{
    int cantSimple,cantGrande,cantRemolque;

    f.CantidadCamionesPorTipo(cantSimple,cantGrande,cantRemolque);

    cout << "\nCantidades de camiones por tipo: ";
    cout << "\nSimple: " << cantSimple;
    cout << "\nGrande " << cantGrande;
    cout << "\nRemolque: " << cantRemolque;

    cin.sync();

}


