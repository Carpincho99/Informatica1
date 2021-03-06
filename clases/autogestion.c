#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define COL_WIDTH -12

typedef struct{
  char nombre[80], apellido[80];
  int legajo;
  int parcial1;
  int parcial2;
  int promedio;
}est_t;

int setN(void);
void load(int, est_t*);
void view(int, est_t*);
int menu(void);
void delete(int, est_t*);
void busquedaLegajo(int, est_t *);
void ordenPromedio(int, est_t *);
void ordenParcial1(int, est_t *);
void ordenParcial2(int, est_t *);
void swapEst(est_t *, int, int);
void errLegajo(void);
int cantSinCargar(int, est_t *);
void volver(){}


int main(void){
  int n; //numero de alumnos

  est_t *estudiantes;
  n = setN();
  estudiantes = calloc(n, sizeof(est_t));

  system(CLEAR);

  if (estudiantes == NULL) {
    printf("Error al intentar acceder a la memoria. Vuelva a ejecutar el programa\n");
    return 1;
  }

  view(n, estudiantes);

  free(estudiantes);
  return 0;
}

int setN (void){
  int n;
  printf("Cantidad total de estudiantes: ");
  scanf("%d", &n);
  while(getchar() != '\n');
  return n;
}

void load(int n, est_t *p){
  int cantidad;

  if (cantSinCargar(n, p) == 0) {
    printf("\nCapacidad max. de estudiantes utilizada.\n\n");
    printf("[Pulse enter para volver...]");
    while(getchar() != '\n');
  }else{

    if (cantSinCargar(n, p) == 1) {
      cantidad = 1;
    }else {
      printf("¿Cuantos estudiantes desea cargar? (max. %d): ", cantSinCargar(n, p));

      do{
        scanf("%d", &cantidad);
        while(getchar() != '\n');
        if (cantidad < 0 || cantidad > cantSinCargar(n, p)) {
          printf("Erro. Ingrese un valor valido: ");
        }
      }while(cantidad < 0 || cantidad > cantSinCargar(n, p));
    }

    for (int i = 0; i < cantidad; i++) {
      if((p+i)->nombre[0] == 0){
        system(CLEAR);
        printf("Nombre: ");
        scanf("%s", &(p+i*sizeof(est_t))->nombre[0]);
        printf("Apellido: ");
        scanf("%s", &(p+i*sizeof(est_t))->apellido[0]);
        printf("Legajo: ");
        scanf("%d", &(p+i*sizeof(est_t))->legajo);
        printf("Parcial 1: ");
        scanf("%d", &(p+i*sizeof(est_t))->parcial1);
        printf("Parcial 2: ");
        scanf("%d", &(p+i*sizeof(est_t))->parcial2);
        (p+i*sizeof(est_t))->promedio = ((p+i*sizeof(est_t))->parcial1 + (p+i*sizeof(est_t))->parcial2)/2;
      }
    }
  }

  system(CLEAR);
  view(n, p);
}

void view(int n, est_t *p){
  void (*funcView[7])(int, est_t *); 
  funcView[0] = load;
  funcView[1] = delete;
  funcView[2] = ordenPromedio;
  funcView[3] = ordenParcial1;
  funcView[4] = ordenParcial2;
  funcView[5] = busquedaLegajo;
  funcView[6] = volver;

  char *header[7] = {"|Nombre", "|Apellido", "|Legajo", "|Parcial 1", "|Parcial 2", "|Promedio", "|Estado académico"};

  printf("AUTOGESTIÓN\n\n");
  printf("+------------------------------------------------------------------------------------------+\n");
  for (int i = 0; i < 7; ++i) {
    printf("%*s", COL_WIDTH, *(header+i));
  }
  printf("\n+------------------------------------------------------------------------------------------+\n");

  for (int i = 0; i < n; i++) {
    if((p+i*sizeof(est_t))->nombre[0] != 0){
      printf(" %*s", COL_WIDTH, (p+i*sizeof(est_t))->nombre);
      printf("%*s", COL_WIDTH, (p+i*sizeof(est_t))->apellido);
      printf("%*d", COL_WIDTH, (p+i*sizeof(est_t))->legajo);
      printf("%*d", COL_WIDTH, (p+i*sizeof(est_t))->parcial1);
      printf("%*d", COL_WIDTH, (p+i*sizeof(est_t))->parcial2);
      printf("%*d", COL_WIDTH, (p+i*sizeof(est_t))->promedio);
      if ((p+i)->promedio < 6) {
        printf("%*s", COL_WIDTH, "Desaprobado");
      }
      if ((p+i)->promedio == 6) {
        printf("%*s", COL_WIDTH, "Regular");
      }
      if ((p+i)->promedio > 6) {
        printf("%*s", COL_WIDTH, "Aprobación directa");
      }
      printf("\n");
    }
  }
  if (cantSinCargar(n, p) == n) {
    printf("%*s %s\n", COL_WIDTH, " ",  "No se ha cargado ningún estudiante aún");
  }
  printf("+------------------------------------------------------------------------------------------+\n");
  printf("Cantidad total de alumnos cargados: %d\n\n", n-cantSinCargar(n, p));

  funcView[menu()](n, p);
}

