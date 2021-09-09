#include <stdio.h>

int factorial(int);

int main(void){
  int input;
  
  printf("Ingrese un número: ");
  scanf("%d", &input);
  printf("!%d = %d\n",input, factorial(input));

  return 0;
}

int factorial(int n){
  if(n == 0){
    return 1;
  }else{
    return n*factorial(n-1);
  }
}

