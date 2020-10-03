#ifndef FORMS_H_INCLUDED
#define FORMS_H_INCLUDED



#endif // FORMS_H_INCLUDED

/**********************************
        PROTOTIPOS
 **********************************/


/** \brief Despliegue del menú principal donde se puede:
            - Ingresar un empleado
            - Modificar un empleado
            - Dar de baja un empleado
            - Informar dos tipos de resultados
 *
 * \return int Entero que indica la opción seleccionada
 *
 */
int menu();

/** \brief Muestra por pantalla un mensaje de confirmacion de salida y retorna la respuesta ingresada
 *
 * \return char Caracter que representa la confirmación de la salida
 *
 */
char confirmacionSalida();

/** \brief Formulario para agregar un empleado
 *
 * \param list Employee*
 * \param length int
 *
 */
void formAddEmployee(Employee* list, int length);

/** \brief Formulario para modificar un empleado
 *
 * \param list Employee*
 * \param length int
 *
 */
void formModifyEmployee(Employee* list, int length);

/** \brief Formulario para dar de baja un empleado
 *
 * \param list Employee*
 * \param length int
 *
 */
void formDeleteEmployee(Employee* list, int length);

/** \brief Formulario para mostrar un empleado
 *
 * \param list Employee*
 * \param length int
 *
 */
void formPrintEmployee(Employee* list, int length);
