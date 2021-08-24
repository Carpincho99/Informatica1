#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  int arr[11] = {0};
  int sumDados;

  srand(time(NULL)); //set rand seed

  for (int i = 0; i < 36000; i++) {
    sumDados = (1+rand()%6) + (1+rand()%6);
    for (int j = 0; j < 11; j++) {
      if (sumDados == j+2) {
        arr[j]++; 
      } 
    }
  }

  printf("Valor   Cantidad de veces\n\n");
  for (int i = 0; i < 10; i++) {
    printf("%2d:%12d\n", i+2, arr[i]);
  }

  return 0;
}

