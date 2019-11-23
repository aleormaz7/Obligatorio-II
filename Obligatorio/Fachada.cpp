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

void Fachada :: ListadoCamioneros(Iterador &iter)
{
    camioneros.listarCamioneros(iter);
}






