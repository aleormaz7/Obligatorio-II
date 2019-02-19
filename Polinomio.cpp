#include "Polinomio.h"

void Crear(Polinomio &p, String nombre, ListaTerminos listaT)
{
    p.nombre = nombre;
    p.Terminos = listaT;
}

void darListaTerminos(Polinomio p, listaTerminos &listaT)
{





}

void mostrarPolinomio(Polinomio p)
{
    print(p.nombre);
    printf("/n");
    mostrarListaTerminos(p.Terminos);
}

void darNombre(Polinomio p, String &s)
{
    strcop(&s,p.nombre);
}

Boolean esNulo (Polinomio p)
{
    Boolean resu = FALSE;


    return resu;
}

void borrar()

