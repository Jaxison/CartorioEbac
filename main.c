#include <stdio.h>  //comunicação com usuário
#include <stdlib.h> //alocação de espaço em memória
#include <locale.h> //incluir caracteres da lingua por regiao
#include <string.h> //responsavel por cuidar das str

void registro() //Registro de usuário
{
    int continuar = 2;
    while (continuar == 2)
    {
    setlocale(LC_ALL, "Portuguese");//Linguagem 

    printf("Você selecionou registrar usuário\n");

    char arquivo[40];
    char cpf[15];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char nascimento[11];
    ///   Variaveis 

    printf("Para fazer o registro informe os dados logo abaixo.\nCPF: ");//Input
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //Copia valores das str
    strcat(arquivo, ".txt");

    FILE *file; //cria o arquivo
    file = fopen (arquivo, "w"); //cria o arquivo
    if (file == NULL)

    {
        printf("Erro ao criar arquivo");
        return;
    }

    fprintf(file, "CPF: %s\n", cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    file = fopen(arquivo, "a");    

    printf("Nome: ");
    scanf("%s", nome); 
    fprintf(file, "Nome: %s\n", nome);
    
    printf("Sobrenome: ");
    scanf("%s", sobrenome);
    fprintf(file, "Sobrenome: %s\n", sobrenome);

    printf("Cargo ocupacional: ");
    scanf("%s", cargo);
    fprintf(file, "Cargo: %s\n", cargo);
    
    printf("Data de nascimento: ");
    scanf("%s", nascimento);
    fprintf(file, "Nascimento: %s\n", nascimento);

    fclose(file);
    system("cls");
    printf("\tRegistro finalizado com sucesso!\n");
    printf("Deseja: \n 1 - Voltar ao menu\n 2 - Registrar outro usuário\nEscolha: ");
    scanf("%d", &continuar);
    }
}
void consultar()
{   int continuar = 2;
    while (continuar == 2)
    {
    setlocale(LC_ALL, "Portuguese");//Linguagem
    char cpf[15];
    char conteudo[200];

    printf("Você selecionou Consultar Usuário, informe o cpf a ser consultado\nCpf: ");
    scanf("%s", cpf);

    char arquivo[60];
    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");

    FILE *file;
    file = fopen(arquivo,"r");

    if(file == NULL)
    {
        printf("Usuário não foi encontrado, cpf inválido ou não cadastrado.");
    }
    system("cls");
    printf("\t---Essas são as informações do usuário---\n");
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("%s", conteudo);
    }
    system("pause");
    system("cls");
    printf("\tConsulta finalizada com sucesso!\n");
    printf("Deseja: \n 1 - Voltar ao menu\n 2 - Consultar outro usuário\nEscolha: ");
    scanf("%d", &continuar);
    }

}

void excluir()

{  
    int continuar = 2;
    while (continuar == 2)
    {
    setlocale(LC_ALL, "Portuguese");//Linguagem

    char cpf[15];
    char arquivo[60];

    printf("\t--- Você selecionou Excluir registro ---\n\nInsira o CPF do usuário a ser deletado\nCPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //Copia valores das str
    strcat(arquivo, ".txt");

    FILE * file;
    file = fopen(arquivo,"r");

    if(file == NULL)
    {
        printf("O usuário não foi removido pois não está cadastrado!\n");
        system("pause");
        return;
    }
    fclose(file);
    
    int opcao = 0;

    printf("Tem certeza que gostaria de excluir usuário?\n\t1 - Excluir usuário\n\t2 - Voltar ao menu\nEscolha:  ");
    scanf("%d", &opcao);

    if (opcao == 1 && remove(arquivo) == 0)
    {
        printf("Usuário foi removido com sucesso!.\n");
    }
    else 
    {
       printf("Exclusão foi cancelada.\n");
    }
    system("cls");
    printf("\tExclusão finalizada com sucesso!\n");
    printf("Deseja: \n 1 - Voltar ao menu\n 2 - Excluir outro usuário\nEscolha: ");
    scanf("%d", &continuar);
    }
}

int main() 
{
    int opcao = 0; //Variavel
    int laco = 1;
    for (laco = 1;laco == 1;)
{
    system("cls");//Clean terminal

   setlocale(LC_ALL, "Portuguese");//Linguagem

    printf("\t---- CENTRAL EBAC ----\n\n");//Start
    printf("Selecione alguma opção para prosseguir:\n\n");
    printf("\t 1 - Registrar usuários\n\n");
    printf("\t 2 - Consultar usuários\n\n");
    printf("\t 3 - Excluir usuários\n\n");
    printf("Opção: ");
    scanf ("%d", &opcao);//Input of user
    system("cls");//Clean terminal

    switch (opcao)//Cases of choose
    {
    case 1:
        registro();
        break;
    case 2:
        consultar();
        break;
    case 3:
        excluir();
        break; 
    default:
        printf("Comando invalido, tente novamente\n");
        system("pause");
        break;
    }

}

}
