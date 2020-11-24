#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED



#endif // AUX_H_INCLUDED

/** \brief Obtener un entero validando que sea mayor al minimo
 *
 * \param entero int*
 * \param minimo int
 * \param mensajePedir char*
 * \param mensajeError char*
 * \return int Entero que indica si hubo errores.
 *
 */
int aux_getEntero(int* entero, int minimo, char* mensajePedir, char* mensajeError);

/** \brief Obtener un entero validando que este en el rango especificado
 *
 * \param entero int*
 * \param minimo int
 * \param maximo int
 * \param mensajePedir char*
 * \param mensajeError char*
 * \return int Entero que indica si hubo errores.
 *
 */
int aux_getEnteroEntre(int* entero, int minimo, int maximo, char* mensajePedir, char* mensajeError);

/** \brief Obtener un char (S/N) de confirmacion
 *
 * \param mensajePedir char*
 * \param mensajeError char*
 * \return char Caracter indicado por el usuario (S/N)
 *
 */
char aux_getConfirmacion(char* mensajePedir, char* mensajeError);

/** \brief Obtener una cadena de solo caracteres, sin numeros.
 *
 * \param cadena char*
 * \param mensajePedir char*
 * \param mensajeError char*
 * \return int Entero que indica si hubo errores.
 *
 */
int aux_getCadena(char* cadena, char* mensajePedir, char* mensajeError);

/** \brief Verifica si cadena, es una cadena que contenga caracteres alfabeticos
 *
 * \param cadena char*
 * \return int Entero que indica si hubo errores
 *
 */
int esCadenaAlfabetica(char* cadena);
