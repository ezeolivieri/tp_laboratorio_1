#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if( nuevoEmpleado != NULL )
    {
        employee_setId(nuevoEmpleado, 0);
        employee_setNombre(nuevoEmpleado, "-");
        employee_setHorasTrabajadas(nuevoEmpleado, 0);
        employee_setSueldo(nuevoEmpleado, 0);
    }

    return nuevoEmpleado;
}

Employee* employee_newParametrosChar(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();

    if( nuevoEmpleado != NULL )
    {
        if( !( employee_setId(nuevoEmpleado, atoi(idStr))
            && employee_setNombre(nuevoEmpleado, nombreStr)
            && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
            && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)) ) )
        {
            employee_delete(nuevoEmpleado);
        }
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* nuevoEmpleado = employee_new();

    if( nuevoEmpleado != NULL )
    {
        if( !( employee_setId(nuevoEmpleado, id)
            && employee_setNombre(nuevoEmpleado, nombre)
            && employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas)
            && employee_setSueldo(nuevoEmpleado, sueldo)) )
        {
            employee_delete(nuevoEmpleado);
        }

        employee_setId(nuevoEmpleado, id);
        employee_setNombre(nuevoEmpleado, nombre);
        employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas);
        employee_setSueldo(nuevoEmpleado, sueldo);
    }

    return nuevoEmpleado;
}

void employee_delete(Employee* this)
{
    free( this );
}

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if( this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL && strlen(nombre) > 3 )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas > 0 )
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo > 0 )
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int printEmployee(Employee* pEmployee)
{
    int todoOk = 0;
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    char nameAux[128];

    if( pEmployee != NULL )
    {
        if( employee_getId(pEmployee,&idAux) &&
            employee_getNombre(pEmployee,nameAux) &&
            employee_getHorasTrabajadas(pEmployee,&horasTrabajadasAux) &&
            employee_getSueldo(pEmployee,&sueldoAux) )
        {
            printf("%5d %16s %8d %10d\n",idAux,nameAux,horasTrabajadasAux,sueldoAux);
        }
        else
        {
            printf("Error intentando obtener los datos del empleado.\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int emp_sortByNombre(void* empUno,void* empDos)
{
    char nameUnoAux[128];
    char nameDosAux[128];

    if( empUno != NULL && empDos != NULL )
    {
        employee_getNombre((Employee*) empUno,nameUnoAux);
        employee_getNombre((Employee*) empDos,nameDosAux);

        if( strcmp(nameUnoAux, nameDosAux) > 0 )
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    return 0;
}

int emp_sortById(void* empUno,void* empDos)
{
    int idUnoAux;
    int idDosAux;

    if( empUno != NULL && empDos != NULL )
    {
        employee_getId((Employee*) empUno,&idUnoAux);
        employee_getId((Employee*) empDos,&idDosAux);

        if( idUnoAux > idDosAux )
        {
            return 1;
        }

        if( idUnoAux < idDosAux )
        {
            return -1;
        }
    }

    return 0;
}

int emp_sortBySueldo(void* empUno,void* empDos)
{
    int salarioUnoAux;
    int salarioDosAux;

    if( empUno != NULL && empDos != NULL )
    {
        employee_getSueldo((Employee*) empUno,&salarioUnoAux);
        employee_getSueldo((Employee*) empDos,&salarioDosAux);

        if( salarioUnoAux > salarioDosAux )
        {
            return 1;
        }

        if( salarioUnoAux < salarioDosAux )
        {
            return -1;
        }
    }

    return 0;
}

int emp_sortByHorasTrabajadas(void* empUno,void* empDos)
{
    int horasUnoAux;
    int horasDosAux;

    if( empUno != NULL && empDos != NULL )
    {
        employee_getHorasTrabajadas((Employee*) empUno,&horasUnoAux);
        employee_getHorasTrabajadas((Employee*) empDos,&horasDosAux);

        if( horasUnoAux > horasDosAux )
        {
            return 1;
        }

        if( horasUnoAux < horasDosAux )
        {
            return -1;
        }
    }


    return 0;
}
