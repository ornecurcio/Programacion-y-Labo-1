/*
 * calculos.c
 *
 *  Created on: 2 abr. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>

int utn_sumar(int* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numUno+numDos;
		retorno=0;
	}

	return retorno;
}
int utn_restar(int* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numUno-numDos;
		retorno=0;
	}

	return retorno;
}
int utn_multiplicar(int* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numUno*numDos;
		retorno=0;
	}

	return retorno;
}
int utn_dividir(float* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL && numDos!=0)
	{
		*pResultado = (float)numUno/numDos;
		retorno=0;
	}

	return retorno;
}
int utn_promediarArray(float* pPromedioResultado, int array[], int cantidadArray)
{
	int retorno = -1;
	int i;
	int acumulador=0;

	if(pPromedioResultado != NULL)
	{
		for(i=0; i<cantidadArray; i++)

		{
		acumulador = acumulador + array[i];
		}

		*pPromedioResultado = (float)acumulador/cantidadArray;
	}
	return retorno;
}
void utn_imprimirArray(int listaDeArray[], int cantidadDeArray)
	{	int i;
		for(i=0; i<cantidadDeArray; i++)
		{
			printf("%d ", listaDeArray[i]);
		}
	}
int utn_factorial(int* pResultado, int num)
{
	int retorno= -1;
	int i;
	*pResultado=1;
	if(num==0)
	{
		*pResultado = 1;
		retorno = 0;
	}
	else
	{
		if(num>0)
		{
			for(i=num; i>1; i--)
			{
				*pResultado=*pResultado*i;
				retorno=0;
			}
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}
int imprimirArrayResultados(int listaDeArray[], int resultadosArray[], float resultadoDiv)
{
	int retorno = -1;
		do{
		if(listaDeArray[0]==0)
		{
			printf("El resultado de la suma es %d\n", resultadosArray[0]);
		}
		else
		{
			printf("Error, no se realizo la suma\n");
		}
		if(listaDeArray[1]==0)
		{
			printf("El resultado de la resta es %d\n", resultadosArray[1]);
		}
		else
		{
			printf("Error, no se realizo la resta\n");
		}
		if(listaDeArray[2]==0)
		{
			printf("El resultado de la multiplicacion es %d\n", resultadosArray[2]);
		}
		else
		{
			printf("Error, no se realizo la multiplicacion\n");
		}
		if(listaDeArray[3]==0)
		{
			printf("El resultado de la division es %.2f\n", resultadoDiv);
		}
		else
		{
			printf("Error, no se realizo la division\n");
		}
		retorno=0;
		if(listaDeArray[4]==0)
		{
			printf("El factorial de A es %d\n", resultadosArray[3]);
		}
		else
		{
			printf("Error, no se realizo factorial\n");
		}
		if(listaDeArray[4]==0)
		{
			printf("El factorial de B es %d\n", resultadosArray[4]);
		}
		else
		{
			printf("Error, no se realizo factorial\n");
		}

		}while(retorno==-1);

	return retorno;
}
int promediar2Notas(float* pPromedioResultado, int num1, int num2)
{
	int retorno = -1;

	if(pPromedioResultado != NULL)
	{
		*pPromedioResultado = ((float)num1+num2)/2;
		retorno=0;
	}
	return retorno;
}
