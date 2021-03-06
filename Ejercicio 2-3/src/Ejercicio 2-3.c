/*
 ============================================================================
 Name        : Ejercicio 2-3.c
 Author      : Ornela Curcio
 Version     :
 Copyright   :
 Description :Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona
debemos obtener los siguientes datos:
n?mero de cliente,
estado civil (s para soltero; c para casado o v para viudo),
edad( solo mayores de edad, m?s de 17),
temperatura corporal (validar por favor)
y sexo (f para femenino, m para masculino, o para no binario).
NOTA: el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado viudo de m?s de 60 a?os.
b) el n?mero de cliente y edad de la mujer soltera m?s joven.
c) cu?nto sale el viaje total sin descuento.
d) si hay m?s del 50% de los pasajeros que tiene m?s de 60 a?os , el precio final tiene un descuento del 25%, que
solo mostramos si corresponde.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroClienteIngresado;
	char estadoCivilIngresado;
	int edadIngresada;
	float temperaturaIngresada;
	char sexoIngresado;
	char respuesta;
	int contadorPasajeros = 0;
	int contadorViudosMasSesenta = 0;
	int numeroClienteMujerMasJoven;
	int edadMujerMasJoven;
	int contadorMujerJoven = 0;
	int contadorPersonasMasSesenta = 0;
	int precioTotal;
	int precioPasajero;
	int descuento;
	float pasajerosDescuento;

	precioPasajero = 600;
	descuento = 0;
	respuesta = 's';

	while(respuesta=='s')
	{
		contadorPasajeros = contadorPasajeros + 1;
		printf("Ingrese numero de cliente");
		fflush(stdin);
		scanf("%d", &numeroClienteIngresado);

		printf("Ingrese Estado Civil: soltero 's', casado 'c', viudo 'v'");
		fflush(stdin);
		scanf("%c", &estadoCivilIngresado);
		while(estadoCivilIngresado!='s' && estadoCivilIngresado!='c' && estadoCivilIngresado!='v')
		{
			printf(" Error ingrese Estado Civil: soltero 's', casado 'c', viudo 'v'");
			fflush(stdin);
			scanf("%c", &estadoCivilIngresado);
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

		printf("Ingrese su temperatura corporal");
		fflush(stdin);
		scanf("%f", &temperaturaIngresada);
		while(temperaturaIngresada<28 || temperaturaIngresada>42)
		{
			printf("Error, ingrese su temperatura corporal entre 28 y 42");
			fflush(stdin);
			scanf("%f", &temperaturaIngresada);
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

		if(edadIngresada>60)
		{
			contadorPersonasMasSesenta = contadorPersonasMasSesenta + 1;
			if(estadoCivilIngresado=='v')
			{
				contadorViudosMasSesenta = contadorViudosMasSesenta + 1;
			}
		}
		switch(sexoIngresado)
		{
			case'f':
				if(estadoCivilIngresado=='s')
				{
					if(contadorPasajeros==1)
					{
						edadMujerMasJoven = edadIngresada;
						numeroClienteMujerMasJoven = numeroClienteIngresado;
						contadorMujerJoven = 1;
					}
					else
					{
						if(edadMujerMasJoven>edadIngresada)
						{
							edadMujerMasJoven = edadIngresada;
							numeroClienteMujerMasJoven = numeroClienteIngresado;
						}
					}
				}
				break;
			case'm':
				break;
			case'o':
				break;
		}
		if(sexoIngresado=='f')
		{
			if(contadorPasajeros==1)
			{
				edadMujerMasJoven = edadIngresada;
				numeroClienteMujerMasJoven = numeroClienteIngresado;
				contadorMujerJoven = 1;
			}
			else
			{

			}
		}
		printf("Desea continuar? coloque 's'");
		fflush(stdin);
		scanf("%c", &respuesta);
	}//fin de while

	precioTotal = precioPasajero*contadorPasajeros;
	pasajerosDescuento = (float)contadorPersonasMasSesenta*100/contadorPasajeros;

	if(contadorViudosMasSesenta!=0)
	{
		printf("\nLa cantidad de personas con estado viudo de m?s de 60 a?os es %d", contadorViudosMasSesenta);
	}
	else
	{
		printf("\nNo hay personas mayores de 60 a?os que sean viudas");
	}
	if(contadorMujerJoven==1)
	{
		printf("\nEl n?mero de cliente de la mujer soltera m?s joven es %d y tiene %d a?os", numeroClienteMujerMasJoven, edadMujerMasJoven);
	}
	else
	{
		printf("\nNo hay mujeres solteras");
	}

	printf("\nEl precio del viaje sin descuentos es %d", precioTotal);

	if(pasajerosDescuento>50)
	{
		descuento = 25;
		precioTotal = precioTotal- (precioTotal*descuento/100);
		printf("\nEl precio del viaje con descuento es %d", precioTotal);
	}
	else
	{
		printf("\nNo corresponde descuento en los pasajes");
	}

	return EXIT_SUCCESS;
}
