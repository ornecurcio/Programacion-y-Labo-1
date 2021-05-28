/*
 ============================================================================
 Name        : Puntero-Flecha.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Utilizar aritmética de punteros.
 Dada la siguiente estructura: int legajo; char nombre[20]; int edad; Realizar una función que cargue un array de 3 estudiantes.
 Recibe un entero. Retorna el estudiante dado de alta y por parámetro 0 si funcionó correctamente -1 mal.
 Una vez devuelto el estudiante cargarlo en una posición del array. Al final mostrar el array cargado

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

typedef struct{
	int legajo;
	char nombre[20];
	int edad;
}eDatos;

int cargarEstudiantes(eDatos* pEstudiante, int cantidadDeArray);
int main(void) {
	setbuf(stdout, NULL);

	eDatos personas[3];
	int resultado;

	resultado=cargarEstudiantes(personas, 3);
		if(resultado==0)
		{
			for(int i=0; i<3; i++)
			{
				printf("\nel nombre es: %s, la edad es: %d, el legajo es: %d", (*(personas+i)).nombre, (*(personas+i)).edad, (*(personas+i)).legajo);
			}

		}
		else
		{
			printf("error en carga");
		}

	return EXIT_SUCCESS;
}
int cargarEstudiantes(eDatos* pEstudiante, int cantidadDeArray)
{
	int retorno=-1;

	if(pEstudiante!=NULL)
	{
		for(int i=0; i<cantidadDeArray; i++)
		{
			printf("\nIngrese nombre");
			fflush(stdin);
			gets((*(pEstudiante+i)).nombre);

			printf("\nIngrese edad");
			scanf("%d", &(*(pEstudiante+i)).edad);

			printf("\nIngrese legajo");
			scanf("%d", &(*(pEstudiante+i)).legajo);

			retorno=0;
		}

	}
	return retorno;
}
/*
 ============================================================================
 Name        : Puntero-Flecha.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Utilizar aritmética de punteros.
 Dada la siguiente estructura: int legajo; char nombre[20]; int edad; Realizar una función que cargue un array de 3 estudiantes.
 Recibe un entero. Retorna el estudiante dado de alta y por parámetro 0 si funcionó correctamente -1 mal.
 Una vez devuelto el estudiante cargarlo en una posición del array. Al final mostrar el array cargado

 ============================================================================
 */
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int legajo;
	char nombre[20];
	int edad;
}eDatos;

eDatos cargarEstudiante(int* pResultado);
int main(void) {
	setbuf(stdout, NULL);

	eDatos personas[3];
	int resultado;

	for(int i=0; i<3; i++)
	{
		(personas+i)=cargarEstudiante(&resultado);

		if(resultado==0)
		{
			continue;
		}
		else
		{
			printf("error en carga");
			break;
		}
	}

	for(int i=0; i<3; i++)
	{
		printf("\nel nombre es: %s, la edad es: %d, el legajo es: %d", (*(personas+i)).nombre, (*(personas+i)).edad, (*(personas+i)).legajo);
	}

	return EXIT_SUCCESS;
}
eDatos cargarEstudiante(int* pResultado)
{
    eDatos estudiante;
	*pResultado=-1;
	if(pResultado!=NULL)
	{
		printf("\nIngrese nombre");
		fflush(stdin);
		gets(estudiante.nombre);

		printf("\nIngrese edad");
		scanf("%d", &estudiante.edad);

		printf("\nIngrese legajo");
		scanf("%d", &estudiante.legajo);

		*pResultado=0;
	}
	return estudiante;
}
*/
