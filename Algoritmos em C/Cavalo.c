#include <stdio.h>
#include <stdlib.h>


struct Cavalo{
    int linha;
    int coluna;
    int movimento;
};
struct Movimento{
    int mov[2];
};
typedef struct Movimento Mov_cavalo;
typedef struct Cavalo cavalo;
//Declaração funcoes
int **criar_tabuleiro(int linhas,int colunas);
void movimentar_cavalo(int **tabuleiro,int linhas,int colunas,cavalo *ca);
void printar_tabuleiro(int **tabuleiro,int linhas,int colunas);
void muda(int **tabuleiro,int linhas,int colunas,cavalo *ca,Mov_cavalo movimento[],int movs);

void main(){
    cavalo cavalo;
    int linhas = 8,colunas = 8;
    Mov_cavalo movimento[8];

    movimento[0].mov[0] = 2;
    movimento[0].mov[1]= 1;

    movimento[1].mov[0]=2;
    movimento[1].mov[1]=-1;

    movimento[2].mov[0]=-2;
    movimento[2].mov[1]=1;

    movimento[3].mov[0]=-2;
    movimento[3].mov[1]=-1;

    movimento[4].mov[0]=1;
    movimento[4].mov[1]=2;

    movimento[5].mov[0]=-1;
    movimento[5].mov[1]=2;

    movimento[6].mov[0]=1;
    movimento[6].mov[1]=-2;

    movimento[7].mov[0]=-1;
    movimento[7].mov[1]=-2;

    cavalo.linha = 0;
    cavalo.coluna = 5;
    cavalo.movimento = 1;

    int **tabuleiro = criar_tabuleiro(linhas,colunas);
    //movimentar_cavalo(tabuleiro,linhas,colunas,&cavalo);

    //movimentar_cavalo(tabuleiro,linhas,colunas,&cavalo);

    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    muda(tabuleiro, linhas,colunas,&cavalo,movimento,8);
    printf("\nQuantidade de movimentos:%i\n",cavalo.movimento);    
    printar_tabuleiro(tabuleiro,linhas,colunas);


}


//PROBLEMAS 

//Não existenciaa da celula
//Celula ocupada
int **criar_tabuleiro(int linhas,int colunas){
    int **matriz;
    int i,j,k;
    //colunas
    matriz = (int**) malloc(sizeof(int)*colunas);

    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int**) malloc(sizeof(int)*colunas);
    }

    for (j = 0; j < linhas; j++)
    {
        for (k = 0; k < colunas; k++)
        {
            matriz[j][k] = 0;
        }
        
    }

    return matriz;
}
//POSSIBILIDADES

//2,1
//2,-1
//-2,1
//-2,-1

//1,2
//-1,2
//1,-2
//-1,-2

void muda(int **tabuleiro,int linhas,int colunas,cavalo *ca,Mov_cavalo movimento[],int movs){
    int i;
   for (i = 0; i < movs; i++)
   {
        if (ca->movimento == 1)
        {
            printf("\nENTROU %i",i);
            tabuleiro[ca->linha][ca->coluna] = ca->movimento;
            printf("[%i][%i]\n",ca->linha,ca->coluna);
            //printf("Move %i",ca->movimento);

            ca->movimento+=1;
            
        }else{
            if(((ca->linha+movimento[i].mov[0] )>= 0) && ((ca->coluna+movimento[i].mov[1]) >= 0) &&(ca->linha+movimento[i].mov[0] < linhas) && (ca->coluna+movimento[i].mov[1] < colunas)&&(tabuleiro[ca->linha + movimento[i].mov[0]][ca->coluna + movimento[i].mov[1]]==0)){
                printf("ENTROU %i",i);

                tabuleiro[ca->linha+movimento[i].mov[0]][ca->coluna+movimento[i].mov[1]] = ca->movimento;
                printf("[%i][%i]\n",ca->linha+movimento[i].mov[0],ca->coluna+movimento[i].mov[1]);
                ca->linha +=movimento[i].mov[0];
                ca->coluna+=movimento[i].mov[1];
                //printf("\nMove %i\n",ca->movimento);
                ca->movimento+=1;
            }
        }
   }
}



