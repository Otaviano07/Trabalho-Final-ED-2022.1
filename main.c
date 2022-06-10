#include <stdio.h>
#include <stdlib.h>

typedef struct No{
   int id;
   int sexo;
   int num_filhotes;
   struct No * prox;
   struct No * ant;
}NO;

NO * inicio;
int tam = 0;

void add(int id, int sexo, int num_filhotes){
    
    
        NO * novo = malloc(sizeof(NO));
        novo->id = id;
        novo->sexo = sexo;
        novo->num_filhotes = num_filhotes;

        if(tam == 0){ //lista vazia
            novo->prox = novo;
            novo->ant = novo;
            inicio = novo;
            tam++;
        }else{
            

        }       
        }else if(pos == tam){ //fim
            novo->ant = fim; //NOVIDADE!
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"
            
            NO * aux = inicio;
            for(int i = 0; i < pos; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            }
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
            tam++;
        }
    
    }else{
        printf("deu ruim!!\n");
    }
}


void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Cod prod: %d\n", aux->cod_prod);
            aux = aux->prox;
    }
}



int main(){

    add(1, 1, 2);
    add(2, 1, 1);
    add(3, 0, 0);
    add(4, 1, 2);
    add(5, 0, 0);
       
    return 0;
}




