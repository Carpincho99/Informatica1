#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define TITLE "Aprenda a multiplicar v5.0\n\n"
#define P 3 //cantidad de preguntas
#define Q 5 //cantidad de operaciones en opcion combinada
#define PROGRESS_BAR_WIDHT 12*P

int numRand(int);
int setOperacion(void);
int setDificultad(void);
int preg(int, int, int, int);
int pregCombinada(int, int, int);
void resultadoTest(int, int);
void progreso(int);
int finPrograma(void);

int suma(int, int);
int resta(int, int);
int mult(int, int);

int main(void){
  int operacion;
  int dificultad;
  int indice;
  int porcentaje;

  srand(time(NULL)); //set rand seed

  do{
    indice = 1;
    porcentaje = 0;
    printf(TITLE);
    operacion = setOperacion();
    system(CLEAR);
    printf(TITLE);
    dificultad = setDificultad();
    system(CLEAR);

    for (int i = 0; i < P; i++) {
      printf(TITLE);
      progreso(indice);

      if(operacion == 3){
        porcentaje += pregCombinada(indice, Q, dificultad);
      }else{
        porcentaje += preg(indice, numRand(dificultad), numRand(dificultad), operacion);
      }

      indice++;
      system(CLEAR);
    }

    resultadoTest(porcentaje, P);
    system(CLEAR);
  }while(finPrograma());

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
  printf("4) Combinado\n");
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
      printf("Error. Seleccione una opción valida: ");
    }
  }while(seleccion != 1 && seleccion != 2 && seleccion != 3);

  return seleccion;
}

int preg(int ind, int num1, int num2, int op){
  int rta;
  char simbolos[3] = {'+','-','*'};

  int (*p[3]) (int, int);
  p[0] = suma;
  p[1] = resta;
  p[2] = mult;

  printf("%d)¿Cuanto es %d%c%d? \n", ind, num1, simbolos[op], num2);
  printf("Respuesta: ");
  scanf("%d", &rta);
  while(getchar() != '\n');

  if((*p[op]) (num1, num2) == rta){
    return 1;
  }else{
    return 0;
  }

}

int pregCombinada(int ind, int q, int dificultad){
  int rta;
  int num[q];
  int op[q];
  char simbolos[3] = {'+','-','*'};

  int (*p[3]) (int, int);
  p[0] = suma;
  p[1] = resta;
  p[2] = mult;

  for (int i = 0; i < q; i++) {   //generar operaciones y numeros
    op[i] = rand()%3;
    num[i] = numRand(dificultad);
  }

  printf("%d)¿Cuanto es ", ind); 
  printf("%d", num[0]);
  for (int i = 1; i < q; i++) {
    printf(" %c %d", simbolos[op[i]], num[i]);
  }
  printf("?\n");

  for (int i = 1; i < q; i++) {   //realizar las multiplicaciones primero
    if(op[i] == 2){
      num[i] = (*p[op[i]]) (num[i-1], num[i]); 
      if(op[i-1] == 1 && i != 1){
        num[i] *= -1;
      }
      num[i-1] = 0;
      op[i] = 0;
    } 
  }

  for (int i = 1; i < q; i++) {   //sumatoria total
    num[0] =+ (*p[op[i]]) (num[0], num[i]);
  }

  printf("Respuesta: ");
  scanf("%d", &rta);
  while(getchar() != '\n');

  if(num[0] == rta){
    return 1;
  }else{
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

int suma (int num1, int num2){
  return num1 + num2;
}

int resta (int num1, int num2){
  return num1 - num2;
}

int mult (int num1, int num2){
  return num1 * num2;
}
