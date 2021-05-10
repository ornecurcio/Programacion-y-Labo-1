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
	int tipo; // 1. sinfonica, 2. Filarmonica, 3. Camara
	int isEmpty;

}eOrquesta;

void eOrquesta_Inicializar(eOrquesta array[], int cantidadDeArray);
int eOrquesta_BuscaLibre(eOrquesta array[], int cantidadDeArray);
int eOrquesta_BuscarPorID(eOrquesta array[], int cantidadDeArray, int ID);
void eOrquesta_MostrarUno(eOrquesta Orquesta);
int eOrquesta_MostrarTodos(eOrquesta array[], int cantidadDeArray);
int eOrquesta_MostrarDadosDeBaja(eOrquesta array[], int cantidadDeArray);
eOrquesta eOrquesta_CargarDatos(void);
eOrquesta eOrquesta_ModificarUno(eOrquesta Orquesta);
int eOrquesta_Alta(eOrquesta array[], int cantidadDeArray);
int eOrquesta_Baja(eOrquesta array[], int cantidadDeArray);
int eOrquesta_Modificacion(eOrquesta array[], int cantidadDeArray);
int eOrquesta_Sort(eOrquesta array[], int cantidadDeArray, int criterio);


#endif /* ORQUESTA_H_ */
