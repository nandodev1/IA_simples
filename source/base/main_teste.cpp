#include<iostream>
#include "../IA/agente.h"

Agente clonar(Agente agente);

using namespace std;

int main( int argc, char * argv [])
{
	Agente ag1 = Agente(300, 300);

	Agente clone = clonar(ag1);

	return EXIT_SUCCESS;
}
