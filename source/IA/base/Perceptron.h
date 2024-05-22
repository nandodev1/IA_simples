#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <vector>

#define SAIDA_RELU  "relu"
#define SAIDA_SIGMOID  "sigmoid"

using namespace std;

class Perceptron
{
    private:
        int quant_entradas;
        string tipo_saida;
        float bias;

    public:
        Perceptron();
        Perceptron( int quant_entradas,const string &tipo_saida);
        virtual ~Perceptron();
        vector<float> pesos;
        float peso_bias;
        float random();
        float somatorio(vector<float> entradas);
        float ativacao_sigm( float somatorio);
        float ativacao_relu( float somatorio);
        float saida(const vector<float> &entradas);
        void treinamento( vector<float> entradas, float saida_esperada, float taxa_aprendizado);

    protected:

};

Perceptron::Perceptron()
{
}

Perceptron::Perceptron(int quant_entradas, const string &tipo_saida)
{
    this->quant_entradas = quant_entradas;
    this->tipo_saida = tipo_saida;
    this->bias = 1;
    srand(time(0)); //garante valores aleatórios a cada execução do programa.
    //Preenche pesos com valores aleatórios
    this->peso_bias = this->random();
    for( int i = 0; i < this->quant_entradas; i++)
    {
        this->pesos.push_back(this->random());
    }
}
//retorna um valor aleatório entre 0 -1
float Perceptron::random()
{
    float random = (float)(rand()%10000) / 10000;
    if( rand() % 2)
        return random;
    return random * -1;
}

//Recepe as entradas do perceptron e devolve o somatorio dos produtos
float Perceptron::somatorio( vector<float> entradas)
{
    float produtos = 0;
    for ( int i = 0; i < this->quant_entradas; i++)
    {
        produtos += entradas[i] * this->pesos[i];
    }
    return produtos + this->bias * this->peso_bias;

}

//Implementação função sigmóid para classificadores
float Perceptron::ativacao_sigm( float somatorio)
{
    return 1/(1 + exp(-somatorio));
}

//uso da funcao relu como ativacao
float Perceptron::ativacao_relu( float somatorio)
{
    if ( somatorio <= 0)
        return -1;
    return 1;
}

//Saida do neuronio relu
float Perceptron::saida(const vector<float> &entradas)
{
    if ( this->tipo_saida == SAIDA_SIGMOID)
        return this->ativacao_sigm(this->somatorio(entradas));
    else
        return this->ativacao_relu(this->somatorio(entradas));
}

//Função de treinamento do perceptron
void Perceptron::treinamento( vector<float> entradas, float saida_esperada, float taxa_aprendizado)
{
    float saida_prevista = this->saida(entradas);
    if (float delta = saida_esperada - saida_prevista)
    {
        this->peso_bias += taxa_aprendizado*delta;
        for ( int i = 0; i < this->quant_entradas; i++)
            this->pesos[i] += taxa_aprendizado*delta*entradas[i];
    }
}

Perceptron::~Perceptron()
{
    //dtor
}


#endif // PERCEPTRON_H
