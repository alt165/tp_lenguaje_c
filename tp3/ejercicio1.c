/*
## 1. Fracciones

Desarrollar las funciones necesarias para operar con fracciones de números enteros.
Operaciones a implementar:
 * Mostrar una fraccion por consola.
 * Suma entre fracciones
 * Multiplicacion entre fracciones
 * Suma con un número entero.

El `main` para este ejercicio debe utilizar todas estas operaciones.

José Lambrechts - 2022
Usuario GitHub alt165
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#if defined(_WIN32)
#include <windows.h>
#define CLEAR "cls"
#elif defined(_WIN64)
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif
#define SLEEP_TIME 3

typedef struct fraccion
{
    int numerador;
    int denominador;
} fraccion_t;

/* Prototipos funcionales */
fraccion_t cargarFraccion(int numerador, int denominador);
void mostrarFraccion(fraccion_t fraccion);
fraccion_t multiplicacion_fraciones(fraccion_t fraccion1, fraccion_t fraccion2);
int obtener_max_divisor(int numero1, int numero2);
void simplificar_fraccion(fraccion_t *fraccion);
fraccion_t suma_fracciones(fraccion_t fraccion1, fraccion_t fraccion2);
fraccion_t suma_fraccion_y_entero(fraccion_t fraccion, int entero);

/* Definicion de funciones */

/*  Precondicion: dos enteros != 0
    Poscondicion: devuelve un struct tipo fraccion_t
    con los valores de una fraccion simplificada */
fraccion_t cargarFraccion(int numerador, int denominador)
{
    fraccion_t resultado;
    resultado.numerador = numerador;
    resultado.denominador = denominador;
    simplificar_fraccion(&resultado);
    return resultado;
}

/*  Precondicion: recibe un puntero a un struc_t,
    los valores de numerador y denominador deben ser validos,
    es decir dos enteros != 0
    Poscondicion: se modifica la fraccion pasada por puntero de
    forma que quede expresada como el la razon de los maximos divisores
    comunes de numerador y denominador. Se tiene en cuenta el signo de
    la fraccion y si es negativa el numerador es quien lleva el signo  */
void simplificar_fraccion(fraccion_t *fraccion)
{
    int factor;
    int numerador = fraccion->numerador;
    int denominador = fraccion->denominador;
    if (numerador > 0 && denominador < 0)
    {
        numerador = numerador * -1;
        denominador = fabs(denominador);
    }
    else if (numerador < 0 && denominador < 0)
    {
        numerador = fabs(numerador);
        denominador = fabs(denominador);
    }
    factor = obtener_max_divisor(numerador, denominador);
    fraccion->numerador = numerador / factor;
    fraccion->denominador = denominador / factor;
}

/*  Precondicion: la funcion recibe un struct fraccion_t
    Poscondicion: la funcion imprime el numerador/denominador */
void mostrarFraccion(fraccion_t fraccion)
{
    printf("%d", fraccion.numerador);
    printf("/");
    printf("%d", fraccion.denominador);
}

/*  Precondicion: la funcion recibe dos structs fraccion_t
    Poscondicion: devuelve un struct fraccion_t resultado de multiplicar ambas fracciones */
fraccion_t multiplicacion_fraciones(fraccion_t fraccion1, fraccion_t fraccion2)
{
    fraccion_t resultado;
    resultado.numerador = fraccion1.numerador * fraccion2.numerador;
    resultado.denominador = fraccion1.denominador * fraccion2.denominador;
    simplificar_fraccion(&resultado);
    return resultado;
}

/*  Precondicion: dos enteros != 0.
    Poscondicion: un entero positivo que es el maximo comun divisor de ambos */
int obtener_max_divisor(int numero1, int numero2)
{
    int resultado;
    int i = 1;
    numero1 = fabs(numero1);
    numero2 = fabs(numero2);
    while (i <= numero1 && i <= numero2)
    {
        if (numero1 % i == 0 && numero2 % i == 0)
        {
            resultado = i;
        }
        i++;
    }
    return resultado;
}

