#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ESCOLAS 5
#define MAX_UTILIZADORES 200
#define MAX_TRANSACOES 5000

typedef struct
{
    int dia,mes,ano,hora,minuto,segundo;
} t_data;

struct tm *data_hora_atual;

typedef struct
{
    int id;
    char nome[50];
    char abreviatura[5];
    int campus;
    char localidade[50];
} t_escola;

typedef struct
{
    int id;
    int id_escola;
    char nome[50];
    int nif;
    char tipo_utilizador[50];
    char email[50];
    float saldo;
} t_utilizador;

typedef struct
{
    int id;
    int id_utilizador;
    char tipo_transacao[50];
    float valor_transacao;
    t_data data;
} t_transacao;


int menu_opcoes(void);
int menu_escolas(void);
int menu_utilizadores(void);
int menu_transacoes(void);
int ler_numero(int minimo, int maximo, char texto[50]);

int registar_escolas(t_escola vetor_escolas[], int numero_escolas);
void mostrar_escolas(t_escola vetor_escolas[], int numero_escolas);
void mostra_escola(t_escola vetor_escolas[], int numero_escolas);
void verifica_escola(t_escola vetor_escolas[], int numero_escolas, t_utilizador vetor_utlizadores[], int numero_utilizadores);
int registar_utilizadores(t_utilizador vetor_utlizadores[], int numero_utilizadores, t_escola vetor_escolas[], int numero_escolas);
void mostrar_utilizadores(t_utilizador vetor_utlizadores[], int numero_utilizadores);
void mostra_utilizador(t_utilizador vetor_utlizadores[], int numero_utilizadores);
void verifica_utilizador(t_utilizador vetor_utlizadores[], int numero_utilizadores, t_transacao vetor_transacao[], int numero_transacoes);
int registar_transacoes(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores);
void mostrar_transacoes(t_transacao vetor_transacao[], int numero_transacoes);
void mostrar_transacao(t_transacao vetor_transacao[], int numero_transacoes);
void carregamentos_pagamentos(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores);
void carregamentos(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores);
void pagamentos(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores);
void data_info(t_transacao vetor_transacao[], int numero_transacoes);




int main()
{
    t_escola vetor_escolas[MAX_ESCOLAS];
    t_utilizador vetor_utilizadores[MAX_UTILIZADORES];
    t_transacao vetor_transacoes[MAX_TRANSACOES];
    int total_escolas = 0, total_utilizadores = 0, total_transacoes = 0,opcao_menu, opcao_escolas, opcao_utilizadores, opcao_transacoes;

    do
    {

        opcao_menu = menu_opcoes();

        switch(opcao_menu)
        {
        case 1:
            do
            {
                opcao_escolas = menu_escolas();

                switch(opcao_escolas)
                {
                case 1:
                    total_escolas = registar_escolas(vetor_escolas, total_escolas);
                    break;
                case 2:
                    mostrar_escolas(vetor_escolas, total_escolas);
                    break;
                case 3:
                    mostra_escola(vetor_escolas, total_escolas);
                    break;
                }
                if(opcao_escolas != 0)
                {
                    fflush(stdin);
                    getchar();
                }
            }while(opcao_escolas != 0);
            break;
        case 2:
            do
            {
                opcao_utilizadores = menu_utilizadores();

                switch(opcao_utilizadores)
                {
                case 1:
                    total_utilizadores = registar_utilizadores(vetor_utilizadores, total_utilizadores, vetor_escolas, total_escolas);
                    break;
                case 2:
                    mostrar_utilizadores(vetor_utilizadores, total_utilizadores);
                    break;
                case 3:
                    mostra_utilizador(vetor_utilizadores, total_utilizadores);
                    break;
                }
                if(opcao_utilizadores != 0)
                {
                    fflush(stdin);
                    getchar();
                }
            }while(opcao_utilizadores != 0);
            break;
        case 3:
            do
            {
                opcao_transacoes = menu_transacoes();

                switch(opcao_transacoes)
                {
                case 1:
                    total_transacoes = registar_transacoes(vetor_transacoes, total_transacoes, vetor_utilizadores, total_utilizadores);
                    break;
                case 2:
                    mostrar_transacoes(vetor_transacoes, total_transacoes);
                    break;
                case 3:
                    mostrar_transacao(vetor_transacoes, total_transacoes);
                    break;
                }
                if(opcao_transacoes != 0)
                {
                    fflush(stdin);
                    getchar();
                }
            }while(opcao_transacoes != 0);
            break;
        }

    }while(opcao_menu != 0);
}


