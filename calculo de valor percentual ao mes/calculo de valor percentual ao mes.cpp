#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");

    float valorI = 0;
    int periodo = 0;
    float percentualRendimento = 0;

    printf("Insira o valor do investido:\n");
    scanf("%f", &valorI);
    printf("Insira a quantidade de meses do investimento:\n");
    scanf("%d", &periodo);
    printf("Digite o percentual de rendimento ao mes:\n");
    scanf("%f", &percentualRendimento);

    // uce parou aq-------------------------------------

    float resF = valorI;
	float RT = 0 ;
	float imposto = 15;
	float lucro = 0;
	
    for (int i = 1; i <= periodo; i++) {
        RT = (resF / 100) * percentualRendimento;
        resF = resF + RT;

        printf("Depois do mes %d --> R$ %.2f\n", i, resF);
    }
	
	float rendimento = resF - valorI;
	lucro = rendimento - ((rendimento/100) * imposto);
	
	printf ("\nSaldo final : %.2f \n", rendimento+valorI);
	printf("\nValor Saldo Final - Imposto Retido na Font: R$ %.2f \n ", lucro+valorI);
	
	system("pause");
    return 0;
}

