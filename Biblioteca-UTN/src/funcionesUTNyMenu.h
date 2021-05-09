/*
 * numeros.h
 *
 *  Created on: 1 abr. 2021
 *      Author: orne_
 */

#ifndef FUNCIONESUTNYMENU_H_
#define FUNCIONESUTNYMENU_H_
int subMenu(void);

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/*obtiene un numero entero, asigno el resultado a un espacio de memoria,
 * muestra un mensaje de ingreso de dato, un mensaje de error si la validacion esta mal,
 * valida contra minimo y maximo
 * estable cantidad de reintentos de error.
 * */
int utn_getNumeroConDecimales(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
#endif /* FUNCIONESUTNYMENU_H_ */
