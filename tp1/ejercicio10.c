/* ### 10. Factorial

Desarrollar un programa obtenga el factorial de un número entero.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/* funcion que devuelve el factorial de un numero entero > 0 
el resultado es un entero > base. resultado == base solo cuando base = 1*/
int factorialRecursivo(int base)
{
    if(base == 1)
    {
        return 1;
    }
    else
    {
        return factorialRecursivo(base - 1) * base;
    }
}
int factorial(int base)
{
    int resultado = 1;
    while (base > 1)
    {
        resultado = resultado * base;
        base--;
    }
    return resultado;
    

}
int main()
{

    int numero;
    int resultado;
    
    printf("Dame un numero:\n");
    scanf("%d", &numero);
    resultado=factorialRecursivo(numero);
    printf("El factorial de %d = %d\n",numero, resultado);
    resultado = factorial(numero);
    printf("El factorial de %d = %d\n",numero, resultado);
        
    return 0;
 }
