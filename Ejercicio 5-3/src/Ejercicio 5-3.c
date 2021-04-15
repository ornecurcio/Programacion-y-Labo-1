/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 5-3:Realizar un programa que permita el ingreso de 10 números
 enteros distintos de cero.
 La carga deberá ser aleatoria (todos los elementos se inicializarán en cero por default.
 Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores.

 Utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMEROS 10
int promediarArray(float* pPromedioResultado, int array[], int cantidadArray);
void imprimirArray(int indiceDeArray[], int cantidadDeArray);
int main(void) {
	setbuf(stdout, NULL);

	char respuesta;
	int posNum;
	int numero[NUMEROS];
	int i;
	float promedio;
	int retornoProm;
	int contadorArray=0;

	for(i=0; i<NUMEROS; i++)
	{
		numero[i]=0;

	}

	do
	{
		printf("Ingrese posicion");
		scanf("%d", &posNum);
		while(posNum>NUMEROS-1 || posNum<0)
		{
			printf("Error, Ingrese un numero entre 0 y %d", NUMEROS-1);
			scanf("%d", &posNum);
		}
		printf("Ingrese numero entero distinto de 0");
		scanf("%d", &numero[posNum]);
		while(numero[posNum]==0)
		{
			printf("Ingrese Numero entero distinto de 0");
			scanf("%d", &numero[posNum]);
		}
		contadorArray++;
		printf("Quiere ingresar otro numero? Ingrese 's'");
		fflush(stdin);
		scanf("%c", &respuesta);

	}while(respuesta=='s');

	for(i=0; i<NUMEROS; i++)
	{
		if(numero[i]!=0)
		{
			if(numero[i]>0)
		}
	}
	printf("El promedio es %d", promedio);
	imprimirArray(numero, NUMEROS);

	return EXIT_SUCCESS;

}
void imprimirArray(int indiceDeArray[], int cantidadDeArray)
{	int i;
	for(i=0; i<cantidadDeArray; i++)
	{
		printf("%d ", indiceDeArray[i]);
	}
}
int promediarArray(float* pPromedioResultado, int array[], int cantidadArray)
{
	int i;
	int acumulador=0;
	for(i=0; i<cantidadArray; i++)
	{
		acumulador = acumulador + array[i];
	}
	*pPromedioResultado = (float)acumulador/cantidadArray;

	return 0;
}

