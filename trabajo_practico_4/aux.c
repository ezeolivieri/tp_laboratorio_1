#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>
#include "aux.h"

int aux_getEntero(int* entero, int minimo, char* mensajePedir, char* mensajeError)
{
    int todoOk = 0;

    if( entero != NULL && mensajePedir != NULL && mensajeError != NULL )
    {
        printf("\n%s", mensajePedir);
        scanf("%d", entero);

        while( *entero < minimo )
        {
            printf("\n%s", mensajeError);
            scanf("%d", entero);
        }

        todoOk = 1;
    }

    return todoOk;
}

int aux_getEnteroEntre(int* entero, int minimo, int maximo, char* mensajePedir, char* mensajeError)
{
    int todoOk = 0;

    if( entero != NULL && mensajePedir != NULL && mensajeError != NULL )
    {
        printf("\n%s", mensajePedir);
        scanf("%d", entero);

        while( !( *entero >= minimo && *entero <= maximo) )
        {
            printf("\n%s", mensajeError);
            scanf("%d", entero);
        }

        todoOk = 1;
    }

    return todoOk;
}

char aux_getConfirmacion(char* mensajePedir, char* mensajeError)
{
    char confirmar;

    if( mensajePedir != NULL && mensajeError != NULL )
    {
        printf("\n\n%s\n", mensajePedir);
        __fpurge(stdin);
        confirmar = getchar();
        confirmar = toupper(confirmar);

        while( confirmar != 'S' && confirmar != 'N' )
        {
            printf("\n%s\n", mensajeError);
            __fpurge(stdin);
            confirmar = getchar();
            confirmar = toupper(confirmar);
        }
    }

    return confirmar;
}

int aux_getCadena(char* cadena, char* mensajePedir, char* mensajeError)
{
    int todoOk = 0;

    if( cadena != NULL && mensajePedir != NULL && mensajeError != NULL )
    {
        printf("\n%s", mensajePedir);
        __fpurge(stdin);
        scanf("%[^\n]", cadena);

        while( !esCadenaAlfabetica(cadena) )
        {
            printf("\n%s", mensajeError);
            __fpurge(stdin);
            scanf("%[^\n]", cadena);
        }

        todoOk = 1;
    }

    return todoOk;
}

int esCadenaAlfabetica(char* cadena)
{
    int esValida = 1;
    int i = 0;

    // Recorro la cadena de caracteres hasta encontrar el "ENTER"
    while( cadena[i] != '\0' )
    {
        // La primer condicion indica si el codigo ASCII es menor a la del espacio
        // La segunda condicion es para ver si está entre el espacio y A mayuscula
        // La tercera indica si esta entre Z mayuscula y a minuscula
        // La cuarta es para ver si es posterior a Z mayuscula
        if( !( (cadena[i] >= 65 && cadena[i] <= 90) ||
               (cadena[i] >= 97 && cadena[i] <= 122) ||
               (cadena[i] == 32) ||
               (cadena[i] <= 45) ) )
        {
            esValida = 0;
            break;
        }

        i++;
    }

    return esValida;
}
