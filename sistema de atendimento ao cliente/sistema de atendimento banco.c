#include <stdio.h>
#include <math.h>
#include <string.h>

enum TipoPessoa {
    PESSOA_FISICA,
    PESSOA_JURIDICA
};

struct usuario{

	enum tipoPessoa tipo;
	char setor[20] ;
	char nome [50] ;
	char cpf[12];
	int valor;
	
};

void exibirCliente(struct usuario cliente) {

    printf("Nome: %s\n", cliente.nome);
    printf("Documento: %s\n", cliente.cpf);

    if (cliente.tipo == PESSOA_FISICA) {
        printf("Tipo: Pessoa Física\n");
    } else if (cliente.tipo == PESSOA_JURIDICA) {
        printf("Tipo: Pessoa Jurídica\n");
    }
	
    printf("\n");
}

int main(){

	struct usuario pessoa[50];

	int  categoria = 0 ;
	int  clientes = 0;
	char opcao;
	char pessoaFJ;
	int  validacao = 0;

	strcpy(pessoa[0].cpf , "11122233344");
	strcpy(pessoa[0].nome , "kevin");

	
	//menu-------------------------------------------------
	do{

		system("cls");
		printf("menu principal\n"
			"1 - selecionar atendimento \n"
			"2 - lista de atendimento \n"
			"3 - lista de atendimento por setor \n"
			"4 - sair \n");
		
		scanf("%c", &opcao);
		
		switch (opcao){
			case '1':
				// CADASTRO ----------------------
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
						// percorre a struct CPF para validacao ----
						for (int i = 0; i <= 50 ; i++)
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

						if (clientes < 100){

							clientes ++;
							printf("\ninforme seu cpf: \n");//conferir se CPF ja é existente. ------------ [X]
							fflush(stdin); // Limpa o buffer do teclado
							fgets(pessoa[clientes].cpf, sizeof(pessoa[clientes].cpf), stdin);

							printf("\ninforme seu Nome: \n");
							fflush(stdin); // Limpa o buffer do teclado
							fgets(pessoa[clientes].nome, sizeof(pessoa[clientes].nome), stdin);
								
							//DEFININDO SETOR-------------------------

							printf("\n[1] Conta Pessoa Juridica\n[2] Conta Pessoa Fisica\n");
							fflush(stdin);
							scanf("%s", &pessoaFJ);
							
							if (pessoaFJ == '1'){ 
								strcpy (pessoa[clientes].setor, "Pessoa Juridica."); 
							}else if (pessoaFJ == '2'){
								strcpy (pessoa[clientes].setor, "Pessoa fisica.");
							}else {
								printf("OPCAO INCORRETA");
							}

						}else{
							printf("limite de clientes atingido");
						}
						
					}
					else
					{
						printf("[x][x] OPCAO INDISPONIVEL [x][x]");
					}

					fflush(stdin);//clear

				}while(validacao != 1);	

			case '2':
				
				printf("\nqual categoria gostaria de consultar? \n");
				printf("\n[1]-Pessoa Juridia\n[2]-Pessoa fisica\n[4]-voltar\n");
				fflush(stdin);
				scanf("%1d",&categoria);

				if (categoria == 1)
				{

					printf("\n-------- lista Pessoa Juridica --------\n");
					for (int j = 0 ; j <= 50 ; j++){

						printf ("%s\n", pessoa[0].setor);

					}

					system("pause");


				}
				else if(categoria == 2)
				{
					printf("-------- lista Pessoa Fisica --------");
					system("pause");
				}
				else
				{
					break;
				}
			case '3':
				
				break;
			case '4':
				
				validacao =1;
				printf("SAINDO . . . .");
				return 0;

			default:
				
				break;
			
		}

	}while(validacao !=1 );
	

	printf("\nentrou\n"); 
}
