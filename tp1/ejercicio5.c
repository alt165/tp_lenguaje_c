/* ### 5. Suma lenta

Escribir una función que haga la suma entre dos números enteros sin hacer la operación de 
manera directa. Esto quiere decir que para hacer la suma entre 4 y 3, las operaciones 
resultantes deberán ser 4+1+1+1.

La funcion debe ser capaz de sumar cualquier numero entero positivo y negativo.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>


/* La funcion admite como parametro dos enteros 
y retorna la suma  de ambos*/
int sumaLenta(int numero1, int numero2)
{
    if (numero2 < 0)
    {
        while (numero2 < 0)
        {
            numero1--;
            numero2++;
        }
    }
    else
    {
        while (numero2 > 0)
        {
            numero1++;
            numero2--;
        }
        
    }
    return numero1;
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
    resultado = sumaLenta(numero1, numero2);        
    printf("El resultado de la suma es: %d\n", resultado);
    
    return 0;
 }
