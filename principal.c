#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "abb.h"
#include "fila.h"

#define TAM 50 

typedef struct secretario{
    int cpf;
    char * nome;
    char * senha;
    struct secretario *prox;
    struct secretario *ant;
}SECRETARIO;

SECRETARIO *new_sec = NULL;
int id_sec = 0;

void add_sec(char *nome, char *senha, int cpf){
    SECRETARIO *novo = malloc(sizeof(SECRETARIO));
    novo->nome = nome;
    novo->senha = senha;
    novo->cpf = cpf;
    novo->ant = NULL;
    novo->prox = NULL;
    
    if(new_sec == NULL){ //lista vazia
            new_sec = novo;
            fim = novo;
            id_sec++;
    }else{
        new_sec->ant = novo;
        novo->prox = new_sec;
        new_sec = novo;
        id_sec++;
    }

}

int gerar_id(){
    int i;
    srand((unsigned)time(NULL));

    do{
        i = (rand() % 100 -10) * (rand() % 100 -10);
    //}while(buscar(i, tree) != NULL);
    }while(i < 999);
    
    return i;
        
}

char temporizador()
{
    time_t tempo;
    char data_Pedido[50];

    /* Recupera a quantidade de segundos desde 01/01/1970 */
    tempo = time(NULL);

    strftime(data_Pedido, sizeof(data_Pedido), "%d/%m/%Y %H:%M:%S", localtime( &tempo ));

    return data_Pedido;
}


void menu(){
    DOCUMENTO * encontrado;
    char nome[TAM];
    char titulo[TAM];
    char autor[TAM];
    char assunto[TAM];
    char data_emp[TAM];
    int matricula;
    int opcao = -1;
    int id;

    do{

        printf("\n\n------------ Menu Biblioteca ------------\n");
        printf("\n\t[1] Adicionar Encomenda\n");
        printf("\t[2] Remover Pedido\n");
        printf("\t[3] Remover Encomenda\n");
        printf("\t[0] Sair\n");
        printf("\nQual a sua opção? ");
        scanf("%d",&opcao);


        switch(opcao){
            case 1://Nesse caso o usuario adiciona um novo ID na arvore
                printf("\n------------ Menu Adicionar Pedido ------------\n\n");
                printf("\nAdicionar Pedido: ");
                //encomendar um livro
                id = gerar_id();

                printf(" Digite o nome do aluno:\n");
                //fflush(stdin);
                __fpurge(stdin);
                scanf("%s[^\n]", &nome);

                printf(" Digite a matricula:\n");
                scanf("%d", &matricula);

                printf(" Digite o titulo do livro:\n");
                //fflush(stdin);
                __fpurge(stdin);
                scanf("%s[^\n]", &titulo);

                printf(" Digite o autor:\n");
                //fflush(stdin);
                __fpurge(stdin);
                scanf("%s[^\n]", &autor);

                printf(" Digite o assunto:\n");
                //fflush(stdin);
                __fpurge(stdin);
                scanf("%s[^\n]", &assunto);

                data_emp[TAM] = temporizador();

            add_abb(id, nome, matricula, titulo, autor, assunto, data_emp);
                
                // Funcao que pede dados e realiza a funcao
            break;
            case 2://Nesse caso se remove o pedido sendo adicionado um documento no lugar
                printf("\n------------ Menu Remover Pedido ------------\n\n");
                printf("\nRemover Pedido: ");
                // Funcao que pede dados e realiza a funcao
            break;
            case 3://Nesse caso se remove o documento de encomenda pelo transportador
                printf("\n------------ Menu Remover Encomenda ------------\n\n");
                printf("\nRemover Encomenda: ");
                // Funcao que pede dados e realiza a funcao
                               
                //2 - verificar o usuario
                    printf(" Digite seu cpf:\n");
                    char cpf[100];
                    scanf("%s", &cpf);
                    printf(" Digite sua senha:\n");
                    char senha[100];
                    scanf("%s", &senha);
                    //int retorno = verificar(cpf, senha);
                    if(opcao == 1){
                        //remover da fila de prioridade
                    }
            break;
            case 0:
                printf("\nXXXXXXXXXXXX Saindo do sistema XXXXXXXXXXXX\n");
            break;
            default:
                printf("\nXXXXXXXXXXXX Opção Inválida XXXXXXXXXXXX\n");
            break;
        }
    }while(opcao != 0);//Enquanto opcao for diferente de "0" o laco while continua
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    add_sec("Igor", "500063", 11111111111);
    add_sec("Otaviano", "411631", 22222222222);
    add_sec("Guilerme", "511427", 33333333333);
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");

    menu();
    
    
    return 0;
}



