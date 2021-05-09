/*
 * Orquesta.h
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */

#ifndef ORQUESTA_H_
#define ORQUESTA_H_

typedef struct{
	int idOrquesta; //autoincremental
	char nombre[20];
	char lugar[20];
	int idTipo; // 1. sinfonica, 2. Filarmonica, 3. Camara
	int isEmpty;
}eOrquesta;


#endif /* ORQUESTA_H_ */
