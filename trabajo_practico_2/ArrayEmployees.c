#include <string.h>
#include <stdio_ext.h>
#include "Aux.h"
#include "ArrayEmployees.h"

#define FALSE     0
#define TRUE      1
#define C_LEN     30


/*******************************************
                FUNCIONES
 *******************************************/

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
