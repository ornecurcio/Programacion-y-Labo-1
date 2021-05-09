/*
 * Informes.c
 *
 *  Created on: 7 may. 2021
 *      Author: orne_
 */
#include "Alumno.h"
#include <stdio.h>
#include <stdlib.h>

int Informes_listarAlumnosMasGrandes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras, int edad)
{
	int retorno=-1;
	int i;
	char descCarrera[20];

	if(aAlumnos!=NULL && aCarreras!=NULL && cantidadDeArray>0 && cantidadCarreras>0)
	{
		printf("\nId    edad    nombre    CodigoCarrera    Carrera");
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAlumnos[i].isEmpty==1)
				continue;
			else
			{
				if(aAlumnos[i].edad==edad)
				{
					getDescripcionCarrera(aCarreras, cantidadCarreras, aAlumnos[i].idCarrera, descCarrera);
					mostrarAlumno(aAlumnos[i], descCarrera);
				}
			}
		}

	}
	return retorno;
}
int Informes_listarAlumnos1Carrera(Alumno aAlumnos[],int cantidadDeArray, int idCarrera, eCarrera aCarrera[], int cantidadCarrera)
{
	int retorno=-1;
	int i;
	char desCarrera[20];
	if(aAlumnos!=NULL && aCarrera!=NULL && cantidadDeArray>0 && cantidadCarrera>0)
	{
		printf("\nId    edad    nombre    CodigoCarrera    Carrera");

		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAlumnos[i].idCarrera==idCarrera && aAlumnos[i].isEmpty==0)
			{
				getDescripcionCarrera(aCarrera, cantidadCarrera, idCarrera, desCarrera);
				mostrarAlumno(aAlumnos[i],desCarrera);
				retorno=0;
			}
		}
	}
	return retorno;
}
int Informes_listarAlumnosMasJovenes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras, int edad)
{
	int retorno=-1;
	int i;
	char descCarrera[20];

	if(aAlumnos!=NULL && aCarreras!=NULL && cantidadDeArray>0 && cantidadCarreras>0)
	{
		printf("\nId    edad    nombre    CodigoCarrera    Carrera");
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAlumnos[i].isEmpty==1)
				continue;
			else
			{
				if(aAlumnos[i].edad==edad)
				{
					getDescripcionCarrera(aCarreras, cantidadCarreras, aAlumnos[i].idCarrera, descCarrera);
					mostrarAlumno(aAlumnos[i], descCarrera);
				}
			}
		}

	}
	return retorno;
}
