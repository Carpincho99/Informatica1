#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define TITLE "Aprenda a multiplicar v1.0\n\n"
#define P 5 //cantidad de preguntas
#define PROGRESS_BAR_WIDHT 10*P

int numRand(void);
void preg(int, int, int);
void validar(int, int);
int finPrograma(void);
void progreso(int);

int main(void){
  int indice;

  srand(time(NULL)); //set rand seed

  do{
    system(CLEAR);
    indice = 1;
    for (int i = 0; i < P; i++) {
      printf(TITLE);
      progreso(indice);
      preg(indice, numRand(), numRand());
      indice++;
      system(CLEAR);
    }
  }while(finPrograma());

  return 0;
}


int numRand(void){
  return (rand()%10);
}

void preg(int ind, int num1, int num2){
  char enter;

  printf("%d)¿Cuanto es %dx%d? \n", ind, num1, num2);
  printf("Respuesta: ");
  validar(num1, num2);
  printf("\n¡Muy bien!\n\n");
  printf("[Pulse enter para continuar...]");

  while((enter = getchar()) != '\n' && (enter = getchar()) != '\r');
}

void validar(int num1, int num2){
  int rta;
  do{
    scanf("%d", &rta);
    while(getchar() != '\n');

    if (rta != num1 * num2){
      printf("\nNo. Intentelo de nuevo: ");
    }

  }while(rta != num1 * num2);
}


void progreso(int ind){
  printf("Progreso: [");
  for (int i = 0; i < (PROGRESS_BAR_WIDHT/P*ind); i++) {
    printf("#");  
  }
  for (int i = 0; i < (PROGRESS_BAR_WIDHT - PROGRESS_BAR_WIDHT/P*ind); i++) {
    printf("-");
  }
  printf("] (%d%%)\n\n",ind*100/P);
}


int finPrograma(void){
  int cent;

  printf("Fin del programa\n\n");
  printf("Ingrese 0 para salir o 1 para volver a ejecutar: ");
  do{
    scanf("%d", &cent);
    while(getchar() != '\n');

    if (cent != 0 && cent != 1){
      printf("Ingrese un valor valido [1/0]: ");
    }
  }while(cent != 0 && cent != 1);

  return cent;
}
