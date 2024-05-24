#include "layout.h"
#include <fstream>
#include <string>

using namespace std;

Layout::Layout(string path)
{
	this->map = this->loadLayout(path);
}

bool Layout::isOpen(float x, float y)
{
}

void Layout::update(void)
{
	int y = 0;
	int x = 0;
	
	for(int i = 0; i < this->map.size(); i++)
	{
		if(this->map[i] == '#')
			{
				retangulo((x*20), 910 + (y * 26), 20, 20,{ 0, 0, 255});
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
	}
	this->map = str;
	return str;
}
