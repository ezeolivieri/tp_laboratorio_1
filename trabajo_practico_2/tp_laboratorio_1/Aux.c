#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>

#define FALSE     0
#define TRUE      1
#define VERDE_T     "\x1b[32m"
#define ROJO_T      "\x1b[31m"


/*******************************************
                FUNCIONES
 *******************************************/

void pedirNombre(char cadena[], char mensajeParaPedir[], char mensajeDeError[])
{
    printf("%s", mensajeParaPedir);
    __fpurge(stdin);
    scanf("%[^\n]", cadena);
    while( !esCadenaAlfabetica(cadena) ) {
        printf("%s", mensajeDeError);
        __fpurge(stdin);
        scanf("%[^\n]", cadena);
    }

    formatoDeNombre(cadena);
}

void pedirCadena(char cadena[], char mensajeParaPedir[], char mensajeDeError[])
{
    printf("%s", mensajeParaPedir);
    __fpurge(stdin);
    scanf("%s", cadena);
    while( !esCadenaAlfabetica(cadena) ) {
        printf("%s", mensajeDeError);
        __fpurge(stdin);
        scanf("%s", cadena);
    }
}

int esCadenaAlfabetica(char cadena[])
{
    int esValida = TRUE;
    int i = 0;

    // Recorro la cadena de caracteres hasta encontrar el "ENTER"
    while( cadena[i] != '\0' )
    {
        // La primer condicion indica si el codigo ASCII es menor a la del espacio
        // La segunda condicion es para ver si está entre el espacio y A mayuscula
        // La tercera indica si esta entre Z mayuscula y a minuscula
        // La cuarta es para ver si es posterior a Z mayuscula
        if(  cadena[i] < 32 ||
            (cadena[i] > 32 && cadena[i] < 65) ||
            (cadena[i] > 90 && cadena[i] < 97) ||
             cadena[i] > 122  )
             esValida = FALSE;

        i++;
    }

    return esValida;
}

void formatoDeNombre(char cadena[])
{
    int i = 0;

    // El primer caracter lo convierto a mayuscula
    cadena[i] = toupper( cadena[i] );
    i++;

    while( cadena[i] != '\0' )
    {
        // Analizo si hay un espacio en la cadena
        // Si lo hay, avanzo una posicion y pongo una mayuscula
        // Si no hay, convierto el caracter en minuscula
        if( cadena[i] == 32 )
        {
            i++;
            cadena[i] = toupper( cadena[i] );
        } else {
            cadena[i] = tolower( cadena[i] );
        }

        i++;
    }
}

float pedirFlotante(char mensajeParaPedir[], float minimo, float maximo, char mensajeDeError[])
{
    float flotante;

    printf("%s", mensajeParaPedir);
    scanf("%f", &flotante);

    while( flotante < minimo || flotante > maximo )
    {
        printf("%s", mensajeDeError);
        scanf("%f", &flotante);
    }

    return flotante;
}

int pedirEntero(char mensajeParaPedir[], int minimo, int maximo, char mensajeDeError[])
{
    int entero;

    printf("%s", mensajeParaPedir);
    scanf("%d", &entero);

    while( entero < minimo || entero > maximo )
    {
        printf("%s", mensajeDeError);
        scanf("%d", &entero);
    }

    return entero;
}

void errorController( int x )
{
    if( x >= 0 )
        printf(VERDE_T "\nFinished Succesfully [0 error(s)]\n");
    else
        printf(ROJO_T "\nError [Invalid length or NULL pointer]\n");
}

void cadenaMayuscula(char cadena[])
{
    int i = 0;

    while( cadena[i] != '\0')
    {
        cadena[i] = toupper( cadena[i] );
        i++;
    }
}
