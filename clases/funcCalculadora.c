#include<stdio.h>

float suma(float, float);
float resta(float, float);
float mult(float, float);
float div(float, float);
void calc(float, float, char);

int main(void){
  float x;
  float y;
  char op;

  printf("Caculadora\n\n");
  scanf("%f%c%f", &x, &op, &y);

  calc(x, y, op);

  return 0;
}


void calc(float x, float y, char op){
  float resultado;
  int validar = 1;

  switch(op){
    case '+':
      resultado = suma(x, y);
      break;
    case '-':
      resultado = resta(x, y);
      break;
    case '*':
      resultado = mult(x, y);
      break;
    case '/':
      if (y == 0 && x == 0) { 
        validar = 0;
      }
      resultado = div(x, y);
      break;
    default:
      validar = 0;
  }

  if (validar) {
    printf("=%.2f\n", resultado);
  }else{
    printf("Operación no valida\n");
  }

}

float suma(float x, float y){
  return x+y;
}

float resta(float x, float y){
  return x-y;
}

float mult(float x, float y){
  return x*y;
}

float div(float x, float y){
  return x/y;
}
