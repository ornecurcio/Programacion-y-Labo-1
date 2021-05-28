/*
 ============================================================================
 Name        : Puntero-Funcio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar un programa que :
a)tenga 2 funciones una para calcular el minimo y otra para
calcular el maximo :
que retorne -1 si hubo errores y 0 si funcionó bien
que reciba dos número para comparar y un entero por referencia para devolver
el mínimo o máximo encontrado
b)Luego desarrollar una función que reciba por parámetro dos número enteros y
un puntero a función que ejecute la función recibida por parámetro y retorne el
resultado por retorno.  Puede recibir cualquiera de las dos funciones desarrolladas en
el punto a)
Crear un main donde se utilice la función del punto b) utilizando las 2 funciones
desarrolladas en el punto a)
 ============================================================================
 */
/*
#include <stdio.h>
#include <stdlib.h>
int buscaMinimo(int num1, int num2, int* pResultado);
int buscaMaximo(int num1, int num2, int* pResultado);
int buscaMinMax(int num1, int num2, int(pFunsion)(int, int, int*));
int main(void) {
	setbuf(stdout, NULL);

	int A=25;
	int B=30;
	int num;

	num=buscaMinMax(A, B, buscaMinimo);

	printf("\nEl minimo es %d", num);

	num=buscaMinMax(A, B, buscaMaximo);

	printf("\nEl maximo es %d", num);

	return EXIT_SUCCESS;
}

int buscaMinimo(int num1, int num2, int* pResultado)
{
	int retorno=-1;
	if(pResultado!=NULL)
	{
		if(num1<num2)
		{
			*pResultado=num1;
			retorno=0;
		}
		else
		{
			*pResultado=num2;
			retorno=0;
		}
	}
	return retorno;
}
int buscaMaximo(int num1, int num2, int* pResultado)
{
	int retorno=-1;
	if(pResultado!=NULL)
	{
		if(num1>num2)
		{
			*pResultado=num1;
			retorno=0;
		}
		else
		{
			*pResultado=num2;
			retorno=0;
		}
	}
	return retorno;
}
int buscaMinMax(int num1, int num2, int(pFunsion)(int, int, int*))
{
	int resultado;
	if(pFunsion!=NULL)
	{
		pFunsion(num1, num2, &resultado);
	}
	return resultado;
}
*/
/*Realizar una funcion que respete el siguiente prototipo: int Calculador(int, int, int*, int(pFuncion)(int, int))
 * Dicha funcion debera recibir dos operandos y un operador representando mediante la funcion pasada como ´parametro.
 * El puntero a entero, servira como de salida y guardará el resultado de la operacion.*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int suma(int num1, int num2);
int resta(int num1, int num2);
int calculador(int num1, int num2, int(*pFunsion)(int, int), int* pResultado);
int main(void) {
	setbuf(stdout, NULL);

	int A=25;
	int B=30;
	int num;

	calculador(A, B, suma, &num);

	printf("\nEl resultado de la suma es %d", num);

	calculador(A, B, resta, &num);

	printf("\nEl resultado de la resta es %d", num);

	return EXIT_SUCCESS;
}

int suma(int num1, int num2)
{
	int retorno;

	retorno = num1+num2;

	return retorno;
}
int resta(int num1, int num2)
{
	int retorno;

	retorno = num1-num2;

	return retorno;
}
int calculador(int num1, int num2, int(*pFunsion)(int, int), int* pResultado)
{
	int retorno=-1;
	if(pResultado!=NULL && pFunsion!=NULL)
	{
		*pResultado = pFunsion(num1, num2);
	}
	return retorno;
}
*/
/*Realizar una funcion que respete el siguiente prototipo: int Ordenador(eProducto*, int, int(*pFuncion)(eProducto*, eProducto*))
 * La funcion recibira como parametros:
 * el array de productos, dado por el puntero eProducto
 * la cantidad de elementos del array.
 * el criterio de ordenamiento, dado por la funcion pfuncion
 * Ej: int compararPorMarca(eProducto*, eProducto*)
 * Ej: int compararPorPrecio(eProducto*, eProducto*)
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int precio;
	char marca[20];
	int id;
}eProducto;

int compararPorMarca(eProducto* product1, eProducto* product2);
int compararPorPrecio(eProducto* product1, eProducto* product2);
int Ordenador(eProducto* array, int cantidadDeArray,int criterio, int(*pFuncion)(eProducto*, eProducto*));
int main(void) {
	setbuf(stdout, NULL);

	eProducto productos[4]={
			{150, "Playadito", 1},
			{100, "Pampero", 2},
			{120, "Amanda", 3},
			{180, "Rosamonte", 4},
	};

	Ordenador(productos, 4, 0, compararPorMarca);
	for(int i=0; i<4; i++)
	{
		printf("\nEl resultado del ordenamiento ascendente x Marca es %s ", (*(productos+i)).marca);
	}
	Ordenador(productos, 4, 0, compararPorPrecio);

	for(int i=0; i<4; i++)
	{
		printf("\nEl resultado del ordenamiento ascendente x Precio es %s %d", (*(productos+i)).marca, (*(productos+i)).precio);
	}
	Ordenador(productos, 4, 1, compararPorMarca);
	for(int i=0; i<4; i++)
	{
		printf("\nEl resultado del ordenamiento descendente x Marca es %s ", (*(productos+i)).marca);
	}
	Ordenador(productos, 4, 1, compararPorPrecio);

	for(int i=0; i<4; i++)
	{
		printf("\nEl resultado del ordenamiento descendente x Precio es %s %d", (*(productos+i)).marca, (*(productos+i)).precio);
	}

	return EXIT_SUCCESS;
}

int compararPorMarca(eProducto* product1, eProducto* product2)
{
	int retorno=0;

	if(product1!=NULL && product2!=NULL)
	{

		retorno = strcmp((*(product1)).marca, (*(product2)).marca );

	}
	return retorno;
}
int compararPorPrecio(eProducto* product1, eProducto* product2)
{
	int retorno=0;
	if(product1!=NULL && product2!=NULL)
	{
		if( (*(product1)).precio > (*(product2)).precio )
		{
			retorno=1;
		}
		if( (*(product1)).precio < (*(product2)).precio )
		{
			retorno=-1;
		}
	}

	return retorno;
}
int Ordenador(eProducto* array, int cantidadDeArray,int criterio, int(*pFuncion)(eProducto*, eProducto*))
{
	int retorno=-1;
	eProducto aux;
	if(array!=NULL && pFuncion!=NULL)
	{
		for(int i=0; i<cantidadDeArray-1; i++)
		{
			for(int j=i+1; j<cantidadDeArray; j++)
			{
				switch(criterio)
				{
				 case 0:
					if(pFuncion((array+i), (array+j))>0)
					{
						 aux = *(array+i);
						*(array+i) = *(array+j);
						*(array+j) = aux;

						retorno=0;
					}
					break;
				 case 1:
					 if(pFuncion((array+i), (array+j))<0)
					{
						 aux = *(array+i);
						*(array+i) = *(array+j);
						*(array+j) = aux;

						retorno=0;
					}
					break;
				}
			}
		}
	}
	return retorno;
}


