#include<stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else
#define CLEAR "clear" 
#endif


int main(void){
  int gerente;
  int output;
  int selec;
  char enter;
  char c;


  printf("Calculadora Pago Semanal\n\n");
  printf("Ingrese el salario correspondiente a los gerentes: $");
  scanf(" %d", &gerente);
  system(CLEAR);

  printf("Calculadora Pago Semanal\n\n");
  printf("Eliga el codigo correspondiente\n\n");
  printf("\t1) Gerentes\n");
  printf("\t2) Trabajador por hora\n");
  printf("\t3) Trabajador de comisión\n");
  printf("\t4) Trabajadores a destajo\n\n");
  printf("Selección: ");

  do {
    scanf(" %d", &selec);
    //if (selec == 1 || selec == 2 || selec == 3 || selec == 4) {
      system(CLEAR);
      while((c = getchar()) != '\n' && (c = getchar()) != '\r' );
    //}

    switch(selec){
      case 1:
        printf("Salario gerentes: $%d\n\n", gerente);
        printf("[Pulse enter para volver al menú]");

        while( enter != '\n' && enter != '\r' ){
          printf("working?\n");
          enter = getchar();
        }

        break;

      case 2:

        break;

      case 3:

        break;

      case 4:

        break;

      case 0:
        break;

      default:
        printf("Ingrese un valor valido: ");
    }

  }while (selec != 0);

  return 0;

}

