/*
 * Datos.h
 *
 *  Created on: 28 abr. 2021
 *      Author: orne_
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int legajo;
	char sexo;
	int edad;
	int nota1;
	int nota2;
	float promedio;
	char apellido[20];
	int idCarrera;
	int isEmpty;
}Alumno;
typedef struct
{
	int idCarrera;
	char descripCarrera[50];
	int isEmpty;
}eCarrera;
void inicializarArrayNumEnt(int pArray[], int cantidadArray);
void inicializarArrayChar(char pArray[], int cantidadArray);
void inicializarArrayNumFlo(float pArray[], int cantidadArray);
void getString(char mensaje[], char imput[]);
void inicializarArrayCadena(char pArray[][20], int cantidadDeArray);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
int printDatos(char pArray[][20], int limite, char sex[], int leg[], int not1[], int not2[], float prom[]);
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray);
int ordenar1ArrayStr(char pArrayApellido[][20], int limite, int nota1[], int nota2[], int legajo[], float promedio[], char sexo[]);
int inicializarIsEmpty(Alumno pArray[] , int cantidadDeArray);
int buscarLibre(Alumno pArray[], int cantidadDeArray);
int promediar2Notas(float* pPromedioResultado, int num1, int num2);
int cargar1Alumno(Alumno aAlumno[], int cantidadDeArray, int* contadorId);
void mostrarAlumno(Alumno unAlumno, char* desCarrera);
int mostrarAlumnos(Alumno aAuxiliar[], int cantidadDeArray, eCarrera aCarrera[], int cantidadCarrera);
int buscaLegajo(Alumno aAuxiliar[], int cantidadDeArray);
int darBaja(Alumno aAuxiliar[], int posicion, eCarrera aCarreras[], int cantidadCarreras);
int ordenarEstructurasLegajos(Alumno aAlumno[], int cantidadDeArray);
int modificaAlumno(Alumno aAuxiliar[], int posicion, eCarrera aCarrera[], int cantidadCarrera);
int getDescripcionCarrera(eCarrera aCarrera[], int cantidadDeArray, int buscar, char* descripcion);
int buscaIdCarreraXdescripcion(eCarrera aCarrera[], char* descripcion, int* buscar, int cantidadDeArray);
int lista1Carrera(Alumno aAlumnos[],int cantidadDeArray, int idCarrera, eCarrera aCarrera[], int cantidadCarrera);
int alumnosMasGrandes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras);
int alumnosMasJovenes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras);
int mostrarAlumnosXCarrera(Alumno aAlumno[], int cantidadDeArray,eCarrera aCarreras[], int cantidadCarreras);
#endif /* ALUMNO_H_ */
