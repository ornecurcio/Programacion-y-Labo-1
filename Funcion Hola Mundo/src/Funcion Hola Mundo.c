/*
 ============================================================================
 Name        : Funcion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int numeroIngresado();  //declaracion si o si antes del main siempre y termina en ; (a esta declaracion se llama prototipo)


int main(void) {
	setbuf(stdout, NULL);
	int res;

	res = NumeroIngresado(); //llamada o invocacion
	printf("\El numero ingresado es: %d", res);

	res = NumeroIngresado();
	printf("\El numero ingresado es: %d", res);

	return EXIT_SUCCESS;
}
int numeroIngresado() //desarrollo
{
	int num;
	printf("\nF-Ingrese un numero entero");
	scanf("%d", &num);

	return num;
}

