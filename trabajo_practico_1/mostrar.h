#ifndef MOSTRAR_H_INCLUDED
#define MOSTRAR_H_INCLUDED



#endif // MOSTRAR_H_INCLUDED

/** \brief Imprime el resultado de una operacion por pantalla
 *
 * \param operacion char Un caracter que indique la inicial de una operación matemática
 * \param x int Primer operando entero utilizado para la operación indicada
 * \param y int Segundo operando entero utilizado para la operación indicada
 * \param resultado int Resultado de la "operacion" entre x e y
 *
 */
void mostrarResultadosDe( char operacion, int x, int y, int resultado);

/** \brief Imprime el resultado de una division por pantalla, en caso de ser y=0 muestra un error
 *
 * \param x int Divisor entero
 * \param y int Dividendo entero
 * \param resultado float Numero flotante con dos dígitos decimales
 *
 */
void mostrarDivisionDe( int x, int y, float resultado );

/** \brief Imprime el resultado de un factorial por pantalla
 *
 * \param x int Numero entero sobre el cual se calculó el factorial
 * \param resultado int Resultado del factorial de x
 *
 */
void mostrarFactorialDe( int x, int resultado );
