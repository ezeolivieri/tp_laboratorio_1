#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Developer.h"

Developer* developer_new()
{
    Developer* nuevoDev = (Developer*) malloc(sizeof(Developer));

    if( nuevoDev != NULL )
    {
        developer_setId(nuevoDev, 0);
        developer_setNombre(nuevoDev, "-");
        developer_setHorasTrabajadas(nuevoDev, 0);
        developer_setSueldo(nuevoDev, 0);
    }

    return nuevoDev;
}

Developer* developer_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Developer* nuevoDev = developer_new();

    if( nuevoDev != NULL )
    {
        if( !( developer_setId(nuevoDev, id)
            && developer_setNombre(nuevoDev, nombre)
            && developer_setHorasTrabajadas(nuevoDev, horasTrabajadas)
            && developer_setSueldo(nuevoDev, sueldo)) )
        {
            developer_delete(nuevoDev);
        }

        developer_setId(nuevoDev, id);
        developer_setNombre(nuevoDev, nombre);
        developer_setHorasTrabajadas(nuevoDev, horasTrabajadas);
        developer_setSueldo(nuevoDev, sueldo);
    }

    return nuevoDev;
}

Developer* developer_newParametrosChar(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Developer* nuevoDev = developer_new();

    if( nuevoDev != NULL )
    {
        if( !( developer_setId(nuevoDev, atoi(id))
            && developer_setNombre(nuevoDev, nombre)
            && developer_setHorasTrabajadas(nuevoDev, atoi(horasTrabajadas))
            && developer_setSueldo(nuevoDev, atoi(sueldo)) ) )
        {
            developer_delete(nuevoDev);
        }

        developer_setId(nuevoDev, atoi(id));
        developer_setNombre(nuevoDev, nombre);
        developer_setHorasTrabajadas(nuevoDev, atoi(horasTrabajadas));
        developer_setSueldo(nuevoDev, atoi(sueldo));
    }

    return nuevoDev;
}

void developer_delete(Developer* this)
{
    free( this );
}

int developer_setId(Developer* this,int id)
{
    int todoOk = 0;

    if( this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int developer_getId(Developer* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

int developer_setNombre(Developer* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL && strlen(nombre) > 3 )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int developer_getNombre(Developer* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int developer_setHorasTrabajadas(Developer* this,int horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas > 0 )
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int developer_getHorasTrabajadas(Developer* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int developer_setSueldo(Developer* this,int sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo > 0 )
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
int developer_getSueldo(Developer* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int printDeveloper(Developer* pDeveloper)
{
    int todoOk = 0;
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    char nameAux[128];

    if( pDeveloper != NULL )
    {
        if( developer_getId(pDeveloper,&idAux) &&
            developer_getNombre(pDeveloper,nameAux) &&
            developer_getHorasTrabajadas(pDeveloper,&horasTrabajadasAux) &&
            developer_getSueldo(pDeveloper,&sueldoAux) )
        {
            printf("%5d %16s %8d %10d\n",idAux,nameAux,horasTrabajadasAux,sueldoAux);
        }
        else
        {
            printf("Error intentando obtener los datos del Dev.\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int dev_sortByNombre(void* devUno,void* devDos)
{
    char nameUnoAux[128];
    char nameDosAux[128];

    if( devUno != NULL && devDos != NULL )
    {
        developer_getNombre((Developer*) devUno,nameUnoAux);
        developer_getNombre((Developer*) devDos,nameDosAux);

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

int dev_sortById(void* devUno,void* devDos)
{
    int idUnoAux;
    int idDosAux;

    if( devUno != NULL && devDos != NULL )
    {
        developer_getId((Developer*) devUno,&idUnoAux);
        developer_getId((Developer*) devDos,&idDosAux);

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

int dev_sortBySueldo(void* devUno,void* devDos)
{
    int salarioUnoAux;
    int salarioDosAux;

    if( devUno != NULL && devDos != NULL )
    {
        developer_getSueldo((Developer*) devUno,&salarioUnoAux);
        developer_getSueldo((Developer*) devDos,&salarioDosAux);

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

int dev_sortByHorasTrabajadas(void* devUno,void* devDos)
{
    int horasUnoAux;
    int horasDosAux;

    if( devUno != NULL && devDos != NULL )
    {
        developer_getHorasTrabajadas((Developer*) devUno,&horasUnoAux);
        developer_getHorasTrabajadas((Developer*) devDos,&horasDosAux);

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
