#include "Fachada.h"

Fachada :: Fachada(): camioneros(), camiones()
{

}

void Fachada :: AltaCamionero(Camionero * c,tipoError &error)
{
    if(camioneros.Member(c->getCedula()))
        error = EXISTE_CAMIONERO;
    else
    {
        camioneros.Insert(c);
        error = SIN_ERROR;
    }
}

void Fachada :: AltaCamion(Camion * c,long cedula,tipoError &error)
{
    if(camiones.Member(c->getMatricula()))
        error = EXISTE_CAMION;
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
            error = NO_EXISTE_CAMIONERO;
    }
}

void Fachada :: ListadoCamioneros(Iterador &iter)
{
    camioneros.listarCamioneros(iter);
}

void Fachada :: DetalleCamion(String mat, Camion * &c, tipoError &error)
{
    if(camiones.Member(mat))
        c = camiones.Find(mat);
    else
        error = NO_EXISTE_CAMION;
}

///*NUEVO*/
void Fachada :: ModificarViajesAnuales(int cant,String mat,Camion * &c,tipoError &error)
{
    if(camiones.Member(mat))
    {
        c = camiones.Find(mat);
        c->setCantViajesAnuales(cant);
        error = SIN_ERROR;
    }
    else
    {
        error = NO_EXISTE_CAMION;
    }
}

void Fachada :: ListadoCamiones(Iterador &iter)
{
    camiones.listarCamiones(iter);
}
