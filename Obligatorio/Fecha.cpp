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
    /*bool igual = false;
    if(anio == f.anio)
    {
        if(mes == f.mes)
        {
            if(dia == f.dia)
            {
                igual = true;
            }
        }
    }*/
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

///prefija
Fecha Fecha :: operator++()
{
    SumarUnDia();

    return (*this);
}

///posfija
Fecha Fecha :: operator++(int x)
{
    Fecha aux = (*this);
    SumarUnDia();
    return aux;
}

Fecha Fecha :: operator+(int cant)
{
    for(int i=0; i < cant; i++)
    {
        SumarUnDia();
    }
    return (*this);
}

///REVISAR................
///**Precondicion: 1er fecha >= que  2da fecha**
int Fecha :: operator-(Fecha f)
{
    int cant = 0;
    Fecha aux = (*this);
    while(!(aux == f))
    {
        aux.RestarUnDia();
        cant = cant + 1;
    }
    return cant;
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

void Fecha :: SumarUnDia()
{
    if(dia < 28)
    {
        dia = dia + 1;
    }
    else
    {
        if(dia == 28)
        {
            if(mes == 2)
            {
                if(anio % 4 != 0)
                {
                    dia = 1;
                    mes = mes + 1;
                }
                else
                    dia = dia + 1;
            }
        }
        else if(dia == 29)
        {
            if(mes == 2)
            {
                dia = 1;
                mes = mes + 1;

            }
            else
                dia = dia +1;

        }
        else if(dia == 31)
        {
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10)
            {
                dia = 1;
                mes = mes + 1;
            }
            else
            {
                if(mes == 12)
                {
                    dia = 1;
                    mes = 1;
                }

            }
        }
        else if(dia == 30)
        {
             if(mes == 4 || mes == 6 || mes == 9 || mes == 11)//meses con 30 dias
             {
                 dia = 1;
                 mes = mes + 1;
             }
        }
    }
}

void Fecha :: RestarUnDia()
{
    if(dia > 1)
        dia = dia - 1;
    else
    {
        if(dia == 1)
        {
            if(mes == 1)
            {
                dia = 31;
                mes = 12;
            }
            else if(mes == 3)
            {
                if(anio % 4 == 0)
                {
                    dia = 29;
                    mes = mes - 1;
                }
                else
                {
                    dia = 28;
                    mes = mes - 1;
                }
            }
            else if(mes == 12|| mes == 10|| mes == 7 || mes == 5)
            {
                dia = 30;
                mes = mes - 1;
            }
            else if(mes == 11|| mes == 9 || mes == 8 || mes == 6 || mes == 4 || mes == 2 )
            {
                dia = 31;
                mes = mes - 1;
            }

        }
    }
}

