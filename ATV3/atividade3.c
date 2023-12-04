#include <stdio.h>
#include <stdlib.h>


void validarMeta(int dia1[3][3] , int dia2[3][3]){
	int meta;
	int matrizSoma[3][3];

	printf("\ndigite a meta: ");
	fflush(stdin);
	scanf("%d", &meta);

	// soma das matrizes ----------------------------
	printf("\n");
	for ( int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			matrizSoma[i][j] = dia1[i][j] + dia2[i][j];
		}
	}

	// ira exibir a tabela de soma das matrizes-------
	printf("soma das matrizes: \n");
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			printf("%d,",matrizSoma[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//validando a meta

	for (int i = 0 ; i < 3 ; i++)
	{
		for (int j = 0 ; j < 3 ; j++)
		{
			if (matrizSoma[i][j] < meta){

				printf("\n[X] Coluna %d, linha %d,A meta nao foi alcancada :(\n",(j+1),(i+1));
			}
			else{

				printf("\n[o] Coluna %d linha %d , a meta foi atingida. \n", (j+1) ,(i+1));
			}
		}
	};
}

int main(){
	
	int dia1 [3][3];
	int dia2 [3][3];
	// int matrizSoma[3][3];

	printf("\n-------------dia 1----------------\n\n");

	for (int i= 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
				
			printf("digite o total de pessoas do setor %d de %d\n",(i+1) , (j+1));
			scanf("%d", &dia1[i][j]);
		}
	}
	
	printf("\n");

	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			printf("%d ", dia1[i][j]);
		}
		printf("\n");
	}

	printf("\n-------------dia 2----------------\n\n");

	for (int i= 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			printf("digite o total de pessoas do setor %d de %d\n",(i+1) , (j+1));
			scanf("%d", &dia2[i][j]);
		}
	}
	
	printf("\n");

	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			printf("%d ", dia2[i][j]);
		}
		printf("\n");
	}

	validarMeta(dia1,dia2);
	
	return 0;
} 
