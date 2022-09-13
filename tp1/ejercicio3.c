/* ### 3. Números positivos y negativos

Escribir una función que reciba un número e indique si el mismo es positivo,
negativo o cero con un numero entero y utilizando operaciones de suma y resta.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <limits.h>

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

/*la función devuelve -1 para negativos, 0 para 0 y 1 para positivos
solo admite numeros enteros como argumento*/
int comparacion(int numero)
{
    int resultado;
    int comparar;
    if (numero == 0)
    {
        resultado = 0;
    }
    else
    {
        comparar = absoluto(numero);
        resultado = comparar / numero;      
    }
    return resultado;
}

int main()
{
    int numero_a_comparar;
    int resultado;
    printf("Ingrese el valor a comprarar:\n");
    scanf("%d", &numero_a_comparar);
    resultado = comparacion(numero_a_comparar);        
    printf("El resultado de la comparacion es: %d\n", resultado);
    
    return 0;
}
