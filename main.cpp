#include <iostream>
#include <Perceptron.h>

using namespace std;

int main()
{
    Perceptron * neuro = new Perceptron( 2, SAIDA_SIGMOID);
    float entr_treino [2] = { -1, -1};
    for (int i = 0; i < 10; i ++)
    {
        entr_treino[0] = -1;
        entr_treino[1] = -1;
        neuro->treinamento( entr_treino, 0, 0.5);
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