void delete(int n, est_t *p){
  int input;
  int pos = -1;

  printf("\nIngrese el legajo del alumno a borrar: ");
  scanf("%d", &input);
  while(getchar() != '\n');

  for (int i = 0; i < n; ++i) {
    if ((p+i)->legajo == input) {
      pos = i;
    }
  }

  if (pos == -1) {
    errLegajo();
  }else{
    (p+pos*sizeof(est_t))->nombre[0] = 0;
  }

  system(CLEAR);
  view(n, p);
}

int menu(){
  int seleccion;

  printf("Opciones\n");
  printf("1)Cargar estudiante\n");
  printf("2)Borrar estudiante\n");
  printf("3)Ordenar por promedio\n");
  printf("4)Ordenar por calificación primer parcial\n");
  printf("5)Ordenar por calificación segundo parcial\n");
  printf("6)Buscar por legajo\n");
  printf("7)Salir\n");
  printf("\nSelección: ");
  scanf("%d", &seleccion);
  while(getchar() != '\n');

  return seleccion - 1;
}

void busquedaLegajo(int n, est_t *p){
  int legajo;
  int pos = -1;

  printf("\nIngrese el legajo que desea buscar: ");
  scanf("%d", &legajo);
  while(getchar() != '\n');

  for (int i = 0; i < n; ++i) {
    if ((p+i*sizeof(est_t))->legajo == legajo) {
      pos = i;
    }
  }

  if(pos != -1){
    swapEst(p, 0, pos);
  }else{
    errLegajo();
  }

  system(CLEAR);
  view(n, p);
}

void ordenPromedio(int n, est_t *p){
  for (int i = 0; i < n-1; i++) {      //burbuja
    for (int j = 0; j < n-1-i; j++) {
      if((p+j*sizeof(est_t))->promedio < (p+(j+1)*sizeof(est_t))->promedio){
        swapEst(p, j, j+1);
      }
    }
  }

  system(CLEAR);
  view(n, p);
}

void ordenParcial1(int n, est_t *p){
  for (int i = 0; i < n-1; i++) {      //burbuja
    for (int j = 0; j < n-1-i; j++) {
      if((p+j*sizeof(est_t))->parcial1 < (p+(j+1)*sizeof(est_t))->parcial1){
        swapEst(p, j, j+1);
      }
    }
  } 

  system(CLEAR);
  view(n, p);
}

void ordenParcial2(int n, est_t *p){
for (int i = 0; i < n-1; i++) {      //burbuja
    for (int j = 0; j < n-1-i; j++) {
      if((p+j*sizeof(est_t))->parcial2 < (p+(j+1)*sizeof(est_t))->parcial2){
        swapEst(p, j, j+1);
      }
    }
  } 

  system(CLEAR);
  view(n, p);
}


void swapEst(est_t *p, int posA, int posB){
  est_t q;

  q = *(p+posA*sizeof(est_t));
  *(p+posA*sizeof(est_t)) = *(p+posB*sizeof(est_t));
  *(p+posB*sizeof(est_t)) = q;
}

void errLegajo(void){
  printf("\nNo se ha encontrado el legajo ingresado\n\n");
  printf("[Pulse enter para volver...]");
  while(getchar() != '\n');
}

int cantSinCargar(int n, est_t *p){
  int cant = 0;

  for (int i = 0; i < n; ++i) {
    if((p+i*sizeof(est_t))->nombre[0] == 0){
      cant++;
    }
  }
  return cant;
}

