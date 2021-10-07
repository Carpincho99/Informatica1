#include <stdio.h>

typedef struct infoRta{
  int indice;
  int rta;
  int rtaCorrecta;
}infoRta;

infoRta preg(int ind, infoRta a){
  int rta;
  int rtaCorrecta = 2;

  scanf("%d", &rta);

  a.indice = ind;
  a.rta = rta;
  a.rtaCorrecta = rtaCorrecta;

  return a;
}

int main(void){
  infoRta arrRespuestas[3];

  printf("Hola\n");

  for (int i = 0; i < 3; i++) {
    arrRespuestas[i] = preg(1, arrRespuestas[i]);  
  }

  for (int i = 0; i < 3; i++) {
    printf("%d\n", arrRespuestas[i].rta);
  }


  return 0;
}


