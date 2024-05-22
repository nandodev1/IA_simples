#include<iostream>

#include "../IA/base/Perceptron.h"
#include <vector>

using namespace std;

int main( int argc, char * argv [])
{
	vector<float> input = {1, 1, -1};
	
	Perceptron perceptron = Perceptron(2, SAIDA_RELU);
	
	vector<float> dados_treinamento = {-1, -1, -1};
	vector<float> dados_treinamento2 = {-1, -1, 1};
	vector<float> dados_treinamento3 = {-1, 1, -1};
	vector<float> dados_treinamento4 = {1, -1, 1};
	
	for(int i = 0; i < 12500; i++)
	{
		perceptron.treinamento(dados_treinamento, -1, 0.0005);
		perceptron.treinamento(dados_treinamento2, 1, 0.0005);
		perceptron.treinamento(dados_treinamento3, 1, 0.0005);
		perceptron.treinamento(dados_treinamento4, 1, 0.0005);
	}
	float out = perceptron.saida(input);
	cout << out << endl;
}
