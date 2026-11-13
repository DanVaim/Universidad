/* Pedir una palabra o una frase separada por ´_´ al usuario y devolver el número de vocales o consonantes que hay. Utilizando punteros P*/
/*Ejercicio 4: Creación de un programa con base en punteros que sea capaz de contar el numero de vocales o consonantes que hay en una palabra o frase*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){ 
setlocale(LC_ALL, "spanish");
	int vocales=0, consonantes=0, a; 
	printf("¿Qué tipo de caracteres deseas saber en la palabra?\n"); 
	printf("1- Las vocales.\n"); 
	printf("2- Las consonantes.\n\n"); 
	printf("Ingresa la opción con la que quieras contar: ");  
 	scanf("%d", &a); 
 		switch (a) { 
 			case 1:
			  	printf("Introduce la frase, para formar espacios utiliza '_': ");
 				char texto[1000]; 
				scanf("%s", &texto);
   				char *p; 
				p = texto; 
				while (*p != '\0'){ 
				if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || *p == 'A' || *p == 'E' || *p =='I' || *p == 'O' || *p == 'U') 
				vocales ++; p++; } 
   				printf("Hay %d vocales.", vocales); 
  		 	break; 
   		 	case 2:
				printf("Introduce la frase, para formar espacios utiliza '_': "); 
				char texto2[1000]; 
   				scanf("%s", &texto2); 
  	 			p = texto2; 
   					while (*p != '\0'){
						if (*p == 'b' || *p == 'B' || *p == 'c' || *p == 'C' || *p == 'd' || *p == 'D' || *p == 'f' || *p =='F' || *p == 'g' || *p == 'G' || *p == 'h' || *p == 'H' || *p == 'j' || *p == 'J' || *p == 'k' || *p == 'K' || *p =='l' || *p == 'L' || *p == 'm' || *p == 'M' || *p == 'n' || *p == 'N' || *p == 'ñ' || *p == 'Ñ' || *p == 'p' || *p== 'P' || *p == 'q' || *p == 'Q' || *p == 'r' || *p == 'R' || *p == 's' || *p == 'S' || *p == 't' || *p == 'T' || *p== 'v' || *p == 'V' || *p == 'w' || *p == 'W' || *p == 'x' || *p == 'X' || *p == 'y' || *p == 'Y' || *p == 'z' ||*p == 'Z') 
						consonantes ++; p++; } 
						printf("Hay %d consonantes.", consonantes);
			break;
			default: printf("Ingresa un número del menú...");
		}
		getch();
	return 0;
}
