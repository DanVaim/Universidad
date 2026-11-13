/*Escriba una función nombrada funcPotencia() la cual recibirá dos parámetros, primero un numero  ENTERO que será la base de la potencia, y
el segundo parámetro de la función será el exponente , el valor de retorno será la potencia de dicho número.*/

#include <stdio.h>
#include <math.h>

int funcPotencia(int base, int exponente);

main() {
	
int entero, potencia;

printf("Bienvenido, este programa busca calcular la potencia de un numero.\n");
printf("El primer numero que ingreses sera la BASE, el segundo sera el EXPONENTE\n");


printf("El resultado es: %d", funcPotencia(entero, potencia));

return 0;
}

int funcPotencia(int base, int exponente) {
	
int potencia, numEntero, numPotencia;

printf("\nIngresa el numero base: ");
scanf("%d", &numEntero);
printf("\nIngresa el exponente: ");
scanf("%d", &numPotencia);

potencia = pow(numEntero, numPotencia); 

return potencia;
}
