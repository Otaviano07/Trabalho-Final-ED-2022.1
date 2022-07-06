#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 50
char atual[TAM];

typedef struct usuario{
    int cpf;
    int senha;
    char *nome;
    char *cargo;
    struct usuario *prox;
}USUARIO;

USUARIO *new_user = NULL;
int user = 0;

USUARIO *busca_user(int cpf, int senha){
    USUARIO *aux = new_user;
    
    if(aux->prox == NULL){
        return NULL;
    }
    else{
        while(aux->cpf != cpf && aux->senha != senha){
            aux = aux->prox;
        }
        return aux;
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
        user++;
    }else{
        new_user->prox = novo;
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
