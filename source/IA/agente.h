#ifndef AGENTE_H
#define AGENTE_H

#include <vector>
#include "./base/Camada.hpp"
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
		Paredes * paredes = new Paredes("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base.lay", 10, 10, 130, 70);
		float xBack;
		float yBack;
		float x;
		float y;
		vector<float> limits = {99999, 99999};
		vector<int> color = {0, 0, 0};
		void mover( uint8_t direcao);
		vector<float> rede(const vector<float> &input); 
		void procSaida();
		void posBack(void);
		vector<Sensor> sensores;
		vector<float> sensorToFloat();
		int score;
		//variavél responsavél por armazenar slots já visitados.
		string caminho;
		void copyMap(void);
		int updata;
		int score_history;
		int updata_history;//update do ultimo score adicionado.
		
	public:
		vector<float> getPosition();
		Agente( float x, float y);
		void update();
		void draw();
		void setColor(vector<int>);
		float speed;
		void setLimits(vector<float>);
		int getScore(void);
		void setScore(int);
		bool isScore(void);
		Camada * camada1;
		Camada * camada1_2;
		Camada * camada2_3;
		Camada * camada2;
		vector<int> getColor(void);
		int getUpdat(void);
		void setUpdat(int);
		virtual ~Agente();
};

Agente::~Agente()
{
}

void Agente::setUpdat(int valor)
{
	this->updata = valor;
}

int Agente::getUpdat(void)
{
	return this->updata;
}

vector<int> Agente::getColor(void)
{
	return this->color;
}

void Agente::setScore(int score)
{
	this->score = score;
}

void Agente::copyMap(void)
{
	string map = paredes->getMap();
	for(int i = 0; i < map.size(); i++)
	{
		char ch = map[i];
		if(ch != '\n')
			this->caminho += ch;
	}
}

bool Agente::isScore(void)
{
	char ch = this->paredes->getCharacterMap(this->x, this->y);
	int x_largura = this->paredes->getDimX();
	int dimXObj = this->paredes->getDimX();


	int posX =  (((int)this->x) % dimXObj);
	int posY = (((int)this->y) % dimXObj);

	if(ch == ' ')
	{
		int posYtmp = posY  * x_largura;

		char chMap = caminho[posX + posY];
		if(chMap != '.')
		{
			this->updata_history = this->updata;
			this->score += 10;
			caminho[posX + posY] = '.';
			return true;
		}
	}
	return false;
}

int Agente::getScore(void)
{
	return this->score;
}

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
	this->updata = 0;
	this->score += 1;
	caminho = "";
	this->copyMap();
	
	this->camada1 = new Camada(20, 4, SAIDA_RELU_POSITIVA);
	this->camada1_2 = new Camada(4, 5, SAIDA_RELU_POSITIVA);
	this->camada2_3 = new Camada(5, 5, SAIDA_RELU_POSITIVA);
	this->camada2 = new Camada(4, 5, SAIDA_RELU);
	
	this->x = x;
	this->y = y;
	for(int i = 0; i < 100;)
	{
		this->sensores.push_back(Sensor(x, y, x, y, i));
		i += 5;
	}
	this->score = 0;
	this->updata_history = 0;
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
	//vector<float> out_camada1_2 = this->camada1->saida(out_camada1);
	//vector<float> out_camada2_3 = this->camada1->saida(out_camada1_2);
	vector<float> out = this->camada2->saida(out_camada1);
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
	
	float dir4 = out[3];
	float dir2 = out[1];
	float dir3 = out[2];
	float dir1 = out[0];
	
	int saida = 0;

	if(dir1 > 0)
		this->mover(CIMA);
	if(dir2 > 0)
		this->mover(BAIXO);
	if(dir3 > 0)
		this->mover(ESQUERDA);
	if(dir4 > 0)
		this->mover(DIREITA);
	if(dir4 > 0)
	{
		this->speed = 1;
	}
	else
	{
		this->speed = 0.5;
	}
}

void Agente::update()
{
	this->updata++;
	if(this->updata - this->updata_history >= 500)
	{
		this->updata = 99999;
	}
	this->score += 0;
	for(int i = 0; i < this->sensores.size(); i++)
	{
		sensores[i].update();
		sensores[i].setInitPosition(this->x, this->y);
	}
	this->procSaida();
	this->isScore();
	this->draw();
}

void Agente::draw()
{
    //retangulo(this->x, this->y, 15.0, 15.0,{this->color[0], this->color[1], this->color[2]});
    circulo(this->x, this->y, 10.0,{(float)this->color[0], (float)this->color[1], (float)this->color[2]});
    //ponto(this->x, this->y, {this->color[0], this->color[1], this->color[2]});
}

#endif
