#include<iostream>

#include "../IA/base/Perceptron.h"
#include "../IA/base/Camada.h"
#include <vector>
#include <fstream>

using namespace std;

int main( int argc, char * argv [])
{
	fstream layout;
	layout.open("source/layout/base.lay", ios::in);//caminho de origem apartir do Makefile
	if (!layout) {
		cout << "No such file";
	}
	else {
		char ch;

		while (1) {
			layout >> ch;
			if (layout.eof())
				break;

			cout << ch;
		}

	}
	layout.close();
	return 0;
}
