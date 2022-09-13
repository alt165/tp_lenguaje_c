/*### 2. Conversión de temperaturas
Se quiere transformar temperaturas en grados fahrenheit a grados centígrados y viceversa.

Escribir las funciones para convertir la temperatura en grados centigrados en fahrenheit como 
un número decimal, utilice esta formula para calcular los grados centígrados y retorne el 
resultado obtenido. Y viceversa.
*/

/*  José Lambrechts - 2022
    Programacion 1 - Ingenieria en computacion
*/

/*gcc -Wall -Wextra -Werror */

#include <stdio.h>
/* fahrenheit_a_centigrados(float cent) admite valores > -460 formato float, devuelve el valor equivalente en 
grados centigrados en formato float */
float fahrenheit_a_centigrados(float cent)
{
    cent = cent * 9 / 5 + 32;
    return cent;
}

/* centrigrados_a_fahrenheit(float fahr) admite valores > -273 formato float, devuelve el valor equivalente en 
grados fahrenheit en formato float */
float centrigrados_a_fahrenheit(float fahr)
{
    fahr = (fahr - 32) * 5 / 9;
    return fahr;
}

int main()
{
   char opcion;
   float resultado;
   float valor_ingresado;
   printf("Para convertir a centigrados presione C, para fahrenheit F:\n");
   printf("Cualquier otra tecla para terminar. \n");
   scanf("%c", &opcion);
   while (opcion == 'c' || opcion == 'C' || opcion == 'f' || opcion == 'F')
   {
        printf("Ingrese los grados a convertir:\n");
        scanf("%f", &valor_ingresado);
        if (opcion == 'c' || opcion == 'C')
        {
            resultado = centrigrados_a_fahrenheit(valor_ingresado);
        } 
        else
        {
            resultado = fahrenheit_a_centigrados(valor_ingresado);
        }
        printf("La conversion es: %f \n",resultado);

   }
    printf("Fin del programa.\n");
    return 0;   
}
