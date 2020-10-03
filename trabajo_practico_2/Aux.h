#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED



#endif // AUX_H_INCLUDED

/**********************************
        PROTOTIPOS
 **********************************/


/** \brief Pido un nombre con mensajeParaPedir, que se va a guardar
 *          en cadena, de no ser válido se mostrará mensajeDeError
 *
 * \param cadena[] char
 * \param mensajeParaPedir[] char
 * \param mensajeDeError[] char
 *
 */
void pedirNombre(char cadena[], char mensajeParaPedir[], char mensajeDeError[]);

/** \brief Analiza caracter por caracter si es una cadena alfabética,
 *          si se encuentra un número entonces no será válida
 *
 * \param cadena[] char
 * \return int Retorno (0 - FALSE) si se encontró un número en cadena
 *                     (1 - TRUE) si es una cadena alfabetica válida
 *
 */
int esCadenaAlfabetica(char cadena[]);

/** \brief Convierte cadena a un formato de nombre del tipo:
 *          primer caracter => mayúscula,
 *          el resto hasta el espacio(si hubiera) => minúscula
 *
 * \param cadena[] char
 *
 */
void formatoDeNombre(char cadena[]);

/** \brief Muestra mensajeParaPedir para pedir un dato de tipo float,
 *          que se encuentre entre minimo, y maximo, sino se mostrará
 *          mensajeDeError
 *
 * \param mensajeParaPedir[] char
 * \param minimo float
 * \param maximo float
 * \param mensajeDeError[] char
 * \return float Retorna flotante validado entre minimo y maximo
 *
 */
float pedirFlotante(char mensajeParaPedir[], float minimo, float maximo, char mensajeDeError[]);

/** \brief Muestra mensajeParaPedir para pedir un dato de tipo entero,
 *          que se encuentre entre minimo, y maximo, sino se mostrará
 *          mensajeDeError
 *
 * \param mensajeParaPedir[] char
 * \param minimo int
 * \param maximo int
 * \param mensajeDeError[] char
 * \return int Retorna entero validado entre minimo y maximo
 *
 */
int pedirEntero(char mensajeParaPedir[], int minimo, int maximo, char mensajeDeError[]);

/** \brief Muestra un mensaje por pantalla de "finalizacion exitosa" o
 *          "hubo errores" dado un resultado x obtenido de otra funcion
 *
 * \param x int
 *
 */
void errorController(int x);

/** \brief Dada una cadena, se convierte caracter por caracter
 *          a mayúsculas
 *
 * \param cadena[] char
 *
 */
void cadenaMayuscula(char cadena[]);
