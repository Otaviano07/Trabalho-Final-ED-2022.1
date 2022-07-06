#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <Windows.h>
#include <unistd.h>
#include "abb.h"
#include "fila.h"
#include "usuario.h"

void menu(){
    USUARIO *encontrado;
    DOCUMENTO *copia;
    char nome[TAM];
    char campus_aluno[TAM];
    char campus_livro[TAM];
    char responsavel[TAM];
    char livro[TAM];
    char data[TAM];
    int prioridade;
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
        printf("\t[4] Adicionar usuario\n");
        printf("\t[0] Sair\n");
        printf("\n\tQual a sua opcao? ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                do{
                    data_atual();
                    strcpy(data, atual);
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

                    add_abb(id, data, nome, matricula, livro, tree);

                    system("cls");
                    printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                    printf("\t-------- Menu Adicionar Encomenda -------\n\n");
                    printf("\t   # Ultima encomenda adicionada:\n");
                    printf("\tID: %d  ", id);
                    printf("\tDATA: %s", data);
                    printf("\n\tALUNO: %s", nome);
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
                    data_atual();
                    strcpy(data, atual);

                    system("cls");
                    printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                    printf("\t---------- Menu Remover Pedido ----------\n\n");
                    printf("\tDigite seus dados para confirmar usuario.\n\n");
                    printf("\tCPF: ");
                    scanf("%d", &cpf);
                    printf("\tSENHA: ");  
                    scanf("%d", &senha);
                    encontrado =  busca_user(cpf, senha);

                    if (encontrado != NULL){
                        system("cls");
                        printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                        printf("\t---------- Menu Remover Pedido ----------\n\n");
                        printf("\t       #Todas encomenda adicionada\n");
                        in_ordem(tree);
                        printf("\n\tDigite o ID do pedido: ");
                        scanf("%d", &id);
                        printf("\n\tAguarde um pouco...");
                        sleep(1);
                        copia = buscar(id,tree);

                        if(copia->id == id){
                            data_atual();
                            strcpy(data, atual);
                            system("cls");
                            printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                            printf("\t---------- Menu Remover Pedido ----------\n\n");
                            printf("\t     Digite os demais dados do pedido\n");
                            printf("\n\tID: %d", copia->id);
                            printf("\tDATA: %s", data);
                            printf("\n\tALUNO: %s", copia->nome_aluno);
                            printf("\n\tMatricula: %d", copia->matricula);
                            printf("\n\tLIVRO: %s", copia->detalhes_livro);
                            printf("\n\tPrioridade: ");
                            scanf("%d", &prioridade);
                            printf("\tCampus do aluno: ");
                            fflush(stdin);
                            scanf("%[^\n]s", &campus_aluno);
                            printf("\tCampus do livro: ");
                            fflush(stdin);
                            scanf("%[^\n]s", &campus_livro);

                            add_fila(prioridade, copia->id, data, copia->nome_aluno, campus_aluno, copia->matricula, copia->detalhes_livro, campus_livro, encontrado->nome, inicio);
                            remover(id,tree);

                            system("cls");
                            printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                            printf("\t---------- Menu Remover Pedido ----------\n\n");
                            printf("\tID removido com sucesso:)\n");
                            printf("\n\tAguarde um pouco... ");
                            sleep(1);
                        }
                        else{
                            printf("\n\tPedido nao encontrda:(\n\n");
                        }
                    }

                    printf("\n\tDeseja remover outro pedido? ");
                    printf("\n\t[1] Sim ou [0] Nao\n\n");
                    printf("\tEscolha: ");
                    scanf("%d", &escolha); 

                }while (escolha != 0 );
            break;
            case 3:
                do{
                    system("cls");
                    printf("\n\t      SISTEMA DE ENCOMENDA DE LIVRO\n");
                    printf("\t--------- Menu Remover Encomenda --------\n\n");
                    printf("\tDigite seus dados para confirmar usuario.\n\n");
                    printf("\tCPF: ");
                    scanf("%d", &cpf);
                    printf("\tSENHA: ");  
                    scanf("%d", &senha);
                    encontrado =  busca_user(cpf, senha);

                    if ( encontrado != NULL){
                        system("cls");
                        printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                        printf("\t---------- Menu Remover Pedido ----------\n\n");
                        printf("\t       #Todos pedidos adicionado\n");
                        imprimir_fila();
                        sleep(1);
                        printf("\n\tAguarde um pouco enquanto removemos o pedido...\n\n");
                        remover_fila();
                        system("pause");
                        system("cls");
                        printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                        printf("\t---------- Menu Remover Pedido ----------\n\n");
                            if(inicio != NULL){
                                printf("\t       #Pedido removido com sucesso:)\n");
                                imprimir_fila();
                            }
                            else{
                                printf("\t       #Pedido removido com sucesso:)\n");
                            }
                        
                    }
                    else{
                        printf("\n\tUsuario nao encontrado encontrda:(\n\n");
                    }
                    
                    printf("\n\tDeseja remover outro pedido? ");
                    printf("\n\t[1] Sim ou [0] Nao\n\n");
                    printf("\tEscolha: ");
                    scanf("%d", &escolha); 

                }while (escolha != 0 );
            break;
            case 4:
                do{
                    char nome_user[TAM];
                    char cargo_user[TAM];
                    int senha_user;
                    int cpf_user;

                    system("cls");
                    printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                    printf("\t--------- Menu Adicionar Usuario --------\n\n");
                    printf("\tDigite seus dados para confirmar usuario.\n\n");
                    printf("\tCPF: ");
                    scanf("%d", &cpf);
                    printf("\tSENHA: ");  
                    scanf("%d", &senha);
                    encontrado =  busca_user(cpf, senha);

                    if ( encontrado != NULL){
                        system("cls");
                        printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                        printf("\t--------- Menu Adicionar Usuario --------\n\n");
                        printf("\tNome do usuario: ");
                        fflush(stdin);
                        scanf("%[^\n]s", &nome_user);

                        printf("\tCargo do usuario: ");
                        fflush(stdin);
                        scanf("%[^\n]s", &cargo_user);

                        printf("\tCPF do usuario: ");
                        scanf("%d", &cpf_user);

                        printf("\tSenha do usuario: ");
                        scanf("%d", &senha_user);
                        add_user(cpf_user, senha_user, nome_user, cargo_user);

                        system("cls");
                        printf("\n\t      SISTEMA DE PEDIDO DE LIVRO\n");
                        printf("\t--------- Menu Adicionar Usuario --------\n\n");
                        printf("\t     Usuario cadastrado com sucesso:)\n\n");
                        imp_user();
                    }
                    printf("\tDeseja adicionar outro usuario? ");
                    printf("\n\t[1] Sim ou [0] Nao\n\n");
                    printf("\tEscolha: ");
                    scanf("%d", &escolha); 

                }while (escolha != 0 );
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
    free(tree);
    free(new_user);
    free(fim_user);
    free(inicio); 
    free(fim);
    
    return 0;
}



