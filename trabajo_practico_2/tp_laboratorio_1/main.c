/*********************************************************
* Programa: Trabajo Práctico 2

* Objetivos:
    - Manejo de arrays
    - Manejo de pasaje por referencia
    - Manejo de estructuras

* Enunciado:
    Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
    dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

* Autor: Olivieri, Ezequiel Agustin
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "Forms.h"

#define FALSE     0
#define TRUE      1
#define ELEMENTS  1000
#define AMARILLO_T  "\x1b[33m"
#define ROJO_T      "\x1b[31m"



/*****************************************
                    MAIN
 *****************************************/
int main()
{
    int continuar = TRUE; // Condicion para continuar en el programa
    Employee empleados[ELEMENTS];
    int ingresados = 0; // Bandera para verificar los ingresos

    // Inicializo todas las posiciones de empleados con isEmpty = TRUE
    initEmployees( empleados, ELEMENTS );

    do
    {
        // limpio pantalla luego de cada iteración sobre el switch
        system("clear");

        switch( menu() )
        {
            case 1:
                formAddEmployee( empleados, ELEMENTS );
                ingresados++;

                break;

            case 2:
                if( ingresados )
                    formModifyEmployee( empleados, ELEMENTS );
                else
                    printf(AMARILLO_T "\nPara modificar, primero debes ingresar un empleado.\n");

                break;

            case 3:
                if( ingresados )
                {
                    formDeleteEmployee( empleados, ELEMENTS );
                    ingresados--;
                }
                else
                {
                    printf(AMARILLO_T "\nPara dar de baja, primero debes ingresar un empleado.\n");
                }

                break;

            case 4:
                if( ingresados )
                    formPrintEmployee( empleados, ELEMENTS );
                else
                    printf(AMARILLO_T "\nPara informar, primero debes ingresar un empleado.\n");

                break;

            case 5:
                if ( confirmacionSalida() == 's' )
                    continuar = FALSE;

                break;

            default:
                __fpurge(stdin);
                printf(ROJO_T "\n\nOpcion invalida.\n\n");

                break;
        }

        // pauso la ejecución del programa para poder mostrar lo sucedido en el main
        system("read -p 'Press Enter to continue...' var");

    }
    while( continuar );

    return 0;
}
