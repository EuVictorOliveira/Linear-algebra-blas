/*
    Arquivo referente aos protótipos das funções utilizadas no algoritmo de Gram-schmidt


    Autor: João Victor Oliveira
*/
#include <vector>

using vetor = std::vector<double>;
using std::vector;

// OPERAÇÕES ELEMENTARES DEFINIDAS PARA UM VETOR:

// produto interno
double produto_interno(const vetor& u, const vetor& v);
// Norma
double norma(const vetor& u);
// Diferença
vetor diferenca(const vetor& u, const vetor& v);
// Produto por escalar
vetor produto_escalar(double, const vetor& u);


// PROJECÃO:
vetor projecao(const vetor& u , const vetor& v);

// Gram-schmidt
vector<vetor> gramSchmidt(const vector<vetor>& v);
// Função de normalização
void normaliza(vector<vetor>& u);

// Função de exibição
void exibe_vetores(const vector<vetor>& vetores);
