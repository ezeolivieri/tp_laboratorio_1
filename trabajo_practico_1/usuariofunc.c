#include <stdio_ext.h>
#include <ctype.h>
#define AZUL_T      "\x1b[34m"
#define BLANCO_T    "\x1b[37m"

int menuDeOpciones(int x, int y, int banderaX, int banderaY)
{
    int opcion; // opcion seleccionada

    printf(AZUL_T "         ===============================================\n");
    printf(AZUL_T "         ==               CALCULADORA                 ==\n");
    printf(AZUL_T "         ===============================================\n\n");

    if( banderaX )
        printf("1. Ingresar 1er operando (A=%d)\n",x);
    else
        printf("1. Ingresar 1er operando (A=x)\n");
    if( banderaY )
        printf("2. Ingresar 2do operando (B=%d)\n",y);
    else
        printf("2. Ingresar 2do operando (B=y)\n");
    printf("3. Calcular todas las operaciones\n");
    printf("   a) Calcular la suma (A+B)\n");
    printf("   b) Calcular la resta (A-B)\n");
    printf("   c) Calcular la division (A/B)\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("   a) El resultado de A+B es: r\n");
    printf("   b) El resultado de A-B es: r\n");
    printf("   c) El resultado de A/B es: r\n");
    printf("   d) El resultado de A*B es: r\n");
    printf("   e) El factorial de A es: r1 y El factorial de B es: r2\n");
    printf("5. Salir\n\n");

    printf("Tu respuesta es: ");
    scanf("%d", &opcion);

    return opcion;
}

int pedirOperando()
{
    int x;

    printf("\nIngrese el operando: ");
    scanf("%d", &x);

    return x;
}

char confirmacionSalida()
{
    char confirm;

    printf(BLANCO_T "\n\nEstá seguro que desea salir?\n\n");
    __fpurge(stdin);
    scanf("%c", &confirm);
    confirm = tolower(confirm);

    return confirm;
}
