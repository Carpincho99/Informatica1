#include <stdio.h>

#define N 5

int busqueda (int, int*, int);

int main(void){
  int arr[N] = {91661, 65211, 87212, 28911};
  int clave = 87212; 
  int *ptArr;

  ptArr = arr;

  printf("Posicion: %d", busqueda(clave, ptArr, N));

  return 0;
}

int busqueda (int clave, int *p, int n){
  int rta = -1;
  for (int i = 0; i < n; i++) {
    if(*(p+i) == clave){
      rta = i;
      break;
    }
  }
  return rta;
}
