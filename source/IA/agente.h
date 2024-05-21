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
		void draw();
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

void Agente::update()
{
	this->draw();
}
void Agente::draw()
{
    retangulo( 300, 100, 15.0, 15.0, { 100, 250, 50});
}

#endif
