#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listareq.h"
#include "abb.h"

// REMOVER COMENTARIOS AO FIM

typedef struct Usuario{ // Ja deve estar cadastrado - Lista
    char * nome_sec;
    char * cpf_sec;
    char * senha_sec;
    char * tipo; // 3 secretarios, 5 transportadores.
    struct Usuario * prox;
}USER;


DOC * remover(REQ * req, USER * responsavel){ //remove requisição retorna documento

    //return documento;
}
// ADD, BUSCA e REMOVER no documento e requisicao - em andamento
// BUSCA no usuario - em andamento
// estagiario add requisicao (nn precisa de validacao de usuario/login, tanto que estagiario nao e cadastrado) - em andamento
// secretario remove requisicao e add documento - em andamento
// trasportador remove documento - em andamento

void menu(){
    DOC * encontrado;
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
    // insercao de secretarios e transportadores aqui
    //  !!!!!!!!!!!!!!!!!!!!!!!!
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu();//chama a funcao menu
    return 0;
}
