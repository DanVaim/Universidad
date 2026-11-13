#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;
 
void Simbolos3(char a,char b,char c, int eleccion1, int eleccion2);
void Simbolos2(char a,char b,char c, int eleccion1, int eleccion2);   //Funciones a utilizar para imprimir simbolos y cantidad de variables
int conectores_logicos(int p, int q, int conector_logico);

int main()
{
		setlocale(LC_CTYPE, "Spanish"); //Función de la librería locale.h que permite colocar acentos
		
	int p, q, r, m, n, opc1;
	char a, b, c;
	
	printf("Bienvenido a este programa que busca determinar el resultado de una tabla de verdad de proposiciones lógicas de hasta 3 variables.\n\n");
	
	printf("¿Cuántas proposiciones va a elegir?\n 1. Dos proposiciones \n 2. Tres proposiciones\n :"); //Menú - selección de modalidad que afecta a la tabla.
    scanf("%d", &opc1);
    
   	 switch(opc1){
	
    	case 1: 
    		system("cls");
    		printf("\n\n\tSeleccionó: Dos proposiciones.\n");
    		printf ("\n\nPara determinar las operaciones en la tabla se presentarán valores booleanos \n\n\t 1 (Verdadero) \n\t 0 (Falso)\n\n  |_A dos variables de su elección_|\n\n ");
		
		printf("Seleccione las variables y los operadores lógicos:\n\t Negación (~) = 0\n\t --------------------\n\t AND (^) = 1\n\t --------------------\n\t OR (\/) = 2\n\t --------------------\n\t´Entonces´ (->) = 3\n\t --------------------\n\t´Si y solo sí´ (<-->)= 4\n\t--------------------\n");
        printf("\nIntroduzca la primera variable:"); cin >> a;
        printf("Introduzca el primero operador lógico:"); cin >> m;
          if(m > 4 || m<0){
        	printf("Ingresa un dígito del 0 al 4...");
        	return 0;
		}
        printf("Introduzca la segunda variable:"); cin >> b;
  

    Simbolos2(a,b,c,m,n);

    int i,j,k;
    for (i=0;i<2;i++)
    {
    	
        for (j=0;j<2;j++)
        {
            for (k=1;k<2;k++)
            {
                printf("%d  |  %d |    ",i,j,k);
                if(m<=n) cout<<conectores_logicos(conectores_logicos(i,j,m),k,n)<<endl;
                else cout<<conectores_logicos(i,conectores_logicos(j,k,n),m)<<endl;				//Construcción de la tabla de 2 variables 2^2 = 4
            }
        }
    }
    	break;
    
   		case 2: 
   			system("cls");												
			printf ("\n\n\tSeleccionó: Tres proposiciones.\n");
			printf ("\n\nPara determinar las operaciones en la tabla se presentarán valores booleanos \n\n\t 1 (Verdadero) \n\t 0 (Falso)\n\n |_A tres variables de su elección_|\n\n");
        	
        printf("Seleccione las variables y los operadores lógicos:\n\t Negación = 0\n\t --------------------\n\t AND = 1\n\t --------------------\n\t OR = 2\n\t --------------------\n\t´Entonces´ = 3\n\t --------------------\n\t´Si y solo sí´ = 4\n\t--------------------\n");
        printf("\nIntroduzca la primera variable:"); cin >> a;				//Ingreso de la variable por parte del usuario, una letra o caracteres que se utilizarán luego.
        printf("Introduzca el primero operador lógico:"); cin >> m;
        if(m > 4 || m<0){
        	printf("Ingresa un dígito del 0 al 4..."); 				// Error emitido por no colocar un dígito válido entre 0 y 4 en la selección.
        	return 0;
		}
        printf("Introduzca la segunda variable:"); cin >> b;
        printf("Introduzca el segundo operador lógico:"); cin >> n;
         if(n > 4 || n<0){
        	printf("Ingresa un dígito del 0 al 4...");
        	return 0;
		}
        printf("Introduzca la tercera variable: "); cin >> c;

    Simbolos3(a,b,c,m,n);

    for (i=0;i<2;i++)
    {
    	
        for (j=0;j<2;j++)
        {
            for (k=0;k<2;k++)
            {
                printf("%d  |  %d  |  %d  |    ",i,j,k);
                if(m<=n) cout<<conectores_logicos(conectores_logicos(i,j,m),k,n)<<endl;
                else cout<<conectores_logicos(i,conectores_logicos(j,k,n),m)<<endl;            //Construcción de la tabla de tres variables. 2^3 = 8
            }
        }
    }
    	break;
    
    	default: printf("\n\n\n\tPor favor, ingrese una opción válida.\n\n\n\n"); // Error emitido por no colocar un dígito válido entre 1 y 2 en la selección.
    	return 0;
	} 
	system("pause");
	return 0;
}
       
	void Simbolos3(char a,char b,char c,int eleccion1,int eleccion2){  //Utilización de los simbolos y aparición de variables en la opción 2
	printf("%c  -  %c  -  %c   -  %c",a,b,c,a);
    switch(eleccion1){
	    case 0:printf("~%c",b);
		break;
		case 1:printf("^%c",b);
		break;
		case 2:printf("\\/%c",b);
		break;
		case 3:printf("->%c",b);
		break;
		case 4:printf("<->%c",b);
		break;
	}
	switch(eleccion2)
	{
		case 0:printf("~%c\n",c);
		break;
		case 1:printf("^%c\n",c);
		break;
		case 2:printf("\\/%c\n",c);
		break;
		case 3:printf("->%c\n",c);
		break;
		case 4:printf("<->%c\n",c);
		break;
	}
}

void Simbolos2(char a,char b,char c,int eleccion1,int eleccion2)  //Utilización de los simbolos y aparición de variables en la opción 1
{
	printf("%c  -  %c  -%c|  %c",a,b,c,a);
    switch(eleccion1)
	{
	    case 0:printf("~%c",b);
		break;
		case 1:printf("^%c",b);
		break;
		case 2:printf("\\/%c",b);
		break;
		case 3:printf("->%c",b);
		break;
		case 4:printf("<->%c",b);
		break;
	}
	switch(eleccion2)
	{
		case 0:printf("~%c\n",c);
		break;
		case 1:printf("^%c\n",c);
		break;
		case 2:printf("\\/%c\n",c);
		break;
		case 3:printf("->%c\n",c);
		break;
		case 4:printf("<->%c\n",c);
		break;
	}
}
int conectores_logicos(int p, int q, int conector_logico) //Función de respaldo para los conectores lógicos que se utilizan en main... Determinan el valor final.
{
    if(conector_logico==1)
	{
		return p*q;
	}
	else if(conector_logico==2)
	{
		return ((p+q)/2+(p+q)%2);
	}
	else if(conector_logico==3)
	{
		if(p==0)
			return 1;
		else
		{
			if(q==1)
				return 1;
			else
				return 0;
		}
	}
	else if(conector_logico==4)
	{
		if(p==q)
			return 1;
		else
			return 0;
	}
}


