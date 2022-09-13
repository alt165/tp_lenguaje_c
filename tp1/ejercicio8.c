/* ### 8. Palíndromo
Escribir una función que indique con True si una palabra o frase 
ingresada se trata de un palindromo.
Palíndromo, es si se lee igual de derecha a izquierda que de 
izquierda a derecha.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

/*gcc -Wall -Wextra -Werror */

#include <stdio.h>
#define LONG_CADENA 50
#define TRUE 1
#define FALSE 0

/* funcion que recibe una cadena y devuelve la cantidad de caracteres antes de \0
retorna un valor entero */
int longitud_cadena(char cadena[])
{
    int i = 0;
    while (cadena[i] != '\0' && i < LONG_CADENA)
    {
        i++;
    }
    return i;
}

/* funcion que recibe una cadena y devuelve TRUE o FALSE si la cadena es o no reversible
la funcion es case sensitive y no ignora espacios */
int es_palindromo(char cadena[])
{
    int i = 0;
    int j;
    int flag = TRUE;
    j = longitud_cadena(cadena) - 1;
    while (i < j && flag != 0)
    {
        if(cadena[i] != cadena[j])
        {
            flag = FALSE;                      
        }
        i++;
        j--;
    }
    return flag;
}

int main()
{
    char cadena[LONG_CADENA];
    int largo;
    printf("dame cadena y te digo si es palindromo: \n\t");
    scanf("%s", &cadena[0]);
    if(es_palindromo(cadena))
    {
        printf("Si, esa cadena es palindromo");
    }else
    {
        printf("Esa cadena no es palindromo");
    }

    return 0;   
}
