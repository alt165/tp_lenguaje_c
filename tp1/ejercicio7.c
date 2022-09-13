/* ### 7. Números primos
Escribir una función que indique con `True` si un numero indicado es Primo.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

/*gcc -Wall -Wextra -Werror */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

/* funcion que devuelve TRUE o FALSE si el argumento es o no primo
admite enteros entre INT_MIN y INT_MAX para todos los valores <= 0
devuelve FALSE */
int es_primo(int numero)
{
    int es_primo_flag = TRUE;
    unsigned int divisor = numero - 1;
    if (numero <= 0)
    {
        es_primo_flag = FALSE;
    }
    
    while (es_primo_flag && divisor > 1)
    {
        if(numero % divisor == 0)
        {
            es_primo_flag = FALSE;
        }
        divisor--;
    }
    return es_primo_flag;
}

int main()
{
    int numero;
    int resultado;

    printf("Dame un numero y te digo si es primo: ");
    scanf("%d", &numero);
    resultado = es_primo(numero);
    if(resultado)
    {
        printf("%d es primo.\n", numero);
    }
    else
    {
        printf("%d no es primo.\n", numero);
    }

    return 0;   
}
