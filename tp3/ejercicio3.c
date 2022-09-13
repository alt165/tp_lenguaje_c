/*
### 3. Gestionando el `tiempo_t`

Desarrollar una estructura y funciones que permitan realizar las siguientes operaciones con 
tiempo expresado en horas, minutos y segundos.

 * Crear `tiempo_t`
 * Mostrar `tiempo_t`
 * Sumar segundos
 * Sumar minutos
 * Sumar horas
 * Sumar dos `tiempo_t`

José Lambrechts - 2022
Usuario GitHub alt165
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
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
#define SLEEP_TIME 1


typedef struct tiempo{
    int horas;
    int minutos;
    int segundos;
}tiempo_t;

tiempo_t normalizar_tiempo(tiempo_t tiempo);
tiempo_t crear_tiempo(int horas, int minutos, int segundos);
void mostrar_tiempo(tiempo_t tiempo);
tiempo_t sumar_segundos(tiempo_t tiempo, int segundos);
tiempo_t sumar_minutos(tiempo_t tiempo, int minutos);
tiempo_t sumar_horas(tiempo_t tiempo, int horas);
tiempo_t sumar_tiempos(tiempo_t t1, tiempo_t t2);

/*  Precondicion: recibe un struct tiempo_t con enteros > 0 en sus elementos
    Poscondicion: devuelve un struct tiempo_t donde segundos y minutos son < 60
    y las cantidades distribuidas entre sus elementos */
tiempo_t normalizar_tiempo(tiempo_t tiempo)
{
    int auxiliar;
    auxiliar = tiempo.segundos / 60;
    tiempo.segundos = tiempo.segundos % 60;
    tiempo.minutos = tiempo.minutos + auxiliar;
    auxiliar = tiempo.minutos / 60;
    tiempo.minutos = tiempo.minutos % 60;
    tiempo.horas = tiempo.horas + auxiliar;

    return tiempo;
}

/*  Precondicion: los argumentos deben ser todos enteros > 0
    Poscondicion: devuelve un struct con los datos cargados en
    sus elementos y minutos y segundos < 60 */
tiempo_t crear_tiempo(int horas, int minutos, int segundos)
{
    tiempo_t resultado;
    resultado.segundos = segundos;
    resultado.minutos = minutos;
    resultado.horas = horas;
    resultado = normalizar_tiempo(resultado);

    return resultado;
}

/*  Precondicion: recibe un struct tiempo_t
    Poscondicion:  imprime por pantalla los elementos del
    struct en el formato xxHs:xxM:xxS */
void mostrar_tiempo(tiempo_t tiempo)
{
    printf("%dHs:%dM:%dS",tiempo.horas, tiempo.minutos, tiempo.segundos);
    fflush(stdout);
}

/*  Precondicion: recibe un struct tiempo_t y un entero > 0
    Poscondicion: devuelve un struct con los datos cargados en
    sus elementos y minutos y segundos < 60 */
tiempo_t sumar_segundos(tiempo_t tiempo, int segundos)
{
    tiempo.segundos = tiempo.segundos + segundos;
    tiempo = normalizar_tiempo(tiempo);
    return tiempo;
}

/*  Precondicion: recibe un struct tiempo_t y un entero > 0
    Poscondicion: devuelve un struct con los datos cargados en
    sus elementos y minutos y segundos < 60 */
tiempo_t sumar_minutos(tiempo_t tiempo, int minutos)
{
    tiempo.minutos = tiempo.minutos + minutos;
    tiempo = normalizar_tiempo(tiempo);
    return tiempo;
}

/*  Precondicion: recibe un struct tiempo_t y un entero > 0
    Poscondicion: devuelve un struct con los datos cargados en
    sus elementos y minutos y segundos < 60 */
tiempo_t sumar_horas(tiempo_t tiempo, int horas)
{
    tiempo.horas = tiempo.horas + horas;
    return tiempo;
}

/*  Precondicion: recibe dos struct tiempo_t
    Poscondicion: devuelve un struct con los datos cargados en
    sus elementos y minutos y segundos < 60 resultado de sumar
    ambos tiempos */
tiempo_t sumar_tiempos(tiempo_t t1, tiempo_t t2)
{
    tiempo_t resultado;
    resultado.segundos = t1.segundos + t2.segundos;
    resultado.minutos = t1.minutos + t2.minutos;
    resultado.horas = t1.horas + t2.horas;
    resultado = normalizar_tiempo(resultado);

    return resultado;
}

int main()
{
    int horas, minutos, segundos;
    tiempo_t t1, t2;
    system(CLEAR);
    printf("Time machine\n");
    printf("Crear tiempo...\n");
    printf("Ingresar cantidad de horas: ");
    scanf("%d", &horas);
    printf("Ingresar cantidad de minutos: ");
    scanf("%d", &minutos);
    printf("Ingresar cantidad de segundos: ");
    scanf("%d", &segundos);
    system(CLEAR);
    t1 = crear_tiempo(horas, minutos, segundos);
    t2 = crear_tiempo(horas, minutos, segundos);
    printf("El tiempo es: ");
    mostrar_tiempo(t1);
    printf("\n");
    sleep(SLEEP_TIME);
    printf("Sumar segundos\n");
    printf("Cuantos segundos:");
    scanf("%d", &segundos);
    t2 = sumar_segundos(t2, segundos);
    mostrar_tiempo(t2);
    sleep(SLEEP_TIME);
    printf("\n");
    printf("Sumar minutos\n");
    printf("Cuantos minutos:");
    scanf("%d", &minutos);
    t2 = sumar_minutos(t2, minutos);
    mostrar_tiempo(t2);
    sleep(SLEEP_TIME);
    printf("\n");
    printf("Sumar horas\n");
    printf("Cuantas horas:");
    scanf("%d", &horas);
    t2 = sumar_horas(t2, horas);
    mostrar_tiempo(t2);
    sleep(SLEEP_TIME);
    printf("\n");
    printf("Sumar dos tiempos:\n");
    mostrar_tiempo(t1);
    printf(" + ");
    mostrar_tiempo(t2);
    t2 = sumar_tiempos(t1, t2);
    printf( " = ");
    mostrar_tiempo(t2);
    printf("\n");

    return 0;

}