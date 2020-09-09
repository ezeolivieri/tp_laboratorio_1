int sumar( int x, int y )
{
    return x + y;
}

int restar( int x, int y )
{
    return x - y;
}

float dividir( int x, int y )
{
    float resultado;

    if( y == 0 )
        resultado = 0;
    else
        resultado = (float) x / y;

    return resultado;
}

int multiplicar( int x, int y )
{
    return x * y;
}

int factorial( int x )
{
    int factorial = 1;

    for( int i = 1; i <= x; i++ )
    {
        factorial = factorial * i;
    }

    return factorial;
}