//-----------------------Inserir Escolas---------------------------

int registar_escolas(t_escola vetor_escolas[], int numero_escolas)
{
    int campus;

    vetor_escolas[numero_escolas].id = numero_escolas;
    printf("\nInsira o nome da escola: ");
    scanf(" %[^\n]s", vetor_escolas[numero_escolas].nome);
    printf("\nInsira a abreviatura da escola: ");
    scanf(" %[^\n]s", vetor_escolas[numero_escolas].abreviatura);
    printf("\nInsira o campus da escola: ");
    scanf("%d", &campus);
    vetor_escolas[numero_escolas].campus = campus;
    printf("\nInsira a localidade da escola: ");
    scanf(" %[^\n]s", vetor_escolas[numero_escolas].localidade);

    return numero_escolas+1;
}


//-----------------------Mostrar Escolas---------------------------

void mostrar_escolas(t_escola vetor_escolas[], int numero_escolas)
{
    int indice = 0;

    for(indice ; indice < numero_escolas ; indice++)
    {
        printf("\nID: %d\n",vetor_escolas[indice].id);
        printf("Nome: %s\n",vetor_escolas[indice].nome);
        printf("Abreviatura: %s\n",vetor_escolas[indice].abreviatura);
        printf("Campus: %d\n",vetor_escolas[indice].campus);
        printf("Localidade: %s\n",vetor_escolas[indice].localidade);
    }
}


//------------------------Mostra Escola----------------------------

void mostra_escola(t_escola vetor_escolas[], int numero_escolas)
{
    int indice = 0 , id_escola;

    printf("Insira o id da escola que deseja procurar: ");
    scanf("%d", &id_escola);

    for(indice ; indice<numero_escolas ; indice++)
    {
        if(vetor_escolas[indice].id == id_escola)
        {
            printf("\nID: %d\n",vetor_escolas[indice].id);
            printf("Nome: %s\n",vetor_escolas[indice].nome);
            printf("Abreviatura: %s\n",vetor_escolas[indice].abreviatura);
            printf("Campus: %d\n",vetor_escolas[indice].campus);
            printf("Localidade: %s\n",vetor_escolas[indice].localidade);
        }
    }
}


//-----------------------------Inserir Utilizadores--------------------------------

int registar_utilizadores(t_utilizador vetor_utlizadores[], int numero_utilizadores, t_escola vetor_escolas[], int numero_escolas)
{
    int indice = 0, exit = 1;

    vetor_utlizadores[numero_utilizadores].id = numero_utilizadores;
    verifica_escola(vetor_escolas, numero_escolas, vetor_utlizadores, numero_utilizadores);
    printf("\nInsira o nome: ");
    scanf(" %[^\n]s", vetor_utlizadores[numero_utilizadores].nome);
    vetor_utlizadores[numero_utilizadores].nif = ler_numero(100000000,999999999,"o NIF");
    printf("\nInsira o tipo de utilizador (Estudante, Docente, Funcionario): ");
    scanf(" %[^\n]s", vetor_utlizadores[numero_utilizadores].tipo_utilizador);
    printf("\nInsira o email: ");
    scanf(" %[^\n]s", vetor_utlizadores[numero_utilizadores].email);
    vetor_utlizadores[numero_utilizadores].saldo = 0.00;

    return numero_utilizadores+1;
}


//-----------------------------Mostrar Utilizadores--------------------------------

void mostrar_utilizadores(t_utilizador vetor_utlizadores[], int numero_utilizadores)
{
    int indice = 0;

    for(indice ; indice<numero_utilizadores ; indice++)
    {
        printf("\nID_aluno: %d\n", vetor_utlizadores[indice].id);
        printf("ID_escola: %d\n", vetor_utlizadores[indice].id_escola);
        printf("Nome: %s\n", vetor_utlizadores[indice].nome);
        printf("NIF: %d\n", vetor_utlizadores[indice].nif);
        printf("Tipo de utilizador: %s\n", vetor_utlizadores[indice].tipo_utilizador);
        printf("Email: %s\n", vetor_utlizadores[indice].email);
        printf("Saldo: %.2f\n", vetor_utlizadores[indice].saldo);
    }
}


//-----------------------------Mostra Utilizador--------------------------------

