#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define NAME_LEN  51
#define LNAME_LEN 51

// ESTRUCTURA DE UN EMPLEADO
typedef struct {

    int id;
    char name[NAME_LEN];
    char lastName[LNAME_LEN];
    float salary;
    int sector;
    int isEmpty;

} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/**********************************
        PROTOTIPOS
 **********************************/


/** \brief Para indicar que todas las posiciones del array están vacías,
            esta función pone la bandera (isEmpty) en TRUE en todas las
            posiciones del array.
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);

/** \brief Agrega en un array de empleados existente, los valores
            recibidos como parámetro en la primer posición libre.
* \param list employee*
* \param len int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
                free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado,
            recibiendo como parámetro su Id.
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Ordena el array de empleados por apellido y sector
            de manera ascendente o descendente.
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief Imprime el array de empleados de forma encolumnada.
*
* \param list Employee*
* \param length int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(Employee* list, int length);

/** \brief Realiza el swapeo entre
            Employee* a y Employee* b
 *
 * \param a Employee*
 * \param b Employee*
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int employeeSwap(Employee* a, Employee* b);

/** \brief Dado un id asociado a un Employee, se pedirá un atributo
 *          que va a ser validado. Y luego se hará la modificación
 *
 * \param list Employee*
 * \param id int
 *
 */
void modifyEmployeeAttribute(Employee* list, int id);

/** \brief Dado un campo asociado a un atributo de Employee,
 *          y un id asociado a un Employee existente. Se switchea
 *          por campo para saber el campo a modificar
 *
 * \param list Employee*
 * \param campo char*
 * \param id int
 *
 */
void switchToModify(Employee* list, char* campo, int id);

/** \brief Dado un id de un Employee existente, se pide el nuevo
 *          nuevo valor de salario, se valida y se modifica.
 *
 * \param list Employee*
 * \param id int
 *
 */
void modifyEmployeeSalary(Employee* list, int id);

/** \brief Dado un id de un Employee existente, se pide el nuevo
 *          nuevo valor de sector, se valida y se modifica.
 *
 * \param list Employee*
 * \param id int
 *
 */
void modifyEmployeeSector(Employee* list, int id);

/** \brief Dado un id de un Employee existente, se pide el nuevo
 *          nuevo valor de apellido, se valida y se modifica.
 *
 * \param list Employee*
 * \param id int
 *
 */
void modifyEmployeeLastName(Employee* list, int id);

/** \brief Dado un id de un Employee existente, se pide el nuevo
 *          nuevo valor de nombre, se valida y se modifica.
 *
 * \param list Employee*
 * \param id int
 *
 */
void modifyEmployeeName(Employee* list, int id);

/** \brief Imprime por pantalla:
 *          - El total de la suma de los sueldos,
 *          - El promedio de los sueldos, y
 *          - La cantidad de empleados por encima del sueldo promedio
 *
 * \param list Employee*
 * \param length int
 *
 */
void printExtraInformation(Employee* list, int length);

/** \brief Retorna la cantidad de empleados que se encuentran por encima
 *          del promedioSueldos
 *
 * \param list Employee*
 * \param length int
 * \param promedioSueldos float
 * \return int Entero que representa la cantidad de empleados
 *
 */
int contarEmpleadosArribaDelSueldoPromedio(Employee* list, int length, float promedioSueldos);
