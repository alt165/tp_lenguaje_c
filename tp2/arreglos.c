#include <stdio.h>
#include <stdlib.h>
#define TAMANIO_ARREGLO 50

int cargar_arreglo(int cantidad, int arreglo[]);
int muestra_arreglo(int cantidad, int arreglo[]);
float promedio_arreglo(int cantidad, int arreglo[]);
int minimo(int cantidad, int arreglo[]);
int maximo(int cantidad, int arreglo[]);
int posicion_minimo(int cantidad, int arreglo[]);
int ordenar_mayor_menor(int cantidad, int arreglo[]);
int ordenar_menor_mayor(int cantidad, int arreglo[]);
int cargar_arreglo_commandos(int cantidad, int arreglo[], char *elementos[]);

/* La funcion recibe un entero > 0 y un puntero a arreglo de int,
el resultado es que se modifica la cadena de int
si la cantidad es < 1 o mayor al tamaño maximo del arreglo
 la funcion devuelve -1 */
int cargar_arreglo(int cantidad, int arreglo[])
{
    int i = 0;
    int dato;
    int resultado;
    if(cantidad > 0 && cantidad < TAMANIO_ARREGLO)
    {    
        while (i < cantidad)
        {
            printf("dato a ingresar en posicion %d \n",i);
            scanf("%d", &dato);
            arreglo[i] = dato;
            i++;
        }
        resultado = 0;
    }
    else
    {
        resultado = -1;
    }
    
    return resultado;
}

/* La funcion recibe un entero > 0 y un puntero a arreglo de int,
el resultado es que se muestran todos los elementos del arreglo 
la funcion devuelve -1 si la cantidad es < 0 
o mayor al tamaño maximo del arreglo*/
int muestra_arreglo(int cantidad, int arreglo[])
{
    int i = 0;
    int resultado;
    if (cantidad > 0 && cantidad < TAMANIO_ARREGLO)
    {        
        while (i < cantidad)
        {
            printf("%d ",arreglo[i]);
            i++;
        }
        resultado = 0;
    }
    else
    {
        resultado = -1;
    }
    return resultado;
}

/* la funcion recibe un entero > 0 y un puntero a arreglo de int
devuelve el promedio de los numeros en el rango pasado en formato int */
float promedio_arreglo(int cantidad, int arreglo[]){
    float resultado = 0;
    int i = 0;
    while (i < cantidad)
    {
        resultado  = resultado + arreglo[i];
        i++;
    }
    resultado = resultado / cantidad;
    
    return resultado;    
}

/* la funcion recibe un entero > 0 y un puntero a arreglo de int
devuelve el minimo de los numeros en el rango pasado en formato int */
int minimo(int cantidad, int arreglo[])
{
    int i = 0;
    int menor = arreglo[i];
    while (i < cantidad - 1)
    {
        i++;
        if (menor > arreglo[i])
        {
            menor = arreglo[i];
        }
    }
    return menor;
}

/* la funcion recibe un entero > 0 y un puntero a arreglo de int
devuelve el maximo de los numeros en el rango pasado en formato int */
int maximo(int cantidad, int arreglo[])
{
    int i = 0;
    int mayor = arreglo[i];
    while (i < cantidad - 1)
    {
        i++;
        if (mayor < arreglo[i])
        {
            mayor = arreglo[i];
        }
    }
    return mayor;
}

/* la funcion recibe un entero > 0 y un puntero a arreglo de int
devuelve la posicion del maximo de los numeros en el rango pasado en formato int */
int posicion_maximo(int cantidad, int arreglo[])
{
    int i = 0;
    int mayor = arreglo[i];
    int posicion = i;
    while (i < cantidad - 1)
    {
        i++;
        if (mayor < arreglo[i])
        {
            mayor = arreglo[i];
            posicion = i;
        }
    }
    return posicion;
}

/* la funcion recibe un entero > 0 y un puntero a arreglo de int
devuelve la posicion del minimo de los numeros en el rango pasado en formato int */
int posicion_minimo(int cantidad, int arreglo[])
{
    int i = 0;
    int menor = arreglo[i];
    int posicion = i;
    while (i < cantidad - 1)
    {
        i++;
        if (menor > arreglo[i])
        {
            menor = arreglo[i];
            posicion = i;
        }
    }
    return posicion;
}

