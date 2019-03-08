#include "ProcesadorComandos.h"

int main()
{
    ///Creo Polinimios para recuperar
    ABBPolinomio abb;
    ABBPolinomioCrear(abb);
    String s,comando;
    ListaString ls;
    boolean fin = FALSE;

    do
    {
        strcrear(s);
        strcrear(comando);
        CrearListaString(ls);

        printf("\nIngrese comando: ");
        scan(s);
        partirString(s,ls);
        obtenerString(ls,0,comando);
        if(streq("crear",comando))
            comandoCrear(abb,ls);
        else
        {
           if(streq("sumar",comando))
                comandoSumar(abb,ls);
           else
           {
               if(streq("multiplicar",comando))
                    comandoMultiplicar(abb,ls);
               else
               {
                   if(streq("evaluar",comando))
                        comandoEvaluar(abb,ls);
                   else
                   {
                       if(streq("esraiz",comando))
                            comandoEsRaiz(abb,ls);
                       else
                       {
                           if(streq("mostrar",comando))
                                comandoMostrar(abb,ls);
                           else
                           {
                               if(streq("guardar",comando))
                                    comandoGuardar(abb,ls);
                               else
                               {
                                   if(streq("recuperar",comando))
                                        comandoRecuperar(abb,ls);
                                   else
                                   {
                                       if(streq("salir",comando))
                                            comandoSalir(abb,fin,ls);
                                       else
                                            print("\nError: no se reconoce el comando.");
                                   }
                               }
                           }
                       }
                   }
               }
           }
        }
    strdestruir(s);
    strdestruir(comando);
    destruirListaString(ls);
    }while(!fin);
}