void mostra_utilizador(t_utilizador vetor_utlizadores[], int numero_utilizadores)
{
    int indice = 0 , id_utilizador;

    printf("Insira o id do utilizador que deseja procurar: ");
    scanf("%d", &id_utilizador);

    for(indice ; indice<numero_utilizadores ; indice++)
    {
        if(vetor_utlizadores[indice].id == id_utilizador)
        {
            printf("\nID_aluno: %d\n", vetor_utlizadores[indice].id);
            printf("ID_escola: %d\n", vetor_utlizadores[indice].id_escola);
            printf("Nome: %s\n", vetor_utlizadores[indice].nome);
            printf("NIF: %d\n", vetor_utlizadores[indice].nif);
            printf("Tipo de utilizador: %s\n", vetor_utlizadores[indice].tipo_utilizador);
            printf("Email: %s\n", vetor_utlizadores[indice].email);
            printf("Saldo: %.2f\n", vetor_utlizadores[indice].saldo);
        }
    }
}


//-----------------------------Inserir Transações--------------------------------

int registar_transacoes(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores)
{
    int id_utilizador, indice = 0;

    vetor_transacao[numero_transacoes].id = numero_transacoes;
    verifica_utilizador(vetor_utlizadores, numero_utilizadores, vetor_transacao, numero_transacoes);
    data_info(vetor_transacao, numero_transacoes);

    return numero_transacoes+1;
}


//-----------------------------Mostrar Transações--------------------------------

void mostrar_transacoes(t_transacao vetor_transacao[], int numero_transacoes)
{
    int indice = 0;

    for(indice ; indice<numero_transacoes ; indice++)
    {
        printf("\nID: %d\n", vetor_transacao[indice].id);
        printf("ID Utilizador: %d\n", vetor_transacao[indice].id_utilizador);
        printf("Tipo de Transacao: %s\n", vetor_transacao[indice].tipo_transacao);
        printf("Valor da Transacao: %.2f\n", vetor_transacao[indice].valor_transacao);
        printf("Data: %d/%d/%d\n", vetor_transacao[indice].data.dia,vetor_transacao[indice].data.mes, vetor_transacao[indice].data.ano);
        printf("Horas: %d:%d:%d", vetor_transacao[indice].data.hora,vetor_transacao[indice].data.minuto,vetor_transacao[indice].data.segundo);
    }
}


//-----------------------------Mostra Transaçao--------------------------------

void mostrar_transacao(t_transacao vetor_transacao[], int numero_transacoes)
{
    int indice, transacao;

    printf("Insira o ID da transacao: ");
    scanf("%d", &transacao);

    for(indice = 0; indice<numero_transacoes ; indice++)
    {
        if(vetor_transacao[indice].id == transacao)
        {
            printf("\nID: %d\n", vetor_transacao[indice].id);
            printf("ID Utilizador: %d\n", vetor_transacao[indice].id_utilizador);
            printf("Tipo de Transacao: %s\n", vetor_transacao[indice].tipo_transacao);
            printf("Valor da Transacao: %.2f\n", vetor_transacao[indice].valor_transacao);
            printf("Data: %d/%d/%d\n", vetor_transacao[indice].data.dia,vetor_transacao[indice].data.mes, vetor_transacao[indice].data.ano);
            printf("Horas: %d:%d:%d", vetor_transacao[indice].data.hora,vetor_transacao[indice].data.minuto,vetor_transacao[indice].data.segundo);
        }
    }
}


//-----------------------------Menus--------------------------------

int menu_opcoes()
{
    int opcao;

    do
    {
        system("cls");
        printf("\n1 - Escolas\n2 - Utilizadores\n3 - Transacoes\n0 - Exit\nInsira: ");
        scanf("%d", &opcao);
    }while(opcao != 1 && opcao !=2 && opcao != 3 && opcao != 0);
    return opcao;
}

int menu_escolas(void)
{
    int opcao;

    do
    {
        system("cls");
        printf("\n1 - Registar Escolas\n2 - Consultar Escolas\n3 - Consulte Escola\n0 - Exit\nInsira: ");
        scanf("%d", &opcao);
    }while(opcao != 1 && opcao !=2 && opcao!=3 && opcao != 0);
    return opcao;
}

int menu_utilizadores(void)
{
    int opcao;

    do
    {
        system("cls");
        printf("\n1 - Registar Utilizador\n2 - Consultar Utilizadores\n3 - Consulte Utilizador\n0 - Exit\nInsira: ");
        scanf("%d", &opcao);
    }while(opcao != 1 && opcao !=2 && opcao!=3 && opcao != 0);
    return opcao;
}

int menu_transacoes(void)
{
    int opcao;

    do
    {
        system("cls");
        printf("\n1 - Registar Transacao\n2 - Consultar Transacao\n3 - Consulte Transacao\n0 - Exit\nInsira: ");
        scanf("%d", &opcao);
    }while(opcao != 1 && opcao !=2 && opcao!=3 && opcao != 0);
    return opcao;
}