void movimentar_cavalo(int **tabuleiro,int linhas,int colunas,cavalo *ca){
    if (ca->movimento == 1)
    {
        printf("MOVIMENTO-1:");
        tabuleiro[ca->linha][ca->coluna] = ca->movimento;
        printf("[%i][%i]\n",ca->linha,ca->coluna);

        ca->movimento+=1;
        
    }else{
        if((ca->linha+2 < linhas) && (ca->coluna+1 < colunas) && (tabuleiro[ca->linha+2][ca->coluna+1] == 0)){
            printf("MOVIMENTO-2:");

            tabuleiro[(ca->linha+2)][(ca->coluna+1)] = ca->movimento;
            printf("[%i][%i]\n",ca->linha+2,ca->coluna+1);
            ca->linha +=2;
            ca->coluna+=1;
            ca->movimento+=1;
        }else if(((ca->linha+2) < linhas) && ((ca->coluna-1) >= 0) && (tabuleiro[ca->linha+2][ca->coluna-1]==0)){
            printf("MOVIMENTO-3:");

            tabuleiro[ca->linha+2][ca->coluna-1] = ca->movimento;
            printf("[%i][%i]\n",ca->linha+2,ca->coluna-1);
            ca->linha +=2;
            ca->coluna-=1;
            ca->movimento+=1;
        }else if(((ca->linha-2) >= 0) && ((ca->coluna+1) < colunas)  && (tabuleiro[ca->linha-2][ca->coluna+1]==0)){
            printf("MOVIMENTO-4:");

            tabuleiro[ca->linha-2][ca->coluna+1] = ca->movimento;
            printf("[%i][%i]\n",ca->linha-2,ca->coluna+1);

            ca->linha -=2;
            ca->coluna+=1;
            ca->movimento+=1;

        }else if(((ca->linha-2 )>= 0) && ((ca->coluna-1) >= 0)  && (tabuleiro[ca->linha-2][ca->coluna-1]==0)){
            printf("MOVIMENTO-5:");

            tabuleiro[ca->linha-2][ca->coluna-1] = ca->movimento;
            printf("[%i][%i]\n",ca->linha-2,ca->coluna-1);
            ca->linha -=2;
            ca->coluna-=1;
            ca->movimento+=1;
        //-------------------------------------------------
        //1,2
//-1,2
//1,-2
//-1,-2
        }else if(((ca->linha+1 )< linhas) && ((ca->coluna+2) < colunas)  && (tabuleiro[ca->linha+1][ca->coluna+2]==0)){
            printf("MOVIMENTO-6:");

            tabuleiro[ca->linha+1][ca->coluna+2] = ca->movimento;
            printf("[%i][%i]\n",ca->linha+1,ca->coluna+2);
            ca->linha +=1;
            ca->coluna+=2;
            ca->movimento+=1;
        }else if(((ca->linha-1 ) >= 0) && ((ca->coluna+2) < colunas)  && (tabuleiro[ca->linha-1][ca->coluna+2]==0)){
            printf("MOVIMENTO-7:");

            tabuleiro[ca->linha-1][ca->coluna+2] = ca->movimento;
            printf("[%i][%i]\n",ca->linha-1,ca->coluna+2);
            ca->linha -=1;
            ca->coluna+=2;
            ca->movimento+=1;
        }else if(((ca->linha+1 )<linhas) && ((ca->coluna-2) >= 0)  && (tabuleiro[ca->linha+1][ca->coluna-2]==0)){
            printf("MOVIMENTO-8:");

            tabuleiro[ca->linha+1][ca->coluna-2] = ca->movimento;
            printf("[%i][%i]\n",ca->linha+1,ca->coluna-2);
            ca->linha +=1;
            ca->coluna-=2;
            ca->movimento+=1;
        }else if(((ca->linha-1 ) >= 0) && ((ca->coluna-2)  >= 0)  && (tabuleiro[ca->linha-1][ca->coluna-2]==0)){
            printf("MOVIMENTO-9: ");

            tabuleiro[ca->linha-1][ca->coluna-2] = ca->movimento;
            printf("[%i][%i]\n",ca->linha-1,ca->coluna-2);
            ca->linha -=1;
            ca->coluna-=2;
            ca->movimento+=1;
        }
    }
    
    
    
}
void printar_tabuleiro(int **tabuleiro,int linhas,int colunas){
    printf("\nTABULEIRO\n");
    int j,k;
    
    for (j = 0; j < linhas; j++)
    {
        for (k= 0; k < colunas; k++)
        {
            printf("%i ",tabuleiro[j][k]);
            if(k==colunas-1)
                printf("\n");
        }
        
    }
}
/*
int StringMatch(text1[],text2[],n1,n2){
    int cont = 0;
    for(int i = 0;i<n1;i++){
        if(text1[0] == text2[i]){
            for(int j = 0;i<n2;j++){
                if(text1[j] != text2[i+j])
                    break;
                else
                    cont++;
            }     
        }   
    }
    if(cont == n1)
        return 1;
    else
        return 0;

}

void mochila(int mochila[],int k,int vetor_itens[],int n){
    int menor_peso=100000;
    int tamanho = k;
for (size_t i = 0; i < count; i++)
{
    for (size_t i = 0; i < count; i++)
    {
        
    }
    
}

    if(vetor_itens[i]<tamanho )
}
*/