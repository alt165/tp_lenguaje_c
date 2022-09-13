# TP1 C1

## Forma de entrega

* Cada punto debe ser entregado en un archivo independiente
* El nombre de cada archivo debe ser ser `ejercicio` seguido 
del numero de ejercicio mas `.c` (el primer ejercicio sera entonces `ejercicio1.c`
* Cada archivo debe seguir la estructura indicada dentro de `plantilla.c`, la cual debe
estar completa con su nombre y usuario de GitHub. 
* En ningún caso se aceptara el uso de variables globales. Toda la información 
necesaria para el funcionamiento de las funciones a desarrollar tienen que ser
pasado como argumentos de las mismas.
* Se provee el prototipo en Python de la función a implementar en todos los ejercicios, 
pero pueden crear mas funciones aparte de la pedida.
* Indiquen las pre y poscondiciones de su algoritmo.
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"

## Ejercicios

### 1. Hola Mundo

Desarrollar un programa que muestre por STDOUT el mensaje "Hola Mundo".

Indicar en un comentario la instrucción de compilación con GCC por linea de comandos.

### 2. Conversión de temperaturas

Se quiere transformar temperaturas en grados fahrenheit a grados centígrados y viceversa.

Escribir las funciones para convertir la temperatura en grados centigrados en fahrenheit como 
un número decimal, utilice esta formula para calcular los grados centígrados y retorne el 
resultado obtenido. Y viceversa.

``` python
def convertir_a_fahrrenheit(centigrados):
def convertir_a_centigrados(fahrenheit):
```
### 3. Números positivos y negativos

Escribir una función que reciba un número e indique si el mismo es positivo, negativo o cero con un numero entero y utilizando operaciones de suma y resta.

``` python
def signo(numero):
```

### 4. Comparación de números

Escribir una función que utilizando sumas y restas, reciba dos valores y retorne:
 * Retornar `-1` si el primero es menor que el segundo
 * Retornar `0` si son iguales
 * Retornar `1` si el primero es mayor que el segundo
 
``` python
def compara(numero, otro_numero):
```

### 5. Suma lenta

Escribir una función que haga la suma entre dos números enteros sin hacer la operación de 
manera directa. Esto quiere decir que para hacer la suma entre 4 y 3, las operaciones 
resultantes deberán ser 4+1+1+1.

La funcion debe ser capaz de sumar cualquier numero entero positivo y negativo.

``` python
def suma_lenta(numero, otro_numero):
```

### 6. Divisiones
Escribir una función que mediante restas sucesivas, obtenga el valor del 
cociente y el resto de dos números enteros.

``` python
def division_lenta(dividendo, divisor):

def cociente_lento(dividendo, divisor):
```


### 7. Números primos
Escribir una función que indique con `True` si un numero indicado es Primo.

``` python
def es_primo(numero):
```

### 8. Palíndromo
Escribir una función que indique con True si una palabra o frase ingresada se trata de un palindromo.
Palíndromo, es si se lee igual de derecha a izquierda que de izquierda a derecha.

``` python
def es_palindromo(texto):
```

### 9. Multiplos de
Escribir una función que indique con `True` si un número entero es multiplo de otro, utilizando sumas y restas.

``` python
def es_multiplo(numero, multiplo):
```

### 10. Factorial

Desarrollar un programa obtenga el factorial de un número entero.

``` python
def factorial(numero, ):
```
---
# TP C2

En este TP, vamos a trabajar principalmente con arreglos.

Tengan **POR LO MENOS** encarado este TP antes de la proxima clase, hará mas facil la tarea
de entender que pasa con los temas que trataremos.

## Forma de entrega

* Cada archivo debe seguir la estructura indicada dentro de `plantilla.c`, la cual debe
estar completa con su nombre y usuario de GitHub.
* La prolijidad cuenta.
* No mezclen tabuladores y espacios en la indentación.
* En ningún caso se aceptara el uso de variables globales. Toda la información 
necesaria para el funcionamiento de las funciones a desarrollar tienen que ser
pasado como argumentos de las mismas.
* Indiquen las pre y poscondiciones de cada funcion implementada.
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"

# Fecha de entrega

La fecha de entrega de este TP es el dia viernes 2 de septiembre a las 17 horas. (02/09/2022)

## Ejercicios

Los tres ejercicios pueden convivir en un solo archivo, para no tener que estar duplicando código.
(la forma correcta de mantener las cosas separadas la veremos mas adelante)

Por lo que la entrega puede ser un archivo como `arreglos.c`

### 1. Cargador de arreglos

Un detalle importante que quedó fuera de la clase, tiene que ver con la forma en la que 
los argumentos de tipo arreglo viajan a una función.

Al pasarlo como `int conjunto[]`, lo que viaja a la funcion, no es el arreglo como bloque,
sino como su ubicacion en la memoria. Por lo tanto, los cambios que le hagan al mismo,
se reflejaran en la variable original. (De la misma manera que `scanf` funciona)

Desarrollar una función que dado un arreglo de numeros enteros, y la cantidad de elementos. 
Solicite valores para completar las posiciones.

Desarrollar tambien una función que permita mostrar el contenido de dicho arreglo, indicando
en que posicion se encuentra cada valor.

Utilicen el valor de `return` para indicar potenciales fallos.

Su programa debe de ser capaz de almacenar e imprimir una cantidad ajustable
en tiempo de compilación.

```C
int cargar_arreglo(int cantidad, int arreglo[]);
int muestra_arreglo(int cantidad, int arreglo[]);
```

## 2. Operaciones con arreglos

Implementar funciones que permitan hacer las siguientes operaciones sobre arreglos de numeros enteros:

 * Promedio
 * Minimo
 * Maximo
 * Ordenar de menor a mayor
 * Ordenar de mayor a menor

## 3. Carga como argumentos

Implementar una funcion que emplee los argumentos del programa para cargar un arreglo, de forma
que sea posible hacer algo como:

```sh
$> ./programa 10 23 4 23 4 5 6 6
```

Pero si no estan estos argumentos, que se utilice la tecnica del punto 1.

---

# TP C3

En este TP, vamos a trabajar con estructuras.

## Forma de entrega

* Cada archivo debe seguir la estructura indicada dentro de `plantilla.c`, la cual debe
estar completa con su nombre y usuario de GitHub.
* La prolijidad cuenta.
* No mezclen tabuladores y espacios en la indentación.
* En ningún caso se aceptara el uso de variables globales. Toda la información 
  necesaria para el funcionamiento de las funciones a desarrollar tienen que ser
  pasado como argumentos de las mismas.
* Cada funcion implementada debe contar con un comentario sobre su prototipo que describa:
  * Las pre y poscondiciones de cada funcion implementada de forma coloquial
  * La descripción de los arguementos que recibe
  * La descripción de los valores que retorna.  
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"

# Fecha de entrega

La fecha de entrega de este TP es el dia viernes 16 de septiembre a las 17 horas. (16/09/2022)

## Ejercicios


### 1. Fracciones

Desarrollar las funciones necesarias para operar con fracciones de números enteros.

```C
typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion_t;
```
Operaciones a implementar:
 * Mostrar una fraccion por consola.
 * Suma entre fracciones
 * Multiplicacion entre fracciones
 * Suma con un número entero.
 
El `main` para este ejercicio debe utilizar todas estas operaciones.

Este ejercicio no requiere de la utilización de punteros.

### 2. División Lenta II

Unificar las funciones de división lenta del TP1 de forma que la funcion retorne una estructura
representando los valores posibles.

Crear las funciones de soporte necesarias.

### 3. Gestionando el `tiempo_t`

Desarrollar una estructura y funciones que permitan realizar las siguientes operaciones con 
tiempo expresado en horas, minutos y segundos.

 * Crear `tiempo_t`
 * Mostrar `tiempo_t`
 * Sumar segundos
 * Sumar minutos
 * Sumar horas
 * Sumar dos `tiempo_t`
 