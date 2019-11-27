#include "Fachada.h"

Fachada :: Fachada(): camioneros(), camiones()
{

}

void Fachada :: AltaCamionero(Camionero * c,tipoError &error)
{
    if(camioneros.Member(c->getCedula()))
    {
        error = EXISTE_CAMIONERO;
    }
    else
    {
        camioneros.Insert(c);
        error = SIN_ERROR;
        //cout << "\nIngreso";
    }
}

void Fachada :: AltaCamion(Camion * c,long cedula,tipoError &error)
{
    if(camiones.Member(c->getMatricula()))
    {
        error = EXISTE_CAMION;
        cout << "\nExiste camion con dicha mat";
    }
    else
    {

        if(camioneros.Member(cedula))
        {
            Camionero * auxFind = camioneros.Find(cedula);
            c->setCamionero(auxFind);
            camiones.Insert(c);
            error = SIN_ERROR;
            cout << "\n sin error, inserto";
        }
        else
        {
            error = NO_EXISTE_CAMIONERO;
            cout << "\nNo existe camionero con esa cedula";
            ///PREGUNTAR: aunque no exista el camionero con esa cedula, se puede crear un camion sin camionero???
        }
    }
}

void Fachada :: ListadoCamioneros(Iterador &iter)
{
    camioneros.listarCamioneros(iter);
}

void Fachada :: ListadoCamiones(Iterador &iter)
{
    camiones.listarCamiones(iter);
}




