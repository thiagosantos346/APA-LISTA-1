# Analise de complexidade
---
```c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
```

- Para o problema do quadrado mágico há diversas implementações diferentes, até implementações com algoritmos genéticos, mas para esse trabalho, foi escolhido um método mais direto e simples. Para isso tem que levar em consideração que existem 3 tipos diferentes de quadrados mágicos e para cada um, existe uma forma diferente de solucionar:
  1. Quadrado mágico Impar, em que o valor de n é impar, chamado de 'Odd Even' (3,5,7,9,...)
  2. Quadrados que são divisíveis perfeitamente por 4, em que valor de n pode ser encontrado através da formula n = (m*4), chamados de 'Doubly Even' (4,8,12,16,...)
  3. Quadrado que são divisíveis por 2, são aqueles que não entram na caso acima, mas ainda são pares e o valor de n é encontrado através da formula n = 2(2*m+1), são chamados de 'Singly even' (6,10,14,18,...)


```c
void printSquare(int n, int square[][n]){
	//Função usada para imprimir os quadrados mágicos
	int i, j;
	printf("Solucao para n = %d e soma magica = %d\n", n, (n*(n*n+1)/2));
	for(i = 0; i < n; i++){
		printf("| ");
		for(j = 0; j < n; j++){
			printf("%3d |", square[i][j]);
		}
		printf("\n");
	}
}
```

```c
void oddSolution(int n,int square[][n]){
```

	
	Quando se n é impar, se começa na linha do meio e na ultima coluna
	(existem implementações diferentes, mas sempre se começa pelo cantos da coluna ou linha do meio)
	Tem que se levar em consideração 3 condições
	1 -> A próxima posição é encontrada decrementando a linha(i) em 1 (i--) e incrementando coluna(j) em 1 (j++)
		,se o valor de i passar a ser negativo, ele recebe n-1 e se a coluna tiver valor igual a n recebe 0.
	2 -> Se a posição em questão ja tiver um valor, então j = j - 2 e i = i + 1
	3 -> Se a linha(i) tiver valor -1 e a coluna(j) tiver valor n, então as novos valores passar a ser i = 0 , j = n-2
	

```c
	int i, j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			square[i][j] = 0;
		}
	}
	
	i = n/2; //setando os valores que serão 
	j = n-1; //pontos de inicio do algoritmo
	int num = 1;

	while(num <= n*n) {
        //Controla a terceira condição
		if (i == -1 && j == n){
            j = n-2;
            i = 0;
        }
        else {
            //Controle da primeira condição para caso o j tenha valor menor que 0
            //isto é, caso saia do quadrado pela parte de cima
            if (i < 0) i = n-1;
                
            //Controle da primeira condição para caso o j tenha valor igual a n
            //isto é, caso saia do quadrado pela lateral
            if (j == n) j = 0;
        }
```
 - Controla a segunda condição para caso a posição verificada já tenha um valor

```c
        if (square[i][j] != 0) {
            j = j-2;
            i++;
        }
        else{
			square[i][j] = num; //coloca o valor naquela posição
			num++;
```
  - Controle da primeira condição em que decrementa i e incrementa j
```c
			i--; 
			j++;
		}
    }
}
```

```c
void doublyEvenSolution(int n){
	
	int square[n][n], i, j; 
	int count = 1;
```

	- Primeiro passo é preencher o quadrado normalmente com valor de 1 a N
	

```c
    for ( i = 0; i < n; i++){
    	for ( j = 0; j < n; j++) {
    		square[i][j] = count;
			count++; 
		}
			
	}
```
    - O proximo passo é alterar as posições de valores dentro da quadrado por posições especificas dentro da matriz seguindo a seguinte regra:
     (n*n+1)-square[i][j] 
 
    - Se começa pelo topo esquerda do quadrado a região que terá seus valores trocados é um quadrado menor com o tamanho (n/4)², dentro do quadrado maior e terá seus valores trocados com os valores que estão no quadrado de tamanho (n/4)² do canto inferior direito, de forma espelhada e invertida.
  
```c
    for ( i = 0; i < n/4; i++) 

        for ( j = 0; j < n/4; j++) 
            square[i][j] = (n*n + 1) - square[i][j]; 
```
   - Agora se troca os valores do topo direito do quadrado seguindo a mesma ideia do passo anterior, uma região quadrada (n/4)² tem seus valores substituidos por um quadrado (n/4)² que se encontra no canto inferior direito, de forma espelhada e invertida
  
```c
    for ( i = 0; i < n/4; i++) 
        for ( j = 3 * (n/4); j < n; j++) 
            square[i][j] = (n*n + 1) - square[i][j]; 
```
    - Agora se faz o mesmo processo em relação ao canto inferior esquerdo, seguindo a mesma ideia dos dois primeiros passos, o que muda é que o vai se basear nos antigos valores do canto superior direito de forma espelhada e invertida
```c
    for ( i = 3 * n/4; i < n; i++) 
        for ( j = 0; j < n/4; j++) 
            square[i][j] = (n*n+1) - square[i][j]; 
```

    - Agora se faz o mesmo processo em relação ao canto inferior direito, seguindo a mesma ideia dos dois primeiros passos, o que muda é que o vai se basear nos antigos valores do canto superior esquerdo de forma espelhada e invertida

     
```c
    for ( i = 3 * n/4; i < n; i++) 
        for ( j = 3 * n/4; j < n; j++) 
            square[i][j] = (n*n + 1) - square[i][j]; 
```
    - Agora se altera o centro do quadrado magico, inverteando os valores internos de forma espelhada e invertida, o quadrado interno que será alterado tem tamanho (n/2)²

