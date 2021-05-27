#include<stdio.h>

int main(void){

  float var1;
  float var2;
  float output;
  char op;

  int cent;

  do {
    printf("~ Calculadora ~\n");
    printf("Ingrese los números y/o operaciones saparados por enter\n");
    
    scanf(" %f", &var1);

    do{
      scanf(" %c", &op);
      if(op != '+' && op != '-' && op != '*' && op != '/' ){
        printf("\nError. Ingrese una operación valida: ");
      }
    }while(op != '+' && op != '-' && op != '*' && op != '/' );
    
    scanf(" %f", &var2);
    
    switch(op){
      case '+' :
        output = var1 + var2;
        printf("\n[ Resultado: %f ]", output);
      break;
      
      case '-' :
        output = var1 - var2;
        printf("\n[ Resultado: %f ]", output);
      break;
      
      case '*' :
        output = var1 * var2;
        printf("\n[ Resultado: %f ]", output);
      break;
      
      case '/' :
        if(var2 != 0){
          output = var1 / var2;
          printf("\n[ Resultado: %f ]", output);
        }
        else{
          printf("\n[ Error ]\n");
        }
      break;
    }
    
    printf("\n\n* Fin del programa *\n");
    printf("Ingrese 0 si desea cerrar el programa, o ingrese 1 si desea volver a ejecutarlo: \n");
    do{
      scanf("%d", &cent);
      if(cent != 0 && cent != 1){
        printf("Ingrese un valor valido[1/0]: ");
      }
    }while(cent != 0 && cent != 1);
    
    printf("__________________________________________________\n\n"); 
  } while (cent == 1);

  return 0;
  }

