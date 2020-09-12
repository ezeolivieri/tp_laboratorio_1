#ifndef USUARIOFUNC_H_INCLUDED
#define USUARIOFUNC_H_INCLUDED



#endif // USUARIOFUNC_H_INCLUDED

/** \brief  Muestra el menú principal con las opciones de la
 *          calculadora, retorna un int con la opción seleccionada
 *
 * \param x int Primer operando ingresado que será reemplazado en el menú
 * \param y int Segundo operando ingresado que será reemplazado en el menú
 * \param banderaX int Bandera que indica 1 si se ingresó el primer operando o 0 en caso contrario
 * \param banderaY int Bandera que indica 1 si se ingresó el segundo operando o 0 en caso contrario
 * \return int Entero que representa la opción seleccionada por el usuario
 *
 */
int menuDeOpciones(int x, int y, int banderaX, int banderaY);

/** \brief Pide un ingreso de un número entero y lo retorna
 *
 * \return int Retorna el entero ingresado
 *
 */
int pedirOperando();

/** \brief Muestra por pantalla un mensaje de confirmacion de salida y retorna la respuesta ingresada
 *
 * \return char Caracter que representa la confirmación de la salida
 *
 */
char confirmacionSalida();
