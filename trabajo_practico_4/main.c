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

/** \brief Define el ID leyendo el ultimo elemento de la lista y sumandole uno.
 *
 * \param pArrayListDesarrollador LinkedList*
 * \param newID int*
 * \return int Entero indicando (0) si hubo errores, o (1) si no los hay.
 *
 */
int defineID(LinkedList* pArrayListDesarrollador, int* newID);



int main()
{
    int option = 0;
    int proximoId = 1;
    int desde, hasta; // Lista filtrada
    int idAux;
    int resultado;
    char confirmaSalir = 'N';

    LinkedList* listaDesarrolladores = ll_newLinkedList();
    LinkedList* listaDadosDeBaja = ll_newLinkedList();
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
                    proximoId++;
                }
                break;

            case 2:
                system("clear");
                if( !ll_isEmpty(listaDesarrolladores) )
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
                if( !ll_isEmpty(listaDesarrolladores) )
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
                if( !ll_isEmpty(listaDesarrolladores) )
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
                if( !ll_isEmpty(listaDesarrolladores) )
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
                if( !ll_isEmpty(listaDesarrolladores) )
                {
                    copiaDeSeguridad = ll_newLinkedList();

                    if( copiaDeSeguridad != NULL )
                    {
                        copiaDeSeguridad = ll_clone( listaDesarrolladores );
                        controller_ListDeveloper( copiaDeSeguridad );
                        printf("\n\n    ->  COPIA DE SEGURIDAD GENERADA CORRECTAMENTE  <-\n\n");
                    }
                }
                else
                {
                    printf("\n\nNO HAY DESARROLLADORES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 7:
                system("clear");
                if( !ll_isEmpty(copiaDeSeguridad) )
                {
                    if( !ll_containsAll(copiaDeSeguridad, listaDesarrolladores) )
                    {
                        printf("\n\n ===> LA COPIA DE SEGURIDAD ESTA DESACTUALIZADA <=== \n\n");
                    }
                    else
                    {
                        if( ll_containsAll(copiaDeSeguridad, listaDesarrolladores) )
                        {
                            printf("\n\n ===> LA COPIA DE SEGURIDAD ESTA ACTUALIZADA <=== \n\n");
                        }
                    }
                }
                else
                {
                    printf("\n\nNO SE GENERO UNA COPIA DE SEGURIDAD EN EL SISTEMA.\n\n");
                }
                break;

            case 8:
                system("clear");
                if( !ll_isEmpty(listaDesarrolladores) )
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
                if( !ll_isEmpty(listaDesarrolladores) )
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
                system("clear");
                if( !ll_isEmpty(listaDesarrolladores) )
                {
                    if( !ll_clear( listaDesarrolladores ) )
                    {
                        proximoId = 1;
                        printf("\n\n    -> DESARROLLADORES BORRADOS CORRECTAMENTE <-\n\n");
                    }
                    else
                    {
                        printf("\n\n    -> OCURRIO UN ERROR INTENTANDO BORRAR LA LISTA DE DESARROLLADORES <-\n\n");
                    }
                }
                else
                {
                    printf("\n\n    -> NO HAY DESARROLLADORES CARGADOS EN EL SISTEMA <-\n\n");
                }
                break;

            case 11:
                system("clear");
                if( !ll_isEmpty(listaDesarrolladores) )
                {
                    aux_getEntero(&idAux, 1, "Ingrese ID de desarrollador a dar de baja: ", "Error. Ingrese un numero mayor a 0: ");
                    resultado = controller_findDeveloperById(listaDesarrolladores, idAux);

                    if( resultado == -1 )
                    {
                        printf("\n\n  ===> NO SE ENCONTRO UN DESARROLLADOR CON ESE ID.\n\n");
                    }
                    else
                    {
                        pDeveloper = (Developer*) ll_pop(listaDesarrolladores, resultado);

                        printf(" ====> EMPLEADO DADO DE BAJA <====== \n\n");
                        printDeveloper(pDeveloper);
                        printf("\n\n");

                        ll_add(listaDadosDeBaja, pDeveloper);
                    }
                }
                else
                {
                    printf("\n\n    -> NO HAY DESARROLLADORES CARGADOS EN EL SISTEMA <-\n\n");
                }
                break;

            case 12:
                system("clear");
                if( !ll_isEmpty(listaDadosDeBaja) )
                {
                    controller_ListDeveloper(listaDadosDeBaja);
                }
                else
                {
                    printf("\n\nNO HAY DESARROLLADORES DADOS DE BAJA EN EL SISTEMA.\n\n");
                }
                break;

            case 13:
                system("clear");
                if( !(controller_loadFromText("data.csv",listaDesarrolladores)) )
                {
                    defineID(listaDesarrolladores, &proximoId);
                    printf("\n\n\n      Desarrolladores cargados desde archivo de texto con exito!.\n\n\n");
                }
                else
                {
                    printf("\n\n\n      Ha ocurrido un error.\n\n\n");
                }
                break;

            case 14:
                if( !controller_saveAsText("data.csv",listaDesarrolladores) )
                {
                    system("clear");
                    printf("\n\n\n      Desarrolladores guardados como archivo de texto con exito!.\n\n\n");
                }
                break;

            case 15:
                confirmaSalir = aux_getConfirmacion("Seguro que desea salir? (s - si / n - no): ", "Error. Ingrese una opcion valida: ");
                break;

            default:
                printf("\n\n OPCION INCORRECTA! \n\n");
                break;
        }

        if( option != 15 )
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

    printf("\n");
    printf("                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                    ~~~~~~     MENU PRINCIPAL    ~~~~~~\n");
    printf("                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    printf("                1.  Alta de desarrollador(ll_add)\n");
    printf("                2.  Modificar datos de desarrollador(ll_set, ll_indexOf)\n");
    printf("                3.  Baja definitiva de desarrollador(ll_remove)\n");
    printf("                4.  Listar desarrolladores(ll_get)\n");
    printf("                5.  Ordenar desarrolladores(ll_sort)\n");
    printf("                6.  Generar copia de seguridad(ll_clone)\n");
    printf("                7.  Estado de la copia de seguridad(ll_containsAll)\n");
    printf("                8.  Mostrar rango de desarrolladores(ll_subList)\n");
    printf("                9.  Mostrar desarrollador por ID(ll_contains)\n");
    printf("                10. Limpiar lista de desarrolladores(ll_clear)\n");
    printf("                11. Baja de desarrollador y registrarla(ll_pop)\n");
    printf("                12. Mostrar desarrolladores dados de baja\n");
    printf("                13. Cargar datos desde archivo data.csv(modo texto).\n");
    printf("                14. Guardar datos en archivo data.csv(modo texto)\n\n");

    printf("                15. Salir\n\n");

    printf("                    Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int defineID(LinkedList* pArrayListDesarrollador, int* newID)
{
    int todoOk = 0;
    int arrayLen = ll_len(pArrayListDesarrollador);
    Developer* pDesarrolladorAux = NULL;

    if( pArrayListDesarrollador != NULL )
    {
        pDesarrolladorAux = (Developer*) ll_get(pArrayListDesarrollador, arrayLen-1);

        if( pDesarrolladorAux != NULL )
        {
            developer_getId(pDesarrolladorAux, newID);

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
