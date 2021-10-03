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

int numRand(int);
int setOperacion(void);
int setDificultad(void);
int preg(int, int *, int, int, char);
void resultadoTest(int, int);
void progreso(int);
int finPrograma(void);

int suma(int, int);
int resta(int, int);
int mult(int, int);
int aleatorio(int, int);

int (*op[4])(int, int);

int main(void){
  int operacion;
  int dificultad;
  int indice;
  int porcentaje;

  char *simbolos[3] = {"+","-","*"};
  simbolos[3] = malloc(sizeof (char));

  op[0] = suma;
  op[1] = resta;
  op[2] = mult;
  op[3] = aleatorio;

  srand(time(NULL)); //set rand seed

  do{
    indice = 1;
    porcentaje = 0;

    system(CLEAR);
    printf(TITLE);
    operacion = setOperacion();
    system(CLEAR);

    printf(TITLE);
    dificultad = setDificultad();
    system(CLEAR);

   for (int i = 0; i < P; i++) {
      printf(TITLE);
      progreso(indice);
      porcentaje += preg((op[operacion]()), numRand(dificultad), numRand(dificultad), simbolos[]);
      indice++;
      system(CLEAR);
    }
    resultadoTest(porcentaje, P);
    system(CLEAR);
  }while(finPrograma());

  free(simbolos[3]);

  return 0;
}


int numRand(int dificultad){
  return (rand()%(int)(pow(10, dificultad)));
}

int setOperacion(void){
  int seleccion;

  printf("Seleccione la dificulta\n\n");
  printf("1) Suma\n");
  printf("2) Resta\n");
  printf("3) Multiplicacion\n");
  printf("4) Aleatorio\n");
  printf("\nOpción: ");

  do{
    scanf("%d", &seleccion);
    while(getchar() != '\n');
    if (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4){
      printf("\nError. Seleccione una seleccionción valida: ");
    }
  }while(seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4);

return seleccion-1;
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
      printf("\nError. Seleccione una opción valida: ");
    }
  }while(seleccion != 1 && seleccion != 2 && seleccion != 3);

  return seleccion;
}

int preg(int ind, int (*p) (int, int), int num1, int num2, char simbolo){
  int rta;

  printf("%d)¿Cuanto es %d%c%d? \n", ind, num1, simbolo,  num2);
  printf("Respuesta: ");
  scanf("%d", &rta);
  while(getchar() != '\n');

  if(rta == (*p)(num1, num2)){
    return 1;
  }else {
    return 0;
  }
}

void resultadoTest (int porcentaje, int p){
  printf("Resultados del test\n\n");
  printf("Respuestas correctas: %d de %d (%d%%)\n\n", porcentaje, P, (porcentaje*100)/P);

  if((porcentaje*100)/P < 75){
    printf("Pídale ayuda adicional a su maestro\n");
  }else{
    printf("¡Felicitaciones, está listo para pasar al siguiente nivel!\n");
  }

  printf("\n[Pulse enter para continuar...]\n");
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


int suma(int num1, int num2){
 return num1 + num2; 
}
int resta(int num1, int num2){
 return num1 + num2; 
}
int mult(int num1, int num2){
 return num1 + num2; 
}
int aleatorio(int num1, int num2, int indice){
  return (*op[rand()%3])(num1, num2, indice);
}
