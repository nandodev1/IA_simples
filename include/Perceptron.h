#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<iostream>

#define SAIDA_RELU  "relu"
#define SAIDA_SIGMOID  "sigmoid"

using namespace std;

class Perceptron
{
    private:
        int quant_entradas;
        string tipo_saida;
        float bias;
        float peso_bias;
        vector<float> pesos;

    public:
        Perceptron( int quant_entradas, string tipo_saida);
        virtual ~Perceptron();
        float random();
        float somatorio(vector<float> entradas);
        float ativacao_sigm( float somatorio);
        float ativacao_relu( float somatorio);
        float saida( vector<float> entradas);
        void treinamento( vector<float> entradas, float saida_esperada, float taxa_aprendizado);

    protected:

};

#endif // PERCEPTRON_H
