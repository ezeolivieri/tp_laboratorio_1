#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Aux.h"

#define AZUL_T      "\x1b[34m"
#define BLANCO_T    "\x1b[37m"


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
