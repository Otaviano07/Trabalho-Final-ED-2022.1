#include <stdio.h>
#include <stdlib.h>

typedef struct pedido{
    int id; 
    int prioridade; 
    int matricula;
    char *detalhes_livro;
    char *nome_aluno;
    char *campus_livro;
    char *campus_aluno;  
    char *responsavel;
    char *data_encomenda;
    
}PEDIDO;

typedef struct No{
   
    PEDIDO *p;
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add_fila(int prioridade, int id, char *data, char *aluno, char *campus_aluno, int matricula, char *campus_livro, char *campus_aluno,  char *responsavel, NO *aux){
    
        PEDIDO * p = malloc(sizeof(PEDIDO));
        p->id = id;
        p->data_encomenda = data;
        p->matricula = matricula;
        p->nome_aluno = aluno;          
        p->detalhes_livro = livro;
        p->prioridade = prioridade;
        p->responsavel = responsavel;    
        p->campus_livro = campus_livro;
        p->campus_aluno = campus_aluno; 
        
        NO * novo = malloc(sizeof(NO));
        novo->p = p;
        novo->prox = NULL;
    
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
            tam++;
        }else{
            if(novo->p->prioridade > aux->p->prioridade){
                    add_fila(prioridade, id, data_pedido, nome_aluno, campus_aluno, matricula, campus_livro, campus_aluno,  responsavel, aux->p->prox);
            }
            else{
                fim->prox = novo;
                fim = novo;
                tam++;
            }
        }
}

void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("\tID: %d\n", aux->p->id);
            aux = aux->prox;
    }
}

PEDIDO remover_fila(){
    PEDIDO pedido;
        //remover!
        if(inicio != NULL){ //remover do antigo inicio da lista!
            
            NO *lixo = inicio;
            inicio = inicio->prox;
            pedido.identificador = lixo->p->identificador;
            //...
            free(lixo);
            tam--;
            if(tam == 1){
                fim = NULL;
            }
        }
    return pedido;
}


