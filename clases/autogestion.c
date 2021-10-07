#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

typedef struct estudiante {
  char nombre[80], apellido[80];
  int legajo;
  int parcial1;
  int parcial2;
}est;

int menu(void);
int setN(void);
void load(int, est*);
void view(int, est*);
void delete(int, est*);

void (*op[3])(int, est*);

int main(void){
  int n;

  op[0] = load;
  op[1] = view;
  op[2] = delete;

  est *estudiantes;
  n = setN();
  estudiantes = calloc(n, sizeof (est));

  system(CLEAR);
  op[menu()](n, estudiantes);




  free(estudiantes);

  return 0;
}

int setN (void){
  int n;
  printf("Cantidad de estudiantes: ");
  scanf("%d", &n);
  while(getchar() != '\n');
  return n;
}

int menu (void){
  int seleccion;
  printf("Autogestion\n\n");
  printf("Seleccione una opcion\n");
  printf("1)Cargar\n");
  printf("2)Visualizar\n");
  printf("3)Borrar\n");
  printf("Seleccion: ");
  scanf("%d", &seleccion);
  while(getchar() != '\n');

  return seleccion - 1;
}

void load(int n, est* p){
  for (int i = 0; i < n; i++) {
    system(CLEAR);
    printf("Nombre: ");
    scanf("%s", &p->nombre[0]);
    printf("Apellido: ");
    scanf("%s", &p->apellido[0]);
    printf("Legajo: ");
    scanf("%d", &p->legajo);
    printf("Parcial 1: ");
    scanf("%d", &p->parcial1);
    printf("Parcial 2: ");
    scanf("%d", &p->parcial2);
   }
}

void view(int n, est* p){
printf("ok\n");

}

void delete(int n, est* p){
printf("ok\n");

}
