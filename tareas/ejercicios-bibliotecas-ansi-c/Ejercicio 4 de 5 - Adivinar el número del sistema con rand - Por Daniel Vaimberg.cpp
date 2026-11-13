#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <locale.h>

#define Intentos_Maximos 5 /*Ajustes del programa*/
#define Inferior 1 
#define Superior 100  
int aleatorio_en_rango(int minimo, int maximo);


int main() {

  setlocale(LC_ALL, "spanish");
  srand(getpid());

  int secreto = aleatorio_en_rango(Inferior, Superior);
  int respuesta, intentos = 0;

  printf("Bienvenido al programa de números aleatorios \n El sistema ha seleccionado un número al azar entre %d y %d, tu tarea es adivinarlo en un máximo %d intentos\n", Inferior, Superior, Intentos_Maximos);

  while (1) {
    intentos++;
    printf("\nEscribe el número que crees que seleccioné: ");
    scanf("%d", &respuesta);
    if (respuesta == secreto) {
      printf("\nCorrecto. El número que seleccioné fue %d y lo adivinaste en %d " "intento(s)", secreto, intentos);
      break;
    } else if (respuesta < secreto) {
      printf("\nError, pero te doy una pista: el número que elegí es mayor que %d\n", respuesta);
    } else {
      printf("\nError, pero te doy una pista: el número que elegí es menor que %d\n", respuesta);
    }

    if (intentos >= Intentos_Maximos) {
      printf("\n\nNo acertaste. El número que seleccionó el sistema fue %d", secreto);
      break;
    }
  }
}

int aleatorio_en_rango(int minimo, int maximo) {
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
