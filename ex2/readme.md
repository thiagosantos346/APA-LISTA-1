> ## Análise do Algortimo para Decomposição de Numero
>
> Primeiramente, o programa pegará o N, para entrar na função de parciona-lo, para isso é necessario sempre ter o indice mais a direita do vetor de partições
> e o numero a ser adicionado (k e z), e vai imprimindo constantemente o p, que é o vetor de partições que a cada partição ele é substituido e impresso de novo,
> até o fim do programa.
> Com isso pode-se fazer até N = 5 tranquilamente e sem nenhum problema, de maneira relativamente simples, porém a partir de N >= 6 vários problemas são encontrados,
> quando chega na hora de 3 + 3, o programa acha que deve adicionar + 1 ao 2 e deixar 3 + 2 + 1, e uma simples mudança
> na condição não era o suficiente, por isso houve a necessidade de encurtar a partição, para esses casos serem resolvidos de maneiras consistentes, mesmo que o codigo
> não seja o mais agradavel para se ler, ele faz muito bem seu trabalho.
> ## Análise de Complexidade para O Decomposição de Numero
> 
> Para cada p partição de n, a complexidade pra computar é Θ(len(p))
> A complexidade do algoritmo seria Θ(sum_{p partição de n} len(p)).
> Tem um conceito em partição de inteiros que é o conjugado que vale len(p) = max(conj(p)).
> E, defininindo P(m, n) como sendo o número de partições p de n tal que max(p) <= m, vale a recorrência P(m, n) = sum_{1 <= k <= n} P(k, n - k).
> o número de partições de n seria P(n, n)
> Por questão de conjugado acho que tem que sum_{p partição de n} len(p)) = sum_{1 <= k <= n} (P(k, n - k) * k)
> Logo uma formula mais detalhada pra complexidade seria Θ(sum_{1 <= k <= n} (P(k, n - k) * k))
