/*
 ============================================================================
 Name        : Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno:
 legajo, sexo, edad, nota1, nota2, promedio, apellido.
 1-Menú e Inicialización
2-Alta
3-Listar
4-Baja
5-Modificar edad y sexo. x legajo. con sub menu.
6-Ordenar
7-Agregar autoincremental para el número de legajo: el legajo comienza en 1000, se incrementa solo
(NO lo ingresa el usuario),
si doy de baja no altera la numeración, el siguiente alta deberá respetar la numeración correlativa del autoincremental.
(Ej alta leg 1000, alta leg 1001, alta legajo 1002, baja leg 1002, alta leg 1003)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "Carrera.h"

#define QTY_AUMNOS 5
#define QTY_CARRERA 3


int main(void) {
	setbuf(stdout, NULL);

	Alumno vecDatos[QTY_AUMNOS];
	eCarrera vecCarreras[QTY_CARRERA]={
			{1, "TYO", 0},
			{2, "ENDO", 0},
			{3, "NEURO", 0}
	};
	int opcionPrincipal;
	int respuestaMenu;
	int posLegajo;
	int contadorLegajo=1000;

	inicializarIsEmpty(vecDatos, QTY_AUMNOS);
	//printf("Los isEmpty estan en: %d, %d, %d", vecDatos[0].isEmpty,vecDatos[1].isEmpty,vecDatos[2].isEmpty);
	//auxInt=buscarLibre(vecDatos, QTY_AUMNOS);
	//printf("hay %d, arrays libres", auxInt);

	do{
		respuestaMenu = utn_getNumero(&opcionPrincipal, "\n1. Cargar Alumno, 2. Mostrar alumnos, 3. Baja, 4. Ordena. 5. Modifica 6. Salir", "Error, Ingrese una opcion del 1 al 5.", 1, 6, 2);
		if(respuestaMenu==0)
		{
			switch(opcionPrincipal)
			{
			case 1: // funcion cargar alumnos.
				//auxInt=buscarLibre(vecDatos, QTY_AUMNOS);
				//if(auxInt!=-1)
				//{
					//retornoCargaAlumno=;
					//vecDatos[auxInt].legajo=contadorLegajo;
					//contadorLegajo++;
					if(cargar1Alumno(vecDatos, QTY_AUMNOS, &contadorLegajo)!=0)
					{
						printf("Error al cargar Alumno");
						break;
					}
				//}
				break;
			case 2: //mostrar-listar
				mostrarAlumnos(vecDatos, QTY_AUMNOS);
				break;
			case 3:
				buscaLegajo(vecDatos, QTY_AUMNOS);
				darBaja(vecDatos, QTY_AUMNOS, posLegajo);
				//buscar por legajo,
				// borra lo q esta ahi retorna algo
				break;
			case 4:
				ordenarEstructurasLegajos(vecDatos, QTY_AUMNOS);
				break;
			case 5:
				posLegajo=buscaLegajo(vecDatos, QTY_AUMNOS);
				modificaAlumno(vecDatos, QTY_AUMNOS, posLegajo);
				break;
			}
		}
	}while(opcionPrincipal!=6);

	return EXIT_SUCCESS;
}
