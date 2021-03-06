/*
 ============================================================================
 Name        : Sabado.Clase 1, Ej 3
 Author      : Ornela Curcio
 Version     :
 Copyright   :
 Description : Ejercicio 3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una
divisi?n de la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L:libre - P:presencial ? R: remota ;)
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: ?femenino? ? M: ?masculino? , O: ?no binario?)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que
corresponda.
a) El Legajo del mejor promedio que femenino.
b) El legajo del m?s joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa m?s materias. (Sin importar su g?nero)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroLegajoIngresado;
	char tipoCursadaIngresada;
	int edadIngresada;
	char sexoIngresado;
	int cantidadMateriasIngresada;
	float notaPromedioIngresada;
	char respuesta;
	int legajoMejorPromedioFemenino;
	int notaMejorPromedioFemenino;
	int legajoMasculinoMasJovenYLibre;
	int edadMasculinoMasJovenYLibre;
	int banderaMasculinoMasJovenYLibre = 0;
	int contadorMasculinos = 0;
	int acumuladorNotaMasculinos = 0;
	float promedioNotaSexoMasculino;
	int contadorFemeninos = 0;
	int acumuladorNotaSexoFemenino = 0;
	float promedioNotaSexoFemenino;
	int contadorNoBinario = 0;
	int acumuladorNoBinario = 0;
	float promedioNotaNoBinario;
	int edadCursaMasMaterias;
	int legajoCursaMasMaterias;
	int cantidadCursaMasMaterias;
	int banderaCursaMasMaterias=0;


	respuesta = 's';


	while(respuesta=='s')
		{
			printf("Ingrese numero de legajo");
			fflush(stdin);
			scanf("%d", &numeroLegajoIngresado);

			printf("Ingrese tipo de cursada: presencial 'p', libre 'l', remota 'r'");
			fflush(stdin);
			scanf("%c", &tipoCursadaIngresada);
			while(tipoCursadaIngresada!='p' && tipoCursadaIngresada!='c' && tipoCursadaIngresada!='v')
			{
				printf(" Error ingrese tipo de cursada: presencial 'p', libre 'l', remota 'r'");
				fflush(stdin);
				scanf("%c", &tipoCursadaIngresada);
			}

			printf("Ingrese su edad, debe ser mayor a 18");
			fflush(stdin);
			scanf("%d", &edadIngresada);
			while(edadIngresada<17 || edadIngresada>90)
			{
				printf("Error, ingrese su edad, debe ser mayor a 18");
				fflush(stdin);
				scanf("%d", &edadIngresada);
			}
			printf("Ingrese sexo: femenino 'f', masculino 'm', no binario 'o'");
			fflush(stdin);
			scanf("%c", &sexoIngresado);
			while(sexoIngresado!='f' && sexoIngresado!='m' && sexoIngresado!='o')
			{
				printf(" Error ingrese sexo: femenino 'f', masculino 'm', no binario 'o'");
				fflush(stdin);
				scanf("%c", &sexoIngresado);
			}
			printf("Ingrese cantidad de materias, (1 a 8)");
			fflush(stdin);
			scanf("%d", &cantidadMateriasIngresada);
			while(cantidadMateriasIngresada<1 || cantidadMateriasIngresada>8)
			{
				printf("Error, ingrese cantidad de materias, (1 a 8)");
				fflush(stdin);
				scanf("%d", &cantidadMateriasIngresada);
			}

			printf("Ingrese su nota promedio (0 a 10)");
			fflush(stdin);
			scanf("%f", &notaPromedioIngresada);
			while(notaPromedioIngresada<0 || notaPromedioIngresada>10)
			{
				printf("Error, ingrese su nota promedio (0 a 10)");
				fflush(stdin);
				scanf("%f", &notaPromedioIngresada);
			}

			switch(sexoIngresado)
			{
			case'f':
				contadorFemeninos++;
				acumuladorNotaSexoFemenino+=notaPromedioIngresada;

				if(contadorFemeninos==1 || notaPromedioIngresada > notaMejorPromedioFemenino)
				{
					notaMejorPromedioFemenino = notaPromedioIngresada;
					legajoMejorPromedioFemenino = numeroLegajoIngresado;
				}
				break;
			case'm':
				contadorMasculinos++;
				acumuladorNotaMasculinos+=notaPromedioIngresada;
				if((tipoCursadaIngresada=='l' && banderaMasculinoMasJovenYLibre==0) || (tipoCursadaIngresada=='l' && edadMasculinoMasJovenYLibre>edadIngresada))
				{
					edadMasculinoMasJovenYLibre = edadIngresada;
					legajoMasculinoMasJovenYLibre = numeroLegajoIngresado;
					banderaMasculinoMasJovenYLibre = 1;
				}
				break;
			case'o':
				contadorNoBinario++;
				acumuladorNoBinario+=notaPromedioIngresada;
				break;
			}

			if(banderaCursaMasMaterias==0 ||cantidadCursaMasMaterias<cantidadMateriasIngresada)
			{
				cantidadCursaMasMaterias=cantidadMateriasIngresada;
				edadCursaMasMaterias=edadIngresada;
				legajoCursaMasMaterias=numeroLegajoIngresado;
				banderaCursaMasMaterias = 1;
			}

			printf("Desea continuar? coloque 's'");
			fflush(stdin);
			scanf("%c", &respuesta);
		}//fin while

			promedioNotaNoBinario=(float)acumuladorNoBinario/contadorNoBinario;
			promedioNotaSexoFemenino=(float)acumuladorNotaSexoFemenino/contadorFemeninos;
			promedioNotaSexoMasculino=(float)acumuladorNotaMasculinos/contadorMasculinos;

			if(contadorFemeninos!=0)
			{
				printf("El legajo del mejor promedio femenino es %d", legajoMejorPromedioFemenino);
			}
			else
			{
				printf("No ingresaron alumnos femeninos");
			}
			if(contadorMasculinos!=0)
			{
				printf("\nEl legajo de mas joven de los alumnos masculinos que da libre es %d que tiene %d a?os", legajoMasculinoMasJovenYLibre, edadMasculinoMasJovenYLibre);
			}
			else
			{
				printf("\nNo ingresaron alumnos masculinos");
			}
			printf("\nEl promedio de nota: sexo masculino es %.2f, sexo femenino %.2f, sexo No Binario %.2f", promedioNotaSexoMasculino, promedioNotaSexoFemenino, promedioNotaNoBinario);
			printf("\nLa edad del que cursa mas masterias es %d y tiene el numero de legajo %d", edadCursaMasMaterias, legajoCursaMasMaterias);
			return EXIT_SUCCESS;
 }

