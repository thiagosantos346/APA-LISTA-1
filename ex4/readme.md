
#include <stdio.h>

int SomaVetor(int vetor[], int tamSub, int inic){
int soma=0;
/*esse for deve ir do inicio até o final do sub vetor*/
```c
for(int i=inic;i<inic+tamSub;i++){/*esse for deve ir do inicio até o final do sub vetor*/
  soma+=vetor[i];
}

if(soma<0){soma=0;};
  return soma;
}
```

```c
int main(){
  int n,i,j,tamSub,soma,Msoma;
  int vetor[10]={3,-4,6,3,-5,6,10,-9,-2,8};
```
  - Tamanho do sub vetor.
  
```c
  tamSub=1;
```
  - Maior soma.

```c
  Msoma=0;
```
  - Tamanho do vetor principal.
```c
  n=10;

  //=============================================
  for(j=0;j<n;j++){

    for(i=0;i<=n-tamSub;i++){
      soma=SomaVetor(vetor,tamSub,i);
      if(Msoma<soma){Msoma=soma;};
    };

    tamSub++;
  };
```
  O tamanho do sub vetor aumenta a cada execuçao da mesma forma que o numero de execuçoes
  diminui na medida em que o tamanho do sub vetor aumenta ent deveria afetar a complexidade
  (isso é o q se passa na minha cabeça)
  

```c
//=============================================
  printf("maior soma: %d\n",Msoma);

}
```
