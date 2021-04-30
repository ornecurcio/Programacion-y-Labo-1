/*
 ============================================================================
 Name        : Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno:
 legajo, sexo, edad, nota1, nota2, promedio, apellido.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Alumno.h"


#define QTY_AUMNOS 3

int promediar2Notas(float* pPromedioResultado, int num1, int num2);
int cargar1Alumno(Alumno aAlumno[], int posicion);
void mostrarAlumno(Alumno unAlumno);
int mostrarAlumnos(Alumno aAuxiliar[], int catidadDeArray);
int buscaLegajo(Alumno aAuxiliar[], int cantidadDeArray);
int darBaja(Alumno aAuxiliar[], int cantidadDeArray, int posicion);
int main(void) {
	setbuf(stdout, NULL);

	Alumno vecDatos[QTY_AUMNOS];
	int opcionPrincipal;
	int respuestaMenu;
	int auxInt;
	int retornoCargaAlumno;

	inicializarIsEmpty(vecDatos, QTY_AUMNOS);
	printf("Los isEmpty estan en: %d, %d, %d", vecDatos[0].isEmpty,vecDatos[1].isEmpty,vecDatos[2].isEmpty);
	auxInt=buscarLibre(vecDatos, QTY_AUMNOS);
	printf("hay %d, arrays libres", auxInt);

	do{
		respuestaMenu = utn_getNumero(&opcionPrincipal, "\n1. Cargar Alumno, 2. Mostrar alumnos, 3. Alta, 4. Baja. 5. Salir", "Error, Ingrese una opcion del 1 al 5.", 1, 5, 2);
		if(respuestaMenu==0)
		{
			switch(opcionPrincipal)
			{
			case 1: // funcion cargar alumnos.
				auxInt=buscarLibre(vecDatos, QTY_AUMNOS);
				if(auxInt!=-1)
				{
					retornoCargaAlumno=cargar1Alumno(vecDatos, auxInt);

					if(retornoCargaAlumno!=0)
					{
						printf("Error al cargar Alumno");
						break;
					}
				}
				break;
			case 2: //mostrar-listar
				mostrarAlumnos(vecDatos, QTY_AUMNOS);
				break;
			case 3:
				buscaLegajo(vecDatos, QTY_AUMNOS, aLegajo)
				//buscar por legajo,
				// borra lo q esta ahi retorna algo

				break;
			case 4:
				break;
			}
		}
	}while(opcionPrincipal!=5);

	return EXIT_SUCCESS;
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
int cargar1Alumno(Alumno aAlumno[], int posicion)

{
	Alumno aAuxiliar;
	int retorno = -1;
	if(posicion>-1)
	{
		if((utn_getNumero(&aAuxiliar.legajo, "Ingrese legajo", "Error ingrese legajo entre 1000 y 9999", 1000, 9999, 2)==0) &&
		(utn_getCaracterSexo(&aAuxiliar.sexo, "Ingrese Sexo: f, m, o", "Error, ingrese f, m, o", 2)==0) &&
		(utn_getNumero(&aAuxiliar.edad, "Ingrese edad", "Ingrese edad", 18, 70, 2)==0)&&
		(utn_getNumero(&aAuxiliar.nota1, "Ingrese nota 1", "Error, ingrese nota entre 1 y 10", 1, 10, 2)==0)&&
		(utn_getNumero(&aAuxiliar.nota2, "Ingrese nota 2", "Error, ingrese nota entre 1 y 10", 1, 10, 2)==0)&&
		(promediar2Notas(&aAuxiliar.promedio,aAuxiliar.nota1 ,aAuxiliar.nota2)==0)&&
		(utn_getString(aAuxiliar.apellido, "Ingrese Apellido", "Error, ingrese Apellido", 2))==0)
		{
			aAuxiliar.isEmpty=0;
			aAlumno[posicion]=aAuxiliar;
			retorno=0;
		}
	}
	return retorno;
}
void mostrarAlumno(Alumno unAlumno)
{
	printf("\nLegajo: %d, Sexo: %c, Edad: %d,",unAlumno.legajo, unAlumno.sexo, unAlumno.edad);
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
			if(aAuxiliar[i].legajo==aLegajo && aAuxiliar[i].isEmpty==1)
			{
				retorno = i;
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
				printf("Desea borrar ese legajo, ingrese 's'");
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
