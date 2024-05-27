#include<iostream>
#include "../layout/obstaculos.h"

using namespace std;

int main( int argc, char * argv [])
{
	"""1234\
	   5678\
	   90ab""";
	   ////////////////////////
	   // I = input O = output
	   ////////////////////////
	   //   X Y
	   // I 3 2
	   // O 3 0
	   ////////
	   // I 2 1
	   // O 2 1
	   ////////
	   // I 1 2
	   // O 1 0
	   ////////
	   // I 1 0
	   // O 1 2
	   //////// 
	Paredes mapa = Paredes("./source/layout/base.lay", 10, 10, 130, 91);
	//for(int i = 390; i > 300; i--)
	cout << "caracter: " << mapa.getCharacterMap( 371, 120) << endl;
}
