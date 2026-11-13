#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char **cadena, *aux;
	int i, j, n=10;
	char temp[20];
	
		printf("%s%s\n", "Este programa ordena diez nombres introducidos por teclado.");
		printf("Introduce los diez nombres:\n");
		cadena = (char**)malloc(10*sizeof(char*));
		
	for (i=0; i<n; i++) {
		printf("Nombre %d: ", i+1);
		scanf(" %s", temp);
			cadena[i]=(char*)malloc((strlen(temp)+1)*sizeof(char));
		strcpy(cadena[i], temp);
	}
	
	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++)
			if ((strcmp(cadena[i], cadena[j]))>0) {
				aux=cadena[i];
				cadena[i]=cadena[j];
				cadena[j]=aux;
			}
			
		printf("La lista ordenada es:\n\n -----------------------\n\n");
			for (i=0; i<n ; i++)
			printf("%s\n", cadena[i]);
		for (i=0; i<n; i++)free(cadena[i]);free(cadena);
}
