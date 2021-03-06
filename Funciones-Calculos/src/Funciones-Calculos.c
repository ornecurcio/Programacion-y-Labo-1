/*
 ============================================================================
 Name        : Funciones-Calculos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Un programa que pida un numero al usuario,despues que pida una operacion(suma,resta,div,mul)
 despues que pida otro numero. Segun la operacion ingresada se llamara a la funcion correspondiente,
 y luego mostrar al usuario el resultado. El mostrar resultado no puede estar dentro de las funciones.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresadoUno;
	int numeroIngresadoDos;
	char operacionSeleccionada;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	int huboError;

	printf("Ingrese un numero");
	fflush(stdin);
	scanf("%d", &numeroIngresadoUno);

	printf("Ingrese una operacion: s-Suma, r-Restar, m-Multiplicar, d-Dividir");
	fflush(stdin);
	scanf("%c", &operacionSeleccionada);

	printf("Ingrese un numero");
	fflush(stdin);
	scanf("%d", &numeroIngresadoDos);

	switch(operacionSeleccionada)
	{
	case 's':
		resultadoSuma=sumar(numeroIngresadoUno, numeroIngresadoDos);
		printf("El resultado es %d", resultadoSuma);
		break;
	case'r':
		resultadoResta=restar(numeroIngresadoUno, numeroIngresadoDos);
		printf("El resultado es %d", resultadoResta);
		break;
	case'm':
		huboError = multiplicar(numeroIngresadoUno, numeroIngresadoDos, &resultadoMultiplicacion);
		if(huboError==0)
		{
			printf("El resultado de la multiplicacion es %d", resultadoMultiplicacion);
		}
		else
		{
			printf("No es posible multiplicar por cero");
		}
		break;
	case'd':
		huboError = dividir(numeroIngresadoUno, numeroIngresadoDos, &resultadoDivision);
		if(huboError==0)
		{
		printf("El resultado de la division es %f", resultadoDivision);
		}
		else
		{
			printf("No es posible dividir por cero");
		}
		break;
	}
	return EXIT_SUCCESS;
}

