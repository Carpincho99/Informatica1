#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define N 100 //cantidad max. de productos
#define FILE_NAME "hardware.dat"

typedef struct{
  int codigo;
  char nombre[80];
  int stock;
  float precio;
}producto_t;

void initFile(FILE *, int);
int countReg(producto_t[], int);
void show(producto_t[], int, int);
int menu(void);
producto_t scanfProducto(void);
int validarCantd(int, int);

int load(FILE *, int, int);
int update(FILE *, int, int);
int delete_(FILE *, int, int);
int close(FILE *, int, int);

int (*op[4])(FILE *fp, int nRegCargados, int n);

int main(void){
  op[0] = load; 
  op[1] = update;
  op[2] = delete_;
  op[3] = close;

  int cent;
  int nRegCargados;
  FILE *fp;
  producto_t items[N] = {0};

  fp = fopen(FILE_NAME, "rb+");
  if (fp == NULL){
    initFile(fp, N);
    fp = fopen(FILE_NAME, "rb+");
  }

  do{
    system(CLEAR);
    fseek(fp, 0, SEEK_SET);
    fread(items, sizeof(producto_t), N, fp);
    nRegCargados = countReg(items, N);
    show(items,nRegCargados, N);
    cent = (*op[menu()])(fp, nRegCargados, N);
    if (cent == -1){
      printf("\n\n[Error en tiempo de ejecución. Reinicie el programa]\n");
      cent = 1;
    }
  }while(!cent);

  fclose(fp);
  return 0;
}

int countReg(producto_t items[], int n){
  int cantd = 0;
  for (int i = 0; i < n; i++) 
    if (items[i].nombre[0] != 0)
      cantd++;

  return cantd;
}

void show(producto_t items[], int nRegCargados, int n){
  printf("+----------------------------------------------------------+\n");
  printf("|%-11s%-30s%-7s%-11s%s","Código", "Nombre", "Stock", "Precio", "|\n");
  printf("+----------------------------------------------------------+\n");
  if (nRegCargados != 0) {
    for (int i = 0; i < n; i++) {
      if (items[i].nombre[0] != 0){
        printf("|%-10d", items[i].codigo);
        printf("%-30s", items[i].nombre);
        printf("%-5d \t", items[i].stock);
        printf("$%10.2f|\n", items[i].precio);
      }
    }
  }else {
    printf("| No se ha encontrado ningún producto cargado...           |\n");
  }
  printf("+----------------------------------------------------------+\n");
  printf("Mostrando %d productos \n", nRegCargados);
}

int menu(void){
  int seleccion = 0;

  printf("\nMenú\n");
  printf("1) Ingresar nuevo producto\n");
  printf("2) Actualizar un producto\n");
  printf("3) Eliminar un producto\n");
  printf("4) Salir\n");
  printf("Selección: ");

  do {
    scanf("%d", &seleccion);
    while (getchar() != '\n');
    if (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4)
      printf("Error. Seleccione una opción valida: ");
  }while (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4);

  printf("\n");
  return seleccion-1;
}

void initFile(FILE *fp, int n){
  producto_t item = {0};
  fp = fopen(FILE_NAME, "wb");
  for (int i = 0; i < n; i++) {
    fwrite(&item, sizeof(producto_t), 1, fp);
  }
  fclose(fp);
}

producto_t scanfProducto(void){
  producto_t item = {0};
  printf("Nombre: ");
  scanf("%80[^\n]s", item.nombre); while(getchar() != '\n');
  printf("Stock: ");
  scanf("%d", &item.stock); while(getchar() != '\n');
  printf("Precio: $");
  scanf("%f", &item.precio); while(getchar() != '\n');
  printf("\n");
  return item;
}

int validarCantd(int nRegCargados, int n){
  int cantd = 0;
  do{
    scanf("%d", &cantd); while (getchar() != '\n');
    if (cantd > n-nRegCargados || cantd < 0) 
      printf("Error. Ingrese un valor valido: ");
  }while(cantd > n-nRegCargados || cantd < 0);

  return cantd;
}

int load(FILE *fp, int nRegCargados, int n){
  int cantd = 0;
  int codigo = 0;
  producto_t item = {0};

  printf("¿Cuantos nuevos productos desea cargar? (max. %d): ", n-nRegCargados); 
  cantd = validarCantd(nRegCargados, n);
  for (int i = 0; i < cantd; i++) {
    do {
      printf("Código (0-%d): ", n-1);
      scanf("%d", &codigo); while(getchar() != '\n');

      fseek(fp, codigo*sizeof(producto_t), SEEK_SET);
      fread(&item, sizeof(producto_t), 1, fp);

      if (item.nombre[0] != 0 || codigo < 0 || codigo > n-1) {
        printf("Error. Código invalido o en uso.\n");
      }
    }while (item.nombre[0] != 0 || codigo < 0 || codigo > n-1);

    item = scanfProducto();
    item.codigo = codigo;
    fseek(fp, codigo*sizeof(producto_t), SEEK_SET);
    if (fwrite(&item, sizeof(producto_t), 1, fp) < 1) {
      return -1;
    }
  }
  return 0;
}

int update(FILE *fp, int nRegCargados, int n){
  int codigo = 0;
  producto_t item = {0};
  printf("Ingrese el código del producto a actualizar: ");

  do{
    scanf("%d", &codigo); while(getchar() != '\n');
    if (codigo < 0 || codigo > n-1) 
      printf("Error. Ingrese un código valido(1-%d): ", n);
  }while(codigo < 0 || codigo > n-1);

  fseek(fp, codigo*sizeof(producto_t), SEEK_SET);
  fread(&item, sizeof(producto_t), 1, fp);
  item = scanfProducto();
  item.codigo = codigo;
  fseek(fp, codigo*sizeof(producto_t), SEEK_SET);
  if (fwrite(&item, sizeof(producto_t), 1, fp) < 1) {
    return -1;
  }  
  return 0;
}

int delete_(FILE *fp, int nRegCargados, int n){
  int codigo = 0;
  producto_t item = {0};

  printf("Ingrese el código del producto a eliminar: ");
  do{
    scanf("%d", &codigo); while(getchar() != '\n');
    if (codigo < 0 || codigo > n-1) 
      printf("Error. Ingrese un código valido(1-%d): ", n);
  }while(codigo < 0 || codigo > n-1);

  fseek(fp, codigo*sizeof(producto_t), SEEK_SET);
  if (fwrite(&item, sizeof(producto_t), 1, fp) < 1) {
    return -1;
  }  
  return 0;
}

int close(FILE *fp, int nRegCargados, int n){
  return 1;
}
