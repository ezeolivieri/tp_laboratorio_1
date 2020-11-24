#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "aux.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char idAux[900];
    char nameAux[900];
    char horasTrabajadasAux[900];
    char sueldoAux[900];
    FILE* fpArchivo;
    Employee* empAux = NULL;

    if( pArrayListEmployee != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "r");

        if( fpArchivo != NULL )
        {
            do
            {
                if( fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, horasTrabajadasAux, sueldoAux) == 4 )
                {
                    empAux = employee_newParametrosChar(idAux, nameAux, horasTrabajadasAux, sueldoAux);

                    if( empAux != NULL )
                    {
                        ll_add(pArrayListEmployee, empAux);
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* fpArchivo;
    Employee* empAux = NULL;

    if( path != NULL && pArrayListEmployee != NULL )
    {
        fpArchivo = fopen(path, "rb");

        if( fpArchivo != NULL )
        {
            do
            {
                empAux = employee_new();

                if( empAux != NULL )
                {
                    if( fread( empAux, sizeof(Employee), 1,  fpArchivo ) > 0 )
                    {
                        ll_add(pArrayListEmployee, empAux);
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int idEmp)
{
    int retorno = -1;
    int horasTrabajadasAux;
    int sueldoAux;
    char nameAux[100];
    Employee* pEmpleadoAux = NULL;

    if( pArrayListEmployee != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ################ Alta de Empleado #################\n");
        printf("    ###################################################\n\n");

        aux_getCadena(nameAux, "Ingrese nombre: ", " Error. Ingrese un nombre valido: ");
        aux_getEntero(&horasTrabajadasAux, 0, "Ingrese horas trabajadas: ", "Error. Ingrese una cantidad valida: ");
        aux_getEntero(&sueldoAux, 0, "Ingrese sueldo: ", "Error. Ingrese un sueldo valido: ");

        pEmpleadoAux = employee_newParametros(idEmp, nameAux, horasTrabajadasAux, sueldoAux);

        if( pEmpleadoAux != NULL )
        {
            ll_add(pArrayListEmployee, pEmpleadoAux);
            printf("\n\n   ##### ALTA DE EMPLEADO EXITOSA #####   \n\n");
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int respuesta;
    int indiceAux;
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    char confirmar;
    char nameAux[100];
    Employee* pEmpleadoAux = NULL;

    if( pArrayListEmployee != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ################ Edicion de Empleado ##############\n");
        printf("    ###################################################\n\n");

        aux_getEntero(&idAux, 1, "Ingrese ID del empleado a modificar: ", "Error. Ingrese un id valido: ");

        indiceAux = controller_findEmployeeById(pArrayListEmployee, idAux);

        if( indiceAux == -1 )
        {
            printf("\n\n     NO SE ENCONTRO UN EMPLEADO CON ESE ID.\n\n");
        }
        else
        {
            pEmpleadoAux = (Employee*) ll_get(pArrayListEmployee, indiceAux);
            printf("\n  #####  EMPLEADO A MODIFICAR  #####  \n");
            printEmployee(pEmpleadoAux);

            respuesta = subMenuEdicion();

            switch( respuesta )
            {
                case 1:
                    aux_getCadena(nameAux, "Ingrese nuevo nombre: ", "Error. Reingrese: ");
                    confirmar = aux_getConfirmacion("Confirma la modificacion? s - si / n - no: ", "\nERROR. Escriba una opcion valida: ");
                    if( confirmar == 'S' )
                    {
                        strcpy(pEmpleadoAux->nombre, nameAux);
                        printf("\n\n##### Edicion realizada con exito. #####\n\n");
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
                        pEmpleadoAux->horasTrabajadas = horasTrabajadasAux;
                        printf("\n\n##### Edicion realizada con exito. #####\n\n");
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
                        pEmpleadoAux->sueldo = sueldoAux;
                        printf("\n\n##### Edicion realizada con exito. #####\n\n");
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

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int indiceAux;
    int idRemove;
    char confirmar;
    Employee* pEmpleadoAux;

    if( pArrayListEmployee != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ################ Baja de Empleado #################\n");
        printf("    ###################################################\n\n");

        aux_getEntero(&idRemove, 1, "Ingrese ID del empleado: ", "Error. Ingrese un id valido: ");

        indiceAux = controller_findEmployeeById(pArrayListEmployee, idRemove);

        if( indiceAux == -1 )
        {
            printf("\n\n     NO SE ENCONTRO UN EMPLEADO CON ESE ID.\n\n");
        }
        else
        {
            pEmpleadoAux = (Employee*) ll_get(pArrayListEmployee, indiceAux);
            printf("\n  #####  EMPLEADO A DAR DE BAJA  #####  \n");
            printEmployee(pEmpleadoAux);

            confirmar = aux_getConfirmacion("Confirma la baja? s - si / n - no: ", "\nERROR. Escriba una opcion valida: ");

            if( confirmar == 'S' )
            {
                ll_remove( pArrayListEmployee, indiceAux );
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

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int hayCargados = 0;
    Employee* pEmpleadoAux = NULL;
    int arrayLen = ll_len(pArrayListEmployee);

    if( pArrayListEmployee != NULL )
    {
        printf("\n\n");
        printf("   ID   |     Nombre     |  Horas  |   Sueldo   \n");
        printf("------------------------------------------------\n");
        printf("\n\n");

        for( int i=0; i<arrayLen; i++ )
        {
            pEmpleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

            if( pEmpleadoAux != NULL )
            {
                printEmployee( pEmpleadoAux );
            }

            hayCargados = 1;
        }

        if( !hayCargados )
        {
            printf("No hay empleados cargados en el sistema.\n\n");
        }

        printf("\n\n");

        retorno = 0;
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int respuesta;
    int criterio;

    if( pArrayListEmployee != NULL )
    {
        printf("\n\n");
        printf("    ###################################################\n");
        printf("    ################ Ordenar Empleados ################\n");
        printf("    ###################################################\n\n");

        printf("           ====== CAMPOS =======\n");
        printf("1- ID\n");
        printf("2- Horas de Trabajo\n");
        printf("3- Nombre\n");
        printf("4- Sueldo\n");
        printf("5- Volver al menu principal\n");

        aux_getEnteroEntre(&respuesta, 1, 5, "Respuesta: ", "Error. ingrese una opcion valida: ");
        aux_getEnteroEntre(&criterio, 0, 1, "Criterio? 0 - Ascendente / 1 - Descendente: ", "Error. ingrese una opcion valida: ");

        switch(respuesta)
        {
            case 1:
                if( !ll_sort(pArrayListEmployee,emp_sortById,criterio) )
                {
                    printf("Ordenado con exito!\n");
                }
                else
                {
                    printf("\n\nOcurrio un error al intentar ordenar.\n");
                }
                break;

            case 2:
                if( !ll_sort(pArrayListEmployee,emp_sortByHorasTrabajadas,criterio) )
                {
                    printf("\n\nOrdenado con exito!\n");
                }
                else
                {
                    printf("\n\nOcurrio un error al intentar ordenar.\n");
                }
                break;

            case 3:
                if( !ll_sort(pArrayListEmployee,emp_sortByNombre,criterio) )
                {
                    printf("Ordenado con exito!\n");
                }
                else
                {
                    printf("\n\nOcurrio un error al intentar ordenar.\n");
                }
                break;

            case 4:
                if( !ll_sort(pArrayListEmployee,emp_sortBySueldo,criterio) )
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* fpArchivo;
    int arrayLen = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux = NULL;
    int idAux;
    char nameAux[128];
    int horasTrabajadasAux;
    int sueldoAux;

    if( pArrayListEmployee != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "w");

        if( fpArchivo != NULL )
        {
            for( int i=0; i < arrayLen; i++ )
            {
                pEmpleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

                if( pEmpleadoAux != NULL )
                {
                    if(!( employee_getId(pEmpleadoAux, &idAux) &&
                          employee_getNombre(pEmpleadoAux, nameAux) &&
                          employee_getHorasTrabajadas(pEmpleadoAux, &horasTrabajadasAux) &&
                          employee_getSueldo(pEmpleadoAux, &sueldoAux) ) )
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int arrayLen = ll_len( pArrayListEmployee );
    FILE* fpArchivo;
    Employee* pEmpleadoAux = NULL;

    if( path != NULL && pArrayListEmployee != NULL )
    {
        fpArchivo = fopen(path, "wb");

        if( fpArchivo != NULL )
        {
            for( int i=0; i<arrayLen; i++ )
            {
                pEmpleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

                if( pEmpleadoAux != NULL )
                {
                    fwrite(pEmpleadoAux, sizeof(Employee), 1, fpArchivo);
                }
            }

            fclose(fpArchivo);
        }

        retorno = 0;
    }

    return retorno;
}

int controller_findEmployeeById(LinkedList* pArrayListEmployee, int findId)
{
    int indiceAux = -1;
    int arrayLen = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux = NULL;

    if( pArrayListEmployee != NULL )
    {
        for( int i=0; i<arrayLen; i++ )
        {
            pEmpleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

            if( pEmpleadoAux != NULL )
            {
                if( pEmpleadoAux->id == findId )
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
    printf("3- Sueldo.\n");
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
