#include <stdio.h>
#include <stdlib.h>

#define TAM 50

char atual[TAM];

typedef struct usuario{
    int cpf;
    int senha;
    char *nome;
    char *cargo;
    struct usuario *prox;
}USUARIO;

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

USUARIO *new_user = NULL;
USUARIO *fim_user = NULL;
int user = 0;

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
    if(tree == NULL){
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
        printf("Insercao invalida!\n");     
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
            if(buscar(id, tree) == NULL){
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
            else{
                 printf("\n\tID %d nao pode ser adicionado!Existente da arvore.\n\n", id);
            }
        }
    }
}

USUARIO *busca_user(int cpf, int senha){
    USUARIO *aux = new_user;
    
    while(aux->cpf != cpf && aux->senha != senha){
        aux = aux->prox;
    }
    if(aux->prox != NULL){
        return aux;
    }
    else{
        return NULL;
    }
}

void add_user(int cpf, int senha, char *nome, char *cargo){
    
    USUARIO *novo = malloc(sizeof(USUARIO));
    novo->nome = nome;
    novo->senha = senha;
    novo->cpf = cpf;
    novo->cargo = cargo;
    novo->prox = NULL;
    
    if(new_user == NULL){
            new_user = novo;
            fim_user = novo;
            user++;
    }else{
        fim_user->prox = novo;
        fim_user = novo;
        user++;
    }

}

void data_atual(){

    time_t tempo;
    tempo = time(NULL);
    strftime(atual, sizeof(atual), "%d/%m/%Y %H:%M:%S", localtime( &tempo ));
    
}

int gerar_id(){
    int i;
    int b;

    srand((unsigned)time(NULL));

    do{
        i = (rand() % 100 -10) * (rand() % 100 -10);
    }while(i < 999 );

    return i;

}

void preCadastro(){

    if(new_user == NULL){    
        add_user(500063, 500063, "Igor", "Secretario");
        add_user(411631, 411631, "Otaviano", "Secretario");
        add_user(511427, 511427, "guilherme", "Secretario");
        add_user(111111, 111111, "Transportador_01", "Transportador");
        add_user(222222, 222222, "Transportador_02", "Transportador");
        add_user(333333, 333333, "Transportador_03", "Transportador");
        add_user(444444, 444444, "Transportador_04", "Transportador");
        add_user(555555, 555555, "Transportador_05", "Transportador");
    }
    
}

void imp_user(){

    USUARIO * aux = new_user;
    for(int i = 0; i < user; i++){
        printf("\tCPF: %d\n", aux->cpf);
        printf("\tNome: %s\n", aux->nome);
        printf("\tSenha: %d\n", aux->senha);
        printf("\tCargo: %s\n\n", aux->cargo);
        aux = aux->prox;
    }
}
