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

int sumar(int operadorUno, int operadorDos);
int restar(int operadorUno, int operadorDos);
int multiplicar(int operadorUno, int operadorDos);
float dividir(int operadorUno, int operadorDos);

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresadoUno;
	int numeroIngresadoDos;
	char operacionSeleccionada;
	int resultadoSuma;
	int resultadoResta;
	int resultadoDivision;
	int resultadoMultiplicacion;

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
		resultadoMultiplicacion=multiplicar(numeroIngresadoUno, numeroIngresadoDos);
		printf("El resultado es %d", resultadoMultiplicacion);
		break;
	case'd':
		resultadoDivision=dividir(numeroIngresadoUno, numeroIngresadoDos);
		printf("El resultado es %d", resultadoDivision);
		break;
	}

	return EXIT_SUCCESS;
}

int sumar(int operadorUno, int operadorDos)
{
	int resultado;
	resultado = operadorUno+operadorDos;
	return resultado;
}
int restar(int operadorUno, int operadorDos)
{
	int resultado;
	resultado = operadorUno-operadorDos;
	return resultado;
}
int multiplicar(int operadorUno, int operadorDos)
{
	int resultado;
	if(operadorUno==0 || operadorDos==0)
	{
		printf("Error no se puede multiplicar por cero");
	}
	resultado = operadorUno*operadorDos;
	return resultado;
}
float dividir(int operadorUno, int operadorDos)
{
	int resultado;
	if(operadorUno==0 || operadorDos==0)
	{
		printf("Error no se puede multiplicar por cero");
	}
	resultado = (float)operadorUno/operadorDos;
	return resultado;
}
