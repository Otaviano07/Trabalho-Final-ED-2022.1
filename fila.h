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

void add_fila(int prioridade, int id, char *data, char *aluno, char *campus_aluno, int matricula, char *livro, char *campus_livro, char *responsavel, NO *aux){
    
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
                novo->prox = inicio;
                tam++;
            }
            else{
                while(aux->prox && novo->p->prioridade < aux->p->prioridade){
                    aux = aux->prox;
                }
                novo->prox = aux->prox;
                aux->prox = inicio;
            }
        }
}

void imprimir_fila(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("\tID: %d\n", aux->p->id);
        printf("\tDATA: %s", aux->p->data_encomenda);
        printf("\tPRIORIDADE: %d", aux->p->prioridade);
        printf("\n\tALUNO: %s", aux->p->nome_aluno);
        printf("\n\tCAMPUS ALUNO: %s", aux->p->campus_aluno);
        printf("\n\tMatricula: %d", aux->p->matricula);
        printf("\n\tLIVRO: %s", aux->p->detalhes_livro);
        printf("\n\tCAMPUS LIVRO: %s\n\n", aux->p->campus_livro);
        aux = aux->prox;
    }
}

PEDIDO remover_fila(){
    PEDIDO p;
        if(inicio != NULL){
            
            NO *lixo = inicio;
            inicio = inicio->prox;
            p.id = lixo->p->id;
            p.data_encomenda= lixo->p->data_encomenda;
            p.matricula= lixo->p->matricula;
            p.nome_aluno= lixo->p->nome_aluno;          
            p.detalhes_livro= lixo->p->detalhes_livro;
            p.prioridade= lixo->p->prioridade;
            p.responsavel= lixo->p->responsavel;    
            p.campus_livro= lixo->p->campus_livro;
            p.campus_aluno= lixo->p->campus_aluno; 
            free(lixo);
            tam--;
            if(tam == 1){
                fim = NULL;
            }
        }
    return p;
}


