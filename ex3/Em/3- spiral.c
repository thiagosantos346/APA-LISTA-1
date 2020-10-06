#include<stdio.h>
#include<math.h>

int main(){

    /*Para este programa utilizaremos as seguintes variaveis para controlar os valores referentes as coodenadas geográficas
      coordX para o eixo X, e coordY para o eixo y do plano cartesiano.*/   
    
    int coordX=1;
    int coordY=0;
    int valor=0;
    int resul=1;
    int controle1=0;
    int controle2=0;
    int controle3=0;
    int controle4=0;
    int controle5=0;
    int controle6=0;
   // A variável resul , refere-se ao resultado que deve coincidir com o numero informado pela usuário no inciar da aplicação.

     printf("Digite um valor : ");
     scanf("%d",&valor);
       //  Entrada do valor pelo usuário, este valor se refere-se ao ponto no qual irá ser feita a busca de suas devidas coordenadas.

    // Incia- se o programa com um comando "While" que diz que enquanto resul for diferente do valor fornecido pelo usuário vamos estar repentindo novamente todo o conteudo do programa
     //os valores atribuidos para as variaveis de coordenada coordX= 1 e coordY=0, que se refere-se a primeira posição do ponto no plano cartesiano.
    while(resul != valor){
    //  Começamos o programa, calculando o quadrante direito superior no plano cartesiano, dentro do laço while , se coordX for diferente de coordY então deve se incrementar o valor de Y até que o mesmo seja igual ao valor de X.

        if(coordX != coordY && controle1==0 ){    //enquanto Y for menor ou diferente que X, soma se +1 ao valor de Y.
                if(resul==valor)break;
                // printf("lasso 1 %d %d %d\n",resul,coordX,coordY);



                coordY++;
                resul++;

        }
        else{
            controle1=1;
             //Quando os valores da coordX forem iguais ao valores da coordY a variavel controle é acionada nao podendo somar mais o Y. Indo então para o segundo condicional do programa.
        }









          if(controle1==1){

            //ao chegar ao ponto mais alto da direita positiva começa se o decremnto de x até que x*(-1)seja iqual ao valor de Y.
            //   enquanto o valor da coordX*(-1) for diferente do valor presente na coordenadaY, decrementamos a variavel de coordenada X.


            if( coordX <= coordY && controle2 == 0){//ao chegar ao ponto mais alto da dirreita positiva começa se o decremnto de x até que x*(-1)== Y.
                    if(coordX == coordY*(-1)){
                        if(resul==valor)break;
                        // printf("lasso 1 %d %d %d\n",resul,coordX,coordY);

                        controle2=1;
                        coordY--;
                        resul++;
                       // printf("%d",(-1)*coordX);
                        //  Ao localizar o mesmo valor possuímos um outro comando de verificação que confirma que a varialvel coordX*(-1) é igual a varaivel
                       //   de coordY.

                    }
                    else{
                        if(resul==valor)break;
                            if(resul==valor)break;
                           //  printf("lasso 1 %d %d %d\n",resul,coordX,coordY);

                            coordX--;
                            resul++;
                    }
            }
           // printf("veio ate aqui");
           // printf("cotrole2 %d",controle2);-1 0




             //Ao localizar a ultima coordenada da  espiral no quadrante esquerdo superior, iniciamos então o mapeamento rumo ao quadrante
              //esquerdo inferior utilizando novamente uma condicional verificamos se os valores contidos são diferentes e se sim iniciamos então a decrementetação
             //do coordY até que os valores das CoordX e coordY seja iguais , a partir do momento em que os valores se tornarem iguais , utilizamos uma variavel de controle para irmos até a próxima sessão.

            if(controle2==1 && controle3==0){
                if(coordX != coordY){
                   if(resul==valor)break;
                   // printf("lasso 1 %d %d %d\n",resul,coordX,coordY);

                    coordY--;
                    resul++;
                }
                else{
                    controle3=1;
                }
            }
            //-1-1
            // Nesta sessão utilizamos novamente um comando condicional para identidicar os pontos presentes no quadrante negatico que parte do quadrante esquerdo até o quadrante direito
            //usamos a váriavel de controle para verificar-se o ultimo valor do quadrante esquerdo foi localizado.Se sim vamos adiante verificamos se a variavel coordX é maior que
            //a variavel coordY e se nossa variável de controle é igual a 0. Se sim incrementamos a variavel coordX . Dentro desse comando de condicional utilizamos uma nova condicional
            //para testar  se os valores da variavel coordX subtraidos os valores da variável coordY é igual ao resultado 1, se sim , descobrimos então o ultimo ponto daquela spiral no
            //quadrante direito inferior e começamos então há subrair da variavel coodY até que seu valor seja igual a zero. Ao chegar nesse ponto as variavis de controle são resetadas
            //iniciando então, mais uma volta na espiral.


            if(controle3==1){
                if(coordX >= coordY && controle4==0){
                   if(resul==valor)break;
                   // printf("lasso 1 %d %d %d\n",resul,coordX,coordY);

                    coordX++;
                    resul++;
                }


                    if(coordX+coordY ==1){
                       controle4=1;
                        //printf("lasso 1 %d %d %d\n",resul,coordX,coordY);
                        if(resul==valor)break;
                        coordY++;
                        resul++;
                         if(resul==valor)break;
                         // printf("lasso 1 %d %d %d\n",resul,coordX,coordY);


                    }
                    if(coordY==0){
                        controle1=0;
                        controle2=0;
                        controle3=0;
                        controle4=0;
                    }


            }
            }

        }
        printf("Coordenadas X: %d e Y: %d \n",coordX,coordY);
        //NO fim é dado as coordenadas para o ponto no plano cartesiano
        //Os testes de entradas para este programa fora feito apenas com numero pequenos , nao realizamos testes para números muitos grandes, logo pode ocorrer falhas.

}















