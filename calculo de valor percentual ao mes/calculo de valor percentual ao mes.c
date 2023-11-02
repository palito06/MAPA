#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");

    float valorI = 0;
    int periodo = 0;
    float percentualRendimento = 0;

    printf("insira o valor do investido:\n ");
    scanf("%f", &valorI);
    printf("insira a quantidade de meses do investimento: \n");
    scanf("%d", &periodo);
    printf("digite o percentual de rendimento ao mês \n");
    scanf("%f", &percentualRendimento);

    // -------------------------------------

    float resF;

    for (int i = 0; i <= periodo; i++) {
        resF = (valorI / 100) * percentualRendimento;
        valorI = valorI + resF;

        printf("mês %d --> %.2f\n", i, valorI);
    }

    return 0;
}

