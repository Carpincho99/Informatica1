#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

typedef struct cliente{
  int cuenta;
  char nombre[80];
  int balance;
}cliente_t;

void load(FILE *fp){
  cliente_t cliente;
  printf("Ingrese nº cuenta, nombre y balance\n");

  scanf("%d %s %d", &cliente.cuenta, cliente.nombre, &cliente.balance);
  while (!feof(stdin)){
    fprintf(fp, "%d %s %d", cliente.cuenta, cliente.nombre, cliente.balance);
    scanf("%d %s %d", &cliente.cuenta, cliente.nombre, &cliente.balance);
  } 
}

void show(FILE *fp){
  char cadena[160] = {0};
  printf("+------------------------------------------------------+\n");
  printf("Nº Cuenta    Nombre    Balance\n");
  printf("+------------------------------------------------------+\n");
  rewind(fp);
  fgets(cadena, 160, fp);
  printf("%s\n", cadena);
  while(!feof(fp)){
    printf("\n");
    fgets(cadena, 160, fp);
    printf("%s\n", cadena);
  }
  printf("+------------------------------------------------------+\n");
}
int main(void){
  FILE *fp;

  fp = fopen("cliente.dat", "w+");
  load(fp);
  system(CLEAR);
  show(fp);


  fclose(fp);
  return 0;
}

