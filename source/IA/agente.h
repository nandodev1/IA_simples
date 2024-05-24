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
		Camada * camada1;
		Camada * camada2;
		void mover( uint8_t direcao);
		vector<float> rede(const vector<float> &input); 
		void procSaida();
		
	public:
		vector<float> getPosition();
		Agente( float x, float y);
		void update();
		void draw();
		void setColor(vector<int>);
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
void Agente::setColor(vector<int> color)
{
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}

Agente::Agente( float x, float y)
{
	this->speed = 0.1;
	
	this->camada1 = new Camada(2, 2, SAIDA_SIGMOID);
	this->camada2 = new Camada(2, 4, SAIDA_RELU);
	
	this->x = x;
	this->y = y;
}

vector<float> Agente::getPosition()
{
	return { this->x, this->y};
}

////////////////////////////////////////////////////////////////////
// Rede simples apenas composta de duas camadas e quatro saidas.
// Podendo modifiar aumentando ou diminuindo a rede.
// Esta função recebe uma vetor de float de tamanho arbitrario
// que corresponde a entrada da rede,e devolve um vetor de float
// de tamnho da saida da rede. correspondendo os outputs da rede
// configurada.
// Detalhe que esta rede pode assumir varias configurações.
// Levando em consideração a possibilidade de obter a saida de uma camada
// e ultizar esta saida como entrada para outra camada. 
///////////////////////////////////////////////////////////////////

vector<float> Agente::rede(const vector<float> &input)
{
	vector<float> out_camada1 = this->camada1->saida(input);
	vector<float> out = this->camada2->saida(out_camada1);
	return out;
}

void Agente::procSaida()
{
	vector<float> out = this->rede({this->x,this->y});
	
	float dir4 = out[0];
	float dir2 = out[1];
	float dir3 = out[2];
	float dir1 = out[2];
	
	if(dir1 > 0)
		this->mover(CIMA);
	if(dir2 > 0)
		this->mover(BAIXO);
	if(dir3 > 0)
		this->mover(ESQUERDA);
	if(dir4 > 0)
		this->mover(DIREITA);
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
