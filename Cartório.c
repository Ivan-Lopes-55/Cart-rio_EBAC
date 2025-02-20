#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bibliotexa de alocação de texto por região
#include <string.h> //biblioteca de strings

int opcao=0;//definindo variáveis
int x=1;
	
int registro() //funcção responsável por cadastrar os usuários no sistema
{
	char cpf[40]; //variáves
	char nome[40]; //variáves
	char sobrenome[40]; //variáves
	char cargo[40]; //variáves
	char arquivo[40]; //variáves
	int n=1; //variáves
	char repete; //variáves
	
	
	for(n = 1; n == 1;) //cicla a operação para repetir sem voltar ao menu, utilizando a variável "n"
	{
		
		system("cls");
	
		printf("Você escolheu o registro de nomes.\n\n");
	
	
		printf("Digite o CPF a ser cadastrado: \n");
		scanf("%s",cpf); //colhe informação do usuário para CPF
	
		strcpy(arquivo, cpf); //copia os valores das strings
	
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file, cpf); //salva o valor da variável
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informações
		fclose(file); //fecha o arquivo
	
		printf("Digite o nome a ser cadastrdo: \n");
		scanf("%s", nome); //colhe informação do usuário para nome
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, nome); //salva o valor da variável
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informações
		fclose(file); //fecha o arquivo
	
		printf("Digite o sobrenome: \n");
		scanf("%s", sobrenome); //colhe informação do usuário para sobrenome
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, sobrenome);//salva o valor da variável
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informações
		fclose(file); //fecha o arquivo
	
		printf("Digite o cargo: \n");
		scanf("%s", cargo); //colhe informação do usuário para cargo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, cargo);//salva o valor da variável
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo,"a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informações
		fclose(file); //fecha o arquivo
	
		printf("Cadastrado com sucesso! Deseja cadastrar um novo nome? Digite S para Sim ou N para voltar ao menu.\n");
		scanf(" %c", &repete); //colhe a resposta se o usuário quer repetir a operação
		//printf(" %c", repete);
	
		while(repete != 's' && repete != 'S' && repete != 'n' && repete != 'N'){ //valida se a resposta é correta para repetir a operação
			printf("Resposta inválida. Digite S para Sim ou N para voltar ao menu\n");
			scanf(" %c", &repete);

			}
		if(repete == 'n' || repete =='N'){
			n = 0; //altera a variável n para o caso do usuário escolha N e interrompe o looping voltando ao menu
		}
		
	}
}
int consulta()
{
	int n=1;
	char repete;
	
	for(n = 1; n == 1;)//cicla a operação para repetir sem voltar ao menu, utilizando a variável "n"
	{
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("Você escolheu consultar  nomes.\n\n");
	
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado\n");
		scanf("%s",cpf); //colhe a informação do cpf que vai ser consultado
	
		FILE *file;
		file = fopen(cpf,"r");//abre o arquivo
	
		if(file == NULL){
			printf("Não foi possivel localizar o arquivo\n");//resposta para se o arquivo não for encontrado
		}
	
		while(fgets(conteudo, 200, file)!= NULL) { // colhe as informações do arquivo caso o arquivo seja encontrado e armazena na variavel conteudo
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo); //exibe essas informações na variavel conteudo
			printf("\n\n");
		
		}
		printf("Deseja consultar um novo nome? Digite S para Sim ou N para voltar ao menu.\n");
		scanf(" %c", &repete); //colhe a resposta se o usuário quer repetir a operação
		//printf(" %c", repete);
	
		while(repete != 's' && repete != 'S' && repete != 'n' && repete != 'N'){//valida se a resposta é correta para repetir a operação
			printf("Resposta inválida. Digite S para Sim ou N para voltar ao menu\n");
			scanf(" %c", &repete);

		}
		if(repete == 'n' || repete =='N'){
			n = 0; //altera a variável n para o caso do usuário escolha N e interrompe o looping voltando ao menu
		}
	}
	
}
int deletar()
{
	char cpf[40]; //variavel
	
	printf("Você escolheu deletar nomes.\n\n");
	
	printf("Informe o CPF que deseja deletar: \n");
	scanf("%s", cpf); //colhe informação
	
	FILE *file; //chama a função arquivo
	file = fopen(cpf,"r"); //le o arquivo na pasta
	
	if(file == NULL) //resposta para o caso do arquivo não ser encontrado
	{
		printf("Usuário não encontrado. \n\n");
		system("pause");
	}
	
	else
	{
		remove(cpf); //caso contrario ele deleta o arquivo
		printf("Usuário deletado com sucesso. \n\n");
		system("pause");
		
	}
	
}
int main()
{
	
	for(x=1;x=1;){ //looping para voltar ao menu
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Digite a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n"); //final do menu
		printf("Opção: ");
		//printf("Esse Software foi deselvolvido pelo aluno: Ivan Lopes\n");
	
		scanf("%d", &opcao); //armazenando as seleções
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
				
			default:
				printf("Essa opção não está disponível.\n\n");
				system("pause");
			break;
		}
	

	}
}
