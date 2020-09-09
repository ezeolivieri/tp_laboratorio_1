void mostrarResultadosDe( char operacion, int x, int y, int resultado )
{
    switch( operacion )
    {
        case 'a':
            printf("\n%c)  ==> El resultado de %d + %d es: %d\n", operacion, x, y, resultado);
            break;
        case 'b':
            printf("\n%c)  ==> El resultado de %d - %d es: %d\n", operacion, x, y, resultado);
            break;
        case 'd':
            printf("\n%c)  ==> El resultado de %d * %d es: %d\n", operacion, x, y, resultado);
            break;
    }
}

void mostrarDivisionDe( int x, int y, float resultado )
{
    if ( y == 0 )
        printf("\nNo es posible dividir por 0.\n");
    else
        printf("\nc)  ==> El resultado de %d / %d es: %.2f\n", x, y, resultado);
}

void mostrarFactorialDe( int x, int resultado )
{
    if( x < 0 )
        printf("\ne)  ==> No es posible calcular el factorial de %d porque es un numero negativo.\n", x);
    else
        printf("\ne)  ==> El factorial de %d es: %d\n", x, resultado);
}
