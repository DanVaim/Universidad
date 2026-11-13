/*1.-Escriba un programa que devuelva la parte decimal de cualquierNúmero introducido por el usuario. Por ejemplo si se introduce el número
456.884 debería devolverse el número 0.884.*/

#include <stdio.h>

float numero;
int Entero;
float Decimal(void);

main(){

extern float numero;
extern int Entero;

	printf("Ingrese un numero con decimales: ");
	scanf("%f", &numero);
	
	Entero = numero;
	
	printf("La parte entera es %d\n\n", Entero);
	
	printf("La parte decimal es %f\n", Decimal());
	
return 0;

}

float Decimal(void){
	
	float numd;

		numd = numero - Entero;

return numd;

}
