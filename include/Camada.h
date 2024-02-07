#ifndef CAMADA_H
#define CAMADA_H

#include<iostream>
#include<vector>

#include "Perceptron.h"

using namespace std;


class Camada
{
    private:
        //Guarda os ultimos valores da ultima computação
        vector<float> entradas;
        vector<float> saidas;
    
    public:

        vector<Perceptron> neuronios;
        Camada( int quant_entradas, int quant_saidas);
        vector<float> saida(vector<float> entradas);
        vector<Perceptron> get_neuronios();
        vector<float> get_pesos();
        ~Camada();
};

vector<float> Camada::get_pesos()
{
    vector<float> pesos;
    Perceptron neuro;
    int quant_neuronio = this->neuronios.size();
    //Pega o primeiro neuronio para definir a quantidade pesos
    //considerando que todos neuronios das camadas tem a mesma quantidade de neuronio
    int quant_pesos = this->neuronios[0].pesos.size();
    for ( int i = 0; i < quant_neuronio; i++)
        for( int j = 0; j < quant_pesos; j++)
        {
            neuro = this->neuronios[i];
            pesos.push_back( neuro.pesos[j]);
        }

    return pesos;
}

vector<Perceptron> Camada::get_neuronios()
{
    return this->neuronios;
}

Camada::Camada( int quant_entradas, int quant_saidas)
{
    for ( int i = 0; i < quant_entradas;i++)
        this->entradas.push_back(0);
        this->saidas.push_back(0);

    for ( int i = 0; i < quant_saidas; i++)
        this->neuronios.push_back( Perceptron( quant_entradas, SAIDA_RELU));
};


vector<float> Camada::saida(vector<float> entradas)
{
    for( int i = 0; i < this->neuronios.size(); i++)
    {
        this->saidas[i] = this->neuronios[i].saida( entradas);
    }
    return this->saidas;
};

Camada::~Camada()
{
}

#endif