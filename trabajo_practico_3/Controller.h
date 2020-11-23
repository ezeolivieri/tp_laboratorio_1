int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Encuentra un empleado por su ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param findId int
 * \return int Entero que indica el la posicion del ID buscado en el array, o -1 en caso de no existir.
 *
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int findId);

/** \brief Despliegue de un submenu con los campos de un empleado como opciones a elegir
 *
 * \return int Entero que indica el campo elegido por el usuario
 *
 */
int subMenuEdicion();
