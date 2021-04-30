/*
 * Datos.c
 *
 *  Created on: 28 abr. 2021
 *      Author: orne_
 */

#include "Alumno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarArrayChar(char pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=' ';
	}
}
void inicializarArrayNumFlo(float pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=0;
	}
}
void getString(char mensaje[], char imput[])
{
	printf("%s", mensaje);
	gets(imput);
}
void inicializarArrayCadena(char pArray[][20], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		strcpy(pArray[i],"");
	}
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
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar=='f'|| bufferChar=='m' || bufferChar=='o')
			{
				*pResultado=bufferChar;
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
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[40];


	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferString);

			if(strlen(bufferString)<20)
			{
				strcpy(aux, bufferString);
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
int printDatos(char pArray[][20], int limite, char sex[], int leg[], int not1[], int not2[], float prom[])
{
	int retorno = -1;
	int i;

	if(pArray != NULL && sex != NULL && leg != NULL && not1 != NULL && not2 != NULL && prom != NULL  && limite>0)
	{
		for(i=0; i<limite; i++)
		{
			printf("%s %c %d %d %d %.2f ", pArray[i], sex[i], leg[i], not1[i], not2[i], prom[i]);
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray)
{
	int i;
	int j;
	int aux;
	int retorno = -1;
	for(i=0; i<cantidadDeArray-1; i++)
	{
		for(j=i+1; j<cantidadDeArray; j++)
		{
			if(listaDeArray[i]>listaDeArray[j])
			{
				aux=listaDeArray[i];
				listaDeArray[i]=listaDeArray[j];
				listaDeArray[j]=aux;
			}

		}
		retorno=0;
	}
	return retorno;
}
int ordenar1ArrayStr(char pArrayApellido[][20], int limite, int nota1[], int nota2[], int legajo[], float promedio[], char sexo[])
{
	int flagDesordenado = -1;
	int i;
	char auxiliarApellidoStr[20];
	char auxChar;
	int auxInt;
	float auxFloat;



	while(flagDesordenado==-1)
	{
		flagDesordenado=0;
		for(i=0; i<limite-1; i++)
		{
			if(strcmp(pArrayApellido[i],pArrayApellido[i+1])>0)// compara los array.
			{
				strcpy(auxiliarApellidoStr,pArrayApellido[i]);
				strcpy(pArrayApellido[i],pArrayApellido[i+1]);
				strcpy(pArrayApellido[i+1],auxiliarApellidoStr);

				auxInt=nota1[i];
				nota1[i]=nota1[i+1];
				nota1[i+1]=auxInt;

				auxInt=nota2[i];
				nota2[i]=nota2[i+1];
				nota2[i+1]=auxInt;

				auxInt=legajo[i];
				legajo[i]=legajo[i+1];
				legajo[i+1]=auxInt;

				auxFloat=promedio[i];
				promedio[i]=promedio[i+1];
				promedio[i+1]=auxFloat;

				auxChar=sexo[i];
				sexo[i]=sexo[i+1];
				sexo[i+1]=auxChar;

				flagDesordenado = -1;
			}
		}
	}
	return 0;
}
int inicializarIsEmpty(Alumno pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int buscarLibre(Alumno pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(pArray[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}
