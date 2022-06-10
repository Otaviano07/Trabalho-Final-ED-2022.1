//Nome: Otaviano Rodrigues da Silva Matricula: 411631
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
   
    int id; //identificador unico de cada vertice
    char *nomeAuno;
    char *descricao;
    int matricula;
    struct Vertice * esq;
    struct Vertice * dir;
}VERTICE;

VERTICE * raiz = NULL;
int tam = 0;

VERTICE* buscar(int id, VERTICE *aux){
    
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

void adicionar(int id, VERTICE *aux){

    VERTICE *novo = malloc(sizeof(VERTICE));
    novo->id = id;
    //novo->nomeAuno = nomeAuno;
    //novo->matricula = matricula;
    //novo->descricao = descricao;
    novo->esq = NULL;
    novo->dir = NULL;

    if(raiz == NULL){
        raiz = novo;
        tam++;
        printf("\nNumero %d incluido com sucesso!!!", id);
    }
    else{
        if(buscar(id, raiz) == NULL){
            if(novo->id < aux->id){
                
                if(aux->esq != NULL){
                    adicionar(id, aux->esq);
                }
                else{
                    aux->esq = novo;
                    tam++;
                    printf("Numero %d incluido com sucesso!!!", id);
                }
            }
            else{
                if(aux->dir != NULL){
                    adicionar(id, aux->dir);
                }
                else{
                    aux->dir = novo;
                    tam++;
                    printf("Numero %d incluido com sucesso!!!", id);
                }
            }
        }
        else{
            printf("ID %d nao pode ser adicionado!\nExistente da arvore.", id);
        }
    }

}


void in_ordem(VERTICE *aux){
    //Impressão dos dados da arvore em in-ordem
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d, ", aux->id);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}


void menu(){
    VERTICE *encontrado;
    int opcao;
    int id;

    do{
        
        printf("\n\n------------ Menu Arvore Binaria ------------\n");
        printf("\n\t[1] Incluir Vertice\n");
        printf("\t[2] Imprimir Pre-Ordem\n");
        printf("\t[3] Imprimir In-Ordem\n");
        printf("\t[4] Imprimir Pos-Ordem\n");
        printf("\t[5] Buscar ID\n");
        printf("\t[0] Sair\n");
        printf("\nQual a sua opcao? ");
        scanf("%d",&opcao);

    
        switch(opcao){
            case 1://Nesse caso o usuario adiciona um novo ID na arvore
                printf("\nDigite um numero: ");
                scanf("%d",&id);
                printf("\n------------ Menu Adicionar Numero ------------\n\n");
                adicionar(id,raiz);
            break;
            case 2://Nesse caso e realizado a impressao pre-ordem dos IDs da arvore
                printf("\n------------ Menu Impressao Pre-Ordem ------------\n\n");
                printf("\nImpressao Pre-Ordem: ");
                pre_ordem(raiz);
            break;
            case 3://Nesse caso e realizado a impressao in-ordem dos IDs da arvore
                printf("\n------------ Menu Impressao In-Ordem ------------\n\n");
                printf("\nImpressao In-Ordem: ");
                in_ordem(raiz);
            break;
            case 4://Nesse caso e realizado a impressao pos-ordem dos IDs da arvore
                printf("\n------------ Menu Impressao Pos-Ordem ------------\n\n");
                printf("\nImpressao Pos-Ordem: ");
                pos_ordem(raiz);
            break;
            case 5://Nesse caso e realizado busca do IDs na arvore
                printf("\n------------ Menu Busca Arvore Binaria ------------\n\n");
                printf("\nDigite o numero para procurar: ");
                scanf("%d",&id);
                if(buscar(id, raiz) != NULL){
                    printf("\nNumero %d encontrado com sucesso :)", id);
                }
                else{
                    printf("\nNumero %d nao encontrado :(", id);
                }
            break;
        }
    }while(opcao != 0);//Enquanto opcao for diferente de "0" o laco while continua
}

int main(){
    menu();//chama a funcao menu
    printf("\nSaindo do sistema!!!\n\n");

    return 0;
}
