#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "abb.h"
#include "fila.h"

#define TAM 50 

typedef struct secretario{
    int cpf;
    char * nome;
    char * senha;
    struct secretario *prox;
}SECRETARIO;

SECRETARIO *new = NULL;


void add_sec(char *nome, char *senha, int cpf){
    SECRETARIO *novo = malloc(sizeof(SECRETARIO));
    novo->nome = nome;
    novo->senha = senha;
    novo->cpf = cpf;
    new = novo;
}


int gerar_id(){
    int i;
    do{
        i = rand() % 100;
    }while(buscar(i, tree) != NULL);
        return i;
        
}


void menu(){
    DOCUMENTO * encontrado;
    char nome[TAM];
    int matricula;
    char titulo[TAM];
    char autor[TAM];
    int opcao;
    int id;

    do{

        printf("\n\n------------ Menu Biblioteca ------------\n");
        printf("\n\t[1] Adicionar Pedido\n");
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





            //... matricula e descricao..
            //criar um funcao para gerar id unico (:D)
            //add_abb(id, nome, matricula, descricao);
                
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
    add_sec("igor", "123", 23423423);
    add_sec("Otaviano", "ota123", 41163131161);
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while(resp != 0){
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        if(resp == 1){
            //encomendar um livro
             printf(" Digite o nome do aluno:\n");
             char nome[100];
            fflush(stdin);
             scanf("%s[^\n]", &nome);
             //... matricula e descricao..
             //criar um funcao para gerar id unico (:D)
            //add_abb(id, nome, matricula, descricao);
        }else if(resp == 2){
            //remover uma encomenda de livro da ABB (id)
            //para remover eu preciso:
            //1 - visualizar as encomendas (in_ordem)
            in_ordem();
            //2 - verificar o usuario
            printf(" Digite seu cpf:\n");
            char cpf[100];
            scanf("%s", &cpf);
            printf(" Digite sua senha:\n");
            char senha[100];
            scanf("%s", &senha);
            //int retorno = verificar(cpf, senha);
            if(retorno == 1){
                //3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                //4 - setar novos dados (faltando)
                //5 - add_fila(....);
            }else if(resp == 3){
               
                //2 - verificar o usuario
                    printf(" Digite seu cpf:\n");
                    char cpf[100];
                    scanf("%s", &cpf);
                    printf(" Digite sua senha:\n");
                    char senha[100];
                    scanf("%s", &senha);
                    //int retorno = verificar(cpf, senha);
                    if(retorno == 1){
                        //remover da fila de prioridade
                    }
            }
        
        }
        
    }
    
    return 0;
}



