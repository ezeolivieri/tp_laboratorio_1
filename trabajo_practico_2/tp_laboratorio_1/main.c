/*********************************************************
* Programa: Trabajo Práctico 2

* Objetivos:
    - Manejo de arrays
    - Manejo de pasaje por referencia
    - Manejo de estructuras

* Enunciado:
    Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
    dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

* Autor: Olivieri, Ezequiel Agustin
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#define TRUE      1
#define FALSE     0
#define ELEMENTS  6
#define NAME_LEN  51
#define LNAME_LEN 51
#define C_LEN     30
#define AZUL_T      "\x1b[34m"
#define BLANCO_T    "\x1b[37m"
#define VERDE_T     "\x1b[32m"
#define ROJO_T      "\x1b[31m"
#define AMARILLO_T  "\x1b[33m"



// ESTRUCTURA DE UN EMPLEADO
typedef struct {

    int id;
    char name[NAME_LEN];
    char lastName[LNAME_LEN];
    float salary;
    int sector;
    int isEmpty;

} Employee;





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

/** \brief Muestra por pantalla un mensaje de confirmacion de salida y retorna la respuesta ingresada
 *
 * \return char Caracter que representa la confirmación de la salida
 *
 */
char confirmacionSalida();

void formAddEmployee(Employee* list, int length);

void pedirNombre(char cadena[], char mensajeParaPedir[], char mensajeDeError[]);

int esCadenaAlfabetica(char cadena[]);

void formatoDeNombre(char cadena[]);

float pedirFlotante(char mensajeParaPedir[], float minimo, float maximo, char mensajeDeError[]);

int pedirEntero(char mensajeParaPedir[], int minimo, int maximo, char mensajeDeError[]);

void errorController(int x);

void formModifyEmployee(Employee* list, int length);

void modifyEmployeeAttribute(Employee* list, int id);

void switchToModify(Employee* list, char* campo, int id);

void modifyEmployeeSalary(Employee* list, int id);

void modifyEmployeeSector(Employee* list, int id);

void modifyEmployeeLastName(Employee* list, int id);

void modifyEmployeeName(Employee* list, int id);

void cadenaMayuscula(char cadena[]);

void formDeleteEmployee(Employee* list, int length);

void formPrintEmployee(Employee* list, int length);

void printExtraInformation(Employee* list, int length);

int contarEmpleadosArribaDelSueldoPromedio(Employee* list, int length, float promedioSueldos);






/*****************************************
                    MAIN
 *****************************************/
int main()
{
    int continuar = TRUE; // Condicion para continuar en el programa
    Employee empleados[ELEMENTS];
    int ingresados = 0; // Bandera para verificar los ingresos


    // Inicializo todas las posiciones de empleados con isEmpty = TRUE
    initEmployees( empleados, ELEMENTS );


    do
    {

        // limpio pantalla luego de cada iteración sobre el switch
        system("clear");


        switch( menu() )
        {
            case 1:
                formAddEmployee( empleados, ELEMENTS );
                ingresados++;

                break;

            case 2:
                if( ingresados )
                    formModifyEmployee( empleados, ELEMENTS );
                else
                    printf(AMARILLO_T "\nPara modificar, primero debes ingresar un empleado.\n");

                break;

            case 3:
                if( ingresados )
                {
                    formDeleteEmployee( empleados, ELEMENTS );
                    ingresados--;
                }
                else
                {
                    printf(AMARILLO_T "\nPara dar de baja, primero debes ingresar un empleado.\n");
                }

                break;

            case 4:
                if( ingresados )
                    formPrintEmployee( empleados, ELEMENTS );
                else
                    printf(AMARILLO_T "\nPara informar, primero debes ingresar un empleado.\n");

                break;

            case 5:
                if ( confirmacionSalida() == 's' )
                    continuar = FALSE;

                break;

            default:
                __fpurge(stdin);
                printf(ROJO_T "\n\nOpcion invalida.\n\n");

                break;
        }


        // pauso la ejecución del programa para poder mostrar lo sucedido en el main
        system("read -p 'Press Enter to continue...' var");


    } while( continuar );


    return 0;
}







/*******************************************
                FUNCIONES
 *******************************************/


