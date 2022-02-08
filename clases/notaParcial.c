#include <stdio.h>

int main(void){

  char *arr[3] = {"hola", "como", "estas"};

  printf("arr no imprime\n");
  printf("*arr: %s\n", *arr);
  printf("arr[0]: %s\n", arr[0]);
  printf("*&arr[0]: %s\n", *&arr[0]);

  printf("----------------\n");

  char ARR[3][5] = {"hola", "como", "estas"};

  printf("ARR no imprime \n");
  printf("*ARR: %s\n", *ARR);
  printf("ARR[0]: %s\n", ARR[0]);
  printf("*&ARR[0]: %s\n", *&ARR[0]);



  return 0;
}

