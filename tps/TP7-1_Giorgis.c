#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define TITLE "Aprenda a multiplicar v1.0\n\n"
#define P 3 //cantidad de preguntas


int numRand(void);
void preg(void);
void rtaCorrecta(void);
void rtaIncorrecta(void);
int finPrograma(void);

int main(void){

  srand(time(NULL)); //set rand seed

  do{
    for (int i = 0; i < P; i++) {
      printf(TITLE);
      preg();
      system(CLEAR);
    }
  }while(finPrograma());

  return 0;
}


int numRand(void){
  return (rand()%10);
}

void preg(void){
  static int indice = 1;
  int num1 = numRand();
  int num2 = numRand();
  int rta;
  char enter;

  printf("%d)¿Cuanto es %dx%d? \n", indice, num1, num2);
  printf("Respuesta: ");
  do{
    scanf("%d", &rta);
  
    if (rta != num1 * num2){
      printf("\nNo. Intentelo de nuevo: ");
    }

  }while(rta != num1 * num2);

  printf("\n¡Muy bien!\n\n");
  printf("[Pulse enter para continuar...]\n");

  while((enter = getchar()) != '\n' && (enter = getchar()) != '\r'); //dischard scanf enter
  while((enter = getchar()) != '\n' && (enter = getchar()) != '\r');

  indice++;
}


int finPrograma(void){
  int cent;

  printf("Fin del programa\n\n");
  printf("Ingrese 0 para salir o 1 para volver a ejecutar: ");
  do{
    scanf("%d", &cent);

    if (cent != 0 && cent != 1){
      printf("Ingrese un valor valido [1/0]: ");
    }
  }while(cent != 0 && cent != 1);

  system(CLEAR);
  return cent;

}
