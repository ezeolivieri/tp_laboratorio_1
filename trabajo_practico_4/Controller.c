#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Developer.h"
#include "aux.h"
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListDeveloper)
{
    int retorno = -1;
    char idAux[900];
    char nameAux[900];
    char horasTrabajadasAux[900];
    char sueldoAux[900];
    FILE* fpArchivo;
    Developer* devAux = NULL;

    if( pArrayListDeveloper != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "r");

        if( fpArchivo != NULL )
        {
            do
            {
                if( fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, horasTrabajadasAux, sueldoAux) == 4 )
                {
                    devAux = developer_newParametrosChar(idAux, nameAux, horasTrabajadasAux, sueldoAux);

                    if( devAux != NULL )
                    {
                        ll_add(pArrayListDeveloper, devAux);
                    }
                }
            }
            while( !feof(fpArchivo) );

            fclose(fpArchivo);
            retorno = 0;
        }
        else
        {
            printf("\n\nERROR INTENTANDO ABRIR EL ARCHIVO.\n\n");
        }
    }

    return retorno;
}

/** \brief Alta de desarrolladores
 *
 * \param path char*
 * \param pArrayListDeveloper LinkedList*
 * \return int
 *
 */
int controller_addDeveloper(LinkedList* pArrayListDeveloper,int idDev)
{
    int retorno = -1;
    int horasTrabajadasAux;
    int sueldoAux;
    char nameAux[100];
    Developer* pDesarrolladorAux = NULL;

    if( pArrayListDeveloper != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ############## Alta de Desarrollador ##############\n");
        printf("    ###################################################\n\n");

        aux_getCadena(nameAux, "Ingrese nombre: ", " Error. Ingrese un nombre valido: ");
        aux_getEntero(&horasTrabajadasAux, 0, "Ingrese horas trabajadas: ", "Error. Ingrese una cantidad valida: ");
        aux_getEntero(&sueldoAux, 0, "Ingrese sueldo: ", "Error. Ingrese un sueldo valido: ");

        pDesarrolladorAux = developer_newParametros(idDev, nameAux, horasTrabajadasAux, sueldoAux);

        if( pDesarrolladorAux != NULL )
        {
            ll_add(pArrayListDeveloper, pDesarrolladorAux);
            printf("\n\n      DISTE DE ALTA EXITOSAMENTE A:\n\n");
            printDeveloper( pDesarrolladorAux );
            printf("\n\n");
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Modificar datos de Desarrollador
 *
 * \param path char*
 * \param pArrayListDeveloper LinkedList*
 * \return int
 *
 */
int controller_editDeveloper(LinkedList* pArrayListDeveloper)
{
    int retorno = -1;
    int respuesta;
    int indiceAux;
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    char confirmar;
    char nameAux[100];
    Developer* pDesarrolladorAux = NULL;
    Developer* pModifyDev = NULL;

    if( pArrayListDeveloper != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ############# Edicion de Desarrollador ############\n");
        printf("    ###################################################\n\n");

        aux_getEntero(&idAux, 1, "Ingrese ID del Desarrollador a modificar: ", "Error. Ingrese un id valido: ");

        indiceAux = controller_findDeveloperById(pArrayListDeveloper, idAux);

        if( indiceAux == -1 )
        {
            printf("\n\n     NO SE ENCONTRO UN DESARROLLADOR CON ESE ID.\n\n");
        }
        else
        {
            pDesarrolladorAux = (Developer*) ll_get(pArrayListDeveloper, indiceAux);

            developer_getNombre(pDesarrolladorAux, nameAux);
            developer_getHorasTrabajadas(pDesarrolladorAux, &horasTrabajadasAux);
            developer_getSueldo(pDesarrolladorAux, &sueldoAux);

            printf("\n  #####  DESARROLLADOR A MODIFICAR  #####  \n");
            printDeveloper(pDesarrolladorAux);

            respuesta = subMenuEdicion();

            switch( respuesta )
            {
                case 1:
                    aux_getCadena(nameAux, "Ingrese nuevo nombre: ", "Error. Reingrese: ");
                    confirmar = aux_getConfirmacion("Confirma la modificacion? s - si / n - no: ", "\nERROR. Escriba una opcion valida: ");
                    if( confirmar == 'S' )
                    {
                        pModifyDev = developer_newParametros(idAux, nameAux, horasTrabajadasAux, sueldoAux);

                        if( pModifyDev != NULL )
                        {
                            ll_set( pArrayListDeveloper, ll_indexOf(pArrayListDeveloper, pDesarrolladorAux), pModifyDev);
                            printf("\n\n##### Edicion realizada con exito. #####\n\n");
                        }
                    }
                    else
                    {
                        printf("\n\n     EDICION CANCELADA.     \n\n");
                    }
                    break;

                case 2:
                    aux_getEntero(&horasTrabajadasAux, 0, "Ingrese la modificacion de horas trabajadas: ", "Error. Reingrese: ");
                    confirmar = aux_getConfirmacion("Confirma la modificacion? s - si / n - no: ", "\nERROR. Escriba una opcion valida: ");
                    if( confirmar == 'S' )
                    {
                        pModifyDev = developer_newParametros(idAux, nameAux, horasTrabajadasAux, sueldoAux);

                        if( pModifyDev != NULL )
                        {
                            ll_set( pArrayListDeveloper, ll_indexOf(pArrayListDeveloper, pDesarrolladorAux), pModifyDev);
                            printf("\n\n##### Edicion realizada con exito. #####\n\n");
                        }
                    }
                    else
                    {
                        printf("\n\n     EDICION CANCELADA.     \n\n");
                    }
                    break;

                case 3:
                    aux_getEntero(&sueldoAux, 0, "Ingrese la modificacion de sueldo: ", "Error. Reingrese: ");
                    confirmar = aux_getConfirmacion("Confirma la modificacion? s - si / n - no: ", "\nERROR. Escriba una opcion valida: ");
                    if( confirmar == 'S' )
                    {
                        pModifyDev = developer_newParametros(idAux, nameAux, horasTrabajadasAux, sueldoAux);

                        if( pModifyDev != NULL )
                        {
                            ll_set( pArrayListDeveloper, ll_indexOf(pArrayListDeveloper, pDesarrolladorAux), pModifyDev);
                            printf("\n\n##### Edicion realizada con exito. #####\n\n");
                        }
                    }
                    else
                    {
                        printf("\n\n     EDICION CANCELADA.     \n\n");
                    }
                    break;
            }
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Baja de Desarrollador
 *
 * \param path char*
 * \param pArrayListDeveloper LinkedList*
 * \return int
 *
 */
int controller_removeDeveloper(LinkedList* pArrayListDeveloper)
{
    int retorno = -1;
    int indiceAux;
    int idRemove;
    char confirmar;
    Developer* pDesarrolladorAux;

    if( pArrayListDeveloper != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ############# Baja de Desarrollador ###############\n");
        printf("    ###################################################\n\n");

        aux_getEntero(&idRemove, 1, "Ingrese ID del Desarrollador: ", "Error. Ingrese un id valido: ");

        indiceAux = controller_findDeveloperById(pArrayListDeveloper, idRemove);

        if( indiceAux == -1 )
        {
            printf("\n\n     NO SE ENCONTRO UN DESARROLLADOR CON ESE ID.\n\n");
        }
        else
        {
            pDesarrolladorAux = (Developer*) ll_get(pArrayListDeveloper, indiceAux);
            printf("\n  #####  DESARROLLADOR A DAR DE BAJA  #####  \n");
            printDeveloper(pDesarrolladorAux);

            confirmar = aux_getConfirmacion("Confirma la baja? s - si / n - no: ", "\nERROR. Escriba una opcion valida: ");

            if( confirmar == 'S' )
            {
                ll_remove( pArrayListDeveloper, indiceAux );
                printf("\n\n##### Baja realizada con exito. #####\n\n");
            }
            else
            {
                printf("\n\n     BAJA CANCELADA.     \n\n");
            }
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Listar desarrolladores
 *
 * \param path char*
 * \param pArrayListDeveloper LinkedList*
 * \return int
 *
 */
int controller_ListDeveloper(LinkedList* pArrayListDeveloper)
{
    int retorno = -1;
    Developer* pDesarrolladorAux = NULL;
    int arrayLen = ll_len(pArrayListDeveloper);

    if( pArrayListDeveloper != NULL )
    {
        printf("\n\n");

        printf("    ###################################################\n");
        printf("    ############ LISTA DE DESARROLLADORES #############\n");
        printf("    ###################################################\n\n");

        printf("   ID   |     Nombre     |  Horas  |   Sueldo   \n");
        printf("------------------------------------------------\n\n");

        for( int i=0; i<arrayLen; i++ )
        {
            pDesarrolladorAux = (Developer*) ll_get(pArrayListDeveloper, i);

            if( pDesarrolladorAux != NULL )
            {
                printDeveloper( pDesarrolladorAux );
            }
        }

        printf("\n\n");

        retorno = 0;
    }

    return retorno;
}

/** \brief Ordenar desarrolladores
 *
 * \param path char*
 * \param pArrayListDeveloper LinkedList*
 * \return int
 *
 */
int controller_sortDeveloper(LinkedList* pArrayListDeveloper)
{
    int retorno = -1;
    int respuesta;
    int criterio;

    if( pArrayListDeveloper != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ############# Ordenar Desarrolladores #############\n");
        printf("    ###################################################\n\n");

        printf("           ====== CAMPOS =======\n");
        printf("1- ID\n");
        printf("2- Horas de Trabajo\n");
        printf("3- Nombre\n");
        printf("4- Sueldo\n\n");

        printf("5- Volver al menu principal\n\n");

        aux_getEnteroEntre(&respuesta, 1, 5, "Respuesta: ", "Error. ingrese una opcion valida: ");
        aux_getEnteroEntre(&criterio, 0, 1, "Criterio? 0 - Ascendente / 1 - Descendente: ", "Error. ingrese una opcion valida: ");

        switch(respuesta)
        {
            case 1:
                if( !ll_sort(pArrayListDeveloper,dev_sortById,criterio) )
                {
                    printf("Ordenado con exito!\n");
                }
                else
                {
                    printf("\n\nOcurrio un error al intentar ordenar.\n");
                }
                break;

            case 2:
                if( !ll_sort(pArrayListDeveloper,dev_sortByHorasTrabajadas,criterio) )
                {
                    printf("\n\nOrdenado con exito!\n");
                }
                else
                {
                    printf("\n\nOcurrio un error al intentar ordenar.\n");
                }
                break;

            case 3:
                if( !ll_sort(pArrayListDeveloper,dev_sortByNombre,criterio) )
                {
                    printf("Ordenado con exito!\n");
                }
                else
                {
                    printf("\n\nOcurrio un error al intentar ordenar.\n");
                }
                break;

            case 4:
                if( !ll_sort(pArrayListDeveloper,dev_sortBySueldo,criterio) )
                {
                    printf("Ordenado con exito!\n");
                }
                else
                {
                    printf("\n\nOcurrio un error al intentar ordenar.\n");
                }
                break;
        }

        retorno = 0;
    }

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListDeveloper)
{
    int retorno = -1;
    FILE* fpArchivo;
    int arrayLen = ll_len(pArrayListDeveloper);
    Developer* pDeveloperAux = NULL;
    int idAux;
    char nameAux[128];
    int horasTrabajadasAux;
    int sueldoAux;

    if( pArrayListDeveloper != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "w");

        if( fpArchivo != NULL )
        {
            for( int i=0; i < arrayLen; i++ )
            {
                pDeveloperAux = (Developer*) ll_get(pArrayListDeveloper, i);

                if( pDeveloperAux != NULL )
                {
                    if(!( developer_getId(pDeveloperAux, &idAux) &&
                          developer_getNombre(pDeveloperAux, nameAux) &&
                          developer_getHorasTrabajadas(pDeveloperAux, &horasTrabajadasAux) &&
                          developer_getSueldo(pDeveloperAux, &sueldoAux) ) )
                    {
                        fprintf(fpArchivo, "%d,%s,%d,%d\n", idAux, nameAux, horasTrabajadasAux, sueldoAux);
                    }
                }
            }

            fclose(fpArchivo);
            retorno = 0;
        }
    }

    return retorno;
}

int controller_findDeveloperById(LinkedList* pArrayListDeveloper, int findId)
{
    int indiceAux = -1;
    int arrayLen = ll_len(pArrayListDeveloper);
    Developer* pDesarrolladorAux = NULL;

    if( pArrayListDeveloper != NULL )
    {
        for( int i=0; i<arrayLen; i++ )
        {
            pDesarrolladorAux = (Developer*) ll_get(pArrayListDeveloper, i);

            if( pDesarrolladorAux != NULL )
            {
                if( pDesarrolladorAux->id == findId )
                {
                    indiceAux = i;

                    break;
                }
            }
        }
    }

    return indiceAux;
}

int subMenuEdicion()
{
    int opcion;

    printf("\n\n##### CAMPO A MODIFICAR #####\n");
    printf("1- Nombre.\n");
    printf("2- Horas de Trabajo.\n");
    printf("3- Sueldo.\n\n");
    printf("4. Cancelar.\n\n");

    printf("Respuesta: ");
    scanf("%d",&opcion);

    while( opcion < 1 || opcion > 4 )
    {
        printf("ERROR. Respuesta: ");
        scanf("%d",&opcion);
    }

    return opcion;
}
