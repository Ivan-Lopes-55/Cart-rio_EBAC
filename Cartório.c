#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibliotexa de aloca��o de texto por regi�o
#include <string.h> //biblioteca de strings

int opcao=0;//definindo vari�veis
int x=1;
	
int registro() //func��o respons�vel por cadastrar os usu�rios no sistema
{
	char cpf[40]; //vari�ves
	char nome[40]; //vari�ves
	char sobrenome[40]; //vari�ves
	char cargo[40]; //vari�ves
	char arquivo[40]; //vari�ves
	int n=1; //vari�ves
	char repete; //vari�ves
	
	
	for(n = 1; n == 1;) //cicla a opera��o para repetir sem voltar ao menu, utilizando a vari�vel "n"
	{
		
		system("cls");
	
		printf("Voc� escolheu o registro de nomes.\n\n");
	
	
		printf("Digite o CPF a ser cadastrado: \n");
		scanf("%s",cpf); //colhe informa��o do usu�rio para CPF
	
		strcpy(arquivo, cpf); //copia os valores das strings
	
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file, cpf); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informa��es
		fclose(file); //fecha o arquivo
	
		printf("Digite o nome a ser cadastrdo: \n");
		scanf("%s", nome); //colhe informa��o do usu�rio para nome
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, nome); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informa��es
		fclose(file); //fecha o arquivo
	
		printf("Digite o sobrenome: \n");
		scanf("%s", sobrenome); //colhe informa��o do usu�rio para sobrenome
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, sobrenome);//salva o valor da vari�vel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informa��es
		fclose(file); //fecha o arquivo
	
		printf("Digite o cargo: \n");
		scanf("%s", cargo); //colhe informa��o do usu�rio para cargo
	
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file, cargo);//salva o valor da vari�vel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo,"a"); //abre o arquivo
		fprintf(file, ";"); //coloca um ";" para separar as informa��es
		fclose(file); //fecha o arquivo
	
		printf("Cadastrado com sucesso! Deseja cadastrar um novo nome? Digite S para Sim ou N para voltar ao menu.\n");
		scanf(" %c", &repete); //colhe a resposta se o usu�rio quer repetir a opera��o
		//printf(" %c", repete);
	
		while(repete != 's' && repete != 'S' && repete != 'n' && repete != 'N'){ //valida se a resposta � correta para repetir a opera��o
			printf("Resposta inv�lida. Digite S para Sim ou N para voltar ao menu\n");
			scanf(" %c", &repete);

			}
		if(repete == 'n' || repete =='N'){
			n = 0; //altera a vari�vel n para o caso do usu�rio escolha N e interrompe o looping voltando ao menu
		}
		
	}
}
int consulta()
{
	int n=1;
	char repete;
	
	for(n = 1; n == 1;)//cicla a opera��o para repetir sem voltar ao menu, utilizando a vari�vel "n"
	{
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("Voc� escolheu consultar  nomes.\n\n");
	
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado\n");
		scanf("%s",cpf); //colhe a informa��o do cpf que vai ser consultado
	
		FILE *file;
		file = fopen(cpf,"r");//abre o arquivo
	
		if(file == NULL){
			printf("N�o foi possivel localizar o arquivo\n");//resposta para se o arquivo n�o for encontrado
		}
	
		while(fgets(conteudo, 200, file)!= NULL) { // colhe as informa��es do arquivo caso o arquivo seja encontrado e armazena na variavel conteudo
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo); //exibe essas informa��es na variavel conteudo
			printf("\n\n");
		
		}
		printf("Deseja consultar um novo nome? Digite S para Sim ou N para voltar ao menu.\n");
		scanf(" %c", &repete); //colhe a resposta se o usu�rio quer repetir a opera��o
		//printf(" %c", repete);
	
		while(repete != 's' && repete != 'S' && repete != 'n' && repete != 'N'){//valida se a resposta � correta para repetir a opera��o
			printf("Resposta inv�lida. Digite S para Sim ou N para voltar ao menu\n");
			scanf(" %c", &repete);

		}
		if(repete == 'n' || repete =='N'){
			n = 0; //altera a vari�vel n para o caso do usu�rio escolha N e interrompe o looping voltando ao menu
		}
	}
	
}
int deletar()
{
	char cpf[40]; //variavel
	
	printf("Voc� escolheu deletar nomes.\n\n");
	
	printf("Informe o CPF que deseja deletar: \n");
	scanf("%s", cpf); //colhe informa��o
	
	FILE *file; //chama a fun��o arquivo
	file = fopen(cpf,"r"); //le o arquivo na pasta
	
	if(file == NULL) //resposta para o caso do arquivo n�o ser encontrado
	{
		printf("Usu�rio n�o encontrado. \n\n");
		system("pause");
	}
	
	else
	{
		remove(cpf); //caso contrario ele deleta o arquivo
		printf("Usu�rio deletado com sucesso. \n\n");
		system("pause");
		
	}
	
}
int main()
{
	
	for(x=1;x=1;){ //looping para voltar ao menu
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Digite a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n"); //final do menu
		printf("Op��o: ");
		//printf("Esse Software foi deselvolvido pelo aluno: Ivan Lopes\n");
	
		scanf("%d", &opcao); //armazenando as sele��es
	
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
				printf("Essa op��o n�o est� dispon�vel.\n\n");
				system("pause");
			break;
		}
	

	}
}
