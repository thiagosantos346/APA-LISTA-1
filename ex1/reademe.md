# Selection Sort e Heap Sort um Selection Sort SelectionSort aprimorado 

## Análise de Complexidade para O selection Sort

https://github.com/thiagosantos346/APA-LISTA-1/blob/db328629e8af1dd87677ecbcccf32dce2aaf6917/ex1/main.c#L255-L268


|classe |Algoritmo de ordenação|
| ------| -------------------- |
| Estrutura de dados |	Array, Listas ligadas |
| Complexidade pior caso |	O (n²) |
| Complexidade caso médio| 	O (n²) |
| Complexidade melhor caso |	O (n²) |

* Note que o motivo dessa complexidade está diretamente ligada as seguintes linhas :

https://github.com/thiagosantos346/APA-LISTA-1/blob/db328629e8af1dd87677ecbcccf32dce2aaf6917/ex1/main.c#L260-L265

* Neste caso temos o primeiro for externo, ambas as funções contem laços for também, veja :
Esta função é responsável por fazer uma busca linear pelo menor item do array.
https://github.com/thiagosantos346/APA-LISTA-1/blob/db328629e8af1dd87677ecbcccf32dce2aaf6917/ex1/main.c#L36

https://github.com/thiagosantos346/APA-LISTA-1/blob/db328629e8af1dd87677ecbcccf32dce2aaf6917/ex1/main.c#L223-L230

* Já esta é responsável por remover esse item do vetor para evitar que ele seja comparado novamente:
https://github.com/thiagosantos346/APA-LISTA-1/blob/db328629e8af1dd87677ecbcccf32dce2aaf6917/ex1/main.c#L38

https://github.com/thiagosantos346/APA-LISTA-1/blob/db328629e8af1dd87677ecbcccf32dce2aaf6917/ex1/main.c#L242-L250

* Note que ambas  contém laços e assim temos a formula de n(n+n) = 2n+2n = 4n² , que tem limite a assintótico igual n².



___
## Análise de Complexidade para o SelectionSort aprimorado
