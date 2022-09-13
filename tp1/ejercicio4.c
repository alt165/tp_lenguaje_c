/* ### 4. Comparación de números

Escribir una función que utilizando sumas y restas, reciba dos valores y retorne:
 * Retornar `-1` si el primero es menor que el segundo
 * Retornar `0` si son iguales
 * Retornar `1` si el primero es mayor que el segundo
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <limits.h>

int absoluto(int numero){
    /* Si el numero es positivo la operacion develve 0, si no es INT_MIN
    INT_MIN en binario es un 1 seguido todo de  0 lo uso para obtener el bit de signo
    */
    int comparar = numero;
    comparar = numero & INT_MIN;
    if(comparar){
        /* si el numero es negativo se aplica el cambio de signo usando complemento a 2*/
        numero = ~numero + 1;
    }
    return numero;
}

/* Los parametros de entrada sn dos numeros enteros
la función devuelve -1 si el primer numero es menor,
 0 si son iguales y 1 si el primer numero es mayor*/
int comparacion(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 - numero2;
    if (resultado != 0)
    {
        resultado = resultado / absoluto(resultado);
    }
    return resultado;
}

int main()
{
    int numero1;
    int numero2;
    int resultado;

    printf("Dame un numero:\n");
    scanf("%d", &numero1);
    printf("Dame otro numero:\n");
    scanf("%d", &numero2);
    resultado = comparacion(numero1, numero2);        
    printf("El resultado de la comparacion es: %d\n", resultado);

    return 0;
 }
