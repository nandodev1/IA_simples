#include <iostream>
#include "include/Perceptron.h"
#include "include/Camada.h"

using namespace std;

int main()
{
    vector<float> entr_treino = { 0, 0};

    Camada * camada = new Camada( 2, 30);

    for (int i = 0; i < 10; i ++)
    {
        camada->neuronios[0].treinamento( { -1, -1}, -1, 0.5);
        camada->neuronios[0].treinamento( { -1, 1}, 1, 0.5);
        camada->neuronios[0].treinamento( {1, -1}, 1, 0.5);
    }
    vector<float> input;
    input.push_back(0.4);
    input.push_back(-0.7);
    cout <<  camada->saida( input)[0] << endl;
    camada->get_pesos();
    return 0;
}
