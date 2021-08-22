#include<stdio.h>

#define N 10
int main(void){
  int arr[N] = {4,9,1,2,3,7,5,6,8,0};
  int mayor;
  int tmp;
  int mayor_i;

  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < N-1; i++) {
    mayor = arr[i];
    mayor_i = i;
    for (int j = i; j < N; j++) {
      if (arr[j] > arr[mayor_i]) {
        mayor = arr[j];  
        mayor_i = j;
      }
    }
    tmp = arr[i];
    arr[i] = arr[mayor_i];
    arr[mayor_i] = tmp;
    
  }

  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");

  int inicial = 0, final = N, medio;
  int busqueda = 5;

  while(inicial <= final){
    medio = (inicial + final) / 2;

    if(busqueda == arr[medio]){
      printf("Posicion %d\n", medio);
    }

    if (busqueda < arr[medio]) {
      inicial = medio + 1;
    }else{
      final = medio - 1;
    }


  }

  return 0;
}

