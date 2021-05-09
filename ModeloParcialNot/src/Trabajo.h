/*
 * Fecha.h
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{
	int dia;
	int mes;
	int año;
}eFecha;
typedef struct{
	int idMarca;
	char descMarca[20]; // COMPAQ, ASUS, ACER, HP
}eMarca;
typedef struct{
	int idTipo;
	char descMarca[20]; //GAMER, DISENIO, ULTRABOOK, NORMALITA
}eTipo;
typedef struct{
	int idNotebook;
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
}eNotebook;
typedef struct{
	int idServicio;
	char descServicio[25]; //Bateria 250, Antivirus 300, actualizacion 400, fuente 600
	int precio;
}eServicio;
typedef struct{
	int idTrabajo; //autoincremental
	int idNotebook;
	int idServicio;
	eFecha fecha;
}eTrabajo;


#endif /* TRABAJO_H_ */
