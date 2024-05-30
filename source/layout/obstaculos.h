#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <fstream>

using namespace std;

class Paredes
{
	private:
		string map;
		int dimXmap;
		int dimYmap;
		int dimXobj;
		int dimYobj;
		string loadLayout(string);


	public:
		Paredes(string, int, int, int, int);
		char getCharacter(int x, int y);
		char getCharacterMap(int x, int y);
		float getDimX(void);
};

float Paredes::getDimX(void)
{
	return (float)this->dimXmap;
}

//Função para ultilizar de acordo com as coordenadas da tela de exibição dos agentes
char Paredes::getCharacterMap(int x, int y)
{
	if(x != 0)
	{
		x /= 10;
	}
	
	if(y != 0)
	{
		y /= 10;
	}
	char character = this->getCharacter(x, y);
	return character;
}

string Paredes::loadLayout(string path)
{
	string str;
	ifstream file;
	file.open(path, ios::in);
	if(file){
		while (!file.eof()) str.push_back(file.get());
	}else{
		cout << "Arquivo: " << path << " not found." << endl;
	}
	this->map = str;
	return str;
}

//parada para continuar
//Retorna -1 caso valores estejam fora do range do mapa
char Paredes::getCharacter(int x, int y)
{
	//adequar mapa para pesquisa na string resultante de arquivos .lay
	if(y > this->dimYmap)
	{
		y = this->dimYmap;
		return '#';
	}
	y = this->dimYmap - 1 - y;
	return this->map[x + (y * this->dimXmap) + y];
}

Paredes::Paredes(string map, int dimXObj, int dimYObj, int xMap, int yMap)
{
	this->dimXmap = xMap;
	this->dimYmap = yMap;
	this->dimXobj = dimXobj;
	this->dimYobj = dimYobj;
	this->loadLayout(map);
}



#endif
