#include <stdio.h>
#include <stdlib.h>

typedef struct Documento{
    int id; 
    int prioridade; 
    int matricula;
    char *detalhes_livro;
    char *nome_aluno;
    char *campus_livro;
    char *campus_aluno;  
    char *responsavel;
    char *data_pedido;
    struct Documento *esq;
    struct Documento *dir;
}DOCUMENTO;

DOCUMENTO *tree = NULL;
int item = 0;

void in_ordem(DOCUMENTO *aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
        printf("\n\tID: %d  ", aux->id);
        printf("\tDATA: %s", aux->data_pedido);
        printf("\n\tALUNO: %s", aux->nome_aluno);
        printf("\n\tMatricula: %d", aux->matricula);
        printf("\n\tLIVRO: %s\n", aux->detalhes_livro);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

DOCUMENTO *buscar(int id, DOCUMENTO *aux){
    
    if(aux != NULL){ 
        if(aux->id == id){ 
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return NULL;                
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return NULL;
            }
        }
    }else{
        return NULL;
    }
}

DOCUMENTO *remover(int id, DOCUMENTO *lixo ){
    DOCUMENTO *b = buscar(id, tree);
    
    if(tree == NULL){
        return NULL;        
    }
    else if(b == NULL){
        return NULL; 
    }
    else if(lixo->id > id){
        lixo->esq = remover(id, lixo->esq);
    }
    else if(lixo->id < id){
        lixo->dir = remover(id, lixo->dir);
    }
    else{
        if(lixo->esq == NULL && lixo->dir == NULL){
            free(lixo);
            return NULL;
        }
        else if(lixo->esq == NULL){
            DOCUMENTO *aux = lixo;
            lixo = lixo->dir;
            free(aux);
        }
        else if(lixo->dir == NULL){
            DOCUMENTO *aux = lixo;
            lixo = lixo->esq;
            free(aux);
        }
        else{
            DOCUMENTO *aux = lixo->esq;
            while(aux->dir != NULL){
                aux = aux->dir;
            }
            lixo->id = aux->id;
            aux->id = id;
            lixo->esq = remover(id, lixo->esq);
        }
    }
}

void add_abb(int id, char *data, char *aluno, int matricula, char *livro, DOCUMENTO *aux){

    if(aux != NULL && aux->id == id){
        printf("\n\tInsercao invalida!\n");     
    }else{
        DOCUMENTO *novo = malloc(sizeof(DOCUMENTO));
        novo->id = id;
        novo->data_pedido = data;
        novo->matricula = matricula;
        novo->nome_aluno = aluno;          
        novo->detalhes_livro = livro;
        novo->prioridade = 0;
        novo->responsavel = NULL;    
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
                    add_abb(id, data, aluno, matricula, livro, aux->dir);
                }
                else{
                aux->dir = novo;
                item++;
                }
            }

        }
    }
}
