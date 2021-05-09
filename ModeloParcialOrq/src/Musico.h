/*
 * Entidades.h
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */

#ifndef MUSICO_H_
#define MUSICO_H_

typedef struct{
	int iDMusico; //autoincremental
	char apellido[20];
	char nombre[20];
	int edad;
	int idOrquesta; //1-2-3
	int idInstrumento;
	int isEmpty;
}eMusico;


#endif /* MUSICO_H_ */
