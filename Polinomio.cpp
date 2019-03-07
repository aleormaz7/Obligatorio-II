#include "Polinomio.h"

void crearPolinomio(Polinomio &p,String nombre, ListaTerminos lst)
{
    listaTerminosCrear(p.listaTerminos);
    strcrear(p.nombre);
    strcop(p.nombre,nombre);
    listaTerminosCopiar(lst,p.listaTerminos);
}

void darListaTerminosPolinomio(Polinomio p, ListaTerminos &listaT)
{
    listaTerminosCrear(listaT);
    listaT = p.listaTerminos;
}

void mostrarPolinomio(Polinomio p)
{
    print(p.nombre);
    printf(" = ");
    listaTerminosMostrar(p.listaTerminos);
}

void darNombrePolinomio(Polinomio p, String &s)
{
    strcrear(s);
    strcop(s,p.nombre);
}

void borrarPolinomio(Polinomio &p)
{
    strdestruir(p.nombre);
    destuirListaTerminos(p.listaTerminos);
}
