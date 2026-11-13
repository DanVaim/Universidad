/*escriba un programa que mediante el uso de funciones, realice las opresiones aritméticas básicas, suma resta, multiplicación y división de números enteros,
se debe pedir al usuario , los dos números a ser operados ydebe poder elegir el tipo de operación ( +,-,* o /).*/

#include <iostream>
#include <stdio.h>

float suma(float a,float b);
float resta (float a,float b);
float producto (float a,float b);
float division (float a,float b);

int main(){
	int opcion;
	float a, b;
	
	printf("Bienvenido, en este programa se aplicaran las principales operaciones a dos numeros empleando funciones\n\n");
	printf("Ingresa el primer numero: ");
	scanf("%f", &a);
	printf("\nIngresa el segundo numero: ");
	scanf("%f", &b);
	
	printf("\n La suma es: %.2f", suma(a, b));
	printf("\n La resta es: %.2f", resta(a, b));
	printf("\n El producto es: %.2f", producto(a, b));
	printf("\n La division es: %.2f", division(a, b));
	
	printf("\n\nCual opcion eliges?\n1- Suma \n2- Resta \n3- Producto\n4- Division\n\n");
	scanf("%d", &opcion);
	switch(opcion){
	
	case 1: 
	printf("\n La suma es: %.2f", suma(a, b)); 
	break;
	case 2: 
	printf("\n La suma es: %.2f", resta(a, b)); 
	break;
	case 3: 
	printf("\n La suma es: %.2f", producto(a, b)); 
	break;
	case 4: 
	printf("\n La suma es: %.2f", division(a, b)); 
	break;
	default:
		printf("Escoge una opcion valida");
	}
		return 0;
}

float suma(float a,float b){
	
	float Suma;
	
	Suma = a + b; 
	
	return Suma;
}

float resta(float a,float b){
	
	float Resta;
	
	Resta = a - b; 
	
	return Resta;
}

float producto(float a,float b){
	
	float Producto;
	
	Producto = a*b; 
	
	return Producto;
}

float division(float a,float b){
	
	float Division;
	
	Division = a/b; 
	
	return Division;
}
