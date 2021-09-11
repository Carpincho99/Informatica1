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

int main(void){

  srand(time(NULL)); //set rand seed

  for (int i = 0; i < P; i++) {
    system(CLEAR);
    printf(TITLE);
    preg();
  }

  return 0;
}


int numRand(void){
  return (rand()%10);
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
      printf("\nIncorrecto. Intente una vez más: ");
      break;
    case 2:
      printf("\n¡No te rindas!: ");
      break;
    case 3:
      printf("\nNo. Sigue intentándolo: ");
      break;
  }
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
      rtaIncorrecta();
    }

  }while(rta != num1 * num2);

  rtaCorrecta();
  printf("\n[Pulse enter para continuar...]\n");

  while((enter = getchar()) != '\n' && (enter = getchar()) != '\r'); //dischard scanf enter
  while((enter = getchar()) != '\n' && (enter = getchar()) != '\r');

  indice++;
}