//----------------------------Ler numeros--------------------------

int ler_numero(int minimo, int maximo, char texto[50])
{
    int numero;
    do
    {
        printf("Insira %s entre %d e %d: ", texto, minimo, maximo);
        scanf("%d", &numero);
    }while(numero < minimo || numero > maximo);
}


//----------------------------Funções Complementares--------------------------

void verifica_escola(t_escola vetor_escolas[], int numero_escolas, t_utilizador vetor_utlizadores[], int numero_utilizadores)
{
    int id_escola, indice, exit = 1;

    do
    {
        indice = 0;
        printf("\nInsira o ID da escola: ");
        scanf("%d", &id_escola);
        for(indice ; indice<numero_escolas ; indice++)
        {
            if(vetor_escolas[indice].id == id_escola)
            {
                vetor_utlizadores[numero_utilizadores].id_escola = id_escola;
                exit = 0;
            }
        }
        if(exit != 0)
        {
            printf("Escola nao encontrada. Tente inserir um id valido!\n");
        }
    }while(exit != 0);
}

void verifica_utilizador(t_utilizador vetor_utlizadores[], int numero_utilizadores, t_transacao vetor_transacao[], int numero_transacoes)
{
    int id_utilizador, indice, exit = 1;

    do
    {
        indice = 0;
        printf("\nInsira o ID do utilizador: ");
        scanf("%d", &id_utilizador);
        for(indice ; indice<numero_utilizadores ; indice++)
        {
            if(vetor_utlizadores[indice].id == id_utilizador)
            {
                vetor_transacao[numero_transacoes].id_utilizador = id_utilizador;
                carregamentos_pagamentos(vetor_transacao, numero_transacoes, vetor_utlizadores, id_utilizador);
                exit = 0;
            }
        }
        if(exit != 0)
        {
            printf("Utilizador nao encontrado. Tente inserir um id valido!\n");
        }
    }while(exit != 0);
}

void carregamentos_pagamentos(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores)
{
    int opcao;
    float valor;

    do
    {
        printf("\n1 - Carregamento\n2 - Pagamento\nInsira: ");
        scanf("%d", &opcao);
        if(opcao == 1)
        {
            strcpy(vetor_transacao[numero_transacoes].tipo_transacao, "Carregamento");
            carregamentos(vetor_transacao, numero_transacoes, vetor_utlizadores, numero_utilizadores);
        }
        else if(opcao == 2)
        {
            strcpy(vetor_transacao[numero_transacoes].tipo_transacao, "Pagamento");
            pagamentos(vetor_transacao, numero_transacoes, vetor_utlizadores, numero_utilizadores);
        }
        else if(opcao != 1 && opcao != 2)
        {
            printf("Insira um valor válido!");
        }
    }while(opcao != 1 && opcao != 2);
}

void data_info(t_transacao vetor_transacao[], int numero_transacoes)
{
    time_t segundos;

    time(&segundos);

    data_hora_atual = localtime(&segundos);

    vetor_transacao[numero_transacoes].data.dia = data_hora_atual->tm_mday;
    vetor_transacao[numero_transacoes].data.mes = data_hora_atual->tm_mon+1;
    vetor_transacao[numero_transacoes].data.ano = data_hora_atual->tm_year+1900;
    vetor_transacao[numero_transacoes].data.hora = data_hora_atual->tm_hour;
    vetor_transacao[numero_transacoes].data.minuto = data_hora_atual->tm_min;
    vetor_transacao[numero_transacoes].data.segundo = data_hora_atual->tm_sec;
}

void carregamentos(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores)
{
    float valor;

    printf("\nInsira o valor da transacao: ");
    scanf("%f", &valor);
    printf("%f", valor);
    vetor_transacao[numero_transacoes].valor_transacao = vetor_transacao[numero_transacoes].valor_transacao + valor;
    printf("%d", numero_utilizadores);
    vetor_utlizadores[numero_utilizadores].saldo = vetor_utlizadores[numero_utilizadores].saldo + valor;
}

void pagamentos(t_transacao vetor_transacao[], int numero_transacoes, t_utilizador vetor_utlizadores[], int numero_utilizadores)
{
    float valor;

    printf("\nInsira o valor da transacao: ");
    scanf("%f", &valor);
    vetor_transacao[numero_transacoes].valor_transacao = vetor_transacao[numero_transacoes].valor_transacao - valor;
    vetor_utlizadores[numero_utilizadores].saldo = vetor_utlizadores[numero_utilizadores].saldo - valor;
}
