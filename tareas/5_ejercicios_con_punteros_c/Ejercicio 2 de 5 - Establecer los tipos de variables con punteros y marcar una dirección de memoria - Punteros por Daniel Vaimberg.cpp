/*Ejercicio 2 : Pedir al usuario que introduzca un dígito para una cadena de caracteres , para una variable de tipo entera y flotante.
Luego imprimir los valores utilizando punteros y que tambien imprimir las direcciones en memoria de cada valor*/

#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "spanish");
	char c[1000];
	int i;
	float f;

	printf("Digite valor para su cadena: ");
	gets(c);
	printf("\nDigite un valor para su número entero: ");
	scanf("%i", &i);
	printf("\nDigite un valor para su número flotante: ");
	scanf("%f" , &f);

	char * puntero_cadena;
	int * puntero_entero;
	float * puntero_flotante;
 
	puntero_cadena = c; 
	puntero_entero = &i; 
	puntero_flotante = &f; 
 
	printf("\n\nEl puntero para su cadena: %s " , puntero_cadena); 
	printf("\nEl puntero para su número entero: %i " , *puntero_entero); 
	printf("\nEl puntero para su número flotante: %f " , *puntero_flotante );
	printf("\n\nDirección en memoria para la cadena: %p ", &c); 
	printf("\nDirección en memoria para el entero: %p ", &i); 
	printf("\nDirección en memoria para el flotante: %p ", &f); 
 
 return 0;
}
