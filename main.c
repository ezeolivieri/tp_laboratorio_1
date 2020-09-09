<<<<<<< HEAD
/*********************************************************

* Programa: Trabajo Práctico 1 - Calculadora

* Objetivo:
    - Pedir dos operandos
    - Calcular todas las operaciones
    - Informar resultados
    - Preguntar si desea continuar

* Autor: Olivieri, Ezequiel Agustin

*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "matematica.h"
#include "mostrar.h"
#include "usuariofunc.h"

#define VERDE_T     "\x1b[32m"
#define ROJO_T      "\x1b[31m"
#define AMARILLO_T  "\x1b[33m"



int main()
{
    int continuar = 1; // Condicion para continuar
    int ingresoPrimerOperando = 0; // Bandera de ya ingreso el primer operando
    int ingresoSegundoOperando = 0; // Bandera de ya ingreso el segundo operando
    int yaCalculoOperaciones = 0; // Bandera de ya calculo todas las operaciones
    int primerOperando; // operando que será ingresado por el usuario
    int segundoOperando; // operando que será ingresado por el usuario
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int resultadoFactorialUno;
    int resultadoFactorialDos;
    float resultadoDivision;

    do
    {

        // limpio pantalla luego de cada iteración sobre el switch
        system("clear");

        switch ( menuDeOpciones(primerOperando, segundoOperando, ingresoPrimerOperando, ingresoSegundoOperando) )
        {
            case 1:
                // condición para indicar si ya se ingresó el primer operando
                if ( ingresoPrimerOperando ) {
                    printf(VERDE_T "\n\nYa ingresaste el primer operando.\n");
                } else {
                    primerOperando = pedirOperando();
                    ingresoPrimerOperando = 1;
                }
                break;

            case 2:
                // si ya se ingreso el operando muestro el mensaje
                if( ingresoSegundoOperando ) {
                    printf(VERDE_T "\n\nYa ingresaste el segundo operando.\n");
                } else {
                    segundoOperando = pedirOperando();
                    ingresoSegundoOperando = 1;
                }
                break;

            case 3:
                // en caso de haber ingresado los dos operandos, se pueden realizar los cálculos
                if( ingresoSegundoOperando && ingresoPrimerOperando )
                {
                    resultadoSuma = sumar( primerOperando, segundoOperando );
                    resultadoResta = restar( primerOperando, segundoOperando );
                    resultadoDivision = dividir( primerOperando, segundoOperando );
                    resultadoMultiplicacion = multiplicar( primerOperando, segundoOperando );
                    resultadoFactorialDos = factorial( segundoOperando );
                    resultadoFactorialUno = factorial( primerOperando );
                    printf(VERDE_T "\n\nSe realizaron los cálculos correctamente, ya puedes ver los resultados.\n\n");
                    yaCalculoOperaciones = 1;
                }
                // sino, se indica que deberia ingresar los operandos primero
                else
                {
                    printf(AMARILLO_T "\n\nPrimero deberias ingresar los dos operandos\n\n");
                }
                break;

            case 4:
                // si se hicieron los cálculos matemáticos, hago el muestreo de datos y reinicio las banderas
                if( yaCalculoOperaciones )
                {
                    mostrarResultadosDe('a', primerOperando, segundoOperando, resultadoSuma);
                    mostrarResultadosDe('b', primerOperando, segundoOperando, resultadoResta);
                    mostrarDivisionDe(primerOperando, segundoOperando, resultadoDivision);
                    mostrarResultadosDe('d', primerOperando, segundoOperando, resultadoMultiplicacion);
                    mostrarFactorialDe(primerOperando, resultadoFactorialUno);
                    mostrarFactorialDe(segundoOperando, resultadoFactorialDos);

                    ingresoPrimerOperando = 0;
                    ingresoSegundoOperando = 0;
                    yaCalculoOperaciones = 0;
                }
                // en caso contrario, le indico lo que le falta para llegar a ver los resultados
                else
                {
                    if( !( ingresoPrimerOperando && ingresoSegundoOperando ) )
                        printf(AMARILLO_T "\n\nPrimero deberias ingresar los dos operandos\n\n");
                    else
                        printf(AMARILLO_T "\n\nPara mostrar los resultados, deberias realizar los cálculos primero\n\n");
                }

                break;

            case 5:
                if ( confirmacionSalida() == 's' )
                    continuar = 0;
                break;

            default:
                __fpurge(stdin);
                printf(ROJO_T "\n\nOpcion invalida.\n\n");
                break;
        }

        // pauso la ejecución del programa para poder mostrar lo sucedido en el main
        system("read -p 'Press Enter to continue...' var");

    }
    while ( continuar );


=======
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
>>>>>>> 6ab97725c292809e87244afb9463abc8b8a008eb
    return 0;
}
