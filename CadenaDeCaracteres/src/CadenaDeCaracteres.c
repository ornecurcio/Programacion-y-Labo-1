/*
 ============================================================================
 Name        : CadenaDeCaracteres.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	/*
	char texto[]="Amar sin limites"; //[20]--> se pueden escribir 19 caracteres xq 1 es /0
	 //char conjuntoCaracteres[]={'A', 'm', 'o', 'r'} SI YO NO PONGO EL /0 NO SABE HASTA DONDE LEER
	printf("\nEl texto es %s", texto);
	//texto="Ornela" // NO SE PUEDE ASIGNAR UN TEXTO COMO VALOR, XQ NO SABE DESDE DONDE TOMAR EL ARRAY
	//strcpy(texto, "Ornela"); //copia el texto"" y lo asigna a la variable que puse a la izq

	printf("Texto:%s Tamaño: %d \n", texto, sizeof(texto));// el tamaño del array de caracteres total.
	printf("Longitud de la cadena= %d\n", strlen(texto));// la cantidad de array ocupado
	*/

	/*char texto1[20], texto2[20], texto3[30];
	printf("ingrese texto 1: \n"); //Ingresar Amar sin limites
	fflush(stdin);
	scanf("%s", texto1); //NO VA A LEERLO ENTERO, xq si lee un espacio ya corta.
	printf("ingresaste: %s \n", texto1);

	printf("ingrese texto 2: \n");
	//fflush(stdin); NO HACE FALTA PARA EL GET
	gets(texto2);//hace lo mismo que el scanf,va sin modificador de formato xq ya sabe que recibe char
	printf("ingresaste: %s \n", texto2);

	printf("ingrese texto 3: \n");
	//fflush(stdin); NO HACE FALTA
	fgets(texto3, 30, stdin); // a yani no le gusta la funcion. Se usa para levantar archivos
	printf("ingresaste: %s \n", texto3);
	*/

	          //VALIDACION DE CANT DE CARACT PARA GETS
	/*
	char nombre[6];
	char auxNom[10];//usa la variable aux para validar, con un margen mayor de caracter para no pisar nada

	printf("Ingrese un nombre: ");
	fflush(stdin);
	gets(auxNom);
	while(strlen(auxNom)>6)
	{
		printf("El nombre es demasiado largo. Reingrese un nombre: ");
		fflush(stdin);
		gets(auxNom);
	}
	strcpy(nombre, auxNom); //aca paso el 'valor' del auxiliar al nombre.

	printf("Su nombre es %s", nombre);
	*/
			//FUNCIONES CON CARACTERES
	//atoi()/atol()/atof()
	//atoi() convierte string a un numero. Se detine si encuentra un caracter. Si Error = 0
	//atol() convierte un string en un int long.
	//atof()
	//itoa() convierte un numero en cadena de texto.

	char letras[]="123";
	int numeroEntero;
	int numero=1234;
	char cadena[10];
	numeroEntero = atoi(letras); //ascci to integer.
	itoa(numero, cadena, 10);
	printf("Texto convertido en numero %d y el numero en texto %s \n", numeroEntero, cadena);

	//islower() incluida en <ctype.h> comprueba minuscular. Devuelve valor no nulo si el caracter es minuscula.
	// funciona sobre un caracter, no sobre la cadena.
	//isupper() compruba MAYUSCULAS.no sobre una cadena
	char letra;
	letra='t';
	printf("La letra %c islower(): %d\n", letra, islower(letra));
	letra='D';
	printf("La letra %c islower(): %d\n", letra, islower(letra));
	letra='F';
	if(islower(letra)==0)
	{
		printf("\nNO es minuscula");
	}
	else
	{
		printf("\Es minuscula");
	}
	//strlwr() pasa una cadena de caracteres a minuscula.
	//strupr() pasa una cadena a mayuscula.

	// isdigit() indica si caracter es numerico, devuelve verdadero(!=0) falso(0)
	// isalpha() indica si caracter es alfabetico.
	//tolower() - convierte un caracter a minuscula
	//toupper() - convierte a mayuscula
	char valor1;
	valor1='5';
	printf("\nLetra2 %c isdigit(): %d", valor1, isdigit(valor1));
	if(isdigit(valor1)==0)
	{
		printf("\n NO es un numero");
	}
	else
	{
		printf("\n ES un numero");
	}
	//strncpy ()copia n cantidad de caracteres de origen a destino.
	char origen[30]="La division Primero E";
	char destino[2]="a";// tiene que estar inicializada para no barrer basura
	printf("\nLa cadena de origen es : %s", origen);
	strncpy(destino, origen, 2);
	printf("\nLa cadena de destino es : %s", destino);// se pasa la cantidad de array de destino.

	//strcat(destino, origen)=concatena 2 string
	char nombre[12]="Juan"; //[] tiene que tener la cantidad suficiente de array para pegar todo.
	char apellido[12]="Perez";
	printf("\nEl nombre es: %s ", nombre);
	printf("\nEl apellido es: %s ", apellido);
	strcat(nombre, " ");
	strcat(nombre, apellido);
	printf("\nEl Nombre es: %s ", nombre);//tengo que asegurarme que nombre[]tenga la cantidad correcta

	//strncat(); // copia n cantidad de caracteres

	return EXIT_SUCCESS;
}
