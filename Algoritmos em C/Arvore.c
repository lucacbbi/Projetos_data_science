#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<stdbool.h>
struct No {
    int  conteudo; // conteúdo
    struct No *esquerda;
    struct No *direita;
}; // nó

typedef struct No Arvore; //typedef permite ao programador definir um novo nome para um determinado tipo.

//DECLARAÇÃO DE FUNÇÕES----------------------------
void cria_arvore( Arvore **arvoreRaiz);
int contar_nos(Arvore **arvoreRaiz);
int contar_folhas(Arvore **arvoreRaiz);
void alimenta_arvore( Arvore **arvoreRaiz,int qtd_elements);
void insere_arvore(Arvore **arvoreRaiz,int valor);
void imprime_arvore_erd( Arvore **arvoreRaiz);
Arvore *buscar_elemento(Arvore **arvoreRaiz,int valor);

//__________________________________________________
void main(){
//DECLARAÇÃO VARIAVEIS
    Arvore *arvoreRaiz;
    
//__________________________________________________
    cria_arvore(&arvoreRaiz);

    alimenta_arvore(&arvoreRaiz,10);

        
    imprime_arvore_erd(&arvoreRaiz);
    printf("Quantidade de nos:%i\n",contar_nos(&arvoreRaiz));
    printf("Quantidade de folhas:%i\n",contar_folhas(&arvoreRaiz));
    printf("Valor:");
    int valor;
    scanf("%i",&valor);
    printf("AQUI:%i",buscar_elemento(&arvoreRaiz,valor)->conteudo);
    //if(buscar_elemento(&arvoreRaiz,valor))
        //printf("AQUI");
}
void cria_arvore( Arvore **arvoreRaiz){
    *arvoreRaiz = NULL;
    printf("Arvore criada\n");
}

void imprime_arvore_erd(Arvore **arvoreRaiz){
    
    if(*arvoreRaiz != NULL){
        printf("No:%d\n",(*arvoreRaiz)->conteudo);//Pre ordem
        imprime_arvore_erd(&(*arvoreRaiz)->esquerda);
        //printf("No:%d\n",(*arvoreRaiz)->conteudo);//Em ordem
        imprime_arvore_erd(&(*arvoreRaiz)->direita);
        //printf("No:%d\n",(*arvoreRaiz)->conteudo);//Pos ordem
    }
}
void alimenta_arvore(Arvore **arvoreRaiz,int qtd_elements){
    int i;
    for ( i = 0; i < qtd_elements; i++)
    {
        insere_arvore(&(*arvoreRaiz),rand()%qtd_elements);
    }
}

void insere_arvore(Arvore **arvoreRaiz,int valor){
    printf("Entrou para alimentar\n");
    if(*arvoreRaiz == NULL){//Se o no raiz apontar para null
        *arvoreRaiz = (Arvore *)malloc(sizeof(Arvore));//Aloca um espaço na memoria do tamanho da truct No Arvore
        (*arvoreRaiz)->esquerda = NULL;
        (*arvoreRaiz)->direita = NULL;
        (*arvoreRaiz)->conteudo = valor;
    }else{
        if(valor%2 == 0)//Se o numero for par 
            insere_arvore(&(*arvoreRaiz)->esquerda,valor);
        else//Se o numero for impar 
            insere_arvore(&(*arvoreRaiz)->direita,valor);   
    }
}
void remover_arvore(Arvore **arvoreRaiz,int valor){

}
int contar_nos(Arvore **arvoreRaiz){
   if(*arvoreRaiz == NULL)
        return 0;
   else
        return 1 + contar_nos(&(*arvoreRaiz)->esquerda) + contar_nos(&(*arvoreRaiz)->direita);
}

int contar_folhas(Arvore **arvoreRaiz){
   if(*arvoreRaiz == NULL)
        return 0;
   if((*arvoreRaiz)->esquerda == NULL && (*arvoreRaiz)->direita == NULL)
        return 1;
   return contar_folhas(&(*arvoreRaiz)->esquerda) + contar_folhas(&(*arvoreRaiz)->direita);
}
   
/*
bool buscar_elemento(Arvore **arvoreRaiz,int valor){
    
    if (*arvoreRaiz == NULL)
        return false;
    if((*arvoreRaiz)->conteudo == valor)
        return true;
    //if(valor%2 == 0)
        return buscar_elemento(&(*arvoreRaiz)->esquerda,valor);
    //else
        return buscar_elemento(&(*arvoreRaiz)->direita,valor);    
}
*/

Arvore *buscar_elemento(Arvore **arvoreRaiz,int valor){
    
    if (*arvoreRaiz == NULL)
        return NULL;
    if((*arvoreRaiz)->conteudo == valor)
        return *arvoreRaiz;

    return buscar_elemento(&(*arvoreRaiz)->esquerda,valor);
    
    return buscar_elemento(&(*arvoreRaiz)->direita,valor);    
}

int isInTree(Arvore *arvoreRaiz, int num) {
  
  if(arvoreRaiz == NULL) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }
  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return arvoreRaiz->conteudo==num || isInTree(arvoreRaiz->esquerda, num) || isInTree(arvoreRaiz->direita, num);
}


