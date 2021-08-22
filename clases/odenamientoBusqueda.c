#include<stdio.h>

#define N 10

int main(void){
  int arr[N] = {4,5,8,6,6,1,2,3,9,10}; 
  int tmp;
  int busqueda = 6;
  //int resultado[N] = {0};
  int min;
  int min_i;
  int k = 0;

  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
  }

  for (int i = 0; i < 10-1; i++) {
    min = arr[i];
    min_i = i;
    for (int j = i+1; j < 10; j++) {
      if (arr[j] < min) {
        min = arr[j];
        min_i = j;
      }
    }

    tmp = arr[min_i];
    arr[min_i] = arr[i];
    arr[i] = tmp;
    
  }
  

  //ordenamiento burbuja mejorada
  /*
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N-1-i; j++) {
      if (arr[j] > arr[j+1]) {
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }  
  }
  */

  printf("\n");
  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
  }

  //busqueda lineal
  /*
  for (int i = 0; i < N; i++) {
    if (arr[i] == busqueda) {
      resultado[j++] = i;
    }  
  }

  printf("\n");
  for (int i = 0; i < N; i++) {
    if (resultado[i] != 0) {
      printf("%d", resultado[i]);
    }
  }
  */

  //busqueda binaria
  int inicio = 0;
  int final = N;
  int medio;

 
  while(inicio <= final){
    medio = (inicio + final) / 2;
    
    if (arr[medio] == busqueda) {
      printf("\nPosicion: %d", medio);
      break;
    }

    if (busqueda > arr[medio]) {
      inicio = medio + 1;
    }else{
      final = medio - 1;
    }

  }


  return 0;
}

