#include "Perceptron.h"
#include <cstdlib>
#include <ctime>
#include <math.h>

Perceptron::Perceptron( int quant_entradas, string tipo_saida)
{
    this->quant_entradas = quant_entradas;
    this->tipo_saida = tipo_saida;
    this->bias = 1;
    this->peso_bias = this->random() * -1;
    this->pesos = new float[ this->quant_entradas];

    //Preenche pesos com valores aleatórios
    for( int i = 0; i < this->quant_entradas; i++)
    {
        this->pesos[i] = this->random() * -1;
    }
}
//retorna um valor aleatório entre 0 -1
float Perceptron::random()
{
    int seed = time(0);
    srand(seed);
    float random = (float)(rand()%10000);
    random = random / 100000;
    return random;
}

//Recepe as entradas do perceptron e devolve o somatorio dos produtos
float Perceptron::somatorio( float * entradas)
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
float Perceptron::saida( float *entradas)
{
    if ( this->tipo_saida == SAIDA_SIGMOID)
        return this->ativacao_sigm(this->somatorio(entradas));
    else
        return this->ativacao_relu(this->somatorio(entradas));
}

//Função de treinamento do perceptron
void Perceptron::treinamento( float * entradas, float saida_esperada, float taxa_aprendizado)
{
    float saida_prevista = this->saida( entradas);
    float delta = saida_esperada - saida_prevista;
    this->peso_bias += taxa_aprendizado*delta;
    for ( int i = 0; i < this->quant_entradas; i++)
        this->pesos[i] += taxa_aprendizado*delta*entradas[i];
}

Perceptron::~Perceptron()
{
    //dtor
}
