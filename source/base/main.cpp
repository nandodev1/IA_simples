#include <iostream>
#include "../IA/base/Perceptron.h"
#include "../IA/base/Camada.h"
#include "../display/Framework.h"


void testes_redes();
void testes_framework(int * argc, char * argv[]);

using namespace std;

int main( int argc, char * argv[])
{
    testes_framework( &argc, argv);
}


void testes_framework(int * argc, char * argv[])
{
    Framework * fw = new Framework( "Ai_simple", 500, 500, argc, argv);
}

void testes_redes()
{
    Camada * camada_1 = new Camada( 2, 2);
    Camada * camada_saida = new Camada( 2, 1);

    camada_1->set_pesos({ -0.5, 1, 1, -1.5, 1, 1});
    camada_saida->set_pesos({-0.5, 1, -2});

    vector<float> input = { 0, 1};
    vector<float> saida_camada_1;

    saida_camada_1 = camada_1->saida( input);

    float saida_camada_saida = camada_saida->saida(saida_camada_1)[0];
    cout << saida_camada_saida << endl;
}