int menu()
{
    int opcion; // opcion seleccionada

    printf(AZUL_T"         ===========================================================\n");
    printf(AZUL_T"         ======                    EMPRESA UTN                ======\n");
    printf(AZUL_T"         ===========================================================\n\n");

    printf("         1. ALTA DE EMPLEADO\n");
    printf("         2. MODIFICACION DE EMPLEADO\n");
    printf("         3. BAJA DE EMPLEADO\n");
    printf("         4. INFORMAR\n");
    printf("            # EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR.\n");
    printf("            # TOTAL Y PROMEDIO DE SALARIOS.\n");
    printf("                 CANTIDAD EMPLEADOS ARRIBA DEL SALARIO PROMEDIO.\n");
    printf("         5. SALIR\n\n");

    printf("Tu respuesta es: ");
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee* list, int len)
{
    int error = -1;

    if( list != NULL && len > 0 )
    {
        error = 0;
        for( int i = 0; i < len; i++)
        {
            list[i].isEmpty = TRUE;
        }
    }

    return error;
}

int addEmployee(Employee* list, int len, char name[], char lastName[], float salary, int sector)
{
    int error = -1;
    int p = 0;

    if( list != NULL && len > 0 )
    {
        while( p < len )
        {
            if( list[p].isEmpty == TRUE )
            {
                list[p].id = p+1;
                strcpy(list[p].name,name);
                strcpy(list[p].lastName,lastName);
                list[p].salary = salary;
                list[p].sector = sector;
                list[p].isEmpty = FALSE;

                error = 0;
                p = len;
            }
            else
            {
                p++;
            }
        }
    }

    return error;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int employeeID = -1;
    int i = 0;

    if( list != NULL && len > 0 )
    {
        while( i < len )
        {
            if( list[i].id == id )
            {
                employeeID = i;
                i = len;
            }
            else
            {
                i++;
            }
        }
    }

    return employeeID;
}

int removeEmployee(Employee* list, int len, int id)
{
    int error = -1;
    int i = 0;

    if( list != NULL && len > 0 )
    {
        while( i < len )
        {
            if( list[i].id == id && list[i].isEmpty == FALSE )
            {
                list[i].isEmpty = TRUE;
                strcpy(list[i].lastName,"");
                strcpy(list[i].name,"");
                list[i].salary = 0;
                list[i].sector = 0;
                error = 0;
                i = len;
            }
            else
            {
                i++;
            }
        }
    }

    return error;
}

int sortEmployees(Employee* list, int len, int order)
{
    int error = -1;

    if( list != NULL && len > 0 )
    {
        error = 0;

        for( int i = 0; i < len-1; i++ )
        {
            for( int j = i+1; j < len; j++ )
            {
                if( ( list[i].sector > list[j].sector && order ) ||
                    ( list[i].sector < list[j].sector && !order ) )
                {
                    employeeSwap(&list[i], &list[j]);
                }
                else if( list[i].sector == list[j].sector )
                {
                    if( ( strcmp(list[i].lastName, list[j].lastName) > 0 && order ) ||
                        ( strcmp(list[i].lastName, list[j].lastName) < 0 && !order ) )
                        employeeSwap(&list[i], &list[j]);
                }
            }
        }
    }

    return error;
}

int printEmployees(Employee* list, int length)
{
    int error = -1;
    int id;
    int sector;
    char name[NAME_LEN];
    char lastN[LNAME_LEN];
    float sueldo;

    if( list != NULL && length > 0 )
    {
        error = 0;

        printf("\n\n ID |   NOMBRE   |   APELLIDO   |   SUELDO   | SECTOR \n");
        printf("______________________________________________________\n");

        for(int i = 0; i < length; i++)
        {
            if( list[i].isEmpty == FALSE )
            {
                id = list[i].id;
                strcpy(name, list[i].name);
                strcpy(lastN, list[i].lastName);
                sueldo = list[i].salary;
                sector = list[i].sector;

                printf("%04d    %-10s   %-10s     %.2f     %d\n", id, name, lastN, sueldo, sector);
            }
        }
    }

    return error;
}

int employeeSwap(Employee* a, Employee* b)
{
    int error = -1;

    if( a != NULL && b != NULL)
    {
        error = 0;
        Employee aux;

        aux = *a;
        *a = *b;
        *b = aux;
    }

    return error;
}

char confirmacionSalida()
{
    char confirm;

    printf(BLANCO_T "\n\nEstá seguro que desea salir?\n\n");
    __fpurge(stdin);
    scanf("%c", &confirm);
    confirm = tolower(confirm);

    return confirm;
}

