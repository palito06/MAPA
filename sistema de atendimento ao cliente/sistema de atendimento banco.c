#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_clientes 50

enum TipoPessoa {
    PESSOA_FISICA,
    PESSOA_JURIDICA,
	ABERTURA_DE_CONTA,
	CAIXA,
};

struct usuario{

	enum TipoPessoa tipo;
	char nome [50] ;
	char cpf[13];
	int valor;
	
};

//funçao --------------------------------
void exibirPessoasJuridicas(struct usuario pessoa[]) {
    printf("====== Pessoas Juridicas ======\n\n");
    for (int i = 0; i < MAX_clientes; i++) {
        if (pessoa[i].tipo == PESSOA_JURIDICA && pessoa[i].tipo > 0) {
            printf("Nome: %s\n", pessoa[i].nome);
            printf("CPF: %s\n", pessoa[i].cpf);
            printf("Tipo de antedimento: Pessoa Juridica\n\n");
        }
    }
}

void exibirPessoasFisica(struct usuario pessoa[]) {
    printf("\n====== Pessoas Fisicas ======\n\n");
    for (int i = 0; i < MAX_clientes; i++) {
        if (pessoa[i].tipo == PESSOA_FISICA && strlen(pessoa[i].cpf) > 0) {
            printf("Nome: %s\n", pessoa[i].nome);
            printf("CPF: %s\n", pessoa[i].cpf);
            printf("Tipo de antendimento: Pessoa Fisica\n\n");
        }
    }
}

void exibirAberturadeConta(struct usuario pessoa[]) {
    printf("====== Abertura de Conta ======\n\n");
    for (int i = 0; i < MAX_clientes; i++) {
        if (pessoa[i].tipo == ABERTURA_DE_CONTA && pessoa[i].tipo > 0) {
            printf("Nome: %s\n", pessoa[i].nome);
            printf("CPF: %s\n", pessoa[i].cpf);
            printf("Tipo de atendimento: Abertura de conta\n\n");
        }
    }
}
void exibirCAIXA(struct usuario pessoa[]) {
    printf("============ caixa ============\n\n");
    for (int i = 0; i < MAX_clientes; i++) {
        if (pessoa[i].tipo == CAIXA && pessoa[i].tipo > 0) {
            printf("Nome: %s\n", pessoa[i].nome);
            printf("CPF: %s\n", pessoa[i].cpf);
            printf("Tipo de atendimento: caixa\n\n");
        }
    }
}

//-----------------------------------------------

