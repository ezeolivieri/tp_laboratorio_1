#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"



/*********************** PROTOTIPOS ***********************/

/** \brief Despliegue de menu principal
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int menu();

/** \brief Define el ID leyendo el ultimo elemento de la lista y sumandole uno.
 *
 * \param pArrayListEmployee LinkedList*
 * \param newID int*
 * \return int Entero indicando (0) si hubo errores, o (1) si no los hay.
 *
 */
int defineID(LinkedList* pArrayListEmployee, int* newID);






int main()
{

    int option = 0;
    int hayEmpleados = 0;
    int proximoId = 1;

    LinkedList* listaEmpleados = ll_newLinkedList();


    do
    {
        system("clear");

        option = menu();

        switch(option)
        {
            case 1:
                system("clear");
                if( !(controller_loadFromText("data.csv",listaEmpleados)) )
                {
                    if( !hayEmpleados )
                    {
                        hayEmpleados = 1;
                    }

                    defineID(listaEmpleados, &proximoId);
                    printf("\n\n\n      Empleados cargados desde archivo de texto con exito!.\n\n\n");
                }
                else
                {
                    printf("\n\n\n      Ha ocurrido un error.\n\n\n");
                }
                break;

            case 2:
                system("clear");
                if( !controller_loadFromBinary("data.bin",listaEmpleados) )
                {
                    if( !hayEmpleados )
                    {
                        hayEmpleados = 1;
                    }

                    defineID(listaEmpleados, &proximoId);
                    printf("\n\n\n       Empleados cargados desde archivo binario con exito!.\n\n\n");
                }
                else
                {
                    printf("\n\n\n      Ha ocurrido un error.\n\n\n");
                }
                break;

            case 3:
                system("clear");
                if( !controller_addEmployee(listaEmpleados, proximoId) )
                {
                    if( !hayEmpleados )
                    {
                        hayEmpleados = 1;
                    }
                    proximoId++;
                }
                break;

            case 4:
                system("clear");
                if( hayEmpleados )
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("\n\nNO HAY EMPLEADOS CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 5:
                system("clear");
                if( hayEmpleados )
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("\n\nNO HAY EMPLEADOS CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 6:
                system("clear");
                if( hayEmpleados )
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("\n\nNO HAY EMPLEADOS CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 7:
                system("clear");
                if( hayEmpleados )
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\n\nNO HAY EMPLEADOS CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 8:
                if( !controller_saveAsText("data.csv",listaEmpleados) ){
                    system("clear");
                    printf("\n\n\n      Empleados guardados como archivo de texto con exito!.\n\n\n");
                }
                break;

            case 9:
                if( !controller_saveAsBinary("data.bin",listaEmpleados) ){
                    system("clear");
                    printf("\n\n\n       Empleados cargados como archivo binario con exito!.\n\n\n");
                }
                break;
        }

        if( option != 10 )
        {
            // pauso la ejecución del programa
            system("read -p 'Press Enter to continue...' var");
        }

    }while(option != 10);

    return 0;

}





/*******************************
            FUNCIONES
 *******************************/

int menu()
{
    int opcion;
    // system("clear");

    printf("\n\n             ~~~~~~   MENU PRINCIPAL   ~~~~~~\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
    printf("             Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int defineID(LinkedList* pArrayListEmployee, int* newID)
{
    int todoOk = 0;
    int arrayLen = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux = NULL;

    if( pArrayListEmployee != NULL )
    {
        pEmpleadoAux = (Employee*) ll_get(pArrayListEmployee, arrayLen-1);

        if( pEmpleadoAux != NULL )
        {
            employee_getId(pEmpleadoAux, newID);

            *newID = *newID + 1;
        }
        else
        {
            *newID = -1;
        }

        todoOk = 1;
    }

    return todoOk;
}





