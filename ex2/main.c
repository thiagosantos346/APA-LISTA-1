#include <stdio.h>
#include <stdlib.h>

int indicador_direita(int numero_adicionado, int *particao);
int encurtar_particao(int indicador, int numero_adicionado, int *particao);
void imprimir_particao(int numero_adicionado, int *particao);
void preparar_particao_inteiro(int numero);
void particao_numero(int *particao, int indicador, int numero_adicionado, int numero);

int main(void) {
    int numero;
    scanf("%d", &numero);
    preparar_particao_inteiro(numero);
    return EXIT_SUCCESS;
}

/*Recebe o numero e imprime todas as partições de n em ordem lex.*/
void preparar_particao_inteiro(int numero) {
    int indicador, numero_adicionado, *particao;
    /* Prepara um vetor p = (n, 0, ..., 0) de dimensão n e
    z como sendo o primeiro índice tal que p[z] é nulo */
    particao = malloc(numero * sizeof(int));
    particao[0] = numero;
    for (indicador = 1; indicador < numero; indicador++) { particao[indicador] = 0; }
    numero_adicionado = 1;
    /* Enquanto existe uma entrada nula no vetor */
    particao_numero(particao, indicador, numero_adicionado, numero);
}

/* Devolve o índice k mais a direita do vetor p satisfazendo p[k] > 1, sendo p a particao e k o indicador. */
void particao_numero(int *particao, int indicador, int numero_adicionado, int numero) {
    if (numero_adicionado < numero) {
        imprimir_particao(numero_adicionado, particao);
        indicador = indicador_direita(numero_adicionado, particao);
        if (particao[indicador] == 2 || indicador == numero_adicionado-1) {
            particao[indicador]--;
            particao[numero_adicionado]++;
            numero_adicionado++;
        } else {
            particao[indicador]--;
            particao[indicador+1]++;
        }

        numero_adicionado = encurtar_particao(indicador, numero_adicionado, particao);

        particao_numero(particao, indicador, numero_adicionado, numero);
    }
    else {
        imprimir_particao(numero, particao);
        free(particao);
    }
}

/* Devolve o índice k mais a direita do vetor p satisfazendo p[k] > 1, sendo p a particao e k o indicador. */
int indicador_direita(int numero_adicionado, int *particao) {
    int indicador = numero_adicionado-1;
    while (particao[indicador] < 2) { indicador--; }
    return indicador;
}

/* Modifica o vetor (p[k+1], ..., p(z-1]) para que seja a primeira partição de
p[k+1] + ... + p[z-1], em ordem lex, satisfazendo p[k] > p[k+1], sendo p a particao, k o indicador, e z o numero adicionado. */
int encurtar_particao(int indicador, int numero_adicionado, int *particao) {
    int indicador_auxiliar = indicador+1, numero_adicionado_auxiliar = numero_adicionado-1, numero_auxiliar;
    /*Garante que em particoes de numeros acima 6 exiba corretamente somas como "3+3",
    modificando tanto o vetor p, quanto os indicadores k e z, sendo p a particao, k o indicador, e z o numero adicionado. */
    while (indicador_auxiliar < numero_adicionado_auxiliar) {
        numero_auxiliar = particao[indicador_auxiliar-1] - particao[indicador_auxiliar];
        if (particao[numero_adicionado_auxiliar] < numero_auxiliar) { numero_auxiliar = particao[numero_adicionado_auxiliar]; }
        particao[indicador_auxiliar] += numero_auxiliar;
        particao[numero_adicionado_auxiliar] -= numero_auxiliar;
        if (particao[indicador_auxiliar-1] == particao[indicador_auxiliar]) { indicador_auxiliar++; }
        if (particao[numero_adicionado_auxiliar] == 0) { numero_adicionado_auxiliar--; }
    }

    return numero_adicionado_auxiliar+1;
}


/* Recebe um vetor p e imprime "p[0] + p[1] + ... + p[z-1]" */
void imprimir_particao(int numero_adicionado, int *particao) {
    int indicador;
    for (indicador = 0; indicador < numero_adicionado-1; indicador++) { printf("%d + ", particao[indicador]); }
    printf("%d\n", particao[indicador]);
}

