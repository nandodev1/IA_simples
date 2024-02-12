#ifndef AGENTE_H
#define AGENTE_H

#include <vector>

using namespace std;

class Agente
{
	private:
		float x;
		float y;
	public:
		vector<float> getPosition();
		Agente( float x, float y);
		void update();
};

Agente::Agente( float x, float y)
{
	this->x = x;
	this->y = y;
}

vector<float> Agente::getPosition()
{
	return { this->x, this->y};
}

#endif
