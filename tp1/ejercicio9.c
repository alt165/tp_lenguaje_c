/* ### 9. Multiplos de
Escribir una función que indique con `True` si un número entero es divisor de otro,
utilizando sumas y restas.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

/*gcc -Wall -Wextra -Werror */

#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

/* funcion que devuleve TRUE o FALSE si un numero es multiplo de otro,
los argumentos pueden ser cualquier entero */
int es_multiplo(int multiplo, int divisor)
{
    int resultado = TRUE;
    multiplo = fabs(multiplo);
    divisor = fabs(divisor);
    if (divisor > multiplo || !divisor)
    {
        resultado = FALSE;
    }
    
    while(divisor <= multiplo && resultado)
    {
        multiplo = multiplo - divisor;        
    }
    if(multiplo == 0)
    {
        resultado = TRUE;
    }
    else
    {
        resultado = FALSE;
    }
    return resultado;
}

int main()
{
    unsigned int numero1;
    unsigned int numero2;
    
    printf("Dame un numero: ");
    scanf("%d", &numero1);
    printf("Dame otro numero y te digo si es multiplo del anterior: ");
    scanf("%d", &numero2);
    if(es_multiplo(numero2,numero1))
    {
        printf("%d es multiplo de %d\n",numero2, numero1);
    }
    else
    {
        printf("%d no es multiplo de %d\n",numero2, numero1);
    }
 
    return 0;   
}
