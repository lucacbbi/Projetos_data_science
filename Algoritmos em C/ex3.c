#include <stdio.h>
#include <stdlib.h>
int segundo_maior(int vetor[],int n);
void main(){
    int vetor[5] = {1,2,3,4,5};

    printf("%i",segundo_maior(vetor,5));

}

int segundo_maior(int vetor[],int n){
    int i,maior=0,segundoMaior=0;

    for ( i = 0; i < n; i++)//n+1
    {
        if (vetor[i]>maior)//n
        {
            segundoMaior = maior;//1
            maior = vetor[i];//1
        }
    }
    return segundoMaior;
}

//Otimista: n+1 + 3 = n+4 = O(n)
//Medio: n+1 + 2n/2 = 2n+1 = O(n)
//Pessimista: n+1 + 2n = 3n+1 = O(n)
int i,a[6]={1,2,3,4,5,6}, k=0;
for ( i = 0; i < 6; i++)//n+1
{
    if(a[i]==6)//n
        k++;//1
}
//a)2n+2/6
//b)2n+2/2 = 2n
//c)