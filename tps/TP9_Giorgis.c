#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else 
#define CLEAR "clear" 
#endif

#define EDAD_MAX 130

typedef struct date{
  int day;
  int month;
  int year;
}date_t;

typedef struct healthProfile{
  char nombre[80];
  char apellido[80];
  int sexo; //0=masculino, 1=femenino 
  date_t nac;
  float altura;
  float peso;
  int edad;
  int frecMax;
}healthProfile_t;

healthProfile_t cargar(struct tm);
int validarNac(date_t, struct tm);
void edad(healthProfile_t *, struct tm);
float bmi(float, float);
void frecuenciaMax(healthProfile_t *);
void printProfile(healthProfile_t);


int main(void){
  healthProfile_t persona;
  healthProfile_t *p;

  p = &persona;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  
  printf("My health profile\n\n");
  persona = cargar(tm);
  edad(p, tm);
  frecuenciaMax(p);

  system(CLEAR);
  printProfile(persona);

  return 0;
}


int validarSexo(void){
  char ch;
  
  do{
    scanf("%c", &ch);
    while(getchar() != '\n');
    if (ch != 109 && ch != 'f' && ch != 'M' && ch != 'F') {
      printf("Error. Ingrese un valor valido[m/f]: ");
    }
  }while(ch != 'm' && ch != 'f' && ch != 'M' && ch != 'F');

  if (ch == 'm' || ch == 'M') {
    return 0;
  }else{
    return 1;
  }
}

int validarNac(date_t nac, struct tm tm){
  if(nac.year > tm.tm_year + 1900 || tm.tm_year + 1900 - nac.year > EDAD_MAX){
    return 1;
  }

  if(nac.month > 12 || nac.month < 1){
    return 1;
  }

  if(nac.month == 2){
    if(nac.day > 29){
      return 1;
    }
  }

  if(nac.month == 4 || nac.month == 6 || nac.month == 9 || nac.month == 11){
    if(nac.day > 30){
      return 1;
    }
  }else{
    if(nac.day > 31){
      return 1;
    }
  }

  return 0;
}

healthProfile_t cargar(struct tm tm){
  healthProfile_t persona;

  printf("Por favor, complete los siguientes datos con su información personal\n");
  
  printf("Nombre: "); 
  scanf("%s", persona.nombre); while(getchar() != '\n');
  printf("Apellido: "); 
  scanf("%s", persona.apellido); while(getchar() != '\n');
  printf("Sexo [m/f]: "); 
  persona.sexo = validarSexo();

  printf("Fecha de nacimiento (dd/mm/yyyy)\n");
  do{
    printf("\tDía: ");
    scanf("%d", &persona.nac.day); while(getchar() != '\n');
    printf("\tMes: ");
    scanf("%d", &persona.nac.month); while(getchar() != '\n');
    printf("\tAño: ");
    scanf("%d", &persona.nac.year); while(getchar() != '\n');
    if(validarNac(persona.nac, tm) == 1){
      printf("Error. Ingrese una fecha valida\n");
    }
  }while(validarNac(persona.nac, tm));

  printf("Altura (mts): ");
  scanf("%f", &persona.altura);
  printf("Peso (kg): ");
  scanf("%f", &persona.peso);

  return persona;
}

float bmi(float peso, float altura){
  return peso/(altura * altura);
}

void edad(healthProfile_t *persona, struct tm tm){

  if(persona->nac.month == tm.tm_mon + 1){
    if (persona->nac.day < tm.tm_mday) {
      persona->edad = tm.tm_year + 1900 - persona->nac.year;
    }else {
      persona->edad = tm.tm_year + 1900 - persona->nac.year - 1;
    }
  }else{
    if (persona->nac.month < tm.tm_mon + 1) {
      persona->edad = tm.tm_year + 1900 - persona->nac.year;
    }else {
      persona->edad = tm.tm_year + 1900 - persona->nac.year - 1;
    }
  }
}

void frecuenciaMax(healthProfile_t *persona){
  persona->frecMax = 220-persona->edad;
}

void printProfile(healthProfile_t persona){
  printf("Datos cargados\n");
  printf("Nombre: %s\n", persona.nombre);
  printf("Apellido: %s\n", persona.apellido);
  printf("Sexo: %s\n", persona.sexo == 0 ? "Masculino" : "Femenino");
  printf("Fecha de nacimiento: %02d/%02d/%04d\n", persona.nac.day, persona.nac.month, persona.nac.year);
  printf("Altura (mts): %.2f\n", persona.altura);
  printf("Peso (kg): %.2f\n", persona.peso);

  printf("\nDatos calculados\n");
  printf("Edad: %d\n", persona.edad);
  printf("BMI: %.2f\n", bmi(persona.peso, persona.altura));
  printf("Frecuencia cardiaca máxima (ppm): %d\n", persona.frecMax);
  printf("Frecuencia cardiaca deseada (ppm): %.2f a %.2f\n", persona.frecMax*0.5, persona.frecMax*0.85);
}
