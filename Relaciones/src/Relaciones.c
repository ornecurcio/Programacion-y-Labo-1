/*
 ============================================================================
 Name        : Relaciones.c
 Author      : Ornela Curcio
 Version     :
 Copyright   : Your copyright notice
 Description : Crear las siguientes estructuras y definir la manera mas optima de relacionarlas.
// 1. Producto-Provedor (Donde el producto solo puede tener un unico proveedor)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int numero;
	char calle[20];
	int codigoPostal;
	char localidad[20];
	int isEmpty;
}eDireccion ;

typedef struct
{
	int idProveedor;
	char razonSocial[40];
	int isEmpty;
	eDireccion direccion;
}Proveedor;

typedef struct
{
	int idProducto;
	char descripcion[40];
	float precio;
	int isEmpty;
	int idProveedor;
}Producto;

typedef struct
{
	int idAmo;
	char nombre[40];
	int edad;
	char sexo;
	int isEmpty;
}Amo;

typedef struct
{
	int peso;
	char nombreRaza[20];
	char pelo;
	int isEmpty;
}Raza;

typedef struct
{
	int idMascota;
	char nombre[40];
	int edad;
	char sexo;
	Raza raza;
	int idAmo;
}Mascota;

typedef struct
{
	int idLocalidad;
	char descripcion[40];
	int codigoPostal;
}Localidad;

typedef struct
{
	int idAlumno;
	char nombre[30];
	int idLocalidad;
}Alumno;

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	/*void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam)
	{
	    int i;
	    int legajo[]= {1001,1002};
	    int nota1[] = {1,7};
	    int nota2[] = {7,8};
	    char sexo[] = {'m','f'};
	    int edad[] = {18,25};
	    char apellido[][25]= {"Pepito","Pepita"};
	    for(i=0; i<2; i++)
	    {
	        listadoDeAlumnos[i].legajo = legajo[i];
	        listadoDeAlumnos[i].nota1 = nota1[i];
	        listadoDeAlumnos[i].nota2 = nota2[i];
	        listadoDeAlumnos[i].promedio = (float)(nota1[i] + nota2[i]) / 2;
	        listadoDeAlumnos[i].sexo = sexo[i];
	        listadoDeAlumnos[i].edad = edad[i];
	        strcpy(listadoDeAlumnos[i].apellido, apellido[i]);
	        listadoDeAlumnos[i].isEmpty = 0;

	    }


	}*/
	return EXIT_SUCCESS;
}
