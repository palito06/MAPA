#include<stdio.h>
#include<string.h>
#define MAX_clientes 10

enum tipoPessoa{
    ABERTURA_DE_CONTA,
};

struct usuario{ 
    enum tipoPessoa tipo;
    char nome[20];
    char id[20];
};

void exibirAberturadeConta(struct usuario pessoa[])
{
    int max = sizeof(pessoa) / sizeof(pessoa[0]);
    printf("====== Abertura de Conta ======\n\n");
    printf("%d\n\n",max);
    
    for (int i = 0; i < MAX_clientes ; i++) 
    {
        if (pessoa[i].tipo == ABERTURA_DE_CONTA) {
            printf("Nome: %s\n",  pessoa[i].nome);
            printf("CPF: %s\n",  pessoa[i].id);
            printf("Tipo de atendimento: Abertura de conta\n\n");
        }
    }
}

int main(){
    

    struct usuario pessoa[]=
    {

        { // teste de usuario -------------
            .nome = "kevin",
            .id = "50",
            .tipo = ABERTURA_DE_CONTA,
        },
        {//usuario teste 2
            .nome = "vito",
            .id = "20",
            .tipo= ABERTURA_DE_CONTA,
        }

    };
    
    exibirAberturadeConta(pessoa);
    return 0;
}