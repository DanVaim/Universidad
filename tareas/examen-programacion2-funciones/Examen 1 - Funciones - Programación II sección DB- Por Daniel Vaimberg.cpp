/*Escriba un programa que muestre tres opciones al usuario entre las cuales este podrá elegir
una opción de cálculo. 
La primara de estas opciones será calcular las raíces de un polinomio de grado 2 mediante la ecuación de segundo grado, esta operación debe mostrar 
las dos raíces reales (x1 y x2) después de ser ingresados los valores de A, B y C respectivamente, el programa debe mostrar un mensaje de error 
cuando las raíces sean complejas.
La segunda opoción será el cálculo del Volumen de una esfera, el programa debe mostrar el
resultado una vez introducido el valor del radio de la misma, el programa debe ser capaz de Mostar un mensaje de error si el radio es menor o igual a cero.
La tercera opción será el cálculo del desplazamiento de un móvil en movimiento rectilíneo uniforme variado,
 el programa debe pedirle al usuario el desplazamiento inicial, la velocidad inicial, el tiempo de desplazamiento y la aceleración en este intervalo.
Los tres cálculos planteados deben realizarse con el llamado a funciones con paso de parámetros.*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void EcuacionGrad2 ();
float VolEsfera (float R);
float Desplazamiento(float VelInicial, float Aceleracion, float tiempo);

int opcion;
float A, B, C, R, VelInicial, Aceleracion, tiempo;  

int main(){
  
	setlocale(LC_CTYPE, "Spanish"); 
	
		printf("Bienvenido, este programa te mostrá un menú de operaciones que podrá ejecutar según los dígitos que introduzcas.");
		printf ("\n\tMenú de operaciones, elige la que necesites.\n\n");
  
		printf (" 1. Calcular las raíces de un polinomio de grado 2. \n 2. Calcular el volúmen de una esfera. \n 3. Calcular el desplazamiento de un móvil con MRUV.\n\n");
		scanf ("%d", &opcion);
		
		system("cls");
	switch (opcion){
    
    case 1: 
    	printf("\n\tSeleccionó:Cálculo de raíces de un polinomio de grado 2.\n");
        EcuacionGrad2();
    break;
    case 2: 
	printf ("\n\tSeleccionó: Cálculo del volúmen de una esfera.\n");
        printf ("Ingrese el valor del Radio: "); 
		scanf("%f", &R); 
        printf ("\nEl valor del volúmen redondeado quedaría = %.2f\n\n", round(VolEsfera(R)));
    break;
    case 3: 
		printf ("\n\tSeleccionó: Desplazamiento de un móvil con MRUV\n\n");
        printf ("\n\nDesplazamiento = %.2f\n\n", Desplazamiento(VelInicial, Aceleracion,tiempo));
    break;
    default: printf("\n\n\n\tPor favor, ingrese una opción válida.\n\n\n\n");
	}  
  
	system ("pause");
	return 0;
}

void EcuacionGrad2(){
	
	float A, B, C, D;
	
		printf("\nIntroduzca los dígitos de la ecuación de segundo grado\n\n");
		
		printf("Introduce valor de a: ");
		scanf("%f", &A);
		
		printf("Introduce valor de b: ");
		scanf("%f", &B);
		
		printf("Introduce valor de c: ");
		scanf("%f", &C);
	
		D = (B*B)-(4.0*A*C);
	
			if (D == 0.0){
				printf("\nSolución única: = %.2f\n", -B/(2.0*A));
			}else if(D > 0.0){
				printf("x1 = %.2f\n", (-B+sqrt(D))/(2.0*A));
				printf("x2 = %.2f\n", (-B-sqrt(D))/(2.0*A));
			}else if(D < 0.0){
				printf("\n\tError\n\t------\nLa ecuación introducida origina un número complejo.\n\n");
			}	
 		}
 		
	float VolEsfera (float R){
  	float Radio = R, Volumen = (4.0/3.0)*3.141592*pow(R, 3);
  
  		if (Volumen > 0){
  			printf ("\nEl volúmen de la esfera de radio %.2f es: %.2f\n", Radio, Volumen);
  
  		}else if(Volumen <= 0){
  			printf ("\n\tError encontrado\n\t-----------------\nEl radio introducido es menor o igual a 0, inténtalo de neuvo.\n");
  			exit(0);
  		}
	return Volumen;
}

float Desplazamiento(float VelInicial, float Aceleracion, float tiempo){
	
	printf ("Ingrese la velocidad inicial: "); 
	scanf ("%f", &VelInicial);
	
	printf ("Ingrese el tiempo: "); 
	scanf ("%f", &tiempo);
	
 	printf ("Ingrese la aceleración: "); 
	scanf ("%f", &Aceleracion);
	
	float desplazamiento = VelInicial*tiempo+(1.0/2.0*Aceleracion*pow(tiempo, 2));
return desplazamiento;
}

