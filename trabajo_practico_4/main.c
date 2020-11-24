#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Developer.h"
#include "Controller.h"
#include "aux.h"



/*********************** PROTOTIPOS ***********************/

/** \brief Despliegue de menu principal
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int menu();



int main()
{
    int option = 0;
    int proximoId = 1;
    int hayDesarrolladores = 0;
    int hayCopiaDeSeguridad = 0;
    int desde, hasta; // Lista filtrada
    int idAux;
    char confirmaSalir = 'N';

    LinkedList* listaDesarrolladores = ll_newLinkedList();
    LinkedList* copiaDeSeguridad = NULL;
    LinkedList* listaFiltrada = NULL;

    Developer* pDeveloper = NULL;



    do
    {
        system("clear");

        option = menu();

        switch(option)
        {
            case 1:
                system("clear");
                if( !controller_addDeveloper(listaDesarrolladores, proximoId) )
                {
                    if( !hayDesarrolladores )
                    {
                        hayDesarrolladores = 1;
                    }

                    proximoId++;
                }
                break;

            case 2:
                system("clear");
                if( hayDesarrolladores )
                {
                    controller_editDeveloper(listaDesarrolladores);
                }
                else
                {
                    printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 3:
                system("clear");
                if( hayDesarrolladores )
                {
                    controller_removeDeveloper(listaDesarrolladores);
                }
                else
                {
                    printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 4:
                system("clear");
                if( hayDesarrolladores )
                {
                    controller_ListDeveloper(listaDesarrolladores);
                }
                else
                {
                    printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 5:
                system("clear");
                if( hayDesarrolladores )
                {
                    controller_sortDeveloper(listaDesarrolladores);
                }
                else
                {
                    printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 6:
                system("clear");
                if( hayDesarrolladores )
                {
                    copiaDeSeguridad = ll_newLinkedList();

                    if( copiaDeSeguridad != NULL )
                    {
                        copiaDeSeguridad = ll_clone( listaDesarrolladores );
                        printf("\n\n    ->  COPIA DE SEGURIDAD GENERADA CORRECTAMENTE  <-\n\n");

                        hayCopiaDeSeguridad = 1;
                    }
                }
                else
                {
                    printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 7:
                system("clear");
                if( hayDesarrolladores && hayCopiaDeSeguridad )
                {
                    controller_ListDeveloper( copiaDeSeguridad );
                }
                else
                {
                    if( !hayDesarrolladores )
                    {
                        printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                    }
                    else if( !hayCopiaDeSeguridad )
                    {
                        printf("\n\nNO SE GENERO UNA COPIA DE SEGURIDAD EN EL SISTEMA.\n\n");
                    }
                }
                break;

            case 8:
                system("clear");
                if( hayDesarrolladores )
                {
                    if( ll_len(listaDesarrolladores) == 1 )
                    {
                        printf("\n\n    -> HAY UN SOLO DESARROLLADOR EN EL SISTEMA <-   \n\n");
                        printDeveloper( ll_get(listaDesarrolladores, 0) );
                        printf("\n\n");
                    }
                    else
                    {

                        desde = ll_len( listaDesarrolladores ) - 1;
                        hasta = ll_len( listaDesarrolladores );

                        printf("\n\n");

                        printf("Valor maximo posible DESDE: %d\n", desde);
                        printf("Valor maximo posible HASTA: %d\n", hasta);

                        printf("\n\n");

                        aux_getEntero(&desde, 0, "Ingrese desde que ID mostrar: ", "Error. Ingrese un valor mayor a 0: ");
                        aux_getEntero(&hasta, 0, "Ingrese hasta que ID mostrar: ", "Error. Ingrese un valor mayor a 0: ");

                        listaFiltrada = ll_newLinkedList();

                        if( listaFiltrada != NULL )
                        {
                            listaFiltrada = ll_subList(listaDesarrolladores, desde-1, hasta);
                            controller_ListDeveloper(listaFiltrada);
                        }
                    }
                }
                else
                {
                        printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 9:
                system("clear");
                if( hayDesarrolladores )
                {
                    aux_getEntero(&idAux, 0, "\n\nIngrese el ID del empleado a buscar: ", "Error. Ingrese un valor mayor a 0: ");
                    pDeveloper = (Developer*) ll_get(listaDesarrolladores, idAux-1);

                    if( ll_contains(listaDesarrolladores, pDeveloper) )
                    {
                        printf("\n\n  -> RESULTADO DE LA BUSQUEDA <-\n");
                        printDeveloper( pDeveloper );
                        printf("\n\n");
                    }
                    else
                    {
                        printf("\n\n    -> NO SE ENCONTRO NINGUN EMPLEADO CON ESE ID <-\n\n");
                    }
                }
                else
                {
                        printf("\n\n    -> NO HAY DESARROLLADORES CARGADOS EN EL SISTEMA <-\n\n");
                }
                break;

            case 10:
                confirmaSalir = aux_getConfirmacion("Seguro que desea salir? (s - si / n - no): ", "Error. Ingrese una opcion valida: ");
                break;

            default:
                printf("\n\n OPCION INCORRECTA! \n\n");
                break;
        }

        if( option != 10 )
        {
            system("read -p 'Press Enter to continue...' var");
        }

    } while( confirmaSalir != 'S' );

    return 0;
}




/*******************************
            FUNCIONES
 *******************************/

int menu()
{
    int opcion;

    printf("\n\n");
    printf("                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                ~~~~~~     MENU PRINCIPAL    ~~~~~~\n");
    printf("                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    printf("                1. Alta de desarrollador.(ll_add())\n");
    printf("                2. Modificar datos de desarrollador.(ll_get())\n");
    printf("                3. Baja de desarrollador.(ll_remove())\n");
    printf("                4. Listar desarrolladores.(ll_len())\n");
    printf("                5. Ordenar desarrolladores.(ll_sort())\n");
    printf("                6. Generar copia de seguridad.(ll_clone())\n");
    printf("                7. Mostrar copia de seguridad.\n");
    printf("                8. Mostrar desarrolladores (rango).(ll_subList())\n");
    printf("                9. Mostrar desarrollador por ID.(ll_contains())\n\n");

    printf("                10. Salir\n\n");

    printf("                    Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
