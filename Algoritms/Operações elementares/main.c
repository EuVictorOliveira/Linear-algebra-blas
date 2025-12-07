/*
    Arquivo relativo às chamadas das funções das funções para operação de matrizez usando CPU e GPU
    Autor: João Victor Oliveira



*/

// CABEÇALHO:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulos/matriz_cpu.h"

// DEFINIÇÃO DE MACROS E FUNÇÕES

#define N 100  // dimensão das matrizes

// Função para gerar matriz com valores aleatórios
void gerarMatriz(double *M, int n){
    // Percorre a matriz, preenhcendo valores
    for(int i = 0; i < n * n; i++)
        M[i] = ((double)rand() / RAND_MAX) * 1000.0;  // valores entre 0 e 1000
}

int main(){
    double max, min, traco; // variáveis para valor mínimo, valor máximo e traço
    srand(time(NULL));

    // Alocar matrizes de tamanho 100 x 100 dinamicamente e verifica se alocações foram bem-sucedidas
    double *A = (double*)malloc(N*N*sizeof(double));
    if(!A){
        printf("Erro ao alocar matriz A.\n");
        return 1;
    }
    double *B = (double*)malloc(N*N*sizeof(double));
    if(!B){
        printf("Erro ao alocar matriz B.\n");
        return 1;
    }
    double *C = (double*)malloc(N*N*sizeof(double));
    if(!C){
        printf("Erro ao alocar matriz C.\n");
        return 1;
    }
    double *T = (double*)malloc(N*N*sizeof(double));
    if(!T){
        printf("Erro ao alocar matriz T.\n");
        return 1;
    }

    // Gera matrizes A e B de maneira aleatória
    gerarMatriz(A, N);
    gerarMatriz(B, N);

    // Realiza abertura de arquivo para escrita de resultados.
    FILE *fp = fopen("resultados.txt", "w");
    if(!fp){ // Verifica se abertura foi bem-sucedida
        printf("Erro ao abrir arquivo!\n"); 
        return 1; 
    }

    fprintf(fp, "Dimensão das matrizes: %dx%d\n\n", N, N);

    // Escreve matrize A:
    fprintf(fp, "Matriz A:\n");
    for(int i = 0; i< N; i++){
        for(int j = 0; j< N; j++)
            fprintf(fp,"%8.2lf ", A[i*N + j]);
        fprintf(fp,"\n");
    }

    // Escreve matriz B:
    fprintf(fp, "\nMatriz B:\n");
    for(int i= 0; i< N; i++){
        for(int j = 0; j< N; j++)
            fprintf(fp,"%8.2lf ", B[i*N + j]);
        fprintf(fp,"\n");
    }

    // variáveis auxiliares responsáveis pela medição do tempo das operançoes
    clock_t inicio, fim;
    double tempo;

    // SOMA:
    inicio = clock(); // seta início
    somaCPU(A,B,C,N); // chamada da função para realizar soma
    fim = clock(); // seta fim
    // Determina tempo total da operação
    tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
    // Printa matriz resultante e o tempo de operação
    fprintf(fp, "\nSoma (A + B):\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++)
            fprintf(fp,"%8.2lf ", C[i*N + j]);
        fprintf(fp,"\n");
    }
    fprintf(fp,"\nTempo de soma: %lf s\n", tempo);

    // MULTIPLICAÇÃO: 
    inicio = clock(); // seta início
    multiplicacaoCPU(A,B,C,N); // faz chamada da função
    fim = clock();  // seta fim
    // Determina tempo total da operação:
    tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
    // Printa matriz resultando e o tempo de operação
    fprintf(fp, "\nMultiplicacao (A * B):\n");
    for(int i = 0; i< N; i++){
        for(int j = 0; j< N; j++)
            fprintf(fp,"%8.2lf ", C[i*N + j]);
        fprintf(fp,"\n");
    }
    fprintf(fp,"\nTempo de multiplicacao: %lf s\n", tempo);

    // TRANSPOSTA
    inicio = clock(); // seta início
    transpostaCPU(A,T,N); // Chamda função para determinar transposta
    fim = clock(); // seta fim
    tempo = (double)(fim - inicio)/CLOCKS_PER_SEC; // determina tempo da operação
    // Printa resultado e tempo de operação:
    fprintf(fp, "\nTransposta de A:\n");
    for(int i = 0; i< N;i++){
        for(int j = 0; j < N; j++)
            fprintf(fp,"%8.2lf ", T[i*N + j]);
        fprintf(fp,"\n");
    }
    fprintf(fp,"\nTempo de transposta: %lf s\n", tempo);

    // TRAÇO 
    inicio = clock(); // seta inicio
    traco = tracoCPU(A,N); // chama a função para calcular o traço da matriz
    fim = clock(); // seta fim
    tempo = (double)(fim - inicio)/CLOCKS_PER_SEC; // determina tempo total da operação
    // Printa resultado e tempo de operação:
    fprintf(fp, "\nTraço de A: %.2lf\n", traco);
    fprintf(fp,"Tempo de calculo do traço: %lf s\n", tempo);

    // MAX e MIN
    inicio = clock(); // seta início
    maxMinCPU(A,N,&min,&max); // chama função
    fim = clock(); // seta fim
    tempo = (double)(fim - inicio)/CLOCKS_PER_SEC; // determina tempo total da operação
    // Printa resultados e tempo de operação:
    fprintf(fp, "\nValor minimo de A: %.2lf\n", min);
    fprintf(fp, "Valor maximo de A: %.2lf\n", max);
    fprintf(fp, "Tempo de calculo min/max: %lf s\n", tempo);

    // Fecha arquivo.
    fclose(fp);

    // Liberar memória das matrizes alocadas
    free(A); 
    free(B); 
    free(C); 
    free(T);

    printf("Operacoes concluidas. Resultados salvos em resultados.txt\n");

    return 0;
}