void formAddEmployee(Employee* list, int length)
{
    Employee newEmployee;
    int resultado;

    // Ingreso del nombre
    pedirNombre(newEmployee.name, "Ingrese el nombre: ", "Ingreso erróneo. Porfavor reingrese: ");
    // Ingreso del apellido
    pedirNombre(newEmployee.lastName, "Ingrese el apellido: ", "Ingreso erróneo. Porfavor reingrese: ");
    // Ingreso del sueldo
    newEmployee.salary = pedirFlotante("Ingrese salario: ", 0, 1000000, "No es un salario válido. Reingrese: ");
    // Ingreso del sector
    newEmployee.sector = pedirEntero("Ingrese sector: ", 0, 100, "No es un sector válido. Reingrese: ");

    resultado = addEmployee(list, length, newEmployee.name, newEmployee.lastName, newEmployee.salary, newEmployee.sector);
    errorController(resultado);
}

void pedirNombre(char cadena[], char mensajeParaPedir[], char mensajeDeError[])
{
    printf("%s", mensajeParaPedir);
    __fpurge(stdin);
    scanf("%[^\n]", cadena);
    while( !esCadenaAlfabetica(cadena) ) {
        printf("%s", mensajeDeError);
        __fpurge(stdin);
        scanf("%[^\n]", cadena);
    }

    formatoDeNombre(cadena);
}

void pedirCadena(char cadena[], char mensajeParaPedir[], char mensajeDeError[])
{
    printf("%s", mensajeParaPedir);
    __fpurge(stdin);
    scanf("%s", cadena);
    while( !esCadenaAlfabetica(cadena) ) {
        printf("%s", mensajeDeError);
        __fpurge(stdin);
        scanf("%s", cadena);
    }
}

int esCadenaAlfabetica(char cadena[])
{
    int esValida = TRUE;
    int i = 0;

    // Recorro la cadena de caracteres hasta encontrar el "ENTER"
    while( cadena[i] != '\0' )
    {
        // La primer condicion indica si el codigo ASCII es menor a la del espacio
        // La segunda condicion es para ver si está entre el espacio y A mayuscula
        // La tercera indica si esta entre Z mayuscula y a minuscula
        // La cuarta es para ver si es posterior a Z mayuscula
        if(  cadena[i] < 32 ||
            (cadena[i] > 32 && cadena[i] < 65) ||
            (cadena[i] > 90 && cadena[i] < 97) ||
             cadena[i] > 122  )
             esValida = FALSE;

        i++;
    }

    return esValida;
}

void formatoDeNombre(char cadena[])
{
    int i = 0;

    // El primer caracter lo convierto a mayuscula
    cadena[i] = toupper( cadena[i] );
    i++;

    while( cadena[i] != '\0' )
    {
        // Analizo si hay un espacio en la cadena
        // Si lo hay, avanzo una posicion y pongo una mayuscula
        // Si no hay, convierto el caracter en minuscula
        if( cadena[i] == 32 )
        {
            i++;
            cadena[i] = toupper( cadena[i] );
        } else {
            cadena[i] = tolower( cadena[i] );
        }

        i++;
    }
}

float pedirFlotante(char mensajeParaPedir[], float minimo, float maximo, char mensajeDeError[])
{
    float flotante;

    printf("%s", mensajeParaPedir);
    scanf("%f", &flotante);

    while( flotante < minimo || flotante > maximo )
    {
        printf("%s", mensajeDeError);
        scanf("%f", &flotante);
    }

    return flotante;
}

int pedirEntero(char mensajeParaPedir[], int minimo, int maximo, char mensajeDeError[])
{
    int entero;

    printf("%s", mensajeParaPedir);
    scanf("%d", &entero);

    while( entero < minimo || entero > maximo )
    {
        printf("%s", mensajeDeError);
        scanf("%d", &entero);
    }

    return entero;
}

void errorController( int x )
{
    if( x >= 0 )
        printf(VERDE_T "\nFinished Succesfully [0 error(s)]\n");
    else
        printf(ROJO_T "\nError [Invalid length or NULL pointer]\n");
}

void formModifyEmployee(Employee* list, int length)
{
    int id;
    int resultado;

    id = pedirEntero("Ingrese el ID del empleado a modificar: ", 1, 1000, "No es un ID válido. Reingrese: ");

    resultado = findEmployeeById(list, length, id);

    if( resultado >= 0 )
        modifyEmployeeAttribute( list, resultado );

    errorController(resultado);
}

void modifyEmployeeAttribute(Employee* list, int id)
{
    char modificarCampo[C_LEN];

    pedirCadena(modificarCampo, "Ingrese el campo a modificar: ", "Error. Reingrese: ");
    cadenaMayuscula(modificarCampo);

    while( !(strcmp(modificarCampo,"NOMBRE") == 0) &&
           !(strcmp(modificarCampo,"APELLIDO") == 0) &&
           !(strcmp(modificarCampo,"SUELDO") == 0) &&
           !(strcmp(modificarCampo,"SECTOR") == 0 ) )
    {
        printf("No es un campo valido: ");
        __fpurge(stdin);
        scanf("%s", modificarCampo);
        cadenaMayuscula(modificarCampo);
    }

    switchToModify(list, modificarCampo, id);
}

