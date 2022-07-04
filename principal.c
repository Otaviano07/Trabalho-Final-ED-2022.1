#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <Windows.h>
#include <unistd.h>
#include "abb.h"
#include "fila.h"

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
                    data_atual();
                    strcpy(data, atual);
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
                    system("cls");
                    printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                    printf("\t---------- Menu Remover Pedido ----------\n\n");
                    printf("\t       #Todas encomenda adicionada\n");
                    in_ordem(tree);
                    imp_user();

                        printf("\tDigite seus dados para confirmar usuario.\n\n");
                        printf("\tCPF: ");
                        scanf("%d", &cpf);
                        printf("\tSENHA: ");  
                        scanf("%d", &senha);

                    if ( busca_user(cpf, senha) != NULL){
                        printf("\n\nUsuario cadastrado:(\n\n"); 
                    }
                    else{
                        printf("\n\nUsuario nao cadastrado:)\n\n");
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
        sleep(1);
    }while(opcao != 0);
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    preCadastro();
    menu(); 
    
    return 0;
}



