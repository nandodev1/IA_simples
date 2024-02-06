#include<vector>

#include "Perceptron.cpp"

using namespace std;

class MLP_simples
{
    vector<Perceptron> camada;
    float * entradas;
    public:
        MLP_simples( int quant_entradas, int quant_saidas)
        {
            this->entradas = (float *)malloc( sizeof(float) * quant_entradas);
            for ( int i = 0; i < quant_saidas; i++)
                this->camada.push_back( Perceptron( quant_entradas, SAIDA_RELU));
        }
};