/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 Determinar:Cantidad de positivos y negativos.Sumatoria de los pares.
 El mayor de los impares.Listado de los números ingresados.
 Listado de los números pares.Listado de los números de las posiciones impares.
 Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMEROS 4

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void imprimirArray(int indiceDeArray[], int cantidadDeArray);
int sumarNumerosPares(int* pResultado, int num[], int cantidadDeArray);
int buscaElMayorNumImpar(int* pResultado, int num[], int cantidadDeArray);
int contadorNumeros(int* pResultado1,int* pResultado2, int num[], int cantidadDeArray);
void imprimirArrayPares(int indiceDeArray[], int cantidadDeArray);
void imprimirArrayImPares(int indiceDeArray[], int cantidadDeArray);

int main(void) {
	setbuf(stdout, NULL);

	int numero[NUMEROS];
	int numeroIngresado;
	int contadorPositivos;
	int contadorNegativos;
	int sumaPares;
	int mayorImpares;
	int i;

	for(i=0; i<NUMEROS; i++)
	{
		if(utn_getNumero(&numeroIngresado, "Ingrese un numero", "Error, ingrese un numero", -1000, 1000, 2)==0)
		{
			numero[i]=numeroIngresado;
		}
	}
	sumarNumerosPares(&sumaPares, numero, NUMEROS);
	buscaElMayorNumImpar(&mayorImpares, numero, NUMEROS);
	contadorNumeros(&contadorPositivos, &contadorNegativos, numero, NUMEROS);

	//printf("La cantidad de positivos es %d\n", contadorPositivos);
	//printf("La cantidad de negativos es %d\n", contadorNegativos);
	if(contadorNumeros==1)
	{
		printf("La cantidad de positivos es %d\n", contadorPositivos);
		printf("La cantidad de negativos es %d\n", contadorNegativos);
	}
	if(sumarNumerosPares==0)
	{
		printf("La suma de los pares es %d", sumaPares);
		printf("La lista de los pares es", imprimirArrayPares);
	}
	else
	{
		printf("No hay numero pares para sumar");
	}
	/*if(buscaElMayorNumImpar==0)
	{
		printf("El mayor de los impares es %d\n", mayorImpares);
		printf("La lista de los impares es", imprimirArrayImPares);
	}
	else
	{
		printf("No hay numeros impares");
	}*/
	return EXIT_SUCCESS;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInterno);
			if(bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
void imprimirArray(int indiceDeArray[], int cantidadDeArray)
{	int i;
	for(i=0; i<cantidadDeArray; i++)
	{
		printf("%d ", indiceDeArray[i]);
	}
}
int sumarNumerosPares(int* pResultado, int num[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	*pResultado=0;

	for(i=0; i<cantidadDeArray; i++)
	{
		if(num[i]%2==0)
		{
			*pResultado=*pResultado+num[i];
			retorno = 0;
		}
	}
	return retorno;
}
int buscaElMayorNumImpar(int* pResultado, int num[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	int numMayor=num[0];

	for(i=0; i<cantidadDeArray; i++)
	{
		if(num[i]>numMayor)
		{
			*pResultado=num[i];
			retorno = 0;
		}
	}
	return retorno;
}
int contadorNumeros(int* pResultado1,int* pResultado2, int num[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	int contadorPositivos=0;
	int contadorNegativos=0;
	if(pResultado1 != NULL && pResultado2 != NULL)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(num[i]>-1)
			{
				contadorPositivos++;
			}
			else
			{
				contadorNegativos++;
			}
		}
		*pResultado1=contadorPositivos;
		*pResultado2=contadorNegativos;
		retorno = 1;
	}
	return retorno;
}
void imprimirArrayPares(int indiceDeArray[], int cantidadDeArray)
{
	int i;
	for(i=0; i<cantidadDeArray; i++)
	{
		if(indiceDeArray[i]%2==0)
		{
			printf("%d ", indiceDeArray[i]);
		}
	}
}
void imprimirArrayImPares(int indiceDeArray[], int cantidadDeArray)
{
	int i;
	for(i=0; i<cantidadDeArray; i++)
	{
		if(indiceDeArray[i]%2==0)
		{
			printf("%d ", indiceDeArray[i]);
		}
	}
}
