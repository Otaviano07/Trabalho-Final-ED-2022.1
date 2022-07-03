#include <stdio.h>
#include <stdlib.h>

typedef struct Documento{
    int id; 
    int prioridade; 
    int matricula;
    char * detalhes_livro;
    char * nome_aluno;
    char * campus_livro;
    char * campus_aluno;  
    char * secretario;
    char * data_pedido;
    struct Documento *esq;
    struct Documento *dir;
}DOCUMENTO;

DOCUMENTO *tree = NULL;
int item = 0;

DOCUMENTO* buscar(int id, DOCUMENTO *aux){
    printf("Entrou na Buscar!!!\n");
    if(aux != NULL){
        if(aux->id == id){
            printf("LINHA 25\n");
            return aux;
            printf("LINHA 27\n");
        }else if(id < aux->id){
            if(aux->esq != NULL){
                printf("LINHA 30\n");
                return buscar(id, aux->esq);
                printf("LINHA 32\n");
            }else{
                printf("LINHA 34\n");
                return NULL;
                printf("LINHA 36\n");
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                printf("LINHA 40\n");
                return buscar(id, aux->dir);
                printf("LINHA 42\n\n");
            }else{
                printf("LINHA 44\n");
                return NULL;
                printf("LINHA 46\n");
            }
        }
    }else{
        printf("LINHA 50\n");
        return NULL;
        printf("LINHA 52\n");
    }
}

DOCUMENTO* remover(int id, DOCUMENTO *raiz ){
    if(raiz == NULL){
        return NULL;
        printf("\nSolicitacoes de encomenda vazia!!!\n");
    }
    else{
        if(raiz->id == id){
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                return NULL;
            }
            else{
                if(raiz->esq == NULL || raiz->dir == NULL){
                    DOCUMENTO *aux;
                    if(raiz->esq != NULL){
                        aux = aux->esq;
                    }
                    else{
                        aux = aux->dir;
                    }
                    free(aux);
                    return aux;
                }
                else{
                    DOCUMENTO *aux = raiz->esq;
                    while(aux->dir != NULL){
                        aux = aux->dir;
                    }
                        raiz->id = aux->id;
                        aux->id = id;
                        raiz->esq = remover(id, raiz->esq);                            
                }
            }
        }
        else{
                if(id < raiz->id ){
                    raiz->esq = remover(id, raiz->esq);
                }
                else{
                    raiz->dir = remover(id, raiz->dir);
                }
                return raiz;
            }
    }
}

void add_abb(int id, char *data, char *aluno, int matricula, char *livro, DOCUMENTO *aux){
    
    //aux = buscar(id, tree);
    //printf("LINHA 105\n");

    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");     
    }else{
        DOCUMENTO *novo = malloc(sizeof(DOCUMENTO));
        novo->id = id;
        novo->data_pedido = data;
        novo->matricula = matricula;
        novo->nome_aluno = aluno;          
        novo->detalhes_livro = livro;
        novo->prioridade = 0;
        novo->secretario = NULL;    
        novo->campus_livro = NULL;
        novo->campus_aluno = NULL;          
        novo->esq = NULL;
        novo->dir = NULL;

         if(tree == NULL){
            tree = novo;
            item++;

        }
        else{
            if(novo->id < aux->id){
                if(aux->esq != NULL){
                    add_abb(id, data, aluno, matricula, livro, aux->esq);
                }
                else{
                    aux->esq = novo;
                    item++;
                }
            }
            else{
                if(aux->dir != NULL){
                    add_abb(id, data, aluno, matricula, livro, aux->esq);
                }
                else{
                    aux->dir = novo;
                    item++;
                }
            }
        }
        free(novo);
    }
    
}

void in_ordem(DOCUMENTO *aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
        printf("\n\tID: %d  ", aux->id);
        printf("\tDATA: %s", aux->data_pedido);
        printf("\n\tALUNO: %s", aux->nome_aluno);
        printf("\n\tMatricula: %d", aux->matricula);
        printf("\n\tLIVRO: %s\n\n", aux->detalhes_livro);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}
