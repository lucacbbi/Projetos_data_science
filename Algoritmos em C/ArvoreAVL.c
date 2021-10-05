#include <stdio.h>
#include <stdlib.h>

//ESTRTURAS-------------------------------------------------------------

struct No{
    int altura;
    int valor;
    struct No *esq;
    struct No *dir;
};
typedef struct No Arvore;

//ESCOPO DE FUNÇÕES------------------------------------------------------

void cria_arvore(Arvore **raiz);
void inserir(Arvore **raiz,int valor);
void rotacao_RR(Arvore *raiz);
void rotacao_LL(Arvore *raiz);
void rotacao_LR(Arvore *raiz);
void rotacao_RL(Arvore *raiz);
int maior(int x,int y);
int altura_no(Arvore **raiz);

void main(){
Arvore *raiz;
cria_arvore(&raiz);
inserir(&raiz,2);


}
void cria_arvore(Arvore **raiz){
    *raiz = NULL;
    printf("Arvore criada!!");
}
int altura_no(Arvore **raiz){
    if(*raiz == NULL)
        return -1;
    else 
        return (*raiz)->altura;    
}
int fator_de_balanceamento(Arvore **raiz){
    return (altura_no(&(*raiz)->esq) - altura_no(&(*raiz)->dir));
}

int maior(int x,int y){
    if(x>y)
        return x;
    else
        return y;    
}
void rotacao_RR(Arvore *raiz){
    Arvore *aux_raiz,*temp;
    aux_raiz = raiz->esq;
    temp = aux_raiz->dir;
    aux_raiz->dir = raiz;
    raiz->dir = temp;
    raiz = aux_raiz;
}
void rotacao_LL(Arvore *raiz){
    Arvore *aux_raiz,*temp;
    aux_raiz = raiz->dir;
    temp = aux_raiz->esq;
    aux_raiz->esq = raiz;
    raiz->dir = temp;
    raiz = aux_raiz;
}
void rotacao_LR(Arvore *raiz){
    rotacao_dir(&(raiz)->esq);
    rotacao_esq(raiz);
}
void rotacao_RL(Arvore *raiz){
    rotacao_esq(&(raiz)->dir);
    rotacao_dir(raiz);
}

void inserir(Arvore **raiz,int valor){
    int res;
    if(*raiz == NULL){
        *raiz = (Arvore*)malloc(sizeof(Arvore));
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
        (*raiz)->valor = valor;
        return 1;
    }
    
    Arvore *atual = *raiz;

    if(valor<&atual->valor){
        if((res=inserir(&(atual)->esq,valor))==1){
            if(fator_de_balanceamento(&(atual))>=2){
                if(valor<(*raiz)->esq->valor){
                    rotacao_LL(*raiz);
                }else{
                    rotacao_LR(*raiz);
                }
            }
        }
    }else{
        if((res=inserir(&(atual)->esq,valor))==1){
            if(fator_de_balanceamento(&(atual))>=2){
                if(valor<(*raiz)->dir->valor<valor){
                    rotacao_RR(*raiz);
                }else{
                    rotacao_RL(*raiz);
                }
            }
        }else{
            printf("Valor duplicado");
            return 0; 
        }
    }
    atual->altura = maior(altura_no(atual->esq),altura_no(atual->dir))+1;
}


