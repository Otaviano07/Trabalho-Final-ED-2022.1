#include <stdio.h>
#include <stdlib.h>

typedef struct Documento{
    int id; 
    int prioridade; 
    int matricula;
    char * livro;
    char * nome_aluno;
    char * campus_livro;
    char * campus_aluno;  
    char * secretario;
    char * data_pedido;
    struct Documento * esq;
    struct Documento * dir;
}DOCUMENTO;

DOCUMENTO *tree = NULL;
int item = 0;

DOCUMENTO* buscar(int id, DOCUMENTO *aux){
    
    if(aux != NULL){
        if(aux->id == id){
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
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
    
    aux = buscar(id, tree);
    
    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");     
    }else{
        
        DOCUMENTO* novo = malloc(sizeof(DOCUMENTO));
        novo->id = id;
        novo->data_pedido = data;
        novo->matricula = matricula;
        novo->nome_aluno = aluno;          
        novo->livro = livro;
        novo->prioridade = 0;
        novo->secretario = NULL;    
        novo->campus_livro = NULL;
        novo->campus_aluno = NULL;          
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(tree == NULL){//arvore esta vazia
            tree = novo;
            item++;
            printf("\n1 Pedido de emprestimo adicionado com sucesso.\n");
        }
        else{
                if(novo->id < aux->id){
                    
                    if(aux->esq != NULL){
                        add_abb(id, data, aluno, matricula, livro, aux->esq);
                    }
                    else{
                        aux->esq = novo;
                        item++;
                        printf("\n2 Pedido de emprestimo adicionado com sucesso.\n");
                    }
                }
                else{
                    if(aux->dir != NULL){
                        add_abb(id, data, aluno, matricula, livro, aux->esq);
                    }
                    else{
                        aux->dir = novo;
                        item++;
                        printf("\n3 Pedido de emprestimo adicionado com sucesso.\n");
                    }
                }
        }
    }
}

void in_ordem(DOCUMENTO *aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
        printf("\n\tID: %d  ", aux->id);
        printf("\tDATA: %s", aux->data_pedido);
        printf("\n\tALUNO: %s", aux->nome_aluno);
        printf("\n\tMatricula: %s", aux->matricula);
        printf("\n\tLIVRO: %s\n\n", aux->livro);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}
