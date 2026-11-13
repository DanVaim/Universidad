#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "spanish");
	printf("Hola, bienvenido a este programa que contará el número de palabras que posee tu ensayo o asignación \n Introduce el texto a continuación\n");
	char texto[5000];
	int i, contPalabras = 1;
	printf("Ingrese el texto: ");
	fgets(texto, 5000, stdin);
		for(i = 0; i < strlen(texto); i++)
			if(texto[i] == ' ' && i > 0 && texto[i - 1] != ' ')
               contPalabras++;
     printf("Cantidad de palabras en el texto: %d\n", contPalabras);
     system("pause");
     return 0;
}
