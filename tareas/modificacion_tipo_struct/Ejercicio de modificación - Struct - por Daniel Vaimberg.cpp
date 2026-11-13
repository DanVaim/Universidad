//Estructuras Anidadas
#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

struct infoFamiliar{

    char estadoC  [20];
    char Vivienda  [30];
    char Hijos [2];
};

struct ServiciosPublicos{

    char Agua  [7];
    char luz      [7];
    char Telefono [15];
};

struct infoDireccion{

    char direccion  [30];
    char ciudad      [20];
    char municipio [20];
};

struct empleado{

    char   nombre[20];
    struct infoDireccion  dirEmpleado;
    struct ServiciosPublicos  ServEmpleado;
    struct infoFamiliar  FamEmpleado;
    double salario;
	int x;
	
}empleados[2];


int main(){

	setlocale(LC_ALL, "spanish");
    int i, x;
    printf("¿Cuántos empleados son? : ");
    scanf("%d", &x);

    for(i = 0; i < x; i++){

    	fflush(stdin); 
	    
        printf("\n[%i] Digita tu nombre: ", i +1);
        gets(empleados[i].nombre);

        printf("[%i] Digita tu Dirección: ", i +1);
        gets(empleados[i].dirEmpleado.direccion);

        printf("[%i] Digita tu Ciudad: ", i +1);
        gets(empleados[i].dirEmpleado.ciudad);

        printf("[%i] Digita tu Municipio: ", i +1);
        gets(empleados[i].dirEmpleado.municipio);
        
        printf("[%i] Digita tu Estado Civil: ", i +1);
        gets(empleados[i].FamEmpleado.estadoC);

        printf("[%i] Digita el Tipo de Vivienda que tienes: ", i +1);
        gets(empleados[i].FamEmpleado.Vivienda);

        printf("[%i] Digita la cantidad de Hijos que tienes: ", i +1);
        gets(empleados[i].FamEmpleado.Hijos);

	printf("[%i] ¿Posee servicio de Agua? : ", i +1);
        gets(empleados[i].ServEmpleado.Agua);

        printf("[%i] ¿Posee servicio eléctrico? : ", i +1);
        gets(empleados[i].ServEmpleado.luz);
		
        printf("[%i] Digita tu número de teléfono: ", i +1);
        gets(empleados[i].ServEmpleado.Telefono);
        
        printf("[%i] Digita tu salario base: ", i +1);
        scanf("%lf", &empleados[i].salario);

        printf("\n");
        printf("\n");

    }
       for(i = 0; i < x; i++){

            printf("\n\nDatos del empleado número: [%d] ", i + 1);
            printf("\nNombre : %s", empleados[i].nombre);
            printf("\nDirección: %s", empleados[i].dirEmpleado.direccion);
            printf("\nCiudad : %s", empleados[i].dirEmpleado.ciudad);
            printf("\nMunicipio: %s", empleados[i].dirEmpleado.municipio);
            printf("\nEstado Civil: %s", empleados[i].FamEmpleado.estadoC);
            printf("\nNúmero de Hijos: %s", empleados[i].FamEmpleado.Hijos);
            printf("\nTipo de Vivienda: %s", empleados[i].FamEmpleado.Vivienda);
            printf("\nServicio de Agua: %s", empleados[i].ServEmpleado.Agua);
            printf("\nServicio de Electricidad: %s", empleados[i].ServEmpleado.luz);
            printf("\nNúmero de teléfono: %s", empleados[i].ServEmpleado.Telefono);
            printf("\nSalario: %.2lf", empleados[i].salario);
         }
    printf("\n");
    system("pause");
    return 0;
}
