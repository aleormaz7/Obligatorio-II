#include "ABBPolinomio.h"

int main()
{
    ///Creo Polinimios para recuperar
    ABBPolinomio abb;
    ABBPolinomioCrear(abb);
    String s;
    ListaString ls;


    do
    {
        strcrear(s);
        CrearListaString(ls);

        printf("\nIngrese comando: ");
        scan(s);
        partirString(s,ls);

        if(streq("crear",ls->info))
        {
print("\ncrear.");
        }
        else
        {
           if(streq("sumar",ls->info))
           {
print("\nSumar.");
           }
           else
           {
               if(streq("multiplicar",ls->info))
               {
print("\ncMultiplicar.");
               }
               else
               {
                   if(streq("evaluar",ls->info))
                   {
print("\nEvaluar.");
                   }
                   else
                   {
                       if(streq("esraiz",ls->info))
                       {
print("\nEsRaiz.");
                       }
                       else
                       {
                           if(streq("mostrar",ls->info))
                           {
print("\nMostrar.");
                           }
                           else
                           {
                               if(streq("guardar",ls->info))
                               {
print("\nGuardar.");
                               }
                               else
                               {
                                   if(streq("recuperar",ls->info))
                                   {
print("\nRecuperar.");
                                   }
                                   else
                                   {
                                       if(streq("salir",ls->info))
                                       {
print("\nSalir.");
                                       }
                                       else
                                        print("\nError: no se renoce el comando.");
                                   }
                               }

                           }

                       }
                   }
               }

           }

        }
//   strdestruir(s);
//  destruirListaString(ls);
    }while(!streq("salir",ls->info));
/////////////

    ///pruebaModuloString();
    ///pruebaListaStrings();
    ///pruebasModuloArchivo();
    ///pruebasModuloTermino();
    ///pruebasModuloPolinomio();
    ///pruebasSumarPolinomios();
    ///pruebasReducirPolinomio();
    ///pruebasMultiplicarPolinomio();
    ///pruebasControlTerminoIndependienteNoNulo();
    ///pruebasEvaluarPolinomio();
    ///pruebasEsRaiz();
    ///PruebasABBPolinomio();
    ///pruebasListaTermino();
    ///pruebasPasoMinusculas();
    ///mainSumarPolinomios();
    ///mainMultiplicarPolinomios();
    ///mainMostrar();
    ///mainEvaluar();
    ///mainEsRaiz();
    ///mainGuardar();
    ///mainRecuperar();
    ///pruebaStringAEnteroYEsNumero();
    ///pruebaDarExtencion();
}
