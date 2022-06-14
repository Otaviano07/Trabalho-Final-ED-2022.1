#include <stdio.h>
#include <stdlib.h>


typedef struct pedido{
    int identificador;
    char * nome_aluno;
    //... demais dados
    int prioridade;
    
}PEDIDO;

typedef struct No{
   
    PEDIDO *p;
    
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add_fila(int identificador, char *nome_aluno, int prioridade){
    
        PEDIDO * p = malloc(sizeof(PEDIDO));
        p->identificador = identificador;
        p->nome_aluno = nome_aluno;
        p->prioridade = prioridade;
        
        NO * novo = malloc(sizeof(NO));
        novo->p = p;
        novo->prox = NULL;
    
    
        if(inicio == NULL){ //fila vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else{ //adiciona de acordo com a prioridade! :D
            //modificar!
            fim->prox = novo;
            fim = novo;
            tam++;
        }
}


void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Identificador: %d\n", aux->p->identificador);
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


