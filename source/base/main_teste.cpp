#include<iostream>

#include "base/Perceptron.h"
#include <vector>

using namespace std;

int main( int argc, char * argv [])
{
	vector<float> input = { -1, -1};
	Perceptron perceptron = Perceptron(2, SAIDA_RELU);
	float out = perceptron.saida(input);
	cout << out << endl;
}