void switchToModify(Employee* list, char campo[], int id)
{
    if( strcmp(campo, "NOMBRE") == 0 )
        modifyEmployeeName(list, id);

    if( strcmp(campo, "APELLIDO") == 0 )
        modifyEmployeeLastName(list, id);

    if( strcmp(campo, "SUELDO") == 0 )
        modifyEmployeeSalary(list, id);

    if( strcmp(campo, "SECTOR") == 0 )
        modifyEmployeeSector(list, id);
}

void modifyEmployeeSalary(Employee* list, int id)
{
    float newSalary;

    newSalary = pedirFlotante("Ingrese el nuevo sueldo: ", 0, 1000000, "Error. Reingrese: ");
    list[id].salary = newSalary;
}

void modifyEmployeeSector(Employee* list, int id)
{
    int newSector;

    newSector = pedirEntero("Ingrese el nuevo sector: ", 0, 50, "Error. Reingrese: ");
    list[id].sector = newSector;
}

void modifyEmployeeLastName(Employee* list, int id)
{
    char newLastName[LNAME_LEN];

    pedirNombre(newLastName, "Ingrese el nuevo apellido: ", "Error. Reingrese: ");
    strcpy(list[id].lastName, newLastName);
}

void modifyEmployeeName(Employee* list, int id)
{
    char newName[NAME_LEN];

    pedirNombre(newName, "Ingrese el nuevo nombre: ", "Error. Reingrese: ");
    strcpy(list[id].name, newName);
}

void cadenaMayuscula(char cadena[])
{
    int i = 0;

    while( cadena[i] != '\0')
    {
        cadena[i] = toupper( cadena[i] );
        i++;
    }
}

void formDeleteEmployee(Employee* list, int length)
{
    int id;
    int resultado;

    id = pedirEntero("Ingrese el ID del empleado a dar de baja: ", 1, 1000, "No es un ID válido. Reingrese: ");

    resultado = findEmployeeById(list, length, id);

    if( resultado >= 0 )
        removeEmployee( list, length, id );

    if( resultado == 0 )
    {
        resultado++;
        errorController(resultado);
    } else {
        errorController(resultado);
    }
}

void formPrintEmployee(Employee* list, int length)
{
    int respuesta;
    int resultado;
    int order;

    printf("\n1) Empleados ordenados alfabeticamente por apellido y sector.\n");
    printf("2) Total y promedio de sueldos. Empleados arriba del sueldo promedio.\n");
    respuesta = pedirEntero("Respuesta [ 1 / 2 ] :", 1, 2, "Respuesta incorrecta: ");

    if( respuesta == 1 ) {
        order = pedirEntero("1-Ascendente / 0-Descendente: ", 0, 1, "Respuesta incorrecta: ");
        resultado = sortEmployees(list, length, order);

        if( resultado != -1 )
        {
            printEmployees(list, length);
            errorController(resultado);
        }
    }

    if( respuesta == 2 )
        printExtraInformation(list, length);
}

void printExtraInformation(Employee* list, int length)
{
    float promedioSueldos = 0;
    float totalSueldos = 0;
    int cantidadSueldosSumados = 0;
    int empleadosArribaDeSueldoPromedio;

    for( int i = 0; i < length; i++ )
    {
        if( list[i].isEmpty == FALSE )
        {
            totalSueldos += list[i].salary;
            cantidadSueldosSumados++;
        }
    }

    promedioSueldos = totalSueldos / cantidadSueldosSumados;

    empleadosArribaDeSueldoPromedio = contarEmpleadosArribaDelSueldoPromedio(list, length, promedioSueldos);

    printf("\nEl total de la suma de los sueldos es: %.3f\n", totalSueldos);
    printf("\nEl promedio de los sueldos es: %.3f\n", promedioSueldos);
    printf("\nLa cantidad de empleados arriba del sueldo promedio es: %d\n", empleadosArribaDeSueldoPromedio);
}

int contarEmpleadosArribaDelSueldoPromedio(Employee* list, int length, float promedioSueldos)
{
    int contador = 0;

    for( int i = 0; i < length; i++ )
    {
        if( list[i].salary > promedioSueldos )
        {
            contador++;
        }
    }

    return contador;
}
