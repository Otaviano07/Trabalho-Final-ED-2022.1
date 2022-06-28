#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "abb.h"
#include "fila.h"

#define TAM 50 

typedef struct usuario{
    int cpf;
    char * nome;
    char * senha;
    char * cargo;
    struct usuario *prox;
    struct usuario *ant;
}USUARIO;

USUARIO *new_user = NULL;
int id_user = 0;

void add_user(char *nome, char *senha, char *cargo, int cpf){
    USUARIO *novo = malloc(sizeof(USUARIO));
    novo->nome = nome;
    novo->senha = senha;
    novo->cpf = cpf;
    novo->ant = NULL;
    novo->prox = NULL;
    
    if(new_user == NULL){ //lista vazia
            new_user = novo;
            id_user++;
    }else{
        new_user->ant = novo;
        novo->prox = new_user;
        new_user = novo;
        id_user++;
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
    char data_Pedido[TAM];

    /* Recupera a quantidade de segundos desde 01/01/1970 */
    tempo = time(NULL);

    strftime(data_Pedido, sizeof(data_Pedido), "%d/%m/%Y %H:%M:%S", localtime( &tempo ));

    return data_Pedido[TAM];
}

void preCadastro(){

    if(new_user== NULL){    
        add_user("Igor", "500063","Secretario", 500063);
        add_user("Otaviano", "411631", "Secretario", 411631);
        add_user("guilherme", "511427", "Secretario", 511427);
        add_user("Transportador_01", "111111", "Transportador", 111111);
        add_user("Transportador_02", "222222", "Transportador", 222222);
        add_user("Transportador_03", "333333", "Transportador", 333333);
        add_user("Transportador_04", "444444", "Transportador", 444444);
        add_user("Transportador_05", "555555", "Transportador", 555555);
    }
    
}

void menu(){
    DOCUMENTO * encontrado;
    char nome[TAM];
    char titulo[TAM];
    char autor[TAM];
    char assunto[TAM];
    //char data_emp[TAM];
    int matricula;
    int opcao = -1;
    int id;

    do{

        printf("\n\n------------ Menu Biblioteca ------------\n");
        printf("\n\t[1] Adicionar Encomenda\n");
        printf("\t[2] Remover Pedido\n");
        printf("\t[3] Remover Encomenda\n");
        printf("\t[0] Sair\n");
        printf("\nQual a sua opcao? ");
        scanf("%d",&opcao);


        switch(opcao){
            case 1://Nesse caso o usuario adiciona um novo ID na arvore
                printf("\n------------ Menu Adicionar Encomenda ------------\n\n");
                //encomendar um livro
                id = gerar_id();

                printf(" Digite o nome do aluno:\n");
                scanf("%s[^\n]", &nome);

                printf(" Digite a matricula:\n");
                scanf("%d", &matricula);

                printf(" Digite o titulo do livro:\n");
                scanf("%s[^\n]", &titulo);

                printf(" Digite o autor:\n");
                scanf("%s[^\n]", &autor);

                printf(" Digite o assunto:\n");
                scanf("%s[^\n]", &assunto);

                //data_emp[TAM] = temporizador();

            add_abb(id, nome, matricula, autor, titulo, assunto, tree);
            break;
            case 2://Nesse caso se remove o pedido sendo adicionado um documento no lugar
                printf("\n------------ Menu Remover Pedido ------------\n\n");
                printf("\nRemover Pedido: ");

                // Funcao que pede dados e realiza a funcao
            break;
            case 3://Nesse caso se remove o documento de encomenda pelo transportador
                printf("\n------------ Menu Remover Encomenda ------------\n\n");
                in_ordem(tree);
                printf("\n\nRemover Encomenda: ");
                               
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
    preCadastro();
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    menu();
    
    
    return 0;
}



