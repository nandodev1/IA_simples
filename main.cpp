#include <iostream>
#include "include/Perceptron.h"
#include "include/Camada.h"

using namespace std;

int main()
{
    vector<float> entr_treino = { 0, 0};

    Camada camada = Camada( 2, 10);

    for (int i = 0; i < 10; i ++)
    {
        entr_treino[0] = -1;
        entr_treino[1] = -1;
        camada.get_neuronios()[0].treinamento( { -1, -1}, -1, 0.5);
        entr_treino[0] = -1;
        entr_treino[1] = 1;
        camada.get_neuronios()[0].treinamento( entr_treino, 1, 0.5);
        entr_treino[0] = 1;
        entr_treino[1] = -1;
        camada.get_neuronios()[0].treinamento( entr_treino, 1, 0.5);
    }
    entr_treino[0] = 1;
    entr_treino[1] = -1;
    cout <<  camada.saida( entr_treino)[0] << endl;
    camada.get_pesos();
    return 0;
}
