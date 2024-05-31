#ifndef AGENTE_H
#define AGENTE_H

#include <vector>
#include "./base/Camada.h"
#include "../layout/obstaculos.h"
#include "../IA/sensor.hpp"

#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3

#define X_LIMIT 0
#define Y_LIMIT 1

using namespace std;

class Agente
{
private:
		float xBack;
		float yBack;
		float x;
		float y;
		vector<float> limits = {99999, 99999};
		vector<float> color = {0, 0, 0};
		Camada * camada1;
		Camada * camada1_2;
		Camada * camada2;
		void mover( uint8_t direcao);
		vector<float> rede(const vector<float> &input); 
		void procSaida();
		void posBack(void);
		vector<Sensor> sensores;
		vector<float> sensorToFloat();
		
	public:
		vector<float> getPosition();
		Agente( float x, float y);
		void update();
		void draw();
		void setColor(vector<int>);
		float speed;
		void setLimits(vector<float>);
};


void Agente::posBack(void)
{
	this->x = 500;
	this->y = 600;
}

void Agente::setLimits(vector<float> limites)
{
	this->limits[X_LIMIT] = limites[X_LIMIT];
	this->limits[Y_LIMIT] = limites[Y_LIMIT];
}

void Agente::mover( uint8_t direcao)
{
	this->xBack = x;
	this->yBack = y;
	
	if(direcao == CIMA && this->y < limits[Y_LIMIT])
		this->y += this->speed;
	if(direcao == BAIXO && this->y > 20)
		this->y -= this->speed;
	if(direcao == ESQUERDA && this->x > 0)
		this->x -= this->speed;
	if(direcao == DIREITA && this->x < limits[X_LIMIT])
		this->x += this->speed;
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
	this->speed = 4;
	
	this->camada1 = new Camada(100, 5, SAIDA_SIGMOID);
	this->camada1_2 = new Camada(5, 7, SAIDA_SIGMOID);
	this->camada2 = new Camada(7, 4, SAIDA_RELU);
	
	this->x = x;
	this->y = y;
	for(int i = 0; i < 100; i++)
		this->sensores.push_back(Sensor(x, y, x, y, i));
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
	vector<float> out_camada1_2 = this->camada1->saida(out_camada1);
	vector<float> out = this->camada2->saida(out_camada1_2);
	return out;
}

vector<float> Agente::sensorToFloat()
{
	vector<float> tmp;
	for(int i = 0; i < this->sensores.size(); i++)
	{
		tmp.push_back(sensores[i].calcDist());
	}
	return tmp;
}

void Agente::procSaida()
{

	vector<float> out = this->rede(this->sensorToFloat());
	
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
	for(int i = 0; i < this->sensores.size(); i++)
	{
		sensores[i].update();
		sensores[i].setInitPosition(this->x, this->y);
	}
	this->procSaida();
	this->draw();
}

void Agente::draw()
{
    //retangulo(this->x, this->y, 15.0, 15.0,{this->color[0], this->color[1], this->color[2]});
    circulo(this->x, this->y, 60.0,{this->color[0], this->color[1], this->color[2]});
    //ponto(this->x, this->y, {this->color[0], this->color[1], this->color[2]});
}

#endif
