#include <iostream>
#include "src/Perceptron.cpp"

using namespace std;

int main()
{
    Perceptron * neuro = new Perceptron( 2, SAIDA_RELU);
    vector<float> entr_treino = { 0, 0};
    for (int i = 0; i < 10; i ++)
    {
        entr_treino[0] = -1;
        entr_treino[1] = -1;
        neuro->treinamento( { -1, -1}, -1, 0.5);
        entr_treino[0] = -1;
        entr_treino[1] = 1;
        neuro->treinamento( entr_treino, 1, 0.5);
        entr_treino[0] = 1;
        entr_treino[1] = -1;
        neuro->treinamento( entr_treino, 1, 0.5);
    }
    entr_treino[0] = -1;
    entr_treino[1] = -1;
    cout <<  neuro->saida( entr_treino) << endl;
    return 0;
}
