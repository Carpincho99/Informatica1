#include<stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else
#define CLEAR "clear" 
#endif

#define N 3

int main(void){
  int matriz[N][N+1] = {0};
  int tmp;
  char incog[N]; 


  for (int i = 0; i < N; i++) {
    incog[i] = 65 + i; //ASCII
  }



//Carga matriz

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
//-----------------------------------------------------------
      system(CLEAR);
      printf("Calculadora de sistemas de ecuaciones lineales\n\n\n");
      printf("Sistema:\n");

      for (int I = 0; I < N; I++) {
        printf("|");
        for (int J = 0; J <= N; J++) {
          if (J != N+1-1) {
            printf("\t%c%d.%c", matriz[I][J] < 0 ? 00 : '+', matriz[I][J], incog[J]); 
          }
          else{
            printf("\t  = %-5d ", matriz[I][J]); 
          }
        } 
        printf("|\n");
      }
//-----------------------------------------------------------

      printf("\nIngrese el elemento %d;%d: ", i+1, j+1); 
      scanf("%d", &matriz[i][j]);
    }
  }


  system(CLEAR);
  printf("Calculadora de sistemas de ecuaciones lineales\n\n\n");
  printf("Sistema:\n");

  for (int I = 0; I < N; I++) {
    printf("|");
    for (int J = 0; J <= N; J++) {
      if (J != N+1-1) {
        printf("\t%c%d.%c", matriz[I][J] < 0 ? 00 : '+', matriz[I][J], incog[J]); 
      }
      else{
        printf("\t  = %-5d ", matriz[I][J]); 
      }
    } 
    printf("|\n");
  }

  printf("\n\nMatriz ampliada:\n");

  for (int I = 0; I < N; I++) {
    printf("|");
    for (int J = 0; J <= N; J++) {
        printf("%5d", matriz[I][J]); 
    } 
    printf("|\n");
  }

//Proceso Gauss-Jordan

  for (int i = 0; i < N; ++i) {

    tmp = matriz[i][i];
    for (int j = 0; j <= N; ++j) {
      matriz[i][j] /= tmp;
    }

//  for (int I = 0; I < N; ++I) {
//    tmp = matriz[I][i];
//    for (int j = 0; j <= N; ++j) {
//      matriz[I][j] -= tmp * matriz[i][j]; 
//    }
//  }


  }

  printf("Resultado: \n");
  for (int I = 0; I < N; I++) {
    printf("|");
    for (int J = 0; J <= N; J++) {
      if (J != N+1-1) {
        printf("\t%c%d.%c", matriz[I][J] < 0 ? 00 : '+', matriz[I][J], incog[J]); 
      }
      else{
        printf("\t  = %-5d ", matriz[I][J]); 
      }
    } 
    printf("|\n");
  }


  return 0;
}

