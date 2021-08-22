#include<stdio.h>

#define N 12

int main(void){
  int arr[N] = {0};
  int contador = 0;
  int max;
  int bolean = 0;

  for (int i = 0; i < N; i++) {
    printf("Ingrese el elemento %d:", i+1);
    do{
      scanf("%d", &arr[i]);
      if (arr[i] < 0 || arr[i] > 100) {
        printf("Error. Ingrese un número entre 0 y 100:\n");
      }
    }while(arr[i] < 0 || arr[i] > 100);
  }

  printf("\n");
  //fila
  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
  }

  printf("\n\n");
  //3filas-4columnas
  for (int i = 0; i < 3; i++) {
    printf("|");
    for (int j = 0; j < 4; j++) {
      printf("%5d", arr[i]);
    }
    printf("|\n");
  }


  printf("\n\n");
  //4col-3filas
  for (int i = 0; i < 4; i++) {
    printf("|");
    for (int j = 0; j < 3; j++) {
      printf("%5d", arr[i]);
    }
    printf("|\n");
  }



  for (int i = 0; i < N; i++) {
    if ((arr[i]%2) == 0) {
      printf("\n%d es par", arr[i]);
      contador++;
    }
  }
  printf("Hay %d pares\n", contador);

  max = arr[0];

  for (int i = 0; i < N; i++) {
    if (45 == arr[i]) {
      bolean = 1;
    }
  }

  if (bolean) {
    for (int i = 0; i < N; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
  }else{
    for (int i = 0; i < N; i++) {
      if (arr[i] < max) {
        max = arr[i];
      }
    }
  }

  printf("\n%s%d",bolean == 1?"maximo":"minimo:", max);

  return 0;
}

