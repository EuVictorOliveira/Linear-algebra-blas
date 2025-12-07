/*
    Arquivo de implementação das funções definidas em gram-schmidt.h



    autor: João Victor Oliveira
*/
#include <iostream>
#include <cmath>
#include "gram-schmidt.h"

using std::vector;

// IMPLEMENTA PRODUTO INTERNO
double produto_interno(const vetor& u, const vetor& v){
    double soma = 0; 
    
    for(int i = 0; i < (int) u.size(); i++){
        soma += u[i] * v[i]; // percorre vetores realizando o produto dos componentes e incrementando soma com o resultado
    }
    
    return soma;
}

// IMPLEMENTA NORMA
double norma(const vetor& v){
    return std::sqrt(produto_interno(v, v));
}

// IMPLEMENTA DIFERENÇA
vetor diferenca(const vetor& u, const vetor& v){
    vetor resultante(u.size());

    for(int i = 0; i < (int) u.size(); i++){
        resultante[i] = u[i] - v[i];
    }

    return resultante;
}

// IMPLEMENTA PRODUTO POR ESCALAR
vetor produto_escalar(double alfa, const vetor& v){
    vetor resultante(v.size());

    for(int i = 0; i < (int) v.size(); i++){
        resultante[i] = alfa * v[i];
    }

    return resultante;
}   

// IMPLEMENTA PROJEÇÃO
vetor projecao(const vetor& u, const vetor& v){
    double fator = produto_interno(u, v) / produto_interno(u, u);
    
    return produto_escalar(fator, u);
}

// IMPLEMENTA GRAM-SCHMIDT
vector<vetor> gramSchmidt(const vector<vetor>& v){
    int n = v.size();
    vector<vetor> u(n);

    for(int i = 0; i < n; i++){
        u[i] = v[i];

        for (int j = 0; j < i; j++) {
            vetor proj = projecao(u[j], u[i]);
            u[i] = diferenca(u[i], proj);
        }
    }

    return u;
}

// IMPLEMENTA NORMALIZAÇÃO DE VETOR
void normaliza(vector<vetor>& u){
    for(int i = 0; i < (int) u.size(); i++){
        double n = norma(u[i]);

        for(int j = 0; j < u[i].size(); j++){
            u[i][j] /= n;
        }
    }
}

// IMPLEMENTA FUNÇÃO DE EXIBIÇÃO
void exibe_vetores(const vector<vetor>& vetores) {
    for (size_t i = 0; i < vetores.size(); i++) {                
        for (size_t j = 0; j < vetores[i].size(); j++) {        
            std::cout << vetores[i][j] << " ";
        }
        std::cout << std::endl;;
    }
}