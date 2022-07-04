#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <Windows.h>
#include <unistd.h>
#include <stdio_ext.h>
#include "abb.h"
#include "fila.h"


#define TAM 50

char atual[TAM];

typedef struct usuario{
    int cpf;
    int senha;
    char *nome;
    char *cargo;
    struct usuario *prox;
}USUARIO;

USUARIO *new_user = NULL;
USUARIO *fim_user = NULL;
int user = 0;

USUARIO *busca_user(int cpf, int senha, USUARIO *aux){
    printf("Linha 26\n");
    printf("CPF Enviado: %d\n",cpf);
    printf("SENHA Enviada: %d\n\n", senha);

    if(aux != NULL){
        if(aux->cpf == cpf && aux->senha == senha){
            return aux;
        }
        else{
            printf("Linha 34\n");
            busca_user(cpf, senha, aux->prox);
        }
    }else{
        return NULL;
    }
}

void add_user(int cpf, int senha, char *nome, char *cargo){
    
    USUARIO *novo = malloc(sizeof(USUARIO));
    novo->nome = nome;
    novo->senha = senha;
    novo->cpf = cpf;
    novo->cargo = cargo;
    novo->prox = NULL;
    
    if(new_user == NULL){
            new_user = novo;
            fim_user = novo;
            user++;
    }else{
        fim_user->prox = novo;
        fim_user = novo;
        user++;
    }

}

void data_atual(){

    time_t tempo;
    tempo = time(NULL);
    strftime(atual, sizeof(atual), "%d/%m/%Y %H:%M:%S", localtime( &tempo ));
    
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
        add_user(500063, 500063, "Igor", "Secretario");
        add_user(411631, 411631, "Otaviano", "Secretario");
        add_user(511427, 511427, "guilherme", "Secretario");
        add_user(111111, 111111, "Transportador_01", "Transportador");
        add_user(222222, 222222, "Transportador_02", "Transportador");
        add_user(333333, 333333, "Transportador_03", "Transportador");
        add_user(444444, 444444, "Transportador_04", "Transportador");
        add_user(555555, 555555, "Transportador_05", "Transportador");
    }
    
}

void imp_user(){
    USUARIO * aux = new_user;
    for(int i = 0; i < user; i++){
        printf("\tCPF: %d\n", aux->cpf);
        printf("\tNome: %s\n", aux->nome);
        printf("\tSenha: %d\n", aux->senha);
        printf("\tCargo: %s\n\n", aux->cargo);
        aux = aux->prox;
    }
}

void menu(){
    USUARIO * encontrado;
    char nome[TAM];
    char livro[TAM];
    char data[TAM];
    int matricula;
    int escolha;
    int cpf;
    int senha;
    int opcao;    
    int id;

    data_atual();
    strcpy(data, atual);

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
                    escolha = 1;
                    id = gerar_id();
                    system("cls");
                    printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                    printf("\t-------- Menu Adicionar Encomenda -------\n\n");
                    
                    printf("\tPedido: %d", id);
                    printf("\tDATA: %s", data);
                    printf("\n\tNome do aluno: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &nome);

                    printf("\tMatricula do aluno: ");
                    scanf("%d", &matricula);
    
                    printf("\tDetalhes do livro: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &livro);

                    system("cls");
                    printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                    printf("\t-------- Menu Adicionar Encomenda -------\n\n");
                    
                    add_abb(id, data, nome, matricula, livro, tree);
                    printf("\t   # Ultima encomenda adicionada:\n");
                    printf("\tID: %d  ", id);
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
            case 2:
                do{
                    escolha = 1;
                    system("cls");
                    printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                    printf("\t---------- Menu Remover Pedido ----------\n\n");
                    printf("\tDigite o dados para confirmar usuario.\n\n");
                    printf("\tCPF: ");
                    scanf("%d", &cpf);
                    printf("\tSENHA: ");  
                    scanf("%d", &senha);

                    if ( busca_user(cpf, senha, encontrado) == NULL){
                        printf("\n\nUsuario nao cadastrado:(\n\n"); 
                    }
                    else{
                        printf("\n\nUsuario cadastrado:)\n\n");
                    }

                    printf("\tDeseja remover outro pedido? ");
                    printf("\n\t[1] Sim ou [0] Nao\n\n");
                    printf("\tEscolha: ");
                    scanf("%d", &escolha); 

                }while (escolha != 0 );
            break;
            case 3:
                printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                printf("\t--------- Menu Remover Encomenda --------\n\n");
            break;
            case 0:
                printf("\n\tXXXXXXXXXXXX Saindo do sistema XXXXXXXXXXXX\n\n");
            break;
            default:

                printf("\n\tXXXXXXXXXXX Opcao Invalida XXXXXXXXXXXX\n\n");
            break;
        }
        sleep(3);
    }while(opcao != 0);
}

int main(){

    printf("ID: %d\n",gerar_id());
    add_abb(gerar_id(), "01/07/2022 13:25:37", "Otaviano", 411631, "Revelacao", tree);

    setlocale(LC_ALL, "Portuguese_Brazil");
    preCadastro();
    printf("Usuarios: %d\n", user);
    menu(); 
    
    return 0;
}



