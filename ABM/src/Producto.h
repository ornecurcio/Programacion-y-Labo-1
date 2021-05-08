/*
 * Producto.h
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct{
	int idProducto;
	char descripcion[20];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
}eProducto;

int subMenu(void);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroConDecimales(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
int inicializarIsEmpty(eProducto pArray[], int cantidadDeArray);
int buscarLibre(eProducto pArray[], int cantidadDeArray);
int cargar1Producto(eProducto pArray[], int cantidadDeArray, int* contadorId);

#endif /* PRODUCTO_H_ */