/* la funcion recibe un entero > 0 y un puntero a arreglo de int
el resultado es que el arreglo queda ordenado de mayor a menor
con los mismos elementos del arreglo original
la funcion devuelve -1 si la cantidad  es < 0 
o mayor al tamaño maximo del arreglo */
int ordenar_mayor_menor(int cantidad, int arreglo[])
{
    int mayor;
    int i = 0;
    int posicion;
    int cantidad_auxiliar = cantidad;
    int intercambio;
    int resultado;
    if(cantidad > 0 && cantidad < TAMANIO_ARREGLO)
    {
        while (i < cantidad)
        {
            mayor = maximo(cantidad_auxiliar, &arreglo[i]);
            posicion = posicion_maximo(cantidad_auxiliar, &arreglo[i]);
            intercambio = arreglo[i];
            arreglo[i] = mayor;
            arreglo[posicion + i] = intercambio;
            i++;
            cantidad_auxiliar--;
        }
        resultado = 0;
    }
    else
    {
        resultado = -1;
    }
    return 0;
}

/* la funcion recibe un entero > 0 y un puntero a arreglo de int
el resultado es que el arreglo queda ordenado de menor a mayor
con los mismos elementos del arreglo original
la funcion devuelve -1 si la cantidad  es < 0 
o mayor al tamño maximo del arreglo*/
int ordenar_menor_mayor(int cantidad, int arreglo[])
{
    int menor;
    int i = 0;
    int posicion;
    int cantidad_auxiliar = cantidad;
    int intercambio;
    int resultado;
    if(cantidad > 0 && cantidad < TAMANIO_ARREGLO)
        {
        while (i < cantidad)
        {
            menor = minimo(cantidad_auxiliar, &arreglo[i]);
            posicion = posicion_minimo(cantidad_auxiliar, &arreglo[i]);
            intercambio = arreglo[i];
            arreglo[i] = menor;
            arreglo[posicion + i] = intercambio;
            i++;
            cantidad_auxiliar--;
        }
        resultado = 0;
    }
    else
    {
        resultado = -1;
    }
    return resultado;
}

/* La funcion recibe un entero > 0, un puntero a arreglo de int,
y un puntero a char con los elementos pasados por linea de comandos
el resultado es que se carga la cadena de int con los parametros ingresados
si la cantidad es < 1 la funcion devuelve -1 */
int cargar_arreglo_commandos(int cantidad, int arreglo[], char *elementos[])
{
    int i = 1;
    int dato;
    int resultado;
    if (cantidad > 0 && cantidad < TAMANIO_ARREGLO)
        {
        while (i < cantidad)
        {        
            /* los datos son de tipo char, convertir a int */
            dato = atoi(elementos[i]);
            /* los indices en argv estan corridos una posicion */
            arreglo[i-1] = dato;
            i++;
        }
        resultado = 0;
    }
    else{
        resultado = -1;
    }    
    return resultado;
}

/* ***************************************************** */

void main(int argc, char *argv[])
{
    int arreglo[TAMANIO_ARREGLO];
    int cantidad_datos;
    int elemento;
    if (argc > 1)
    {
        cantidad_datos = argc;
        cargar_arreglo_commandos(cantidad_datos, arreglo, argv);
        
        /* argc tiene un dato mas que los que necesito */
        cantidad_datos--;                
    }
    else
    {
        printf("cuantos datos tiene el arreglo? \n");
        scanf("%d", &cantidad_datos);
        cargar_arreglo(cantidad_datos, arreglo);
    }
    printf("\nEl arreglo cargado es: ");
    muestra_arreglo(cantidad_datos, arreglo);
    elemento = minimo(cantidad_datos, arreglo);
    printf("\nEl minimo es: %d", elemento);
    ordenar_mayor_menor(cantidad_datos, arreglo);
    elemento = maximo(cantidad_datos, arreglo);
    printf("\nEl maximo es: %d", elemento);
    printf("\nEl arreglo ordenado de mayor a menor es: ");
    muestra_arreglo(cantidad_datos, arreglo);
    ordenar_menor_mayor(cantidad_datos, arreglo);
    printf("\nEl arreglo ordenado de menor a mayor es: ");
    muestra_arreglo(cantidad_datos, arreglo);
    printf("\n");
}