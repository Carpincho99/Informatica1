#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define M 36000 //Cantidad de lanzamientos

int lanzarDados (void);
void printArr (int[]);

int main(void){
  int arr[11] = {0};
  int sumDados;

  srand(time(NULL)); //set rand seed

  for (int i = 0; i < M; i++) {
    sumDados = lanzarDados() + lanzarDados();
    arr[sumDados-2]++; 
  }

  printArr(arr);

  return 0;
}


int lanzarDados(void){
  return (1+rand()%6);
}

void printArr(int arr[]) {
  printf("Valor   Cantidad de veces   Porcentaje\n\n");
  for (int i = 0; i < 11; i++) {
    printf("%2d:%15d%18.2f%%\n", i+2, arr[i], (arr[i]*100.0)/M);
  }
}
