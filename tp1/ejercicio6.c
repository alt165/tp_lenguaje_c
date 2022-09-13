/*### 6. Divisiones
Escribir una función que mediante restas sucesivas, obtenga el valor del 
cociente y el resto de dos números enteros.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

/*gcc -Wall -Wextra -Werror */

#include <stdio.h>
#include <limits.h>
#define POSITIVO 1
#define NEGATIVO -1

/* funcion para obtener el signo que resulta
de la multiplicacion o division de dos numeros enteros
los argumentos son don numeros enteros y el resultado
es -1 o 1 */
int signo_multiplicacion(int termino1, int termino2)
{
    int resultado = termino1 ^ termino2;
    resultado = resultado & INT_MIN;
    if (resultado == 0)
    {
        resultado = POSITIVO;
    }
    else
    {
        resultado = NEGATIVO;
    }
    return resultado;
}

/* funcion que devuelve el valor absoluto de un numero
el argumento es un numero entero y el resultado es tambien un numero entero */
int absoluto(int numero)
{
    /* Si el numero es positivo la operacion develve 0, si no es INT_MIN
    INT_MIN en binario es un 1 seguido todo de  0 lo uso para obtener el bit de signo
    */
    int comparar = numero;
    comparar = numero & INT_MIN;
    if(comparar)
    {
        /* si el numero es negativo se aplica el cambio de signo usando complemento a 2*/
        numero = ~numero + 1;
    }
    return numero;
}

/* funcion que devuelve la divison entera de dos numero enteros,
el divisor no puede ser == 0
el resultado es un numero entero <=  |dividendo| */
int division_lenta(int dividendo, int divisor)
{
    int signo = signo_multiplicacion(dividendo, divisor);
    int resultado = 0;
    dividendo = absoluto(dividendo);
    divisor = absoluto(divisor);

    while (dividendo >= divisor)
    {
        resultado++;
        dividendo = dividendo - divisor;
    }
    resultado = resultado * signo;
    return resultado;    
}

/* funcion que devuelve el resto de la division entera entre dos numeros
el divisor no puede ser  == 0
el resultado es un entero con el signo del dividendo y < |divisor| */
int resto_division(int dividendo, int divisor)
{
    int signo = dividendo;
    signo = signo / absoluto(dividendo);
    dividendo = absoluto(dividendo);
    divisor = absoluto(divisor);
    while(divisor <= dividendo)
    {
        dividendo = dividendo - divisor;        
    }
    dividendo = dividendo * signo;
    return dividendo;
}

int main()
{
    unsigned int dividendo;
    unsigned int divisor;
    unsigned int resultado;
    unsigned int resto;

    printf("Dame el dividendo: \n");
    scanf("%d", &dividendo);
    printf("Dame el divisor:\n");
    scanf("%d", &divisor);

    resultado = division_lenta(dividendo, divisor);
    resto = resto_division(dividendo, divisor);

    printf("%d / %d = %d. El resto es: %d\n", dividendo, divisor, resultado, resto);
    return 0;   
}
