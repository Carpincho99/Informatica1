#include<stdio.h>
#include <stdlib.h>
#if defined(_WIN32) || defined(_WIN64)
  #define clear cls
#endif

int main(void){
  int CP, CA, CF, CB, C_OTRO;
  float iCP, iCA, iCF, iCB, iC_OTRO;
  char op;

  CP = CA = CF = CB = C_OTRO = 0;
  iCP = iCA = iCF = iCB = iC_OTRO = 0;



  do {
    printf("Administrador de productos - MiniMercado\n\n");

    printf("+---------------------------------------------------------+\n");
    printf(" Descripción\tCódigo\tCantidad\tImporte\n");
    printf(" \t\t\t\t\t\t\t \n");
    printf(" Panadería\t   1\t   %d\t\t$%.2f\n", CP, iCP);
    printf(" Almacen\t   2\t   %d\t\t$%.2f\n", CA, iCA);
    printf(" Frescos\t   3\t   %d\t\t$%.2f\n", CF, iCF);
    printf(" Bazar\t\t   4\t   %d\t\t$%.2f\n", CB, iCB);
    printf(" Otros\t\t   5\t   %d\t\t$%.2f\n", C_OTRO, iC_OTRO);
    printf("+---------------------------------------------------------+\n\n");

    printf("Operaciones\n");
    printf("\t Ingrese el codigo del producto para adicionar stock.\n");
    printf("\t Ingrese \"i\" para registrar importes.\n");
    printf("\t Ingrese \"q\" para salir.\n");
    printf("Selección: ");
    scanf("  %c", &op);

    switch(op){
      case '1': CP++;
        printf("\n");
        system("clear");
      break;

      case '2': CA++;
        printf("\n");
        system("clear");
       break;

      case '3': CF++;
        printf("\n");
        system("clear");
      break;

      case '4': CB++;
        printf("\n");
        system("clear");
      break;

      case '5': C_OTRO++;
        printf("\n");
        system("clear");
      break;

      case 'i':
        do{
          printf("\nIngrese los importes correspondientes a cada producto:\n");
          printf("\tPanadería: $");
          scanf("%f",&iCP);
          printf("\tAlmacen: $");
          scanf("%f",&iCA);
          printf("\tFrescos: $");
          scanf("%f",&iCF);
          printf("\tBazar: $");
          scanf("%f",&iCB);
          printf("\tOtros: $");
          scanf("%f",&iC_OTRO);
          
          if(iCP<0 || iCA<0 || iCF<0 || CB<0 || iC_OTRO<0){
           printf("\nHa ingresado un importe negativo, vuelva a ingresar los valors.\n");
          }
        system("clear");
        
        }while(iCP<0 || iCA<0 || iCF<0 || CB<0 || iC_OTRO<0); 
      break;

      case 'q':
      break;

      default: 
        system("clear");
      break;
    }

  } while (op != 'q');   

  return 0; 
}

