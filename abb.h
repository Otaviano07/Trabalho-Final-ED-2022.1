#include <stdio.h>
#include <stdlib.h>

typedef struct Documento{
    int id; 
    int prioridade; 
    int mat_aluno;
    int cod_livro;
    char * autor;
    char * titulo;
    char * assunto;
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

void add_abb(int id, char *data, char *nome_aluno, int matricula, int codigo, char *autor, char *titulo, char *assunto, DOCUMENTO *aux){
    
    aux = buscar(id, tree);
    
    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");     
    }else{
        
        DOCUMENTO* novo = malloc(sizeof(DOCUMENTO));
        novo->id = id;
        novo->data_pedido = data;
        novo->mat_aluno = matricula;
        novo->nome_aluno = nome_aluno;
        novo->cod_livro = codigo;          
        novo->titulo = titulo;
        novo->autor = autor;      
        novo->assunto = assunto;
        novo->prioridade = 0;
        novo->secretario = NULL;    
        novo->campus_livro = NULL;
        novo->campus_aluno = NULL;          
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(tree == NULL){//arvore esta vazia
            tree = novo;
            item++;
            printf("\n1Pedido de emprestimo adicionado com sucesso.\n");
        }
        else{
            printf("\nOKadsfasd\n");
                if(novo->id < aux->id){
                    
                    if(aux->esq != NULL){
                        add_abb(id, data, nome_aluno, matricula, codigo, autor, titulo, assunto, aux->esq);
                    }
                    else{
                        aux->esq = novo;
                        item++;
                        printf("\nEPedido de emprestimo adicionado com sucesso.\n");
                    }
                }
                else{
                    if(aux->dir != NULL){
                        add_abb(id, data, nome_aluno, matricula, codigo, autor, titulo, assunto, aux->dir);
                    }
                    else{
                        aux->dir = novo;
                        item++;
                        printf("\nDPedido de emprestimo adicionado com sucesso.\n");
                    }
                }
        }
    }
}

void in_ordem(DOCUMENTO *aux){

    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
        printf("\nID: %d  ", aux->id);
        printf("\tDATA: %s", aux->data_pedido);
        printf("\nALUNO: %s  ", aux->nome_aluno);
        printf("\tMATRICULA: %d\n", aux->mat_aluno);
        printf("CODIGO: %s ", aux->cod_livro);  
        printf("\tTITULO: %s ", aux->titulo);
        printf("\tAUTOR: %s ", aux->autor);
        printf("\tASSUNTO: %s\n\n", aux->assunto);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}
