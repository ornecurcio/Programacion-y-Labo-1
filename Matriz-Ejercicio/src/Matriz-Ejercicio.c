/*
 ============================================================================
 Name        : Matriz-Ejercicio.c
 Author      : Ornela Curcio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QTY_ALUMNOS 3

void inicializarArrayNumEnt(int pArray[], int cantidadArray);
void inicializarArrayChar(char pArray[], int cantidadArray);
void inicializarArrayNumFlo(float pArray[], int cantidadArray);
void getString(char mensaje[], char imput[]);
void inicializarArrayCadena(char pArray[][20], int cantidadDeArray);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int utn_getString(char string[][20],char* mensaje,char* mensajeError, int reintentos);
int main(void) {
	setbuf(stdout, NULL);

	int legajo[QTY_ALUMNOS];
	char sexoAlumno[QTY_ALUMNOS];
	int nota1[QTY_ALUMNOS];
	int nota2[QTY_ALUMNOS];
	float promedio[QTY_ALUMNOS];
	char arrayApellido[QTY_ALUMNOS][20];
	//char auxApellido[20];
	int i;

	inicializarArrayNumEnt(legajo, QTY_ALUMNOS);
	inicializarArrayNumEnt(nota1, QTY_ALUMNOS);
	inicializarArrayNumEnt(nota2, QTY_ALUMNOS);
	inicializarArrayNumFlo(promedio, QTY_ALUMNOS);
	inicializarArrayChar(sexoAlumno, QTY_ALUMNOS);
	inicializarArrayCadena(arrayApellido, QTY_ALUMNOS);

	for(i=0; i<QTY_ALUMNOS; i++)
	{
	utn_getNumero(legajo, "Ingrese su numero de legajo", "Erro, ingrese entre 1000 y 9999", 1000, 9999, 3);
	utn_getNumero(nota1, "Ingrese una Nota","Error, ingrese una Nota entre 1 y 10" ,1, 10, 3);
	utn_getNumero(nota2, "Ingrese una Nota","Error, ingrese una Nota entre 1 y 10" ,1, 10, 3);
	utn_getCaracterSexo(sexoAlumno, "Ingrese sexo: f o m u o", "Error, ingrese f o m u o", 3);
	utn_getString(arrayApellido, "Ingrese Apellido: ", "Error, ingrese apellido ", 3);
	}

	return EXIT_SUCCESS;
}
void inicializarArrayNumEnt(int pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=0;
	}
}
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
int utn_getString(char string[][20],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[40];
	int i;

	if(string != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", &bufferString);

			if(strlen(bufferString)<20)
			{
				strcpy(string, bufferString);
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
