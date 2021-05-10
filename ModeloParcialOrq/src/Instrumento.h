/*
 * Instrumento.h
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */

#ifndef INSTRUMENTO_H_
#define INSTRUMENTO_H_

typedef struct{
	int iDInstrumento; //autoincremental
	char nombre[20];
	int tipo; // 1.cuerdas, 2.viento-madera, 3. viento-metal, 4. percusion,
	int isEmpty;
}eInstrumento;

void eInstrumento_Inicializar(eInstrumento array[], int cantidadDeArray);
int eInstrumento_BuscaLibre(eInstrumento array[], int cantidadDeArray);
int eInstrumento_BuscarPorID(eInstrumento array[], int cantidadDeArray, int ID);
void eInstrumento_MostrarUno(eInstrumento aInstrumento);
int eInstrumento_MostrarTodos(eInstrumento array[], int cantidadDeArray);
int eInstrumento_MostrarDadosDeBaja(eInstrumento array[], int cantidadDeArray);
eInstrumento eInstrumento_CargarDatos(void);
eInstrumento eInstrumento_ModificarUno(eInstrumento Instrumento);
int eInstrumento_Alta(eInstrumento array[], int cantidadDeArray);
int eInstrumento_Baja(eInstrumento array[], int cantidadDeArray);
int eInstrumento_Modificacion(eInstrumento array[], int cantidadDeArray);
int eInstrumento_Sort(eInstrumento array[], int cantidadDeArray, int criterio);

#endif /* INSTRUMENTO_H_ */
