#include <stdio.h>
#include <stdlib.h>

typedef struct Livro{
    char * autor;
    char * titulo;
    char * assunto;
}LIVRO;

typedef struct Documento{
    int id; 
    int prioridade; 
    int mat_aluno; 
    char * nome_aluno; 
    char * campus_livro; 
    char * secretario;
    char * data_pedido;
    struct Livro * inf_livro;
    struct Documento * esq;
    struct Documento * dir;
}DOCUMENTO;

DOCUMENTO * tree = NULL;
int tam = 0;

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

DOCUMENTO* remover(DOCUMENTO *raiz, int id){
    if(raiz == NULL){
        return NULL;
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
                        raiz->esq = remover(raiz->esq, id);                            
                }
            }
        }
        else{
                if(id < raiz->id ){
                    raiz->esq = remover(raiz->esq, id);
                }
                else{
                    raiz->dir = remover(raiz->dir, id);
                }
                return raiz;
            }
    }
}

void add_abb(int id, int prioridade, int mat_aluno, char *nome_aluno, char *campus_livro, char *secretario, char *autor, char *titulo, char *assunto, char *data_pedido){

    DOCUMENTO* aux = buscar(id, tree);
    
    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");
    }else{
        
        DOCUMENTO* novo = malloc(sizeof(DOCUMENTO));
        novo->id = id;
        novo->data_pedido = data_pedido;
        novo->prioridade = NULL;
        novo->mat_aluno = matricula;
        novo->nome_aluno = nome_aluno;
        novo->secretario = secretario;    
        novo->campus_livro = NULL;            
        novo->inf_livro->titulo = NULL;
        novo->inf_livro->autor = NULL;      
        novo->inf_livro->assunto = NULL;     
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(aux == NULL){//arvore esta vazia
            tree = novo;
            tam++;
            printf("Pedido de emprestimo recebido com sucesso");
        }else{
            if(id < aux->id){
                aux->esq = novo;
            }else{
                aux->dir = novo;
            }
        }
    }
}


void in_ordem(DOCUMENTO *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d\n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->mat_aluno);
    printf("%s\n", aux->inf_livro->titulo);
    printf("%s\n", aux->inf_livro->autor);
    printf("%s\n", aux->inf_livro->assunto);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
        }
}