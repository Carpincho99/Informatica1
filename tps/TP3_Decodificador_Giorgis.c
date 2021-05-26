#include<stdio.h>


int main(void){
  int input;
  int output;
  
  int unidad;
  int decena;
  int centena;
  int uMil;
  
  int cent;

  do{
    printf("~ Decodificador de números  ~\n\n");
    printf("Ingrese el número codificado: ");  
    do{
      
      scanf("%d", &input);
      if(input > 9999){
        printf("\nError. Ingrese un número de hasta cuatro cifras: ");
      }
      if(input < 0){
        printf("\nError. Ingrese un número entero: ");
      }

    }while(input > 9999 || input < 0);
    
    //proceso de desencriptado
    unidad = input % 10;
    decena = (input / 10) % 10;
    centena = (input / 100) % 10;
    uMil = (input / 1000) %10;
    
    unidad = ((unidad + 3) % 10); 
    decena = ((decena + 3) % 10);
    centena = ((centena + 3) % 10);   
    uMil = ((uMil + 3) % 10);
    
    //printf (%d%d%d%d, decena, unidad, uMil, decena);
    output = decena*1000 + unidad*100 + uMil*10 + centena;
    
    printf("\n[ El número desencriptado es: %d ]", output);
    
    //Fin del programa
    printf("\n\n*Fin del programa*\n");   
    printf("Ingrese 0 si desea cerrar cerrar el programa");
    printf(" o ingrese 1 si desea volver a ejecutarlo: ");
    do{
      
      scanf("%d", &cent);
      
      if(cent != 1 && cent != 0){
        printf("\nIngrese un valor valido [1/0]: ");
      }

    }while(cent != 1 && cent != 0);
    
    printf("________________________________\n\n");
  }while(cent == 1);

  return 0;
  }

