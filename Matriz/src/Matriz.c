/*
 ============================================================================
 Name        : Matriz.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define QTY_CLIENTES 4
#define MSG_INGRESESUNOM "Ingrese su nombre: "
#define MSG_INGRESESUAP "Ingrese su apellido: "

void getString(char mensaje[], char imput[]);
int printArrayStr(char pArray[][20], int limite); // estoy pasando una matriz, entonces hay q aclarar el 20
int ordenar2ArrayStr(char pArrayNombre[][20], char pArrayApellido[][20], int limite); //swapea dos matrices
int main(void) {

	int i;
	char arrayNombres[QTY_CLIENTES][20];
	char arrayApellidos[QTY_CLIENTES][20];
	char auxNombre[20];
	char auxApellido[20];

	//cargar nombre
	for(i=0; i<QTY_CLIENTES; i++)
	{
		getString(MSG_INGRESESUNOM, auxNombre);
		strcpy(arrayNombres[i], auxNombre); // aca paso el dato del aux al array
	}
	printArrayStr(arrayNombres, QTY_CLIENTES);

	for(i=0; i<QTY_CLIENTES; i++)
	{
		getString(MSG_INGRESESUAP, auxApellido);
		strcpy(arrayApellidos[i], auxApellido); // aca paso el dato del aux al array
	}
	printArrayStr(arrayApellidos, QTY_CLIENTES);

	return EXIT_SUCCESS;
}
void getString(char mensaje[], char imput[])
{
	printf("%s", mensaje);
	gets(imput);
}
int printArrayStr(char pArray[][20], int limite)// se aclara la cantidad de elementos de cada array, x ser matriz
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite>0)
	{
		for(i=0; i<limite; i++)
		{
			printf("%s", pArray[i]);
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}
int ordenar2ArrayStr(char pArrayNombre[][20], char pArrayApellido[][20], int limite)
{
	int flagDesordenado = -1;
	int i;
	char auxiliarNombreStr[20];
	char auxiliarApellidoStr[20];

	while(flagDesordenado==-1)
	{
		flagDesordenado=0;
		for(i=0; i<limite-1; i++)
		{
			if(strcmp(pArrayApellido[i],pArrayApellido[i+1])>0)// compara los array.
			{
				strcpy(auxiliarNombreStr,pArrayNombre[i]);
				strcpy(pArrayNombre[i],pArrayNombre[i+1]);
				strcpy(pArrayNombre[i+1],auxiliarNombreStr);

				strcpy(auxiliarApellidoStr,pArrayApellido[i]);
				strcpy(pArrayApellido[i],pArrayApellido[i+1]);
				strcpy(pArrayApellido[i+1],auxiliarApellidoStr);

				flagDesordenado = -1;
			}
		}
	}
	return 0;
}
