#include<iostream>
#include "../Perceptron.h"

using namespace std;

int main( int argc, char * argv [])
{
    Perceptron p1(2, SAIDA_RELU);
    Perceptron p2(2, SAIDA_RELU);
    Perceptron p3(2, SAIDA_RELU);

    vector<float> input = { 0, 1};

    float s1 = p1.saida(input);
    float s2 = p2.saida(input);

    float s3 = p3.saida({s1,s2});

    cout << s3 << endl;
}
