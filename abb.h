typedef struct Documento{ // Documento de Encomenda - ABB
    int id_doc; // sistema q add
    int prioridade; // sec q add
    int mat_aluno; // est q add
    char * nome_aluno; // est q add
    char * detalhes_livro; // est q add
    char * campus_aluno; // est q add
    char * campus_livro;
    char * secretario; // secretario responsavel
    struct Documento * esq;
    struct Documento * dir;
}DOC;

DOC * raiz = NULL;
int tam = 0;

DOC * buscar(int id_doc, DOC *aux){
    if(aux != NULL){
        if(aux->id_doc == id_doc){
            return aux;
        }else if(id_doc < aux->id_doc){
            if(aux->esq != NULL){
                return buscar(id_doc, aux->esq);
            }else{
                return NULL;
            }
        }else if(id_doc > aux->id_doc){
            if(aux->dir != NULL){
                return buscar(id_doc, aux->dir);
            }else{
                return NULL;
            }
        }
    }else{
        return NULL;
    }
}

void adicionar_doc(int id_doc, int prioridade, DOC * pedido, char * campus_livro, char * secretario, DOC * aux){
    DOC * novo = malloc(sizeof(DOC));
    srand(time(NULL));
    novo->id_doc = id_doc;
    novo->prioridade = prioridade;
    novo->mat_aluno = pedido->mat_aluno;
    novo->nome_aluno = pedido->nome_aluno;
    novo->detalhes_livro = pedido->detalhes_livro;
    novo->campus_aluno = pedido->campus_aluno;
    novo->campus_livro = campus_livro;
    novo->secretario = secretario;
    novo->esq = NULL;
    novo->dir = NULL;
    if(raiz == NULL){
        raiz = novo;
        tam++;
        printf("\nNumero %d incluido com sucesso!!!", novo->id_doc);
    }
    else{
        if(buscar(novo->id_doc, raiz) == NULL){
            if(novo->id_doc < aux->id_doc){
                if(aux->esq != NULL){
                    adicionar_doc(novo->id_doc, novo->prioridade, pedido, novo->campus_livro, novo->secretario, aux->esq);
                }
                else{
                    aux->esq = novo;
                    tam++;
                    printf("Numero %d incluido com sucesso!!!", novo->id_doc);
                }
            }
            else{
                if(aux->dir != NULL){
                    adicionar_doc(novo->id_doc, novo->prioridade, pedido, novo->campus_livro, novo->secretario, aux->dir);
                }
                else{
                    aux->dir = novo;
                    tam++;
                    printf("Numero %d incluido com sucesso!!!", novo->id_doc);
                }
            }
        }
        else{
            printf("ID %d nao pode ser adicionado!\nExistente da arvore.", novo->id_doc);
        }
    }
}



void in_ordem(DOC *aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d ", aux->id_doc);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}
