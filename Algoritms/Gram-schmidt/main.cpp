/*

    Arquivo de testes
    autor: João Victor Oliveira

*/


#include <iostream>
#include <vector>
#include "gram-schmidt.h"

using std::cout;
using std::vector;

int main() {
    vector<vetor> v = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1}
    };

    auto u = gramSchmidt(v);
    normaliza(u);

    cout << "Base ortonormal obtida:" << std::endl;
    exibe_vetores(u);

    return 0;
}