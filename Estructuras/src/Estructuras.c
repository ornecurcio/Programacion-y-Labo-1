/*
 ============================================================================
 Name        : Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 4-1 (Estructuras facil):
Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto (programador,
analista, tester).
Crear un menu con las siguientes opciones:
1. Cargar empleados. Carga secuencial.
2. Mostrar empleados. Ordenados por puesto. De a z
3. Mostrar solo los empleados analistas.
4. Mostrar cuantos empleados tester hay.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTY_EMPLEADOS 3

typedef struct{
	int idEmpleado;
	char nombre[20];
	int sueldo;
	char puesto[20];
}empleado;


int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int main(void) {
	setbuf(stdout, NULL);

	int opcionPrincipal;
	int respuestaMenu;
	empleado vecDatos[QTY_EMPLEADOS];
	int i;

	do{
		respuestaMenu = utn_getNumero(&opcionPrincipal, "1. Cargar Empleados, 2. Mostrar empleados. Ordenados por puesto, 3. Mostrar solo los empleados analistas, 4. Mostrar cuantos empleados tester hay. 5. Salir", "Error, Ingrese una opcion del 1 al 5: \n1. Cargar Empleados, 2. Mostrar empleados. Ordenados por puesto, 3. Mostrar solo los empleados analistas, 4. Mostrar cuantos empleados tester hay", 1, 5, 2);
		if(respuestaMenu==0)
		{
			switch(opcionPrincipal)
			{
			case 1:// funcion cargar empleados.
				for(i=0; i<QTY_EMPLEADOS; i++)
				{
					printf("Ingrese IdEmpleado");
					scanf("%d", &vecDatos[i].idEmpleado);
					printf("Ingrese Nombre");
					fflush(stdin);
					gets(vecDatos[i].nombre);
					printf("Ingrese Sueldo");
					scanf("%d", &vecDatos[i].sueldo);
					printf("Ingrese puesto: programador, analista, tester");
					fflush(stdin);
					gets(vecDatos[i].puesto);
				}
				break;
			case 2:
				break;
			case 3:
				// funcion
				//for--- if vecDato.puesto == 'p'--- mostrar

				break;
			case 4:
				break;
			}
		}
	}while(respuestaMenu!=5);

	return EXIT_SUCCESS;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInterno);
			if(bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int printDatos(char pArray[][20], int limite, char sex[], int leg[], int not1[], int not2[], float prom[])
{
	int retorno = -1;
	int i;

	if(pArray != NULL && sex != NULL && leg != NULL && not1 != NULL && not2 != NULL && prom != NULL  && limite>0)
	{
		for(i=0; i<limite; i++)
		{
			printf("%s %c %d %d %d %.2f ", pArray[i], sex[i], leg[i], not1[i], not2[i], prom[i]);
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}
