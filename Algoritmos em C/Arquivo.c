#include <stdio.h>
#include <stdlib.h>

struct reg{
    int valor;
};
typedef struct reg Estrutura;

struct No{
    int valor;
    struct No *prox;
};
typedef struct No Lista;


void imprimir_lista(Lista *li);
void inserir_lista(Lista *li,int valor);
Lista *cria_lista();
void main(){
    FILE *arquivo;
    Estrutura r,c;
    Lista *li;
    li = cria_lista();
    inserir_lista(li,3);
    
    imprimir_lista(li);

    //r.valor = 5;
/*
    arquivo = fopen("texto.txt","a");
    //fseek(arquivo,0,SEEK_SET);
    fwrite(&r,sizeof(Estrutura),1,arquivo);//Usado para variavei heterogeneas(STRUCTS)
    //fseek(arquivo,0,SEEK_SET);
    arquivo = fopen("texto.txt","r");
    fread(&c,sizeof(Estrutura),1,arquivo);
    //fputs();
    printf("%i",c.valor);
*/
}
//void cria_lista(Lista *li){
//    li = (li*) malloc(sizeof(Lista));
//    li = NULL;
//} 

Lista *cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    li->prox = NULL;
    return li; 
}
void inserir_lista(Lista *li,int valor){
    Lista *novo;
    novo = malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = li->prox;
    li->prox = novo;
}

void imprimir_lista(Lista *li){
    Lista *aux = li->prox;
    
    while(aux!=NULL){
        printf("%i\n",aux->valor);
        aux = aux->prox;
    }
}