```c
    for ( i = n/4; i < 3 * n/4; i++) 
        for ( j = n/4; j < 3 * n/4; j++) 
            square[i][j] = (n*n + 1) - square[i][j]; 
            
    printSquare(n, square);
}
```

```c
void singlyEvenSolution(int n) {
```

	| 1Q | 2Q |
	| 3Q | 4Q |
	- Exemplo dos quadrantes dentro do quadrado magico:
		- Esse quadrado tem uma caracteristicas interessante, pelo n ser um par e não divisivel por 4, a metade de N vai sempre ser um valor impar e usaremos isso para resolver o quadrado mágico.

		- O quadrado de tamanho N terá dentro dele 4 quadrados de tamanho n/2, como eles são impares, se utiliza o oddSolution para preencher esses quadrados impares.

		- Após isso cada quadrante do quadrado maior terá 4 sub quadrados preenchidos de 1 até n/2, para criar o quadrado mágico é necessario somar um valor em cada numero de cada quadrante, mas esse valor varia por quadrante, por conta do fator de multiplicação:

		1. No primeiro quadrante(topo esquerda) é somado ((n/2)^2 * fator), sendo fator = 0; 
		2. No o segundo quadrante(topo direito) é somado ((n/2)^2 * fator), sendo fator = 2;
		3. Mo terceiro quadrante(base esquerda) é somado ((n/2)^2 * fator), sendo fator = 3;
		4. E no ultimo quadrante (base direita) é somado ((n/2)^2 * fator), sendo fator = 1;

```c   
    int halfN = (n/2);
```

  - Invés de gerar os valores dentro do quadrado maior, fazemos isso em uma matriz a parte e utilizamos ela para as operações que serão feitas.

```c
	int subSquare[halfN][halfN]; 
```		 
	oddSolution(halfN, subSquare);
```c
  int subSquaresFactors[] = {0, 2, 3, 1};
```

- Será utilizado para determinar o valor que será somado ao numero dentro de cada quadrante
  
```c
    int square[n][n];

 	int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int factor;
            
            if((i < halfN) && (j < halfN)) { //quadrante topo esquerda
            	factor = 0;
			}
            else if((i < halfN) && (j >= halfN)){ // quadrante topo direita
            	factor = 2;
			} 
            else if((i >= halfN) && (j < halfN)){ //quadrante base esquerda
            	factor = 3;
			}
            else{// quadrante base direita
            	factor = 1;
			}  
            
            square[i][j] = subSquare[i % halfN][j % halfN]; // adicionando o valor do quadrado menor no quadrado maior
            square[i][j] += halfN * halfN * factor; //soma o valor extra a posição de determinado quadrante
        }
    }
```
 	- Ainda é necessario mais um passo para se chegar ao quadrado mágico que consiste em pegar números de posições especificas e trocar com  numeros de outras posições;

 	- As trocas irão acontecer no quadrante da esquerda( 1 e 3) e as (m - 1) colunas dos quadrantes da direita(2 e 4) [O m vem da formula n = 2(2*m-1)];

 	- Nos da esquerda, os numeros a esquerda da coluna que divide o quadrante ao meio vão trocar de lugar com o vizinho na vertical;

 	- Os numeros que estão no quadrante 1 vão para o 3 e vice versa, unica excessão é na linha que se encontra no meio do quadrante;
 	- Na linha do meio se pula uma casa, isto é, se pega os numeros da posição 1 ate o numero do centro do quadrante;

 	- E para saber se teremos que alterar os quadrantes 2 e 4, é so usar a formula m-1 e o resultado é a quantidade de colunas que devem ser trocadas entre os quadrantes 2 e 4;

  - Exemplo:
  No caso de n = 6, aplicamos em 6 = 2(2*m-1), temos m = 1, logo 1-1 é 0, logo não se mexe em nenhuma coluna, ja caso n = 10, teremos m = 2, 2-1 = 1, então teríamos que mexer na ultima coluna dos quadrantes 2 e 4 e inverter eles.

- Ao fim desse processo, temos um quadrado magico.
  
```c
    int nColsLeft = halfN / 2;
    int nColsRight = nColsLeft - 1;
 
    for (i = 0; i < halfN; i++){
    	for (j = 0; j < n; j++) {
            if (j < nColsLeft || j >= n - nColsRight || (j == nColsLeft && i == nColsLeft)) {

                if (j == 0 && i == nColsLeft)
                    continue;
 
                int tmp = square[i][j];
                square[i][j] = square[i + halfN][j];
                square[i + halfN][j] = tmp;
        	}
    	}	
	}
	printSquare(n, square);
}
```

---
### Função principal contendo um exemplo de uso das funções implementadas acima.
---
```c
int main(){
	int n, max;
	
	printf("N minimo eh sempre 3\nInsira o valor maximo de n:");
	scanf("%d", &max);
	
	n = 3;
	while(n <= max){
		int square[n][n];
		if((n%2) == 1){
			oddSolution(n, square);
			printSquare(n, square); //caso de impar
		}else if(n%4 == 0){
			doublyEvenSolution(n); //caso de divisiveis por 4
		} else if(((n%4)-2) == 0){
			singlyEvenSolution(n); // caso dos divisiveis por 2, mas não por 4
		}
		n++;	
	};

	return 0;
}
```
---
