#ifndef AGENTE_H
#define AGENTE_H

#include <vector>

using namespace std;

class Agente
{
	private:
		float x;
		float y;
		vector<float> color = {0, 0, 0};
	public:
		vector<float> getPosition();
		Agente( float x, float y);
		void update();
		void draw();
		void setColor(vector<float>);
};
//seleciona cor do agente
void Agente::setColor(vector<float> color)
{
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}

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
	this->y +=0.01;
	this->draw();
}
void Agente::draw()
{
    retangulo(this->x, this->y, 15.0, 15.0,{this->color[0], this->color[1], this->color[2]});
}

#endif
