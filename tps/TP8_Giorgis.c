#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define N 10 //número de encuestados

int validarInput(void);
void calificar(char *[], int [5][N]);
void calcPromedio(float [5], int [5][N]);
int mejorPuntuado(float []);
int peorPuntuado(float []);
int sumPuntos(int, int [5][N]);
void printMejorPuntuado(float [], int [5][N], char *[]);
void printPeorPuntuado(float [], int [5][N], char *[]);
void printTable(char *[], int [5][N]);


int main(void){
  char *causas[5] = {"Inflación", "Política sanitaria", "Urbanización", "Generación de empleo", "Educación"};
  int rtas[5][N];

  calificar(causas, rtas);
  printTable(causas, rtas);

  return 0;
}


void calificar(char *causas[], int rtas[5][N]){
  int calificacion;

  for (int i = 0; i < N; ++i) {
    printf("Califique las siguientes cuestiones socio-ambientales según el nivel de importancia del 1 al 10\n");
    printf("(1 poco importante, 10 muy importante)\n\n");
    printf("Sujeto %d\n\n", i+1);
    for (int j = 0; j < 5; ++j) {
      printf("%s: ", *(causas+j));  

      calificacion = validarInput();
      rtas[j][i] = calificacion;
    }    
    system(CLEAR);
  }
}


int validarInput(){
  int calificacion;

  do{
    scanf("%d", &calificacion);
    while(getchar() != '\n');
    if (calificacion < 1 || calificacion > 10) {
      printf("Error. Ingrese un valor valido [1 a 10]: ");
    }
  }while(calificacion < 1 || calificacion > 10);

  return calificacion;
}

void calcPromedio(float promedio[5], int rtas[5][N]){
  for (int i= 0; i < 5; i++){
    for (int j = 0; j < N; ++j) {
      promedio[i] += rtas[i][j];
    }
    promedio[i] /= N;
  }
}

void printTable(char *causas[], int rtas[5][N]){
  float promedio[5] = {0};
  calcPromedio(promedio, rtas);

  printf("+---------------------------------------------------------------------+\n");
  printf("%-30s", "| Temáticas/Sujeto");
  for (int i = 0; i < N; ++i) {
    printf("%3d", i+1);  
  }
  printf("  Promedio");
  printf("\n+---------------------------------------------------------------------+\n");
  for (int j = 0; j < 5; ++j) {
    printf("| %-30s", causas[j]);
    for (int i = 0; i < N; ++i) {
      printf("%-3d",  rtas[j][i]);
    }
    printf("%-3.2f\n", promedio[j]);
  }
  printf("+---------------------------------------------------------------------+\n\n");
  printMejorPuntuado(promedio, rtas, causas);
  printPeorPuntuado(promedio, rtas, causas);
}

int mejorPuntuado(float promedio[]){
  int max = 0;
  for (int i = 0; i < 5; ++i) {
    if (promedio[i] > promedio[max]) {
      max = i;
    }
  }
  return max;
}

int peorPuntuado(float promedio[]){
  int min = 0;
  for (int i = 0; i < 5; ++i) {
    if (promedio[i] < promedio[min]) {
      min = i;
    }
  }
  return min;
}

int sumPuntos(int ind, int rtas[5][N]){
  int sumatoria = 0;
  for (int i = 0; i < N; ++i) {
    sumatoria += rtas[ind][i];
  }
  return sumatoria;
}

void printMejorPuntuado(float promedio[], int rtas[5][N], char *causas[]){
  int indice;
  indice = mejorPuntuado(promedio);

  printf("Problemática mejor puntuada: %s", causas[indice]);
  printf("; Total de puntos: %d\n", sumPuntos(indice, rtas));
}

void printPeorPuntuado(float promedio[], int rtas[5][N], char *causas[]){
  int indice;
  indice = peorPuntuado(promedio);

  printf("Problemática peor puntuada: %s", causas[indice]);
  printf("; Total de puntos: %d\n", sumPuntos(indice, rtas));
}

