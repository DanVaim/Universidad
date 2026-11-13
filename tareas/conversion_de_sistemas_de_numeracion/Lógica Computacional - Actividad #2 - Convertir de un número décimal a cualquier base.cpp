#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	
	setlocale(LC_ALL, "spanish");
	
	int base, n, i = 0, b[999];  //Enteros a utilizar, el storage de b[] mantiene a cualquier tipo de conversión.
    
    printf("Bienvenido a este programa que calcula la conversión de un número de base 10 a cualquier otra base que especifiques.\n\n");
    printf("Ingresa un número de base 10: ");
    scanf("%i",&n);									//Se lee el número a transformar.
    printf("Ingresa un número que será la base a la que se convertirá: ");
    scanf("%d", &base);								//Se lee la base a la que se transformará.
    
    	while (n!=0){					//Este ciclo permite calcular la conversión elegida, utilizando el residuo y luego dividiendo n (num) entre la base para obtener un nuevo n.
       		b[i] = n%base; 
        	n = n/base; 
        	i++; 						//se sigue con el ciclo de b[].
    }
    i--;
	
	printf("Resultado en base %d: ", base);			//Se imrprime el resultado obtenido.
	 
     while (i>=0) 								
     {
           switch(b[i]) 								//Este condicional permite transformar los digitos que se salen de la base décimal ej: case 10 imprime la ´A´ en lugar del número 10 en base 11 o superior.					
		  
           {
                            case 10:
                                printf("A");
                            break;
                            case 11:
                                printf("B");
                            break;
                            case 12:
                                printf("C");
                            break;
                            case 13:
                                printf("D");
                            break;
                            case 14:
                                printf("E");
                            break;
                            case 15:
                                printf("F");
                            break;
                            case 16:
                                printf("G");
                            break;
                            case 17:
                                printf("H");
                            break;
                            case 18:
                                printf("I");
                            break;
                            case 19:
                                printf("J");
                            break;
                            case 20:
                                printf("K");
                            break;
                            case 21:
                                printf("L");
                            break;
                            case 22:
                                printf("M");
                            break;
                            case 23:
                                printf("N");
                            break;
                            case 24:
                            	printf("Ñ");
                            break;
                            case 25:
                                printf("O");
                            break;
                            case 26:
                                printf("P");
                            break;
                            case 27:
                                printf("Q");
                            break;
                            case 28:
                                printf("R");
                            break;
                            case 29:
                                printf("S");
                            break;
                            case 30:
                                printf("T");
                            break;
                            case 31:
                                printf("U");
                            break;
                            case 32:
                                printf("V");
                            break;
                            case 33:
                                printf("W");
                            break;
                            case 34:
                                printf("X");
                            break;
                            case 35:
                                printf("Y");
                            break;
                            case 36:
                                printf("Z");
                            break;
                             
                            default:
                                  printf("%i",b[i]); 					//Si no existen valores que superen el 9, se imprime el número real.
                            break;
           } 
        i--;
    }
    printf("\n\n");													//Salto de línea para una mejor visualización.
	system("pause");											
	return 0;
}

