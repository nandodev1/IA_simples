#ifndef LAYOUT_H
#define LAYOUT_H

#include <fstream>
#include <string>
#include "Formas.h"
#include "layout.h"


using namespace std;

class Layout
{
	private:
		string map;
		
	public:
		Layout(string);
		string loadLayout(string);
		void update(void);
};

Layout::Layout(string path)
{
	this->map = this->loadLayout(path);
}

void Layout::update(void)
{
	int y = 0;
	int x = 0;

	for(int i = 0; i < this->map.size(); i++)
	{
		if(this->map[i] == '#')
			{
				// TAMANHO_TELA_Y variavel global modificada pela classe framework
				retangulo((x*10), TAMANHO_TELA_Y + (y * 10), 10, 10,{ 125, 125, 125});
				x++;
			}
		else if(this->map[i] == '\n')
		{
			y --;
			x = 0;
		}else
		{
			x ++;
		}
	}
}

string Layout::loadLayout(string path)
{
	string str;
	ifstream file;
	file.open(path, ios::in);
  if (file) {
		while (!file.eof()) str.push_back(file.get());
	}else{
		cout << "Arquivo: " << path << " not found." << endl;
	}
	this->map = str;
	return str;
}

#endif 
