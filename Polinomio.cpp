#include "Polinomio.h"

void crearPolinomio(Polinomio &p, String nombre, ListaTerminos listaT)
{
    strcop(p.nombre,nombre);


    ///p.listaTerminos = listaT;(estaria devolviendo un solo termino)
}

///ListaTerminos darListaTerminosPolinomio(Polinomio p)//////////////
///{
///return p.listaTerminos;// (estaria devolviendo un solo termino)
///}

void darListaTerminosPolinomio(Polinomio p, ListaTerminos &listaT)
{

    //DarCoefTermino(listaT.info) = DarCoefTermino(p.listaTerminos.info);
    //DarGradoTermino(listaT.info) = DarGradoTermino(p.listaTerminos.info);

}

void mostrarPolinomio(Polinomio p)
{
    print(p.nombre);
    listaTerminosMostrar(p.listaTerminos);
}


void darNombrePolinomio(Polinomio p, String &s)
{
    strcop(s,p.nombre);
}

void borrarPolinomio()
{

}

