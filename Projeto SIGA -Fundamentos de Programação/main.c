#include <stdio.h>
#include <stdlib.h>

#define MAX_ESCOLAS 5
#define MAX_UTILIZADORES 200
#define MAX_TRANSACOES 5000

typedef struct
{
    int id;
    char nome[50];
    char abreviatura[5];
    char campus[10];
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
    float salto;
} t_utilizador;

typedef struct
{
    int id;
    int id_utilizador;
    char tipo_transacao[50];
    float valor_transacao;
    char data[10];
    char hora[10];
} t_transacao;

int menu_opcoes(void);
int menu_escolas(void);
int menu_utilizadores(void);
int menu_transacoes(void);
int ler_numero(int minimo, int maximo, char texto[50]);

int registar_escolas(t_escola vetor_escolas[], int numero_escolas);
void mostrar_escolas(t_escola vetor_escolas[], int numero_escolas);
void mostra_escola(t_escola vetor_escolas[], int numero_escolas);
int registar_utilizadores(t_utilizador vetor_utlizadores[], int numero_utilizadores);
void mostrar_utilizadores(t_escola vetor_utlizadores[], int numero_utilizadores);
int registar_transacoes(t_utilizador vetor_utlizadores[], int numero_transacoes);
void mostrar_transacoes(t_escola vetor_utlizadores[], int numero_transacoes);




int main()
{
    t_escola vetor_escolas[MAX_ESCOLAS];
    t_utilizador vetor_utilizadores[MAX_UTILIZADORES];
    int total_escolas = 0, total_alunos = 0, total_transacoes = 0,opcao_menu, opcao_escolas;

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
        case 2:

            break;
        case 3:
            break;
        case 5:
            break;
        }

    }while(opcao_menu != 0);
}


//-----------------------Inserir Escolas---------------------------

int registar_escolas(t_escola vetor_escolas[], int numero_escolas)
{
    vetor_escolas[numero_escolas].id = numero_escolas;
    printf("\nInsira o nome da escola: ");
    scanf(" %[^\n]s", vetor_escolas[numero_escolas].nome);
    printf("\nInsira a abreviatura da escola: ");
    scanf(" %[^\n]s", vetor_escolas[numero_escolas].abreviatura);
    printf("\nInsira o campus da escola: ");
    scanf(" %[^\n]s", vetor_escolas[numero_escolas].campus);
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
        printf("Campus: %s\n",vetor_escolas[indice].campus);
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
            printf("Campus: %s\n",vetor_escolas[indice].campus);
            printf("Localidade: %s\n",vetor_escolas[indice].localidade);
        }
    }

}


//-----------------------------Inserir Utilizadores--------------------------------



//-----------------------------Menus--------------------------------

int menu_opcoes()
{
    int opcao;

    do
    {
        system("cls");
        printf("\n1 - Registar Escolas\n2 - Consultar Escolas\n3 - Registar Utilizadores\n4 - Consultar Utilizadores\n5 - Registar Transacoes\n6 - Consultar Transacoes\n0 - Exit\nInsira: ");
        scanf("%d", &opcao);
    }while(opcao != 1 && opcao !=2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 0);
    return opcao;
}

int menu_escolas(void)
{
    int opcao;

    do
    {
        system("cls");
        printf("\n1 - Registar Escolas\n2 - Consultar Escolas\n3 - Consule Escola\n0 - Exit\nInsira: ");
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
        printf("Insira %s entre %d e %d: ", minimo,maximo,texto);
        scanf("%d", &numero);
    }while(numero < minimo || numero > maximo);
}
