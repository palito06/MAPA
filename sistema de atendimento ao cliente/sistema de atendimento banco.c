#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_clientes 50

enum TipoPessoa {
    PESSOA_FISICA,
    PESSOA_JURIDICA,
	ABERTURA_DE_CONTA
};

struct usuario{

	enum TipoPessoa tipo;
	char nome [50] ;
	char cpf[12];
	int valor;
	
};

//funçao --------------------------------

void exibirPessoasJuridicas(struct usuario pessoa[]) {
    printf("====== Pessoas Juridicas ======\n\n");
    for (int i = 0; i < MAX_clientes; i++) {
        if (pessoa[i].tipo == PESSOA_JURIDICA) {
            printf("Nome: %s\n",  pessoa[i].nome);
            printf("CPF: %s\n",  pessoa[i].cpf);
			printf("Tipo de antedimento: Pessoa Juridica\n\n");
        }
    }
}
void exibirPessoasFisica(struct usuario pessoa[]) {
    printf("====== Pessoas Fisica ======\n\n");
    for (int i = 0; i < MAX_clientes; i++) {
        if (pessoa[i].tipo == PESSOA_FISICA) {
            printf("Nome: %s\n",  pessoa[i].nome);
            printf("CPF: %s\n",  pessoa[i].cpf);
			printf("Tipo de antendimento: Pessoa Fisica\n\n");
        }
    }
}
void exibirAberturadeConta(struct usuario pessoa[]) {
    printf("====== Abertura de Conta ======\n\n");
    for (int i = 0; i < MAX_clientes; i++) {
        if (pessoa[i].tipo == ABERTURA_DE_CONTA) {
            printf("Nome: %s\n",  pessoa[i].nome);
            printf("CPF: %s\n",  pessoa[i].cpf);
			printf("Tipo de atendimento: Abertura de conta\n\n");
        }
    }
}

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
			.tipo = ABERTURA_DE_CONTA,
			.nome = "joelson",
			.cpf  = "33244511366",
		},
		//proximos usuarios ------------
	};

	int categoria = 0 ;
	int  validacao = 0;
	char pessoaFJ;
	char opcao;

	int  MAX_US = sizeof(pessoa) / sizeof(pessoa[0]); // contar o tamanho do array/ struct ------
	
	//menu-------------------------------------------------
	do{

		system("cls");
		printf("menu principal\n"
			"1 - Selecionar atendimento \n"
			"2 - Lista de Atendimento Registrado \n"
			"3 - Lista de atendimento por setor \n"
			"4 - Sair \n");
		
		scanf("%c", &opcao);
		
		switch (opcao){
			case '1':
				// iniando atendimento  ----------------------
				do{
					system("cls");
					printf ("\nja possui cadastro: y/n ?\n");
					fflush(stdin);
					scanf("%s", &pessoaFJ); 
					
					if (pessoaFJ == 'y'){
						system("cls");

						char cpfconfirma[12];
						printf("Informe seu CPF (apenas numeros, sem pontuacao): ");
						scanf("%11s", cpfconfirma);
						
						// percorre a struct para encontrar o CPF EXISTENTE --------------
						for (int i = 0; i <= MAX_clientes ; i++)
						{ 
							if (strcmp(cpfconfirma, pessoa[i].cpf) == 0)
							{
								validacao = 1;
								printf("\n------CPF encontrado------\n");
								printf("\nseja bem vindo de volta %s\n", pessoa[i].nome);
							}
						}
						if (validacao == 0){
							printf("CPF nao encontrado");
						}
						fflush(stdin);
					}
					else if ( pessoaFJ == 'n')
					{
						// ----------------cadastro --------------------
						system("cls");
										
						printf("\n----vamos realizar o seu cadastro agora!----\n"
							   "\ninforme alguns dos seus dados abaixo.\n");

						if (MAX_US < MAX_clientes){

							MAX_US ++;
							printf("\ninforme seu cpf: \n");//conferir se CPF ja é existente. ------------ [X]
							fflush(stdin); // Limpa o buffer do teclado
							fgets(pessoa[MAX_US].cpf, sizeof(pessoa[MAX_US].cpf), stdin);

							printf("\ninforme seu Nome: \n");
							fflush(stdin); // Limpa o buffer do teclado
							fgets(pessoa[MAX_US].nome, sizeof(pessoa[MAX_US].nome), stdin);
								
							//DEFININDO SETOR-------------------------

							printf("\n[1] Conta Pessoa Juridica\n[2] Conta Pessoa Fisica\n");
							fflush(stdin);
							scanf("%s", &pessoaFJ);
							// inplementar abertura de conta -----
							if (pessoaFJ == '1'){ 
								pessoa[MAX_US].tipo = PESSOA_JURIDICA;
								validacao = 1;
							}else if (pessoaFJ == '2'){
								pessoa[MAX_US].tipo = PESSOA_FISICA;
								validacao = 1;
							}else {
								printf("OPCAO INCORRETA");
							}

						}else{
							printf("limite de pessoa atingido");
						}
						
					}
					else
					{
						printf("[x][x] OPCAO INDISPONIVEL [x][x]");
					}

					fflush(stdin);//clear

				}while(validacao != 1);	

			case '2':
				printf("\n\n----exibindo atendimentos totais registrados----\n\n");
				printf("quantidade de usuarios totais: %d\n",MAX_US);
				exibirPessoasJuridicas(pessoa);
				exibirPessoasFisica(pessoa);
				exibirAberturadeConta(pessoa);
				fflush(stdin);
				system("pause");
				break;

			case '3':

				printf("\nqual categoria gostaria de consultar? \n");
				printf("\n[1]-Pessoa Juridia\n[2]-Pessoa fisica\n[3]-abertura de conta\n[4]-voltar\n");
				fflush(stdin);
				scanf("%1d",&categoria);

				if (categoria == 1)
				{
					exibirPessoasJuridicas(pessoa);
					system("pause");
					fflush(stdin);
				}
				else if(categoria == 2)
				{
					
					exibirPessoasFisica(pessoa);
					system("pause");
					fflush(stdin);
				}
				else if(categoria == 3)
				{
					
					exibirAberturadeConta(pessoa);
					system("pause");
					fflush(stdin);
				}
				else
				{
					system("cls");
					fflush(stdin);
					break;
				}

			case '4':
				
				validacao =1;
				printf("SAINDO . . . .");
				return 0;

			default:
				printf("Opcao inesistente.\n");
				fflush(stdin);
				system("pause");
				break;
			
		}
	}while(validacao !=1 );
	
	printf("\nentrou\n"); 
}
