/*
    Arquivo relacionado à modularização das operações de matrizes utilizando a biblioteca numérica BLAS.
    Autor: João Victor Oliveira
*/

// DEFINIÇÕES: 
#ifndef MATRIZ_CPU_H
#define MATRIZ_CPU_H

// RROTÓTIPOS DAS FUNÇÕES

// Função para soma de duas matrizes A e B usando CPU. O resultado é armazenado em C. 
// Parâmetros: ponteiro para matriz A, ponteiro para matriz B, ponteiro para matriz resultante C = A + B, inteiro que representa a dimensão das matrizes.
// Retorno: void(genérico).
void somaCPU(double *A, double *B, double *C, int n);

// Função para multiplicação de duas matrizes A e B usando CPU. O resultado é armezando em C.
// Parâmetros: ponteiro para a matriz A, Ponteiro para matriz B, ponteiro para matriz resultante C = A * B, inteiro que representa dimensão da matriz.
// Retorno: void(genérico).
void multiplicacaoCPU(double *A, double *B, double *C, int n);

// Função para determinar a transposta de uma matriz A. O resultado é armezando em T.
// Parâmetros: ponteiro para a matriz A, ponteiro para matriz resultante T = trasponsta(A), inteiro que representa dimensão da matriz.
// Retorno: void(genérico).
void transpostaCPU(double *A, double *T, int n);

// Função para calcular o traço(TR) de uma matriz A. O resultaod é retornado pela função.
// Parâmetros: ponteiro para a matriz A, inteiro que representa a dimensão da matriz.
// Retorno: valor do traço da matriz, tipo double.
double tracoCPU(double *A, int n);

// Função para determinar o valor máximo e o valor mínimo presentes em uma matriz A. O resultado é armazenado no endereço de max e min.
// Parâmetros: ponteiro para a matriz A, inteiro que representa a dimensão da matriz, ponteiro para o valor máximo, ponteiro para o valor mínimo
// Retorno: void(genérico)
void maxMinCPU(double *Am, int n, double *max, double *min);

#endif