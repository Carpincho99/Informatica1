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

typedef struct infoRta{
  int indice;
  int num[Q];
  int op[Q];
  int rta;
  int rtaCorrecta;
  int output; // rta acertada = 1, rta incorrecta = 0;
}infoRta_t;

int numRand(int);
int setOperacion(void);
int setDificultad(void);
infoRta_t preg(int, int, int, int);
infoRta_t pregCombinada(int, int, int);
void resultadoTest(int, int, int, int, infoRta_t []);
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

  infoRta_t arrRespuestas[P];

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
        arrRespuestas[i] = pregCombinada(indice, Q, dificultad);
        porcentaje += arrRespuestas[i].output;
      }else{
        arrRespuestas[i] = preg(indice, numRand(dificultad), numRand(dificultad), operacion);
        porcentaje += arrRespuestas[i].output;
      }

      indice++;
      system(CLEAR);
    }

    resultadoTest(porcentaje, P, Q, operacion,  arrRespuestas);
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

infoRta_t preg(int ind, int num1, int num2, int op){
  int rta;
  char simbolos[3] = {'+','-','*'};
  infoRta_t a;

  int (*p[3]) (int, int);
  p[0] = suma;
  p[1] = resta;
  p[2] = mult;

  printf("%d)¿Cuanto es %d%c%d? \n", ind, num1, simbolos[op], num2);
  printf("Respuesta: ");
  scanf("%d", &rta);
  while(getchar() != '\n');

  a.indice = ind;
  a.rta = rta;
  a.num[0] = num1;
  a.num[1] = num2;
  a.rtaCorrecta = (*p[op]) (num1, num2);
  a.output = (*p[op]) (num1, num2) == rta ? 1 : 0;

  return a;
}

infoRta_t pregCombinada(int ind, int q, int dificultad){
  int rta;
  int num[q];
  int op[q];
  char simbolos[3] = {'+','-','*'};
  infoRta_t a;

  int (*p[3]) (int, int);
  p[0] = suma;
  p[1] = resta;
  p[2] = mult;

  for (int i = 0; i < q; i++) {   //generar operaciones y numeros
    op[i] = rand()%3;
    num[i] = numRand(dificultad);
  }

  for (int i = 0; i < q; i++) {   //Save info
    a.num[i] = num[i];
    a.op[i] = op[i];
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
      op[i] = 0;  //suma
    } 
  }

  for (int i = 1; i < q; i++) {   //sumatoria total
    num[0] =+ (*p[op[i]]) (num[0], num[i]);
  }

  printf("Respuesta: ");
  scanf("%d", &rta);
  while(getchar() != '\n');

  a.indice = ind;
  a.rta = rta;
  a.rtaCorrecta = num[0];
  a.output = num[0] == rta ? 1 : 0;

  return a;

}

void resultadoTest (int porcentaje, int p, int q, int op, infoRta_t a[]){
  char simbolos[3] = {'+','-','*'};

  printf("Resultados del test\n\n");
  printf("Respuestas correctas: %d de %d (%d%%)\n\n", porcentaje, P, (porcentaje*100)/P);

  if((porcentaje*100)/P < 75){
    printf("Pídale ayuda adicional a su maestro\n");
  }else{
    printf("¡Felicitaciones, está listo para pasar al siguiente nivel!\n");
  }

  if(porcentaje != p){
    printf("\nResumen errores\n");
  }

  if(op == 3){
    for (int i = 0; i < p; i++) {
      if(a[i].output == 0){
        printf("\nPregunta número %d\n", a[i].indice);  
        printf("\t¿Cuanto es "); 
        printf("%d", a[i].num[0]);
        for (int j = 1; j < q; j++) {
          printf(" %c %d", simbolos[a[i].op[j]], a[i].num[j]);
        }
        printf("?\n");
        printf("\tRespuesta ingresada: %d\n", a[i].rta);
        printf("\tRepuesta correcta: %d\n", a[i].rtaCorrecta);
      }
    }
  }else{
    for (int i = 0; i < p; i++) {
      if(a[i].output == 0){
        printf("\nPregunta número %d\n", a[i].indice);  
        printf("\t¿Cuanto es %d%c%d ?\n", a[i].num[0], simbolos[op], a[i].num[1]);
        printf("\tRespuesta ingresada: %d\n", a[i].rta);
        printf("\tRepuesta correcta: %d\n", a[i].rtaCorrecta);
      }
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

int suma (int num1, int num2){
  return num1 + num2;
}

int resta (int num1, int num2){
  return num1 - num2;
}

int mult (int num1, int num2){
  return num1 * num2;
}
