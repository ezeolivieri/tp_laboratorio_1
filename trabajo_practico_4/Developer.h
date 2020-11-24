#ifndef DEVELOPER_H_INCLUDED
#define DEVELOPER_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Developer;

Developer* developer_new();
Developer* developer_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo);
void developer_delete(Developer* this);

int developer_setId(Developer* this,int id);
int developer_getId(Developer* this,int* id);

int developer_setNombre(Developer* this,char* nombre);
int developer_getNombre(Developer* this,char* nombre);

int developer_setHorasTrabajadas(Developer* this,int horasTrabajadas);
int developer_getHorasTrabajadas(Developer* this,int* horasTrabajadas);

int developer_setSueldo(Developer* this,int sueldo);
int developer_getSueldo(Developer* this,int* sueldo);

int printDeveloper(Developer* pDeveloper);

int dev_sortByNombre(void* devUno,void* devDos);
int dev_sortById(void* devUno,void* devDos);
int dev_sortBySueldo(void* devUno,void* devDos);
int dev_sortByHorasTrabajadas(void* devUno,void* devDos);

#endif // DEVELOPER_H_INCLUDED
