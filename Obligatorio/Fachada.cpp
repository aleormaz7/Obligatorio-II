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
        cout << "\nIngreso";
    }
}

void Fachada :: AltaCamion(Camion * c,long cedula,tipoError &error)
{
    if(camiones.Member(c->getMatricula()))
    {
        error = EXISTE_CAMION;
        cout << "\nexiste camion";
    }
    else
    {

        if(camioneros.Member(cedula))
        {
            Camionero * auxFind = camioneros.Find(cedula);
            c->setCamionero(auxFind);
            camiones.Insert(c);
            error = SIN_ERROR;
            cout << "\n sin error";
        }
        else
        {
            error = NO_EXISTE_CAMIONERO;
            cout << "\nno existe camionero";
        }
    }
}

void Fachada :: ListadoCamioneros(Iterador &iter)
{
    camioneros.listarCamioneros(iter);
}






