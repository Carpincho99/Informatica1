#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define TITLE "Aprenda a multiplicar v3.0\n\n"
#define P 10 //cantidad de preguntas
#define PROGRESS_BAR_WIDHT 5*P

int numRand(void);
int preg(int, int, int);
void resultadoTest(int, int);
void progreso(int);
int finPrograma(void);

int main(void){
  int indice;
  int porcentaje;

  srand(time(NULL)); //set rand seed

  do{
    system(CLEAR);
    indice = 1;
    porcentaje = 0;
    for (int i = 0; i < P; i++) {
      printf(TITLE);
      progreso(indice);
      porcentaje += preg(indice, numRand(), numRand());
      indice++;
      system(CLEAR);
    }
    resultadoTest(porcentaje, P);
    system(CLEAR);
  }while(finPrograma());

  return 0;
}


int numRand(void){
  return (rand()%10);
}

int preg(int ind, int num1, int num2){
  int rta;

  printf("%d)¿Cuanto es %dx%d? \n", ind, num1, num2);
  printf("Respuesta: ");
  scanf("%d", &rta);
  while(getchar() != '\n');

  if(rta == num1 * num2){
    return 1; 
  }else{
    return 0;
  }
}

void resultadoTest (int porcentaje, int p){
  printf("Resultados del test\n\n");
  printf("Respuestas correctas: %d de %d (%d%%)\n\n", porcentaje, p, (porcentaje*100)/p);

  if((porcentaje*100)/p < 75){
    printf("Pídale ayuda adicional a su maestro\n");
  }else{
    printf("¡Felicitaciones, está listo para pasar al siguiente nivel!\n");
  }

  printf("\n[Pulse enter para continuar...]");
  while(getchar() != '\n');
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
