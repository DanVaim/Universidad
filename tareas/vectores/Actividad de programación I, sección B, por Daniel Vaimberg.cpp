/*ACTIVIDAD ADICIONAL
Realizar con la Sentencia switch ( ), un programa
que permita Mostrar y Ejecutar el siguiente Menú:
Opciones
1. Llenar Vector A
2. Llenar Vector B
3. Crear Vector C
4. Visualizar los 3 Vectores
5. Consultar Elementos de A
6. Consultar Elementos de B
7. Modificar Elementos de A
8. Modificar Elementos de B || Elegir Opción:*/

#include <iostream>
#include <stdio.h>
#include <conio.h>

int main(){
int opcion, i = 0, j = 0, k = 0, nuevo, nuevo2;
int  A[6], B[6], C[12];


	printf("En el siguiente programa se le presentara un menu para calcular arreglos/vectores unidimensionales de seis digitos \n\n");
		A[2] = 0; A[6] = 0; B[6] = 0; B[2] = 0; B[4]= 0; B[5] = 0;
	
do{
	printf ("1. Llenar vector A\n");
	printf ("2. Llenar vector B\n");
	printf ("3. Crear vector C\n");
	printf ("4. Visualizar los 3 vectores\n");
	printf ("5. Consultar elementos de A\n");
	printf ("6. Consultar elementos de B\n");
	printf ("7. Modificar elementos de A\n");
	printf ("8. Modificar elementos de B\n");
	printf ("9. Salir del programa\n");
	printf ("\nIngrese una opcion: ");
	
	scanf ("%d", &opcion);
	system ("cls");
	
	switch(opcion){
	case 1: /*LLenar vector A*/
		for (i=1; i<=6; i++)
		{
			printf("A [%d]= ", i);
			scanf ("%d", &A[i]);
	}
		
		system("cls");
		
			break;
			
	case 2: /*LLenar vector B*/		
		for (j=1; j<=6; j++)
		{
			printf("B [%d]= ", j);
			scanf ("%d", &B[j]);
		}
		system("cls");
		break;
		
		case 3: /*Crea el vector C a partir de A y B*/
			
		printf("El vector C es igual a la superposicion de A y B\n");
		for (k=1; k<2; k++){
			for (i = 1; i < 7; i++){
				C[i] = A[i];
			}
		for(i = 7; i< 13; i++){
			C[i] = B[i - 6];
		}
		for(i = 1; i<=12; i++){
			printf("C [%d]= %d\n", i, C[i]);
		}
		printf("\n");
	}
		break;
		
		case 4: /*Visualizar los 3 vectores*/
		printf("\n                                 Los vectores a representar son: \n---------------------------------------------------------------------------------------------------------------\n");
	    for (i=1; i<7; i++){
	        printf ("A [%d]= %d\n", i, A[i]);
			}
			  printf("---------------------------------------------------------------------------------------------------------------\n");
		    for (j=1; j<7; j++){
	        printf ("B [%d]= %d\n", j, B[j]);
	   		 } 
				printf("---------------------------------------------------------------------------------------------------------------\n");
		for (k=1; k<2; k++){
			for (i = 1; i < 7; i++){
				C[i] = A[i];
			}
		for(i = 7; i< 13; i++){
			C[i] = B[i - 6];
		}
		for(i = 1; i<=12; i++){
			printf("C [%d]= %d\n", i, C[i]);
		}

	}
	   		 printf("---------------------------------------------------------------------------------------------------------------\n");
		break;
		
		case 5: /*consultar elementos de A*/
		
		printf("\nIngrese una posicion: ");
		scanf("%d", &i);
		printf("Numero[%d] = %d\n\n", i, A[i]);

		break;
			
		case 6: /*consultar elementos de B*/
		printf("\nIngrese una posicion: ");
		scanf("%d", &j);
		printf("Numero[%d] = %d\n\n", j, B[j]);
		
		break;
		
		case 7: /*Modificar elementos de A*/
		printf("\nIngrese la posicion del elemento que sera modificado: ");
		scanf("%d", &i);
		printf("Usted selecciono: numero[%d] = %d\n", i, A[i]);
		printf("Ingrese el nuevo valor del elemento: ");
		scanf("%d", &nuevo);
		A[i] = nuevo;
		printf("El vector queda de la siguiente manera: \n\n");
			for (i=1; i<7; i++)
		{
			printf("A [%d]= %d \n\n", i, A[i]);	
		}
		break;
		
		case 8: /*Modificar elementos de B*/
		printf("\nIngrese la posicion del elemento que sera modificado: ");
		scanf("%d", &j);
		printf("Usted selecciono: numero[%d] = %d\n", j, B[j]);
		printf("Ingrese el nuevo valor del elemento: ");
		scanf("%d", &nuevo2);
		B[j] = nuevo2;
		printf("El vector queda de la siguiente manera: \n\n");
			for (j=1; j<7; j++)
		{
			printf("B [%d]= %d \n\n", j, B[j]);
			
		}
		break;
			default:; 
	}		
    }while(opcion != 9);

	getch();
    return 0;
}
