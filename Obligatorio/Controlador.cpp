#include "Controlador.h"

Controlador :: Controlador() : fachada()
{
}

void Controlador :: altaCamionero()
{
    cout << "\nIngrese datos del camionero: ";
    cout << "\nCedula: ";
    String auxCedula;
    cin.sync();
    auxCedula.scan();
    while(!auxCedula.esEntero())
    {
        cout << "\nIngrese nuevamente, debe contener solo numeros";
        cout << "\nCedula: ";
        auxCedula.scan();
    }
    long cedula = auxCedula.convertirStringAEntero();

    cin.sync();

    String nombre;
    cout << "\nNombre: ";
    nombre.scan();

    cin.sync();

    cout << "\nCantidad de tatuajes: ";
    String auxCntT;
    auxCntT.scan();
    while(!auxCntT.esEntero())
    {
        cout << "\nIngrese nuevamente, debe contener solo numeros";
        cout << "\nCantidad de tatuajes: ";
        auxCntT.scan();
    }
    int cntT = int(auxCntT.convertirStringAEntero());
    //cin >> cntT;
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
    fachada.AltaCamionero(c,error);

    if(error == SIN_ERROR)
    {
        cout << "\nCamionero ingresado en el sistema";
    }
    else
    {
        cout << "\nYa exise camionero con dicha cedula en el sistema";
    }
}

void Controlador :: altaCamion()
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
        if(tipo < 1 || tipo > 3)
            cout << "\nOpcion no valida.";
    }
    while((tipo <1 || tipo > 3));

    cout << "Ingrese datos del camion: ";
    String mat,mar;
    int cantViajes;
    cout << "\nMatricula: ";
    mat.scan();
    cin.sync();

    cout << "\nMarca: ";
    mar.scan();
    cin.sync();

    cout << "\nCantidad viajes anuales: ";
    cin.sync();
    String auxCntViajes;
    auxCntViajes.scan();
    while(!auxCntViajes.esEntero())
    {
        cout << "\nIngrese nuevamente, debe contener solo numeros";
        cout << "\nCantidad viajes anuales: ";
        auxCntViajes.scan();
    }
    cantViajes = int(auxCntViajes.convertirStringAEntero());
    cin.sync();

    cout << "\nIngrese cedula del camionero que lo maneja: ";
    String auxCedula;
    cin.sync();
    auxCedula.scan();
    while(!auxCedula.esEntero())
    {
        cout << "\nIngrese nuevamente, debe contener solo numeros ";
        cout << "\nIngrese cedula del camionero que lo maneja: ";
        auxCedula.scan();
    }
    cedula = auxCedula.convertirStringAEntero();

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

        cout << "\nFecha Adquirido: ";
        Fecha fchAdq = Fecha();
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
        cin.sync();

        cout << "\nFecha Adquirido: ";
        Fecha fchAdq = Fecha();
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

        int capacidad;
        cout << "\nCapacidad remolque: ";
        String auxCap;
        auxCap.scan();
        while(!auxCap.esEntero())
        {
            cout << "\nIngrese nuevamente, debe contener solo numeros";
            cout << "\nCapacidad remolque: ";
            auxCap.scan();
        }
        capacidad = int(auxCap.convertirStringAEntero());


        aux = new CamionConRemolque(mat,mar,cantViajes,vol,fchAdq,capacidad);
    }
    fachada.AltaCamion(aux,cedula,error);

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

void Controlador :: modificarViajesAnuales()
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
    cin.sync();
    String auxCant;
    auxCant.scan();
    while(!auxCant.esEntero())
    {
        cout << "\nIngrese nuevamente, debe contener solo numeros";
        cout << "\nIngrese cantidad de viajes anuales: ";
        auxCant.scan();
    }
    cant = int(auxCant.convertirStringAEntero());

    fachada.ModificarViajesAnuales(cant,mat,c,error);
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

void Controlador :: listadoCamioneros()
{
    Iterador iterador = fachada.ListadoCamioneros();

    if (iterador.hayMasObjetos())
    {
        Camionero * aux = NULL;
        while(iterador.hayMasObjetos())
        {
            aux = (Camionero*)iterador.proximoObjeto();
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


void Controlador :: detalleCamion()
{
    Camion * c = NULL;
    tipoError error;
    String mat;

    cin.sync();

    cout << "\nDetalle de un Camion";
    cout << "\nMatricula: ";
    mat.scan();
    cin.sync();

    fachada.DetalleCamion(mat,c,error);
    if (error == NO_EXISTE_CAMION)
        cout << "\nError: No existe un camion con la matricula ingresada";
    else
    {
        cout << "\n\nDetalle:";
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

void Controlador :: listadoCamiones()
{
    Iterador iterador =  fachada.ListadoCamiones();

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
                cout << " SIMPLE ";
            else
            {
                if(aux->getTipo() == "CAMION GRANDE")
                    cout << " GRANDE ";
                else
                    cout << " CON REMOLQUE ";
            }
            cout << "\n";
        }
    }
    else
        cout << "\nNo hay camiones registrados en el sistema.";
    cin.sync();
}

void  Controlador :: totalMetrosCubicosAnuales()
{
    cout << "\nTotal de metros cubicos de la flota: " << fachada.TotalMetrosCubicosAnuales();
    cin.sync();
}

void Controlador :: obtenerCamionesPorTipo()
{
    int cantSimple,cantGrande,cantRemolque;
    fachada.CantidadCamionesPorTipo(cantSimple,cantGrande,cantRemolque);

    cout << "\nCantidades de camiones por tipo: ";
    cout << "\nSimple: " << cantSimple;
    cout << "\nGrande " << cantGrande;
    cout << "\nRemolque: " << cantRemolque;
    cin.sync();
}

void Controlador :: cantidadCamionesGrandesFechaAdq()
{
    int cant;
    Fecha f;
    cout << "\nIngrese fecha Adquisicion: ";
    do
    {
        f.CargarFecha();
        cin.sync();
        if(!f.esValida())
        {
            cout << "\nFecha Adquirido invalida";
        }
    }
    while(!f.esValida());

    fachada.CantidadCamionesGrandesFechaAdq(cant,f);
    cout << "\nCantidad: " << cant;

}

void Controlador :: camioneroConMayorCntTatuajes()
{
    Camionero * c = fachada.CamionerMayorCntTatuajes();
    if(c == NULL)
        cout << "\nError: aun no hay camioneros ingresados en el sistema. ";
    else
    {
        cout << "\nCamionero: ";
        cout << "\nCedula: ";
        cout << c->getCedula();
        cout << "\nNombre: ";
        c->getNombre().print();
    }
}