/*  Precondicion: dos struct fraccion_t.
    Poscondicion: un struct resultado de sumar ambas fracciones,
    el resultado esta simplificado para que no tengan divisores en comun
    entre numerador y denominador */
fraccion_t suma_fracciones(fraccion_t fraccion1, fraccion_t fraccion2)
{
    fraccion_t resultado;
    resultado.numerador = fraccion1.numerador * fraccion2.denominador + fraccion2.numerador * fraccion1.denominador;
    resultado.denominador = fraccion1.denominador * fraccion2.denominador;
    simplificar_fraccion(&resultado);
    return resultado;
}

/*  Precondicion: un struct fraccion_t y un entero.
    Poscondicion: devuelve un struct con el resultado de sumar ambos numeros */
fraccion_t suma_fraccion_y_entero(fraccion_t fraccion, int entero)
{
    fraccion_t aux;
    fraccion_t resultado;
    aux.numerador = entero * fraccion.denominador;
    aux.denominador = entero;
    resultado = suma_fracciones(fraccion, aux);
    return resultado;
}

int main()
{

    fraccion_t fraccion1;
    fraccion_t fraccion2;
    fraccion_t resultado;
    int numero;
    int opcion = 1;
    while (opcion)
    {
        system(CLEAR);
        printf("Calculadora de fracciones:\n");
        printf("1 - Sumar fracciones.\n");
        printf("2 - Sumar fracciones y entero.\n");
        printf("3 - Multiplicar fracciones.\n");
        printf("0 - Salir\n");
        scanf("%d",&opcion);
        system(CLEAR);

        if (opcion == 1)
        {
            printf("Ingrese numerador fraccion 1: ");
            scanf("%d", &(fraccion1.numerador));
            printf("Ingrese denominador funcion 1: ");
            scanf("%d", &(fraccion1.denominador));
            printf("Ingrese numerador fraccion 2: ");
            scanf("%d", &(fraccion2.numerador));
            printf("Ingrese denominador funcion 2: ");
            scanf("%d", &(fraccion2.denominador));
            resultado = suma_fracciones(fraccion1, fraccion2);
            mostrarFraccion(fraccion1);
            printf(" + ");
            mostrarFraccion(fraccion2);
            printf(" = ");
            mostrarFraccion(resultado);
            fflush(stdout);
            sleep(SLEEP_TIME);          

        }
        else if (opcion == 2)
        {
            printf("Ingrese numerador fraccion: ");
            scanf("%d", &(fraccion1.numerador));
            printf("Ingrese denominador funcion: ");
            scanf("%d", &(fraccion1.denominador));
            printf("Ingrese el entero: ");
            scanf("%d", &numero);
            resultado = suma_fraccion_y_entero(fraccion1, numero);
            mostrarFraccion(fraccion1);
            printf(" + %d", numero);
            printf(" = ");
            mostrarFraccion(resultado);
            fflush(stdout);
            sleep(SLEEP_TIME);  

        }
        else if (opcion == 3)
        {
            printf("Ingrese numerador fraccion 1: ");
            scanf("%d", &(fraccion1.numerador));
            printf("Ingrese denominador funcion 1: ");
            scanf("%d", &(fraccion1.denominador));
            printf("Ingrese numerador fraccion 2: ");
            scanf("%d", &(fraccion2.numerador));
            printf("Ingrese denominador funcion 2: ");
            scanf("%d", &(fraccion2.denominador));
            resultado = multiplicacion_fraciones(fraccion1, fraccion2);
            mostrarFraccion(fraccion1);
            printf(" * ");
            mostrarFraccion(fraccion2);
            printf(" = ");
            mostrarFraccion(resultado);
            fflush(stdout);
            sleep(SLEEP_TIME);
        }   
        else if (opcion != 0)
        {
            printf("No se selecciono una opcion valida\n");
            sleep(2);
        }
            
    }
    return 0;
}