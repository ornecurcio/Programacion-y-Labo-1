/*
 ============================================================================
 Name        : Funciones.c
 Author      : Ornela Curcio
 Version     :
 Copyright   : Your copyright notice
 Description :
 a-Funciones
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
- Muestre el resultado por pantalla
 ============================================================================
 */

/*#include <stdio.h>
#include <stdlib.h>
#define DESCUENTO 5

float realizarDescuento(int num1, int num2);

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;

	float respuestaDescuento;

	printf("Ingrese un numero");
	scanf("%d", &numeroIngresado);
	while(numeroIngresado<10 || numeroIngresado>100)
	{
		printf("Error, ingrese un numero");
		scanf("%d", &numeroIngresado);
	}

	respuestaDescuento = numeroIngresado - realizarDescuento(numeroIngresado,DESCUENTO);


	printf("\nEl valor con descuento es %.2f",respuestaDescuento);

	return EXIT_SUCCESS;
}
float realizarDescuento(int num1, int num2)
{

	float resultado;

	resultado=(float)num1*num2/100;

	return resultado;
}
*/
/*b-Funciones
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores solicitados al usuario
- Valide los mismos entre 10 y 100
- Asigne a la variable operacion el valor solicitado al usuario
- Valide el mismo 's'-sumar, 'r'-restar
- Realice la operación de dichos valores a través de una función
- Muestre el resultado por pantalla*/

/*#include <stdio.h>
#include <stdlib.h>

int sumar(int num1, int num2);
int restar(int num1, int num2);

int main(void) {
	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	char respuesta;
	int resultadoOperacion;

	printf("Ingrese un numero");
	scanf("%d", &numero1);
	while(numero1<10 || numero1>100)
	{
		printf("Error, ingrese un numero");
		scanf("%d", &numero1);
	}
	printf("Ingrese un numero");
	scanf("%d", &numero2);
	while(numero2<10 || numero2>100)
	{
		printf("Error, ingrese un numero");
		scanf("%d", &numero2);
	}
	printf("Usted quiere sumar's' o restar'r'?");
	fflush(stdin);
	scanf("%c", &respuesta);

	if(respuesta=='s')
	{
		resultadoOperacion = sumar(numero1, numero2);
	}
	if(respuesta=='r')
	{
		resultadoOperacion = restar(numero1, numero2);
	}

	printf("\nEl valor de la operacion es %d", resultadoOperacion);

	return EXIT_SUCCESS;
}
int sumar(int num1, int num2)
{

	int resultado;

	resultado = num1+num2;

	return resultado;

}
int restar(int num1, int num2)
{

	int resultado;

	resultado = num1-num2;

	return resultado;

}*/
/*Ornela Curcio
Ejercicio 3-1:
Crear una función que permita determinar si un número es par o no.
La función retorna 1 en caso afirmativo y 0 en caso contrario.
Probar en el main.*/

/*#include <stdio.h>
#include <stdlib.h>

int numeroPar(int numero);

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int respuesta;

	printf("Ingrese un numero");
	scanf("%d", &numeroIngresado);

	respuesta = numeroPar(numeroIngresado);

	printf("\nEl retorno es %d", respuesta);

	return EXIT_SUCCESS;
}
int numeroPar(int numero)
{
	if(numero%2==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}*/
/*Ejercicio 3-2:
Crear una función que muestre por pantalla el número flotante que recibe como parámetro.*/

/*#include <stdio.h>
#include <stdlib.h>

float numeroFlotante(float num);

int main(void) {
	setbuf(stdout, NULL);

	float numeroIngresado;
	printf("Ingrese un numero");
	scanf("%f", &numeroIngresado);

	numeroFlotante(numeroIngresado);

	return EXIT_SUCCESS;
}

float numeroFlotante(float num)
{
	printf("El numero flotante es %.2f", num);
}
*/

/*Ornela Curcio
Ejercicio 3-3:
Crear una función que pida el ingreso de un entero y lo retorne.*/

/*#include <stdio.h>
#include <stdlib.h>

int numeroEntero();

int main(void) {
	setbuf(stdout, NULL);

	numeroEntero();

	return EXIT_SUCCESS;
}

int numeroEntero()
{
	int numeroIngresado;
		printf("Ingrese un numero");
		scanf("%d", &numeroIngresado);
		printf("El numero entero es %d", numeroIngresado);
}
*/

/*Ejercicio 3-4:
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);*/

#include <stdio.h>
#include <stdlib.h>

int sumar1(int num1, int num2);
int sumar2();
void sumar3(int num1, int num2);
void sumar4();

int main(void) {
	setbuf(stdout, NULL);

	int opcionIngresada;
	int numero1;
	int numero2;
	int respuesta;

	printf("Ingrese una opcion de suma: 1, 2, 3, 4");
	scanf("%d", &opcionIngresada);
	while(opcionIngresada<1 || opcionIngresada>4)
		{
			printf("Error, una opcion de suma: 1, 2, 3, 4");
			scanf("%d", &opcionIngresada);
		}
	switch(opcionIngresada)
	{
	case 1:
		printf("Ingrese un numero");
		scanf("%d", &numero1);
		printf("Ingrese un numero");
		scanf("%d", &numero2);
		respuesta = sumar1(numero1, numero2);
		printf("La suma es %d", respuesta);
		break;
	case 2:
		respuesta = sumar2();
		printf("La suma es %d", respuesta);
		break;
	case 3:
		printf("Ingrese un numero");
		scanf("%d", &numero1);
		printf("Ingrese un numero");
		scanf("%d", &numero2);
		sumar3(numero1, numero2);
		break;
	case 4:
		sumar4();
		break;
	}


	return EXIT_SUCCESS;
}

int sumar1(int num1, int num2)
{
	int resultado;
	resultado = num1+num2;
	return resultado;
}
int sumar2()
{
	int resultado;
	int num1;
	int num2;
	printf("Ingrese un numero");
	scanf("%d", &num1);
	printf("Ingrese un numero");
	scanf("%d", &num2);

	resultado = num1+num2;

	return resultado;

}
void sumar3(int num1, int num2)
{
	int resultado;
	resultado=num1+num2;
	printf("La suma es  %d", resultado);
}
void sumar4()
{
	int resultado;
	int num1;
	int num2;
	printf("Ingrese un numero");
	scanf("%d", &num1);
	printf("Ingrese un numero");
	scanf("%d", &num2);

	resultado = num1+num2;

	printf("La suma es %d", resultado);
}
