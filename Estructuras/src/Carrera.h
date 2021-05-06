/*
 * Carrera.h
 *
 *  Created on: 6 may. 2021
 *      Author: orne_
 */

#ifndef CARRERA_H_
#define CARRERA_H_

typedef struct
{
	int idCarrera;
	char descripCarrera[50];
	int isEmpty;
}eCarrera;

int mostrarCarrera(eCarrera aCarrera);
#endif /* CARRERA_H_ */
