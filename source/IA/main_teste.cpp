#include<iostream>

#include "agente.h"

using namespace std;

int main( int argc, char * argv [])
{
	Agente * agente = new Agente( 20.0, 30.0);
	cout << agente->getPosition()[1] << endl;
}
