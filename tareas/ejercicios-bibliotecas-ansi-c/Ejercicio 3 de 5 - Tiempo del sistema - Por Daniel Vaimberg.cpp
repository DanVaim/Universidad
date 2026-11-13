#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

int main(){

	setlocale(LC_ALL, "spanish");
	
	char **cadena, *aux;
	int i, n=1;
	char temp[20];
	
		printf("Introduce tu nombre: ");
		scanf("%s", temp);
		system("cls");
		printf("Bienvenido al programa del reloj %s, el tiempo del sistema es: \n\n", temp);
		

	time_t TiempoSistema;
	time(&TiempoSistema);
	printf("%s\n\n", ctime(&TiempoSistema));
	
	struct tm *tiempolocal = localtime(&TiempoSistema);
	printf("%d/%d/%d\n\n", tiempolocal->tm_mday, tiempolocal->tm_mon+1, tiempolocal->tm_year+1900);
	
i=0;
time_t comienzo, final;
struct tm *tiempoComienzoPtr, *tiempoFinalPtr;
comienzo = time( NULL );
for( i=0; i<10000; i++ );
final = time( NULL );

    double time_spent = 0.0;
 
    clock_t begin = clock();
 
    sleep(3);
 
    clock_t end = clock();
 
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("El tiempo transcurrido tras la ejecución del programa fue de %f segundos", time_spent);
 
return 0;

}
