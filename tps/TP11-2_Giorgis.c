#include <stdio.h>

typedef union{
  float real;
  struct{
    unsigned mantissa:23;
    unsigned exp:8;
    unsigned signo:1;
  }bits_t;
}floatVar_t;

unsigned int get_ieee_sign(float);
unsigned int get_ieee_exp(float);
unsigned int get_ieee_mantissa(float);
void print_n_bits(unsigned, int);
void print_ieee(float);

int main(void){
  float f;

  printf("Ingrese un numero real: ");
  scanf("%f", &f);

  print_ieee(f);

  printf("Bit signo: "); 
  print_n_bits(get_ieee_sign(f), 1);
  printf(" (%d)\n", get_ieee_sign(f));

  printf("Bit del exponente: "); 
  print_n_bits(get_ieee_exp(f), 8);
  printf(" (%d)\n", get_ieee_exp(f));

  printf("Bit de la mantisa: "); 
  print_n_bits(get_ieee_mantissa(f), 23);
  printf(" (%d)\n", get_ieee_mantissa(f));

  return 0;
}

unsigned int get_ieee_sign(float f){
  floatVar_t F = {.real = f};
  return F.bits_t.signo;
}

unsigned int get_ieee_exp(float f){
  floatVar_t F = {.real = f};
  return F.bits_t.exp;
}

unsigned int get_ieee_mantissa(float f){
  floatVar_t F = {.real = f};
  return F.bits_t.mantissa;
}

void print_n_bits(unsigned num, int n){
  unsigned mask = 1<<(n-1);

  for (int i = 0; i < n; i++) {
    printf("%d", num & mask ? 1 : 0);
    mask >>= 1;
  }
}

void print_ieee(float f){
  printf("\n");
  print_n_bits(get_ieee_sign(f), 1);
  print_n_bits(get_ieee_exp(f), 8);
  print_n_bits(get_ieee_mantissa(f), 23);
  printf("\n\n");
}
