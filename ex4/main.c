#include <stdio.h>

int SomaVetor(int vetor[], int tamSub, int inic){
int soma=0;
for(int i=inic;i<inic+tamSub;i++){/*esse for deve ir do inicio até o final do sub vetor*/
soma+=vetor[i];
}
if(soma<0){soma=0;};
return soma;
}


int main(){
int n,i,j,tamSub,soma,Msoma;
int vetor[10]={3,-4,6,3,-5,6,10,-9,-2,8};
tamSub=1;/*tamanho do sub vetor*/
Msoma=0;/*maior soma*/
n=10;/*tamanho do vetor principal*/

//=============================================
for(j=0;j<n;j++){

for(i=0;i<=n-tamSub;i++){
    soma=SomaVetor(vetor,tamSub,i);
    if(Msoma<soma){Msoma=soma;};
};

tamSub++;
};
/*o tamanho do sub vetor aumenta a cada execuçao da mesma forma que o numero de execuçoes
diminui na medida em que o tamanho do sub vetor aumenta ent deveria afetar a complexidade
 (isso é o q se passa na minha cabeça)*/
//=============================================

printf("maior soma: %d\n",Msoma);

}
