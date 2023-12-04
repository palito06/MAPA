#include <stdio.h>
#include <stdlib.h>

struct tipo_endereco
{

    char rua[150];
    int numero;
    char bairro[150];

};

struct tipo_pessoa
{
    char nome[50];
    int numero;
    struct tipo_endereco endereco;
};



int main(){

    struct tipo_pessoa pessoa;

    printf("insira o nome da rua: \n");
    fflush(stdin);
    fgets(pessoa.endereco.rua, sizeof(pessoa.endereco.rua), stdin);

    printf("insira o numero da casa: \n");
    fflush(stdin);
    scanf("%d",&pessoa.endereco.numero);

    printf("insira o bairro: \n");
    fflush(stdin);
    fgets(pessoa.endereco.bairro, sizeof(pessoa.endereco.bairro), stdin);

    printf("Endereco\nRua: %d\nnumero: %d\nbairro: %d\n",pessoa.endereco.rua, pessoa.endereco.numero, pessoa.endereco.bairro);
    fflush(stdin);
    system("pause");

    return 0;
}