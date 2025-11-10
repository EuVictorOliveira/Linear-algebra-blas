/*
    Arquivo relacionado às implementações das funções para operações de matriz utilizando a Biblioteca numérica BLAS. 
    Autor: João Victor Oliveira 

*/
// CABEÇALHO
#include "matriz_cpu.h"
#include <cblas.h>

// =========== IMPLEMENTAÇÕES ===========

// Implementa somaCPU().
void somaCPU(double *A, double *B, double *C, int n){
    // Copia todos os elementos da matriz A na matriz C
    for(int i=0;i<n*n;i++) 
        C[i]=A[i];
    // Realiza soma utilizando função da biblioteca:
    cblas_daxpy(n*n, 1.0, B, 1, C, 1);
}

// Implementa multiplicacaoCPU().
void multiplicacaoCPU(double *A, double *B, double *C, int n){
    // Realiza produto tulizando função da biblioteca:
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                n, n, n, 1.0, A, n, B, n, 0.0, C, n); // chamado equivalente a: 1.0 x A X B + 0.0 X C
}

// Implementa traspostaCPU().
void transpostaCPU(double *A, double *T, int n){
    // Percorre cada elemento (i.j) de A em coloca em (j,i) de T
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            T[j*n + i] = A[i*n + j];
}

// Implementa tracoCPU
double tracoCPU(double *A, int n){
    double tr= 0.0; // valor do traço é inicializado com 0
    // For para percorrer a matriz, somando os elementos da diagonal principal
    for(int i = 0; i< n; i++)
        tr += A[i*n + i];

    return tr; // retorna o valor do traço
}

void maxMinCPU(double *A, int n, double *min, double *max){
    *min = *max = A[0]; // inicializando tanto conteúdo de max quanto de min como sendo o primeiro elemento da matriz
    // Percorrer a matriz do segundo até chegar ao último elemento
    for(int i = 1; i < n * n; i++){
        // Se A[i] for MENOR que o conteúdo de min, conteúdo de min passa a ser A[i]
        if(A[i] < *min) 
            *min = A[i];
        // Se A[i] for MAIOR que o conteúdo de MAX, conteúdo de MAX passa a ser A[i]
        if(A[i] > *max) 
            *max = A[i];
    }
}
