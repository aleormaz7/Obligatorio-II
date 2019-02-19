#include "Polinomio.h"

void polinomioCrear(Polinomio &p, String nombre, ListaTerminos listaT)
{
    p.nombre = nombre;
    p.Terminos = listaT;
}

void darListaTerminos(Polinomio p, ListaTerminos &listaT)
{

}

void mostrarPolinomio(Polinomio p)
{
    print(p.nombre);
    printf("/n");
    listaTerminosMostrar(p.Terminos);
}

/*
void darNombre(Polinomio p, String &s)
{
    strcop(&s,p.nombre);
}
*/

void borrar()
{

}

