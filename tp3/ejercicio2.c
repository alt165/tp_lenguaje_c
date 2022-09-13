/* ### 2. División Lenta II

Unificar las funciones de división lenta del TP1 de forma que la funcion retorne una estructura
representando los valores posibles.

Crear las funciones de soporte necesarias.

 José Lambrechts - 2022
Usuario GitHub alt165
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <math.h>

typedef struct division
{
    int cociente;
    int resto;
} division_t;


/* Prototipos funcionales */
division_t division_lenta(int dividendo, int divisor);
int signo_division(int numero1, int numero2);
void mostrar_resultado(division_t resultado);

/*  Precondiciones: El divisor no puede ser 0, dividendo y divisor
    son enteros.
    Poscondicion: Se devuelve en un struct tipo division_t dos enteros
    en cociente es el resultado de la division entera entre los parametros
    y en resto el resto de esa division
  */
division_t division_lenta(int dividendo, int divisor)
{
    division_t resultado;
    resultado.cociente = 0;
    resultado.resto = 0;
    int signo;
    signo = signo_division(dividendo, divisor);
    dividendo = fabs(dividendo);
    divisor = fabs(divisor);
    while (dividendo >= divisor)
    {
        resultado.cociente++;
        dividendo = dividendo - divisor;
    }
    resultado.resto = dividendo;
    resultado.cociente = resultado.cociente * signo;
     
    return resultado;    

}

/*  Precondicion: dos enteros.
    Pscondicion: la funcion devuelve -1 o 1 segun sea el
    resultado de la multiplicacion de ambos números */
int signo_division(int numero1, int numero2)
{
    if ((numero1 >= 0 && numero2 >=0) || ( numero1 < 0 && numero2 < 0))
    {
        return 1;
    }
    return -1;
}

/*  Precondicion: recibe un struct division_t
    Poscondicion: se imprimen los datos contenidos en el struct */
void mostrar_resultado(division_t resultado)
{
    printf("cociente: %d\n", resultado.cociente);
    printf("resto: %d", resultado.resto);
}


int main ()
{    
    int dividendo, divisor;
    division_t resultado;
    printf("Ingrese dividendo: \n");
    scanf("%d", &dividendo);
    printf("Ingrese divisor: \n");
    scanf("%d", &divisor);
    resultado = division_lenta(dividendo, divisor);
    printf("%d / %d =\n", dividendo, divisor);
    mostrar_resultado(resultado);
    printf("\n");
  
    return 0;
}