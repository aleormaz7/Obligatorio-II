#include "Fecha.h"

///Defecto
Fecha :: Fecha ()
{
    dia = 1;
    mes = 1;
    anio = 2000;
}
///Comun
Fecha :: Fecha(int d,int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}
///Copia
Fecha :: Fecha(const Fecha &copia)
{
    dia = copia.dia;
    mes = copia.mes;
    anio = copia.anio;
}

int Fecha :: getDia()
{
    return dia;
}

int Fecha :: getMes()
{
    return mes;
}

int Fecha :: getAnio()
{
    return anio;
}

bool Fecha :: operator<(Fecha f)
{
    bool es = false;
    if(anio < f.anio)
        es = true;
    else
    {
        if(mes < f.mes)
            es = true;
        else
        {
            if(dia < f.dia)
                es = true;
        }
    }
    return es;
}

bool Fecha :: operator>(Fecha f)
{
    bool es = false;
    if(anio > f.anio)
        es = true;
    else
    {
        if(mes > f.mes)
            es = true;
        else
        {
            if(dia > f.dia)
                es = true;
        }
    }
    return es;
}

bool Fecha :: operator==(Fecha f)
{
    return ((anio == f.anio) && (mes == f.mes) && (dia == f.dia));
}

bool Fecha :: operator>=(Fecha f)///Mayor igual?
{
    bool es = false;
    if(anio >= f.anio)
        es = true;
    else
    {
        if(mes >= f.mes)
            es = true;
        else
        {
            if(dia >= f.dia)
                es = true;
        }
    }
    return es;
}

bool Fecha :: operator<=(Fecha f)///Menor igual?
{
    bool es = false;
    if(anio <= f.anio)
        es = true;
    else
    {
        if(mes <= f.mes)
            es = true;
        else
        {
            if(dia <= f.dia)
                es = true;
        }
    }
    return es;
}

bool Fecha :: esValida()
{
    bool valida;
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: if (dia >= 1 && dia <= 31)
                    valida = true;
                else
                    valida = false;
            break;
        case 4:
        case 6:
        case 9:
        case 11: if (dia >= 1 && dia <= 30)
                    valida = true;
                else
                    valida = false;
            break;
        case 2: if (anio % 4 == 0)
                {
                    if (dia >= 1 && dia <= 29)
                        valida = true;
                    else
                        valida = false;
                }
                else
                {
                    if (dia >= 1 && dia <= 28)
                        valida = true;
                    else
                        valida = false;
                }
            break;

        default: valida = false;
    }
    return valida;
}

void Fecha :: MostrarFecha()
{
    cout << dia << "/" << mes << "/" <<  anio;
}

void Fecha :: CargarFecha()
{
    cin.sync();
    cout << "\nIngrese un dia: ";
    String auxDia;
    auxDia.scan();
    while(!auxDia.esEntero())
    {
        cout << "\nDebe ingresar solo numeros: ";
        auxDia.scan();
    }
    dia = int(auxDia.convertirStringAEntero());

    cin.sync();
    cout << "\nIngrese un mes: ";
    String auxMes;
    auxMes.scan();
    while(!auxMes.esEntero())
    {
        cout << "\nDebe ingresar solo numeros: ";
        auxMes.scan();
    }
    mes = int(auxMes.convertirStringAEntero());

    cin.sync();
    cout << "\nIngrese un anio: ";
    String auxAnio;
    auxAnio.scan();
    while(!auxAnio.esEntero())
    {
        cout << "\nDebe ingresar solo numeros: ";
        auxAnio.scan();
    }
    anio = int(auxAnio.convertirStringAEntero());
}
