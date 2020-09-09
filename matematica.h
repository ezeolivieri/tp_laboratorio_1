#ifndef MATEMATICA_H_INCLUDED
#define MATEMATICA_H_INCLUDED



#endif // MATEMATICA_H_INCLUDED

/** \brief Retorna la suma entre x e y que son dos numeros enteros
 *
 * \param x int Primer operando entero
 * \param y int Segundo operando entero
 * \return int Resultado entero de la suma entre x e y
 *
 */
int sumar( int x, int y );

/** \brief Retorna la resta entre x e y que son dos numeros enteros
 *
 * \param x int Primer operando entero
 * \param y int Segundo operando entero
 * \return int Resultado entero de la resta entre x e y
 *
 */
int restar( int x, int y );

/** \brief Retorna la división entre x e y que son dos números enteros
 *
 * \param x int Divisor entero
 * \param y int Dividendo entero
 * \return float Resultado en numero decimal de la división entre x e y
 *
 */
float dividir( int x, int y );

/** \brief Retorna el producto entre x e y que son dos números enteros
 *
 * \param x int Primer factor del producto
 * \param y int Segundo factor del producto
 * \return int Número entero producto entre x e y
 *
 */
int multiplicar( int x, int y );

/** \brief Calcula el factorial de x
 *
 * \param x int Número entero positivo
 * \return int Retorna el resultado del factorial de x, si es 0 es igual a 1
 *
 */
int factorial( int x );
