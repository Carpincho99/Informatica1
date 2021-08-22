#include<stdio.h>

int main(void){
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  int busqueda = 7;
  int final, inicial, medio;
  int i = -1;

  inicial = 0;
  final = 10-1;

  while(inicial <= final){
    medio = (inicial + final) / 2;

    if(busqueda == arr[medio]){
      i = medio;
      break;
    }

    if (busqueda > arr[medio]) {
      inicial = medio+1;
    }else{
      final = medio-1;
    }

  }

  if (i!=-1) {
    printf("esta en %d\n", i);
  }else{
    printf("No se encontro\n");
  }


    return 0;
}

