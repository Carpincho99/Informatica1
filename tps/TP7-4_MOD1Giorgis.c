#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define TITLE "Aprenda a multiplicar v4.0\n\n"
#define P 3 //cantidad de preguntas
#define PROGRESS_BAR_WIDHT 12*P

typedef struct infoRta{
  int indice;
  int num1;
  int num2;
  int rta;
  int rtaCorrecta;
  int output; //1=rta acertada, 0=rta incorrecta
}infoRta_t;

int numRand(int);
int setDificultad(void);
infoRta_t preg(int, int, int);
void resultadoTest(int, int, infoRta_t []);
void progreso(int);
int finPrograma(void);


int main(void){
  int dificultad;
  int indice;
  int porcentaje;

  infoRta_t arrRespuestas[P];

  srand(time(NULL)); //set rand seed

  do{
    indice = 1;
    porcentaje = 0;
    printf(TITLE);
    dificultad = setDificultad();
    system(CLEAR);

    for (int i = 0; i < P; i++) {
      printf(TITLE);
      progreso(indice);
      arrRespuestas[i] = preg(indice, numRand(dificultad), numRand(dificultad));
      porcentaje += arrRespuestas[i].output;
      indice++;
      system(CLEAR);
    }
    resultadoTest(porcentaje, P, arrRespuestas);
    system(CLEAR);
  }while(finPrograma());

  return 0;
}


int numRand(int dificultad){
  return (rand()%(int)(pow(10, dificultad)));
}

int setDificultad(void){
  int seleccion;

  printf("Seleccione la dificultad\n\n");
  printf("1) Facíl\n");
  printf("2) Intermedio\n");
  printf("3) Avanzado\n");
  printf("\nOpción: ");
  
  do{
    scanf("%d", &seleccion);
    while(getchar() != '\n');
    if (seleccion != 1 && seleccion != 2 && seleccion != 3){
      printf("Error. Seleccione una opción valida: ");
    }
  }while(seleccion != 1 && seleccion != 2 && seleccion != 3);

  return seleccion;
}

infoRta_t preg(int ind, int num1, int num2){
  int rta;
  infoRta_t a;

  printf("%d)¿Cuanto es %dx%d? \n", ind, num1, num2);
  printf("Respuesta: ");
  scanf("%d", &rta);
  while(getchar() != '\n');

  a.indice = ind;
  a.rta = rta;
  a.num1 = num1;
  a.num2 = num2;
  a.rtaCorrecta = num1 * num2;
  a.output = num1 * num2 == rta ? 1 : 0;

 return a; 
}

void resultadoTest (int porcentaje, int p, infoRta_t a[]){
  printf("Resultados del test\n\n");
  printf("Respuestas correctas: %d de %d (%d%%)\n\n", porcentaje, P, (porcentaje*100)/P);

  if((porcentaje*100)/P < 75){
    printf("Pídale ayuda adicional a su maestro\n");
  }else{
    printf("¡Felicitaciones, está listo para pasar al siguiente nivel!\n");
  }

  if(porcentaje != p){
    printf("\nResumen de errores\n");
  }
  for (int i = 0; i < p; i++) {
    if(a[i].output == 0){
      printf("\nPregunta número %d\n", a[i].indice);  
      printf("\t¿Cuanto es %dx%d ?\n", a[i].num1, a[i].num2);
      printf("\tRespuesta ingresada: %d\n", a[i].rta);
      printf("\tRepuesta correcta: %d\n", a[i].rtaCorrecta);
    }
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

  system(CLEAR);
  return cent;
}
