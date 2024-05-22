#ifndef AGENTE_H
#define AGENTE_H

#include <vector>
#include "./base/Camada.h"

#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3

using namespace std;

class Agente
{
	private:
		float x;
		float y;
		vector<float> color = {0, 0, 0};
		void mover( uint8_t direcao);
		Camada * rede;
		void procSaida();
	public:
		vector<float> getPosition();
		Agente( float x, float y);
		void update();
		void draw();
		void setColor(vector<float>);
		float speed;
};

void Agente::mover( uint8_t direcao)
{
	if(direcao == CIMA)
		this->y += this->speed;
	if(direcao == BAIXO)
		this->y -= this->speed;
	if(direcao == ESQUERDA)
		this->x += this->speed;
	if(direcao == DIREITA)
		this->x -= this->speed;
}

//seleciona cor do agente
void Agente::setColor(vector<float> color)
{
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}

Agente::Agente( float x, float y)
{
	this->speed = 0.01;
	
	this->rede = new Camada(4, 4);
	
	this->x = x;
	this->y = y;
}

vector<float> Agente::getPosition()
{
	return { this->x, this->y};
}

void Agente::procSaida()
{
	float dir = this->rede->saida({this->x,this->y, 1, 1})[0];
	float dir2 = this->rede->saida({this->x,this->y, 1, 1})[1];
	float dir3 = this->rede->saida({this->x,this->y, 1, 1})[2];
	float dir4 = this->rede->saida({this->x,this->y, 1, 1})[3];
	

	this->mover(2);
}

void Agente::update()
{
	this->procSaida();
	this->draw();
}
void Agente::draw()
{
    retangulo(this->x, this->y, 15.0, 15.0,{this->color[0], this->color[1], this->color[2]});
}

#endif
