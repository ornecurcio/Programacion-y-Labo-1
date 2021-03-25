/*
 ============================================================================
 Name        : Ejercicio.2-2
 Author      : Ornela Curcio
 Version     :
 Copyright   :
 Description : Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.
 ============================================================================
 otra forma de calcaular minimos y maximos. Biblioteca : #include<limits.h>
 agrego varible:
 int minimoNumero.
 minimoNumero = INT_MAX; Esto solo se puede usar solo en C, asiq conviene trabajar con contador y banderas.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

			 	int contadorNumero = 0;
			 	int contadorNumerosPares = 0;
			 	int contadorNumerosImpares = 0;
				int numeroIngresado;
				int menorNumeroIngresado;
				int mayorNumeroParIngresado;
				int acumuladorNumerosPositivos = 0;
				int acumuladorDeLosNegativos = 1;
				int contadorNumerosNegativos = 0;


				for(contadorNumero=0; contadorNumero<10; contadorNumero++)
				{
					printf("Ingrese un numero distinto de 0");
					fflush(stdin);
					scanf("%d", &numeroIngresado);
					while(numeroIngresado==0)
					{
						printf("Error, ingrese un numero distinto de 0");
						fflush(stdin);
						scanf("%d", &numeroIngresado);
					}

					if(numeroIngresado%2==0)
					{
						contadorNumerosPares = contadorNumerosPares + 1;
						if(contadorNumerosPares==1)
						{
							mayorNumeroParIngresado = numeroIngresado;
						}
						else
						{
							if(mayorNumeroParIngresado<numeroIngresado)
							{
								mayorNumeroParIngresado = numeroIngresado;
							}
						}
					}
					else
					{
						contadorNumerosImpares = contadorNumerosImpares + 1;
					}

					if(numeroIngresado>0)
					{
						acumuladorNumerosPositivos = acumuladorNumerosPositivos + numeroIngresado;
					}
					else
					{
						acumuladorDeLosNegativos = acumuladorDeLosNegativos*numeroIngresado;
						contadorNumerosNegativos = 1;
					}

					if(contadorNumero==0)
					{
						menorNumeroIngresado = numeroIngresado;
					}
					else
					{
						if(menorNumeroIngresado>numeroIngresado)
						{
							menorNumeroIngresado = numeroIngresado;
						}
					}
				}//fin for

                if(contadorNumerosNegativos==1)
                {
                	printf("\nProducto de los negativos es %d", acumuladorDeLosNegativos);
                }
                else
                {
                	printf("\nNo hay numeros negativos");
                }
				printf("\nCantidad de pares es %d y la cantidad de impares es %d", contadorNumerosPares, contadorNumerosImpares);
				printf("\nEl menor número ingresado es %d", menorNumeroIngresado);
				printf("\nDe los pares el mayor número ingresado es %d", mayorNumeroParIngresado);
				printf("\nSuma de los positivos es %d", acumuladorNumerosPositivos);


	return EXIT_SUCCESS;
}
