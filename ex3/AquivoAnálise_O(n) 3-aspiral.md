A terceira implantação utiliza das variaveis 
int coordX=1;
int coordY=0;
Sendo a variavel coordX responsável por informa a referencia do ponto no eixo X e a variavel coordY referente ao 
plano do eixo Y.
O programar requer de um valor inicial passado pelo usuário para a partir deste valor se realizar a busca no spiral.
O programa utiliza de um laço de repetição do tipo while que vai de 1 a N sendo N o valor oferecido pelo usuário para 
localizar no plano os pontos.
O progrma utliza de um while (1<=n>) sendo On que dentro contém 7 if que realizam as funções de verificação dos quadrantes, para cada quadrante do plano cartesiano é realizada uma adição ou subtração das coordenadas do plano cartesiano.
Então sendo um laço while(1< n){  O(N) }
    if(){} O(1)
    if(){} O(1)
    if(){} O(1)
    if(){} O(1)
    if(){} O(1)
    if(){} O(1)
    if(){} O(1)

        Sendo que quando tende se a valores muitos grandes as condicionais IF, sao desprezaveis, sendo apenas O(1)
        logo a análise no pior caso é O(N) pois independete da entrada o pior caso sempre vai ser (O(N)).
}
Os testes de entradas para este programa foram feito apenas com numero pequenos , não realizamos testes para números muitos grandes, logo pode ocorrer falhas.