int main(){

	struct usuario pessoa[] = {

		{//usuario 1
			.tipo = PESSOA_FISICA,
			.nome = "kevin",
			.cpf  = "11122233344",
		},
		{//usuario 2
			.tipo = PESSOA_JURIDICA,
			.nome = "maria do carlos",
			.cpf  = "44322511298",
		},
		{//usuario 3
			.tipo = CAIXA,
			.nome = "joelson",
			.cpf  = "33244511366",
		},
		{//usuario 4
			.tipo = ABERTURA_DE_CONTA,
			.nome = "caudio",
			.cpf = "48379281532",
		},
		{//usuario 5
			.tipo = PESSOA_JURIDICA,
			.nome = "mayco mateus",
			.cpf = "45567789910",
		},
		//proximos usuarios ------------
	};
	fflush(stdin);
	system("cls");

	int  sair = 0;
	int  categoria;
	int  validacao = 0;
	char pessoaFJ;
	char opcao;
	int  MAX_US=0;

	//menu-------------------------------------------------
	
	do {
		system("cls");
		MAX_US = sizeof(pessoa) / sizeof(pessoa[0]); // contar o tamanho do array/ struct 

		printf("menu principal\n"
			"1 - Selecionar atendimento \n"
			"2 - Lista de Atendimento Registrado \n"
			"3 - Lista de atendimento por setor \n"
			"4 - Sair \n");
		fflush(stdin);
		scanf(" %1c", &opcao);
		
		switch (opcao){
			case '1':
				// iniciando atendimento  ----------------------
				do{
					system("cls");
					printf ("\nja possui cadastro: y/n ?  -  [s] Sair\n");
					fflush(stdin);
					scanf("%c", &pessoaFJ); 
					
					if (pessoaFJ == 'y'){

						system("cls");
						char cpfconfirma[12];
						printf("Informe seu CPF (apenas numeros, sem pontuacao): ");
						fflush(stdin);
						fgets(cpfconfirma, sizeof(cpfconfirma), stdin);

						// percorre a struct para encontrar o CPF EXISTENTE --------------
						for (int i = 0; i <= MAX_US ; ++i)
						{ 
							if (strcmp(cpfconfirma, pessoa[i].cpf) == 0) // ver erro de procura de CPF ----------
							{
								sair = 1;
								printf("\n------CPF encontrado------\n");
								printf("\nseja bem vindo de volta %s\n", pessoa[i].nome);
							}
						}

						if (sair == 0){
							printf("[x][x] CPF nao encontrado [x][x]\n\n");
							system("pause");
						}
						fflush(stdin);
					}
					else if (pessoaFJ == 'n' && MAX_US < MAX_clientes)
					{

						// ----------------cadastro --------------------
						printf("\n----vamos realizar o seu cadastro agora!----\n"
							   "\ninforme alguns dos seus dados abaixo.\n");

						MAX_US ++;
						printf("\ninforme seu cpf: \n");//conferir se CPF ja é existente. ------------ [X]
						fflush(stdin); // limpa o buffer
						fgets(pessoa[MAX_US].cpf, sizeof(pessoa[MAX_US].cpf), stdin);

						printf("\ninforme seu Nome: \n");
						fflush(stdin); // Limpa o buffer do teclado
						fgets(pessoa[MAX_US].nome, sizeof(pessoa[MAX_US].nome), stdin);
							
						//DEFININDO SETOR-------------------------
						
						printf("\n[1] Conta Pessoa Juridica\n[2] Conta Pessoa Fisica\n[3]Abertura de conta\n[4]Caixa.\n\n");
						fflush(stdin);
						scanf(" %c", &pessoaFJ);
						
						if (pessoaFJ == '1')
						{ 
							pessoa[MAX_US].tipo = PESSOA_JURIDICA;
						}
						else if (pessoaFJ == '2')
						{
							pessoa[MAX_US].tipo = PESSOA_FISICA;
						}
						else if(pessoaFJ == '3')
						{
							pessoa[MAX_US].tipo = ABERTURA_DE_CONTA;
						}
						else if(pessoaFJ == '4')
						{
							pessoa[MAX_US].tipo = CAIXA;
						}
						else 
						{
							printf("OPCAO INCORRETA");
						}
						fflush(stdin);
						sair = 0;
					}
					else if (MAX_US >= MAX_clientes)
					{
						printf("limite de pessoa atingido");
					}
					else if (pessoaFJ == 's')
					{
						sair = 1;
						printf("\nsaindo . . .\n");
						system("pause");
					}
					else
					{
						printf("\n[x][x] OPCAO INDISPONIVEL [x][x]\n");
						system("pause");
					}
					fflush(stdin);//clear
				}while(sair != 1);
				fflush(stdin);

			case '2':
				
				fflush(stdin);
				printf("\n\n----exibindo atendimentos totais registrados----\n\n");
				printf("quantidade de usuarios totais: %d\n",MAX_US);
				exibirPessoasJuridicas(pessoa);
				exibirAberturadeConta(pessoa);
				exibirPessoasFisica(pessoa);
				exibirCAIXA(pessoa);

				system("pause");
				break;

			case '3':

				categoria = 0 ;
				opcao = 0;
				printf("\nqual categoria gostaria de consultar? \n");
				printf("\n[1]-Pessoa Juridia\n[2]-Pessoa fisica\n[3]-abertura de conta\n[4]-CAIXA\n[5]-voltar\n\n");
				fflush(stdin);
				scanf("%1d",&categoria);

				if (categoria == 1)
				{
					exibirPessoasJuridicas(pessoa);
					fflush(stdin);
					system("pause");
				}
				else if(categoria == 2)
				{	
					exibirPessoasFisica(pessoa);
					fflush(stdin);
					system("pause");	
				}
				else if(categoria == 3)
				{
					exibirAberturadeConta(pessoa);
					fflush(stdin);
					system("pause");
				}
				else if(categoria == 4)
				{
					exibirCAIXA(pessoa);
					fflush(stdin);
					system("pause");
				}
				else
				{
					system("cls");
					fflush(stdin);
				}
				break;

			case '4':

				validacao = 1;
				printf("Saindo . . . .\n\n");
				system("pause");
				break;

			default:

				printf("Opcao inesistente.\n");
				fflush(stdin);
				system("pause");
				break;
			
		}
		printf("----> %d\n",sair);
		system("pause");
	}while(validacao !=1 );

	return 0;
}

