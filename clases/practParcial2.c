#include<stdio.h>

#define N 10

int main(void){
  int arr[N] = {4,9,1,2,3,7,5,6,8,0};
  int tmp;
  int busqueda = 0;
  int resultado[10] = {0};
  int k = 0;

  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N-1-i; j++) {
      if (arr[j] < arr[j+1]) {
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");

  if (busqueda != 0) {
    for (int i = 0; i < N; i++) {
      if (busqueda == arr[i]) {
        resultado[k++] = i;
      }
    }
    for (int i = 0; i < N; i++) {
      if (resultado[i] != 0) {
        printf("posicion %d \n", resultado[i]);
      }
    }
    printf("\n");


  }else{
    for (int i = 0; i < N; i++) {
      resultado[i] = -1;
    }
    for (int i = 0; i < N; i++) {
      if (busqueda == arr[i]) {
        resultado[k++] = i;
      }
    }
    for (int i = 0; i < N; i++) {
      if (resultado[i] != -1) {
        printf("posicion %d \n", resultado[i]);
      }
    }
    printf("\n");


  }


  return 0;
}

