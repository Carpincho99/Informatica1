#include <stdio.h>

typedef union{
  float real;
  int entero;
}floatVar_t;

unsigned int get_ieee_sign(unsigned);
unsigned int get_ieee_exp(unsigned);
unsigned int get_ieee_mantissa(unsigned);
void print_n_bits(unsigned, int);
void print_ieee(unsigned);

int main(void){
  floatVar_t f;

  printf("Ingrese un numero real: ");
  scanf(" %f", &f.real);

  print_ieee(f.entero);

  printf("Bit signo: %d", get_ieee_sign(f.entero)); 
  printf(" (%d)\n", get_ieee_sign(f.entero));

  printf("Bit del exponente: "); 
  print_n_bits(get_ieee_exp(f.entero), 8);
  printf(" (%d)\n", get_ieee_exp(f.entero));

  printf("Bit de la mantisa: "); 
  print_n_bits(get_ieee_mantissa(f.entero), 23);
  printf(" (%d)\n", get_ieee_mantissa(f.entero));

  return 0;
}

unsigned int get_ieee_sign(unsigned entero){
  return entero>>31;
}

unsigned int get_ieee_exp(unsigned entero){
  return (entero<<1)>>24;
}

unsigned int get_ieee_mantissa(unsigned entero){
  return (entero<<9)>>9;
}

void print_n_bits(unsigned num, int n){
  unsigned mask = 1<<(n-1);

  for (int i = 0; i < n; i++) {
    printf("%d", num & mask ? 1 : 0);
    mask >>= 1;
  }
}

void print_ieee(unsigned entero){
  printf("\n");
  printf("%d", get_ieee_sign(entero)); 
  print_n_bits(get_ieee_exp(entero), 8);
  print_n_bits(get_ieee_mantissa(entero), 23);
  printf("\n\n");
}

