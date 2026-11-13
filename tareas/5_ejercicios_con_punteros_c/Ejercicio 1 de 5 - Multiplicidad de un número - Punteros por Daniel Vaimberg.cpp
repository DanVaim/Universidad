/*Ejercicio 1: Creación de un programa con base en punteros que sea capaz de hacer mayor una cantidad aplicando operaciones básicas de multiplicación*/
#include <stdio.h>
#include <locale.h>
#include <conio.h>

	void V2(int *x){
		*x = (*x)*2;
	}
	void V3(int *x){
		*x = (*x)*3;
	}
	void V4(int *x){
		*x = (*x)*4;
	}
	void V5(int *x){
		*x = (*x)*5;
	}

	void V10(int *x){
		*x = (*x)*10;
	}

	int main(){
		setlocale(LC_ALL, "spanish");
		int a, opc, *dir_num;
		
			printf("¿Qué tantas iteraciones propias necesita tu número?\n"); 
			printf("1- Duplicar\n"); 
			printf("2- Triplicar\n"); 
			printf("3- Cuadruplicar\n"); 
			printf("4- Quintuplicar\n"); 
			printf("5- Decaplicar\n");
			printf("\n"); 
			printf("Ingresa la opción con la que quieras contar: "); 
 			scanf("%d", &opc);

				switch(opc){
					
					case 1:
						printf("Ingresa el dígito que quieras duplicar: ");
						scanf("%d", &a);
						dir_num = &a;
						V2(&a);
						printf("\n El resultado es: %d\n", a);
						printf("La posición del número '%d' es %d", a, dir_num);	
					break;
					
					case 2:
						printf("Ingresa el dígito que quieras triplicar: ");
						scanf("%d", &a);
						dir_num = &a;
						V3(&a);
						printf("\n El resultado es: %d\n", a);
						printf("La posición del número '%d' es %d", a, dir_num);
					break;
					
					case 3:
						printf("Ingresa el dígito que quieras cuadriplicar: ");
						scanf("%d", &a);
						dir_num = &a;
						V4(&a);
						printf("\n El resultado es: %d\n", a);
						printf("La posición del número '%d' es %d", a, dir_num);
					break;
					
					case 4:
						printf("Ingresa el dígito que quieras quintuplicar: ");
						scanf("%d", &a);
						dir_num = &a;
						V5(&a);
						printf("\n El resultado es: %d\n", a);
						printf("La posición del número '%d' es %d", a, dir_num);
					break;
					
					case 5:
						printf("Ingresa el dígito que quieras decaplicar: ");
						scanf("%d", &a);
						dir_num = &a;
						V10(&a);
						printf("\n El resultado es: %d\n", a);
						printf("La posición del numero '%d' es %d", a, dir_num);
					break;
					
			default: printf("Seleccione una opción valida...");
		}
	getch();
	return 0;
}
