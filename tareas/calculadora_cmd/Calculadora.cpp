#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int main()
{
           int eleccion, a, b, suma = 0, resta = 0, mult = 1, div = 0;
        float divR;
        printf("\nIngrese uno de los casos");
        printf("\nCaso 1: Suma ");
        printf("\nCaso 2 Resta ");
        printf(" \nCaso 3 Multiplicacion ");
        printf(" \nCaso 4 Division  \n");
        printf(" \n¿Cual operacion desea efectuar? : ", eleccion);

          scanf("%d", &eleccion);                              //aca se guerda la elecion que hizo el usuario


         if (eleccion == 1){

                printf("Usted ha ingresdo en el modulo de suma \n");
                printf("ingrese el valor de a: ", a);
                scanf("%d", &a);
                printf("ingrese el valor de b: ", b);
                scanf("%d", &b);
                suma = a + b;
                printf("\nla suma es: %d", suma);

            }else if(eleccion == 2){ //resta
                printf("Usted ha ingresado en el modulo de la resta\n");
                printf("ingrese el valor de a: ", a);
                scanf("%d", &a);
                printf("ingrese el valor de b: ", b);
                scanf("%d", &b);
                resta = a - b;
                printf("\nla resta es: %d ", resta);

            }else if(eleccion == 3){ //multiplicacion
                 printf("Usted ha ingresado en el modulo de la multiplicacion\n");
                 printf("ingrese el valor de a: ", a);
                 scanf("%d", &a);
                 printf("ingrese el valor de b: ", b);
                 scanf("%d", &b);
                mult = a * b;
                 printf("\nla multiplicacion es: %d", mult);


            }else if(eleccion == 4) {        //division
                 printf("Usted ha ingresado en el modulo de la division\n");
                 printf("ingrese el valor de a: ");
                 scanf("%d", &a);
                 printf("ingrese el valor de b: ");
				 scanf("%d", &b);
                 div = a / b;
                 printf("\nla division entera es: %d ", div);


                divR=float(a)/float(b);

                printf("\n La division decimal es: %f", divR);

        		}else{ printf("\nLa opcion es invalida");
        }

 return 0;
}
