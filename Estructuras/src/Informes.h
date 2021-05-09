/*
 * Informes.h
 *
 *  Created on: 7 may. 2021
 *      Author: orne_
 */

#ifndef INFORMES_H_
#define INFORMES_H_


int Informes_listarAlumnosMasGrandes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras, int edad);
int Informes_listarAlumnos1Carrera(Alumno aAlumnos[],int cantidadDeArray, int idCarrera, eCarrera aCarrera[], int cantidadCarrera);
int Informes_listarAlumnosMasJovenes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras, int edad);


#endif /* INFORMES_H_ */
