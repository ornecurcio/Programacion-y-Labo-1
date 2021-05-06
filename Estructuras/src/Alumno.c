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
int cargar1Alumno(Alumno aAlumno[], int cantidadDeArray, int* contadorId)

{
	Alumno aAuxiliar;
	int retorno = -1;
	int posicion;
	if(aAlumno!=NULL && cantidadDeArray>0 && contadorId!=NULL)
	{
		posicion=buscarLibre(aAlumno, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if((utn_getString(aAuxiliar.apellido, "Ingrese Apellido", "Error, ingrese Apellido", 2)==0)&&
			(utn_getNumero(&aAuxiliar.idCarrera, "Ingrese Carrera: 1.TYO, 2.ENDO, 3.NEURO","Error, ingrese Carrera: 1.TYO, 2.ENDO, 3.NEURO", 1, 3, 2)==0)&&
			(utn_getCaracterSexo(&aAuxiliar.sexo, "Ingrese Sexo: f, m, o", "Error, ingrese f, m, o", 2)==0) &&
			(utn_getNumero(&aAuxiliar.edad, "Ingrese edad", "Error, ingrese edad entre 18 y 70", 18, 70, 2)==0)&&
			(utn_getNumero(&aAuxiliar.nota1, "Ingrese nota 1", "Error, ingrese nota entre 1 y 10", 1, 10, 2)==0)&&
			(utn_getNumero(&aAuxiliar.nota2, "Ingrese nota 2", "Error, ingrese nota entre 1 y 10", 1, 10, 2)==0)&&
			(promediar2Notas(&aAuxiliar.promedio,aAuxiliar.nota1 ,aAuxiliar.nota2)==0))
			{
				aAuxiliar.legajo=*contadorId;
				aAuxiliar.isEmpty=0;
				aAlumno[posicion]=aAuxiliar;
				(*contadorId)++;
				retorno=0;
			}
		}
	}
		return retorno;
}
dyvoid mostrarAlumno(Alumno unAlumno)
{
	printf("\nLegajo: %d, Carrera: %d, Sexo: %c, Edad: %d,",unAlumno.legajo, unAlumno.idCarrera, unAlumno.sexo, unAlumno.edad);
	printf("Nota 1: %d, Nota 2: %d, Promedio: %.2f, Apellido: %s",unAlumno.nota1, unAlumno.nota2, unAlumno.promedio, unAlumno.apellido);
}
int mostrarAlumnos(Alumno aAuxiliar[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].isEmpty!=1)
			{
				mostrarAlumno(aAuxiliar[i]);
				//printf("\nLegajo: %d, Sexo: %c, Edad: %d,",aAuxiliar[i].legajo, aAuxiliar[i].sexo, aAuxiliar[i].edad);
				//printf("Nota 1: %d, Nota 2: %d, Promedio: %.2f, Apellido: %s",aAuxiliar[i].nota1, aAuxiliar[i].nota2, aAuxiliar[i].promedio, aAuxiliar[i].apellido);
				retorno = 0;
			}
		}
	return retorno;
}
int buscaLegajo(Alumno aAuxiliar[], int cantidadDeArray)

{
	int retorno = -1;
	int i;
	int aLegajo;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese legajo");
		scanf("%d", &aLegajo);

		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].legajo==aLegajo && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El %d legajo no existe", aLegajo);
				break;
			}
		}
	}
	return retorno;
}
int darBaja(Alumno aAuxiliar[], int cantidadDeArray, int posicion)
{
	int retorno = -1;
	int i;
	char respuesta;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
		for(i=0; i<cantidadDeArray; i++)
		{
			if(i==posicion)
			{
				mostrarAlumno(aAuxiliar[i]);
				printf("\nDesea borrar ese legajo, ingrese 's'");
				fflush(stdin);
				scanf("%c", &respuesta);
				if(respuesta=='s')
				{
					aAuxiliar[i].isEmpty=1;
					retorno = 0;
				}
			}

		}
	return retorno;
}
int ordenarEstructurasLegajos(Alumno aAlumno[], int cantidadDeArray)
{
	Alumno aAuxiliar;
	int flagDesordenado = -1;
	int i;


	while(flagDesordenado==-1)
	{
		flagDesordenado=0;
		for(i=0; i<cantidadDeArray-1; i++)
		{
			if(aAlumno[i].legajo>aAlumno[i+1].legajo)
			{
				aAuxiliar.legajo=aAlumno[i].legajo;
				aAlumno[i].legajo=aAlumno[i+1].legajo;
				aAlumno[i+1].legajo=aAuxiliar.legajo;
			}

				flagDesordenado = -1;
		}
	}
	return 0;
}
int modificaAlumno(Alumno aAuxiliar[], int cantidadDeArray, int posicion)
{
	int retorno = -1;
	int i;
	char respuesta;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
		for(i=0; i<cantidadDeArray; i++)
		{
			if(i==posicion)
			{
				mostrarAlumno(aAuxiliar[i]);
				printf("\nDesea modificar este legajo, ingrese 's'");
				fflush(stdin);
				scanf("%c", &respuesta);
				if(respuesta=='s')
				{
					printf("\nDesea modificar sexo 's' o edad 'e'");
					fflush(stdin);
					scanf("%c", &respuesta);
					if(respuesta=='s')
					{
						utn_getCaracterSexo(&aAuxiliar[i].sexo, "Ingrese Sexo: f, m, o", "Error, le queda 1 intento", 1);
						printf("Exito, los nuevos datos son: ");
						mostrarAlumno(aAuxiliar[i]);
						break;
					}
					else
					{
						if(respuesta=='e')
						{
							utn_getNumero(&aAuxiliar[i].edad, "Ingrese edad", "Error, le queda 1 intento", 18, 70, 1);
							printf("Exito, los nuevos datos son: ");
							mostrarAlumno(aAuxiliar[i]);
							break;
						}
					}
					retorno = 0;
				}
			}
		}
	return retorno;
}
