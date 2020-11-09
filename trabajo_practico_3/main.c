#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"





/***********************
        PROTOTIPOS
 ***********************/

/** \brief Despliegue de menu principal
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int menu();







int main()
{

    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("clear");

        option = menu();

        switch(option)
        {
            case 1:
                if( controller_loadFromText("data.csv",listaEmpleados) ){
                    system("clear");
                    printf("\n\n\n      Empleados cargados desde archivo de texto con exito!.\n");
                }
                break;

            case 2:
                if( controller_loadFromBinary("data.bin",listaEmpleados) ){
                    system("clear");
                    printf("\n\n\n       Empleados cargados desde archivo binario con exito!.\n");
                }
                break;

            case 3:
                break;
            case 4:
                break;
            case 5:
                break;

            case 6:
                system("clear");
                controller_ListEmployee(listaEmpleados);
                break;

            case 7:
                break;

            case 8:
                if( controller_saveAsText("data.csv",listaEmpleados) ){
                    system("clear");
                    printf("\n\n\n      Empleados guardados como archivo de texto con exito!.\n");
                }
                break;

            case 9:
                if( controller_saveAsBinary("data.bin",listaEmpleados) ){
                    system("clear");
                    printf("\n\n\n       Empleados cargados como archivo binario con exito!.\n");
                }
                break;
        }

        if(option != 10){
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
    system("clear");

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







