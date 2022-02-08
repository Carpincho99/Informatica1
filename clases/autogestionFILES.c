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
void load(int, FILE*);
void view(int, FILE*);
int menu(void);
void delete(int, FILE*);
void busquedaLegajo(int, FILE*);
void ordenPromedio(int, FILE*);
void ordenParcial1(int, FILE*);
void ordenParcial2(int, FILE*);
void swapEst(int, int, FILE*);
void errLegajo(void);
int cantEst(FILE*);

int main(void){
  int n;
  FILE *file;

  file = fopen("autogestion.txt", "a+");

  if ( file  == NULL ) {
    printf("No se pudo abrir el archivo\n");
    return 1;
  }

  n = cantEst(file);

  system(CLEAR);
  view(n, file);

  fclose(file);
  return 0;
}

int setN (void){
  int n;
  printf("Cantidad total de estudiantes: ");
  scanf("%d", &n);
  while(getchar() != '\n');
  return n;
}

void load(int n, FILE *file){
  int cantidad;
  est_t estudiante;

  if (cantEst(file) == 0) {
    printf("\nCapacidad max. de estudiantes utilizada.\n\n");
    printf("[Pulse enter para volver...]");
    while(getchar() != '\n');
  }else{

    if (cantEst(file) == n) {
      cantidad = 1;
    }else {
      printf("¿Cuantos estudiantes desea cargar? (max. %d): ", cantEst(n, p));

      do{
        scanf("%d", &cantidad);
        while(getchar() != '\n');
        if (cantidad < 0 || cantidad > cantEst(n, p)) {
          printf("Error. Ingrese un valor valido: ");
        }
      }while(cantidad < 0 || cantidad > cantEst(n, p));
    }

    for (int i = 0; i < cantidad; i++) {
      if((p+i)->nombre[0] == 0){
        system(CLEAR);
        printf("Nombre: ");
        scanf("%s", &estudiante.nombre[0]);
        printf("Apellido: ");
        scanf("%s", &estudiante.apellido[0]);
        printf("Legajo: ");
        scanf("%d", &estudiante.legajo);
        printf("Parcial 1: ");
        scanf("%d", &estudiante.parcial1);
        printf("Parcial 2: ");
        scanf("%d", &estudiante.parcial2);
        estudiante.promedio = (estudiante.parcial1 + estudiante.parcial2)/2;

        fprintf(file, "%s %s %d %d %d %d\n", estudiante.nombre, 
                                             estudiante.apellido,
                                             estudiante.legajo,
                                             estudiante.legajo,
                                             estudiante.legajo,
                                             estudiante.legajo);
      }
    }
  }

  system(CLEAR);
  view(n, p, file);
}

void view(int n, est_t *p, FILE *file){
  void (*funcView[6])(int, est_t *); 
  funcView[0] = load;
  funcView[1] = delete;
  funcView[2] = ordenPromedio;
  funcView[3] = ordenParcial1;
  funcView[4] = ordenParcial2;
  funcView[5] = busquedaLegajo;

  char *header[7] = {"|Nombre", "|Apellido", "|Legajo", "|Parcial 1", "|Parcial 2", "|Promedio", "|Estado académico"};

  printf("AUTOGESTIÓN\n\n");
  printf("+------------------------------------------------------------------------------------------+\n");
  for (int i = 0; i < 7; ++i) {
    printf("%*s", COL_WIDTH, *(header+i));
  }
  printf("\n+------------------------------------------------------------------------------------------+\n");
   char linea[160];
  rewind(file);
  fgets(linea, 160, file);
  while (!feof(file)) {
    fputs(linea, stdout);
    fgets(linea, 160, file);

  if (cantEst(n, p) == n) {
    printf("%*s %s\n", COL_WIDTH, " ",  "No se ha cargado ningún estudiante aún");
  }
  printf("+------------------------------------------------------------------------------------------+\n");
  printf("Cantidad total de alumnos cargados: %d\n\n", n-cantEst(n, p));

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

int cantEst(FILE *file){
  int cant = 0;

  while (!feof(file)) {
    if (fgetc(file) == '\n') {
    cant++;
    }
  } 

  return cant;
}

