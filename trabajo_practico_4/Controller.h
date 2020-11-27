int controller_loadFromText(char* path , LinkedList* pArrayListDeveloper);
int controller_addDeveloper(LinkedList* pArrayListDeveloper,int id);
int controller_editDeveloper(LinkedList* pArrayListDeveloper);
int controller_removeDeveloper(LinkedList* pArrayListDeveloper);
int controller_ListDeveloper(LinkedList* pArrayListDeveloper);
int controller_sortDeveloper(LinkedList* pArrayListDeveloper);
int controller_saveAsText(char* path , LinkedList* pArrayListDeveloper);

/** \brief Encuentra un empleado por su ID
 *
 * \param pArrayListDeveloper LinkedList*
 * \param findId int
 * \return int Entero que indica el la posicion del ID buscado en el array, o -1 en caso de no existir.
 *
 */
int controller_findDeveloperById(LinkedList* pArrayListDeveloper, int findId);

/** \brief Despliegue de un submenu con los campos de un empleado como opciones a elegir
 *
 * \return int Entero que indica el campo elegido por el usuario
 *
 */
int subMenuEdicion();
