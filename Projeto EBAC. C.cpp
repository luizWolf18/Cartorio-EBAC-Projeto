#include <stdio.h>//biblioteca de comunica��o com o usuario
#include <stdlib.h>//Biblioteca de aloca��o de espa�o e memoia
#include <locale.h>//Biblioteca de aloca��o de texto or regi�o
#include<string.h>//Biblioteca responssavel por cuidar das string

int registro()//Fun��o responsavel por cadastrar os usuarios no sitema
{
	//inicio cria��o de variaveis/string
	 char arquivo[40];
     char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s", cpf);//%s refere- se string
	
	strcpy(arquivo, cpf); //Rsponsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,nome);//salvao valor da variavel
	fclose(file);//fechaa o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,",");//salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
    fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause");		
}

int consulta()
{
 setlocale(LC_ALL,"Portuguese");//Dfnindi a Linguagem
 	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
 
	FILE *file;
    file= fopen(cpf,"r");
	 
	if(file == NULL)
	{
	    printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");	
    }
		 
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usuario: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}

    system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Diite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file= fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se econtra no sistema!.\n");
		system("pause");	
	}
	
	}


int main()
    {
	int opcao=0;//Definindo Variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	 
	 system("cls");

     setlocale(LC_ALL,"Portuguese");//Dfnindi a Linguagem
     
     printf("*** EBAC *** \n");// Inicio do menu
	 printf("\tAlunos EBAC \n\n");
	 printf("Escolha a op��o desejada do menu:\n");
	 printf("\t1- Registrar nomes\n");
	 printf("\t2- Consultar nomes\n");
	 printf("\t3- Deletar nomes\n\n");
	 printf("\t4- Sair do Sistema\n\n");
	 
	 scanf("%d", &opcao);//armazenando a escolha do usuario
	 
     system("cls");//responssavl por limpar a tela
	
	
	    switch (opcao)//inicio da sele��o do menu
	    {
		   case 1:
	      registro();//chamada de fun��es 
	       break;	
	 	
	 	   case 2:
	 	   consulta();
		   break;
		
		   case 3:
		   deletar();
		   break;
		   
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
			
		   default:
		   printf("Essa opcao nao est� disponivel\n");
		   system("pause");
		   break;
        }
    }
}



