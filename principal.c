#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "abb.h"
#include "fila.h"
//#include <stdio_ext.h>

#define TAM 50
#define CPF 11
#define SENHA 6 

typedef struct usuario{
    int cpf;
    char * nome;
    char * senha;
    char * cargo;
    struct usuario *prox;
}USUARIO;

USUARIO *new_user = NULL;
int id_user = 0;

void add_user(char *nome, char *senha, char *cargo, int cpf){
    
    USUARIO *novo = malloc(sizeof(USUARIO));
    novo->nome = nome;
    novo->senha = senha;
    novo->cpf = cpf;
    novo->cargo = cargo;
    novo->prox = NULL;
    
    if(new_user == NULL){ //lista vazia
            new_user = novo;
            id_user++;
    }else{
        novo->prox = new_user;
        new_user = novo;
        id_user++;
    }

}

int gerar_id(){
    int i;
    int b;

    srand((unsigned)time(NULL));

    do{
        i = (rand() % 100 -10) * (rand() % 100 -10);
    }while(i < 999 );

    return i;

}

void preCadastro(){

    if(new_user == NULL){    
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

void imp_user(){
    USUARIO * aux = new_user;
    for(int i = 0; i < id_user; i++){
        printf("CPF: %d\n", aux->cpf);
         printf("Nome: %s\n", aux->nome);
          printf("Senha: %s\n", aux->senha);
           printf("Cargo: %s\n\n", aux->cargo);

            aux = aux->prox;
    }
}

void menu(){
    DOCUMENTO * encontrado;
    char nome[TAM];
    char livro[TAM];
    char data[TAM];
    int matricula;
    int opcao;
    int escolha;
    int id;

    time_t tempo;
    tempo = time(NULL);
    strftime(data, sizeof(data), "%d/%m/%Y %H:%M:%S", localtime( &tempo ));

    do{
        system("cls");
        printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
        printf("\t------------ Menu Biblioteca ------------\n");
        printf("\n\t[1] Adicionar Encomenda\n");
        printf("\t[2] Remover Pedido\n");
        printf("\t[3] Remover Encomenda\n");
        printf("\t[0] Sair\n");
        printf("\n\tQual a sua opcao? ");
        scanf("%d",&opcao);


        switch(opcao){
            case 1:
                do{
                    id = gerar_id();
                    system("cls");
                    printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                    printf("\t-------- Menu Adicionar Encomenda -------\n\n");
                    
                    printf("\tPedido: %d", id);
                    printf("\n\tNome do aluno: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &nome);

                    printf("\tMatricula do aluno: ");
                    scanf("%d", &matricula);
    
                    printf("\tDetalhes do livro: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &livro);

                    //add_abb(id, data, nome, matricula, livro, tree);

                    system("cls");
                    printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                    printf("\t-------- Menu Adicionar Encomenda -------\n\n");
                    printf("\n\tID: %d  ", id);
                    printf("\tDATA: %s", data);
                    printf("\n\tALUNO: %s  ", nome);
                    printf("\n\tMATRICULA: %d", matricula);
                    printf("\n\tLIVRO: %s\n\n", livro);

                    printf("\tDeseja adicionar outro pedido? ");
                    printf("\n\t[1] Sim ou [0] Nao\n\n");
                    printf("\tEscolha: ");
                    scanf("%d", &escolha);

                }while (escolha != 0 );

            break;
            case 2://Nesse caso se remove o pedido sendo adicionado um documento no lugar
                printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                printf("\t---------- Menu Remover Pedido ----------\n\n");
                in_ordem(tree);
                system("pause");

                // Funcao que pede dados e realiza a funcao
            break;
            case 3://Nesse caso se remove o documento de encomenda pelo transportador
                printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                printf("\t--------- Menu Remover Encomenda --------\n\n");
                printf("\n\nAtenção!!! Para remover encomenta o usuario precisa ser algum secretario, "
                        "\npara continuar precione qualquer tecla e informe seus dados de usuario.\n");
                //system("pause");

                printf(" Digite seu cpf:\n");
                    char cpf[CPF];
                scanf("%s", &cpf);
                printf(" Digite sua senha:\n");
                    char senha[SENHA];
                scanf("%s", &senha);
                    //int retorno = verificar(cpf, senha);
                if(opcao == 1){
                        //remover da fila de prioridade
                }
            break;
            case 0:
                //system("clear");
                system("cls");
                printf("\n\tXXXXXXXXXXXX Saindo do sistema XXXXXXXXXXXX\n\n");
                system("pause");
            break;
            default:
                //system("clear");
                system("cls");
                printf("\n\tXXXXXXXXXXX Opcao Invalida XXXXXXXXXXXX\n\n");
                system("pause");
            break;
        }
    }while(opcao != 0);
}

int main(){
    //add_abb(gerar_id(), "01/07/2022 13:25:37", "Otaviano", 411631, 12345, "Jesus", "Apocalipse", "Revelacao", tree);

    
    setlocale(LC_ALL, "Portuguese_Brazil");
   // preCadastro();
   menu();
   // in_ordem(tree);
    //imp_user();
    //gerar_id();
    
    return 0;
}



