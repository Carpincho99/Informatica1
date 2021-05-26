#include<stdio.h>


int main(void){
  int input;
  int output;
  int cent;
  
  int unidad;
  int decena;
  int centena;
  int uMil;
  
 
  do{

    printf("~ Codificador de números ~\n\n");
    printf("Este programa codifica numeros de cuatro cifras.\n");
    printf("\nIngrese un número positivo entero de cuatros cifras: ");
    
    do{
      
      scanf("%d", &input);
      
      if(input > 9999 || input < 0){
        printf("\nError. Ingrese un número valido: ");
      }
     
    }while(input > 9999 || input < 0);
    
    //proceso de encriptado
    unidad = input % 10;
    decena = (input / 10) % 10;
    centena = (input / 100) % 10;
    uMil = (input / 1000) % 10;
    
    unidad = (unidad + 7) % 10;
    decena = (decena + 7) % 10; 
    centena = (centena + 7) % 10;
    uMil = (uMil + 7) % 10;
    
    //printf("%d%d%d%d", decena, unidad, uMil, decena);
    output =  decena*1000 + unidad*100 + uMil*10 + centena;
    
    printf("\n[ El encriptado de %d es: %d ]", input, output);
    
    //Fin del programa
    printf("\n\n*Fin del programa*\n");
    printf("Ingrese 0 si desea cerrar el programa");
    printf(" o ingrese 1 si desea volver a ejecutarlo: ");
    
    do{ 
      
      scanf("%d", &cent);
      
      if(cent != 1 && cent != 0){
        printf("\nIngrese una opción valida[1/0]: ");
      }
      
    }while(cent != 1 && cent != 0);
    
    
    printf("___________________________________________\n\n");
    
  }while(cent == 1);
  

  return 0;
  }

