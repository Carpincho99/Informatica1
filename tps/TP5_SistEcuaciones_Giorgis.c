#include<stdio.h>
#include<stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else
#define CLEAR "clear" 
#endif

#define E 0.01
#define N 3 //Cantidad de incognitas

int main(void){
	float matriz[N][N+1] = {0};
	float tmp;
	char incog[N]; 
	
	for (int i = 0; i < N; i++) {
		incog[i] = 65 + i; //ASCII
	}
	
//Carga matriz
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
//-----------------------------------------------------------
			system(CLEAR);
			printf("Calculadora de sistemas de ecuaciones lineales compatible determinado\n\n\n");
			printf("Sistema:\n");
			
			for (int I = 0; I < N; I++) {
				printf("|");
				for (int J = 0; J <= N; J++) {
					if (J != N+1-1) {
						printf("%+9.2f %-3c", matriz[I][J], incog[J]); 
					}
					else{
						printf("  =  %9.2f ", matriz[I][J]); 
					}
				} 
				printf("|\n");
			}
//-----------------------------------------------------------
			printf("\nIngrese el elemento %d;%d: ", i+1, j+1); 
			scanf("%f", &matriz[i][j]);
			if (matriz[i][j] == -0) { //evitar imprimir "+-0" al ingresar -0
				matriz[i][j] = 0;  
			}
		}
	}
	
	system(CLEAR);
	printf("Calculadora de sistemas de ecuaciones lineales compatible determinado\n\n\n");
	
	printf("Sistema:\n");
	for (int I = 0; I < N; I++) {
		printf("|");
		for (int J = 0; J <= N; J++) {
			if (J != N) {
				printf("%+9.2f% -3c", matriz[I][J], incog[J]); 
			}
			else{
				printf("  =  %9.2f ", matriz[I][J]); 
			}
		} 
		printf("|\n");
	}
	
	printf("\n\nMatriz ampliada:\n");
	for (int I = 0; I < N; I++) {
		printf("|");
		for (int J = 0; J <= N; J++) {
			if (J != N) {
				printf("%9.2f", matriz[I][J]); 
			}
			else{
				printf("  | %9.2f ", matriz[I][J]); 
			}
		} 
		printf("|\n");
	}
	
	
//Evitar 0 en la diagonal
	for (int k = 0; k < N; k++) {
		
		for (int i = 0; i < N; i++) {
			if (matriz[i][i] == 0) {
				if (i != (N-1)) {
					for (int j = 0; j <= N; j++) {
						tmp = matriz[i+1][j];
						matriz[i+1][j] = matriz[i][j];
						matriz[i][j] = tmp;
					}
				}else{
					for (int j = 0; j <= N; j++) {
						tmp = matriz[i-1][j];
						matriz[i-1][j] = matriz[i][j];
						matriz[i][j] = tmp;
					}
				}
			}
		}
		
	}
	
	
//Proceso Gauss-Jordan
	for (int i = 0; i < N; i++) {
		
		tmp = matriz[i][i];
		for (int j = 0; j <= N; j++) {
			matriz[i][j] /= tmp;
		}
		
		for (int p = 0; p < N; p++) {
			if (p != i) {
				tmp = matriz[p][i];
				for (int j = 0; j <= N; j++) {
					matriz[p][j] -= matriz[i][j] * tmp;  
				}
			}
		}
		
	}
	
	
//Matriz reducida 
	printf("\n\nMatriz reducida por filas:\n");
	for (int I = 0; I < N; I++) {
		printf("|");
		for (int J = 0; J <= N; J++) {
			if (J != N) {
				printf("%9.2f", matriz[I][J] < 0 && matriz[I][J] > -E ? 0 : matriz[I][J]); 
			}
			else{
				printf("  | %9.2f ", matriz[I][J] < 0 && matriz[I][J] > -E ? 0 : matriz[I][J]); 
			}
		} 
		printf("|\n");
	}
	
	
//Output
	printf("\n\nResultado:\n");
	printf("(");
	for (int i = 0; i < N; i++) {
		printf("%c%c", incog[i], i == N-1 ? 00 : ';');
	}
	printf(") = (");
	for (int i = 0; i < N; i++) {
		printf("%9.2f%c", matriz[i][N], i == N-1 ? 00 : ';');
	}
	printf(")\n\n");
	
	
	return 0;
}


