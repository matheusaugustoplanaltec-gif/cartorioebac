#include <stdio.h>   // Biblioteca padrão de entrada e saída. Permite usar funções como printf e scanf para se comunicar com o usuário.
#include <stdlib.h>  // Biblioteca para alocação de memória, conversão de tipos, controle de processos e outras utilidades do sistema.
#include <locale.h>  // Biblioteca que permite configurar a localização (idioma, acentuação, formatos de data e número, etc.).
#include <string.h>  // Biblioteca que fornece funções para manipular cadeias de caracteres (strings), como copiar, comparar e medir tamanho.3'
		
int registro()  // função responsavel por cadastrar o usuario no sistema
{                   //inicio na criação das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informação do usuario
	scanf("%s", cpf);         //%s refere-se a armazenar informação em uma string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo  e o "w" sgnifica escrever 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo atualizado
	fprintf(file,","); //adiciona uma virgula no codigo
	fclose(file);  // fecha o file 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	int escolha;

printf("\nDeseja adicionar mais um usuário ou voltar ao menu?\n");
printf("1 - Adicionar outro usuário\n");
printf("2 - Menu\n");
scanf("%d", &escolha);

switch (escolha) {
    case 1:
        registro();
        break;
    case 2:
        return 0;
    default:
        printf("Opção inválida!\n");
}
	
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf que deseja consultar");
	scanf("%s",cpf);
		
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // procura o arquivo
	 
	 if(file == NULL) // compara se o arquivo existe com o banco de dados 
	 {
	 	printf("Não foi possivel identificar o cpf");
	
	 }
	 	while(fgets(conteudo, 200, file) != NULL)
	 	{
	 		printf(" Essas são as informações do usuario: ");
	 		printf("%s",conteudo);
		}
		  system("pause");
}
	


int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	
	printf("Digite o cpf que deseja excluir");
	scanf("%s",cpf);
		
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // procura o arquivo
	 remove(cpf);
	 if(file == NULL) // compara se o arquivo existe com o banco de dados 
{
	 	printf("Não foi possivel identificar o cpf");
		system("pause");
}
	 	
}



	
int main()
	{
	int opcao=0; 
	int x=1;
	char senhadigitada[10] = "a";
	int comparacao;
	
	printf("#Cartorio da EBAC #\n\n");
	printf("Loguin de adiministrador, digite sua Senha\n\n");
	scanf("%s", senhadigitada);
	printf("\nSenha digitada: %s\n", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	if (comparacao == 0)
	{
	
		for(x=1;x=1;)
		{

			system("cls");

			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
			printf("#Cartorio da EBAC #\n\n"); //inicio do menu
			printf("Escolha uma opção : \n\n");
			printf("\t1 - Registrar \n");
			printf("\t2 - Consultar \n");
			printf("\t3 - Deletar \n");
						
			scanf("%d", &opcao); //armazenando dentro da opçao
		
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
				printf("invalido\n");
				system("pause");
				break;
			
			} 
		}
	
	}
  		else 
 		printf("senha incorreta");
	
}
	
