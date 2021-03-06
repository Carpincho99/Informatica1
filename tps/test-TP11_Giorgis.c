#include <stdio.h>

typedef union {
  float f;
  struct
  {
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } raw;
} myfloat;

void printBinary(int n, int i)
{
  int k;
  for (k = i - 1; k >= 0; k--) {

    if ((n >> k) & 1)
      printf("1");
    else
      printf("0");
  }
}

void printIEEE(myfloat var)
{
  printf("%d | ", var.raw.sign);
  printBinary(var.raw.exponent, 8);
  printf(" | ");
  printBinary(var.raw.mantissa, 23);
  printf("\n");
}


int main(void){

  myfloat real = {78};

  printIEEE(real);




  return 0;
}

