#include <iostream>
#include "include/Perceptron.h"
#include "include/Camada.h"

using namespace std;

int main()
{
    Camada * camada_1 = new Camada( 2, 2);
    Camada * camada_saida = new Camada( 2, 1);

    camada_1->set_pesos({ -0.5, 1, 1, -1.5, 1, 1});
    camada_saida->set_pesos({-0.5, 1, -2});

    vector<float> input = { 1, 1};
    vector<float> saida_camada_1;

    saida_camada_1 = camada_1->saida( input);
    
    float saida_camada_saida = camada_saida->saida(saida_camada_1)[0];
    cout << saida_camada_saida << endl;
    return 0;
}
