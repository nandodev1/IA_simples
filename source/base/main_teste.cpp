#include<iostream>

#include "../IA/base/Perceptron.h"
#include "../IA/base/Camada.h"
#include <vector>

using namespace std;
void teste_rede(void);

Perceptron p = Perceptron();
Perceptron p2 = Perceptron();

int main( int argc, char * argv [])
{
	//teste_rede();
    srand((unsigned)time(NULL)); //garante valores aleatórios a cada execução do programa.
	cout << p.random() << endl;
	cout << p.random() << endl;
	cout << p.random() << endl;
	cout << p2.random() << endl;
	cout << p2.random() << endl;
	cout << p2.random() << endl;
}

void teste_rede(void)
{
	Camada camada1 = Camada(2, 2);
	Camada camada2 = Camada(2, 2);
	
	vector<float> input = {1, 0};
	
	vector<float> out_camada1 = camada1.saida(input);
	vector<float> out_camada2 = camada2.saida(out_camada1);
	cout << "Fim de Programa." << endl;
}

void teste1(void)
{
	
	vector<float> input = {1, 1, -1};
	
	Perceptron perceptron = Perceptron(2, SAIDA_RELU);
	Camada camada1 = Camada(2, 1);
	
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
