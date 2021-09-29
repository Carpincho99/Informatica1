#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define TITLE "Aprenda a multiplicar v2.0\n\n"
#define P 3 //cantidad de preguntas
#define PROGRESS_BAR_WIDHT 12*P

int numRand(void);
void preg(int);
void validar(int, int);
void rtaCorrecta(void);
void rtaIncorrecta(void);
int finPrograma(void);
void progreso(int);

int main(void){
  int indice;

  srand(time(NULL)); //set rand seed

  do{
    indice = 1;
    for (int i = 0; i < P; i++) {
      printf(TITLE);
      progreso(indice);
      preg(indice);
      indice++;
      system(CLEAR);
    }
  }while(finPrograma());

  return 0;
}


int numRand(void){
  return (rand()%10);
}

void preg(int ind){
  int num1 = numRand();
  int num2 = numRand();
  char enter;

  printf("%d)¿Cuanto es %dx%d? \n", ind, num1, num2);
  printf("Respuesta: ");
  validar(num1, num2);
  rtaCorrecta();
  printf("\n[Pulse enter para continuar...]");

  while((enter = getchar()) != '\n' && (enter = getchar()) != '\r');
}

void validar(int num1, int num2){
  int rta;
  do{
    scanf("%d", &rta);
    while(getchar() != '\n');

    if (rta != num1 * num2){
      rtaIncorrecta();
    }

  }while(rta != num1 * num2);
}

void rtaCorrecta(void){
  switch(rand()%4){
    case 0:
      printf("\n¡Muy bien!\n");
      break;
    case 1:
      printf("\n¡Excelente!\n");
      break;
    case 2:
      printf("\n¡Buen trabajo!\n");
      break;
    case 3:
      printf("\n¡Siga con el buen trabajo!\n");
      break;
  }
}


void rtaIncorrecta(void){
  switch(rand()%4){
    case 0:
      printf("\nNo. Por favor intente de nuevo: ");
      break;
    case 1:
      printf("\nIncorrector. Intente una vez más: ");
      break;
    case 2:
      printf("\n¡No te rindas!: ");
      break;
    case 3:
      printf("\nNo. Sigue intentándolo: ");
      break;
  }
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

  system(CLEAR);
  return cent;
}
