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
Informar Estudiantes de una Carrera (Pedir la descripción de la Carrera y Listar los Estudiantes))
8.1. Informar estudiantes de una carrera, 2. Informar Estudiante mas joven, 3.Informar estudiante mas grande 4.Informar estudiantes de cada carrera"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "Informes.h"


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
	int subMenu;
	int auxId;
	char auxChar[20];

	inicializarIsEmpty(vecDatos, QTY_AUMNOS);
	//printf("Los isEmpty estan en: %d, %d, %d", vecDatos[0].isEmpty,vecDatos[1].isEmpty,vecDatos[2].isEmpty);
	//auxInt=buscarLibre(vecDatos, QTY_AUMNOS);
	//printf("hay %d, arrays libres", auxInt);

	do{
		respuestaMenu = utn_getNumero(&opcionPrincipal, "\n1. Cargar Alumno, 2. Mostrar alumnos, 3. Baja, 4.Ordena. 5.Modifica 6.Informes 7.Salir", "Error, Ingrese una opcion del 1 al 5.", 1, 7, 2);
		if(respuestaMenu==0)
		{
			switch(opcionPrincipal)
			{
			case 1:
					if(cargar1Alumno(vecDatos, QTY_AUMNOS, &contadorLegajo)!=0)
					{
						printf("Error al cargar Alumno");
					}
				break;
			case 2: //mostrar-listar
				mostrarAlumnos(vecDatos, QTY_AUMNOS, vecCarreras, QTY_CARRERA);
				break;
			case 3:
				posLegajo=buscaLegajo(vecDatos, QTY_AUMNOS);
				darBaja(vecDatos, posLegajo, vecCarreras, QTY_CARRERA);
				break;
			case 4:
				ordenarEstructurasLegajos(vecDatos, QTY_AUMNOS);
				break;
			case 5:
				posLegajo=buscaLegajo(vecDatos, QTY_AUMNOS);
				modificaAlumno(vecDatos, posLegajo, vecCarreras, QTY_CARRERA);
				break;
			case 6:
				utn_getNumero(&subMenu, "1. Informar estudiantes de una carrera, 2. Informar Estudiante mas joven, 3.Informar estudiante mas grande 4.Informar estudiantes de cada carrera", "Error, entre 1 y 4", 1, 4, 2);
				switch(subMenu)
				{
				case 1://Informar estudiantes de una carrera
					printf("Ingrese carrera a listar: TYO, ENDO, NEURO");
					fflush(stdin);
					gets(auxChar);
					buscaIdCarreraXdescripcion(vecCarreras, auxChar, &auxId, QTY_CARRERA);
					Informes_listarAlumnos1Carrera(vecDatos, QTY_AUMNOS, auxId, vecCarreras, QTY_CARRERA);
					break;
				case 2: //Informar Estudiante mas joven
					alumnosMasJovenes(vecDatos, QTY_AUMNOS, vecCarreras, QTY_CARRERA);
					break;
				case 3: //Informar estudiante mas grande
					alumnosMasGrandes(vecDatos, QTY_AUMNOS, vecCarreras, QTY_CARRERA);
					break;
				case 4: //Informar estudiantes de cada carrera
					ordenarAlumnosXCarrera(vecDatos, QTY_AUMNOS, vecCarreras, QTY_CARRERA);
					break;
				}
				break;
			}
		}
	}while(opcionPrincipal!=7);

	return EXIT_SUCCESS;
}
