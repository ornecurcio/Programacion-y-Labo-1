/*
 * Datos.h
 *
 *  Created on: 28 abr. 2021
 *      Author: orne_
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct{
	int legajo;
	char sexo;
	int edad;
	int nota1;
	int nota2;
	float promedio;
	char apellido[20];
	int isEmpty;
}Alumno;

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

#endif /* ALUMNO_H_ */
