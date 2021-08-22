#include<stdio.h>

int main(void){
  int busqueda = 1;
  int j=0;
  int encontrados[10] = {0}; 
  int arr[10] = {5,4,1,8,9,1,3,6,2};

  for (int i = 0; i < 10; i++) {
    printf("  %d", arr[i]);
  }

  for (int i = 0; i < 10; i++) {
    if (busqueda == arr[i]) {
      encontrados[j] = i;
      j++;
    }
  }

  printf("\n");
  for (int i = 0; i < 10; i++) {
    if (encontrados[i] != 0) {
      printf("  %d", encontrados[i]);
    }
  }


  return 0;
}

