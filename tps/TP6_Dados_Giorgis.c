#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define M 36000 //Cantidad de lanzamientos

int lanzarDados (void);
void cargarArr (int[], int);
void printArr (int[]);

int main(void){
  int arr[11] = {0};
  int sumDados;

  srand(time(NULL)); //set rand seed

  for (int i = 0; i < M; i++) {
    sumDados = lanzarDados() + lanzarDados();
    cargarArr(arr, sumDados);    
  }

  printArr(arr);

  return 0;
}


int lanzarDados(void){
  return (1+rand()%6);
}

void cargarArr(int arr[], int sumDados) {
  for (int j = 0; j < 11; j++) {
    if (sumDados == j+2) {
      arr[j]++; 
    } 
  }
}

void printArr(int arr[]) {
  printf("Valor   Cantidad de veces\n\n");
  for (int i = 0; i < 11; i++) {
    printf("%2d:%12d\n", i+2, arr[i]);
  }
}
