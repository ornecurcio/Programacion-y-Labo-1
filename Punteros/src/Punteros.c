/*
 ============================================================================
 Name        : Punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void funcion1(int aArray[], int cantidadDeArray);
void funcion2(int aArray[], int cantidadDeArray);
void funcion2(int aArray[], int cantidadDeArray);
void funcion3(int* aArray, int cantidadDeArray);
void funcion4(int* aArray, int cantidadDeArray);
int main(void) {
	setbuf(stdout, NULL);

	int vec[TAM];

	//funcion1(vec, TAM);
	//funcion2(vec, TAM);
	//funcion3(vec, TAM);
	funcion4(vec, TAM);
	return EXIT_SUCCESS;
}

void funcion1(int aArray[], int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		aArray[i]=i+1;
	    printf("\n%d", aArray[i]);
	}
}
void funcion2(int aArray[], int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		*(aArray+i)=i+1;
	    printf("%d", *(aArray+i));
	}
}
void funcion3(int* aArray, int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		aArray[i]=i+1;
		printf("%d", aArray[i]);
	}
}
void funcion4(int* aArray, int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		*(aArray+i)=i+1;
		printf("%d",*(aArray+i));
	}
}
*/
/*Realizar una función Suma que reciba como parámetros dos enteros (los que va a
sumar) y un puntero a entero que guardara el resultado de esta. La función retorna 1 si
pudo realizar la suma y cero en caso de no haberla podido realizar.
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int suma(int*pResultado, int num1, int num2);
int main(void) {
	setbuf(stdout, NULL);

	int numero1=5;
	int numero2=10;
	int resultado;

	suma(&resultado, numero1, numero2);
	printf("%d", resultado);

	return EXIT_SUCCESS;
}
int suma(int*pResultado, int num1, int num2)
{
	int retorno=0;
	if(pResultado!=NULL)
	{
	*pResultado=num1+num2;
	retorno=1;
	}

	return retorno;
}*/
/*Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 6

int nombre(char*pResultado, char letra1, char letra2);

int main(void) {
	setbuf(stdout, NULL);

	char cadena[6]={"Ivana"};
	char letra1='a';
	char letra2='e';
	int contador;

	contador=nombre(cadena, letra1, letra2);
	printf("%s el contador es %d", cadena, contador);

	return EXIT_SUCCESS;
}
int nombre(char* pResultado, char letra1, char letra2)
{
	int contador=-1;
	int len;
	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		contador=0;
		len = strlen(pResultado);
		for(int i=0; i<len; i++)
		{
			if(*(pResultado+i)==letra1)
			{
				*(pResultado+i)=letra2;
				contador++;
			}
		}
	}

	return contador;
}
/*Realizar una función que reciba como parámetros un array de enteros y un entero por
referencia. La función calculara el máximo valor de ese array y utilizara el valor por
referencia para retornar ese valor.*/
/*
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void buscaMayor(int*pArray, int cantidadDeArray, int*maximo);
int main(void) {
	setbuf(stdout, NULL);

	int vecNumero[TAM]={10, 9, 8, 7, 6, 4, 5, 3, 2, 12};
	int maximo;

	buscaMayor(vecNumero, TAM, &maximo);

	printf("%d", maximo);

	return EXIT_SUCCESS;
}
void buscaMayor(int*pArray, int cantidadDeArray, int*maximo)
{
	int flag=0;
	int auxMax;

	if(pArray!=NULL && TAM>0)
	{
		for(int i=0; i<cantidadDeArray; i++)
		{
			if(flag==0)
			{
				auxMax=*(pArray+i);
			}
			else
			{
				if(*(pArray+i)>auxMax)
				{
					auxMax=*(pArray+i);
				}
			}
		}
		*maximo=auxMax;
	}
}
*/
/*
Ejercicio 8.4
Escriba una función que reciba dos números enteros y los devuelva ordenados. Es
decir que en el primer parámetro debe devolver el menor valor y en el 2do. el mayor.*/
/*
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void buscaMayor(int*pArray, int cantidadDeArray, int*maximo);
int main(void) {
	setbuf(stdout, NULL);

	int vecNumero[TAM]={10, 9, 8, 7, 6, 4, 5, 3, 2, 12};
	int maximo;

	buscaMayor(vecNumero, TAM, &maximo);

	printf("%d", maximo);

	return EXIT_SUCCESS;
}
void buscaMayor(int*pArray, int cantidadDeArray, int*maximo)
{
	int flag=0;
	int auxMax;

	if(pArray!=NULL && cantidadDeArray>0)
	{
		for(int i=0; i<cantidadDeArray; i++)
		{
			if(flag==0)
			{
				auxMax=*(pArray+i);
			}
			else
			{
				if(*(pArray+i)>auxMax)
				{
					auxMax=*(pArray+i);
				}
			}
		}
		*maximo=auxMax;
	}
}*/
/*Ejercicio 8.5
Realizar una función que reciba como parámetros dos vectores. La función deberá
determinar si el segundo vector esta contenido en el primero.*/
/*#include <stdio.h>
#include <stdlib.h>
#define QTY_1 10
#define QTY_2 5

int buscaUnoenOtro(int*pArray1, int cantidadDeArray1, int*pArray2, int cantidadDeArray2);
int main(void) {
	setbuf(stdout, NULL);

	int vecNum1[QTY_1]={10, 9, 8, 7, 6, 4, 5, 3, 2, 12};
	int vecNum2[QTY_2]={3,2,12,8,7};
	int num;

	printf("%d", num);

	return EXIT_SUCCESS;
}
int buscaUnoenOtro(int*pArray2, int cantidadDeArray2)
{
	int retorno=-1;
	if(pArray2!=NULL && cantidadDeArray2>0)
	{
		for(int i=0; i<cantidadDeArray2; i++)
		{

		}
	}
	return retorno;
}
int buscaArray(int*pArray1, int cantidadDeArray1, int num1)
{
	int retorno=-1;
	if(pArray1!=NULL && cantidadDeArray1>0)
	{
		for(int i=0; i<cantidadDeArray1; i++)
		{
			if((*(pArray1+i))==num1)
			{

			}
		}
	}
}
*/
