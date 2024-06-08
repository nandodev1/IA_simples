#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <math.h>

#include "Formas.h"
#include "layout.h"
#include "obstaculos.h"

#define PI_2 ((3.14159265 * 2)/100)

class Sensor
{
	private:
		vector<float> color = {0, 0, 0};
		Paredes paredes = Paredes("base2.lay", 10, 10, 130, 70);
		float x_parent;
		float y_parent;
		float x_init;
		float y_init;
		float angulo;
		bool line_show;
		
	public:
		float x;
		float y;
		Sensor(float x, float y, float x_parent, float y_parent, float angle);
		void update(void);
		void setColor(vector<int> color);
		float calcDist();
		void setInitPosition(float x, float y);
		void setLineShow(bool active);
};

void Sensor::setLineShow(bool active)
{
	this->line_show = active;
}

void Sensor::setInitPosition(float x, float y)
{
	this->x_init = x;
	this->y_init = y;
}

float Sensor::calcDist()
{
	float dist;
	float a;
	float b;
	float c;
	//obtem modulos dos valores base
	if(this->x > this->x_init)
		b = this->x - this->x_init;
	else
		b = this->x_init - this->x;

	if(this->y > this->y_init)
		c = this->y - this->y_init;
	else
		c = this->y_init - this->y;

	a = sqrt(b * b + c * c);
	return a;//this->paredes.getDimX();//Mais ganbiarra
}

Sensor::Sensor(float x, float y, float x_parent, float y_parent, float angle)
{
	this->x = x;
	this->y = y;
	
	this->x_parent = x_parent;
	this->y_parent = y_parent;
	this->x_init = x;
	this->y_init = y;
	this->angulo = angle;

	this->line_show = false;
}

//seleciona cor do agente
void Sensor::setColor(vector<int> color)
{
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}

void Sensor::update(void)
{	
	while(true)
	{
		float dist;
		char ch;
		ch = this->paredes.getCharacterMap(this->x, this->y);
        this->x += cos(this->angulo*PI_2);
        this->y += sin(this->angulo*PI_2);
		if(ch == '#')
		{
			dist = this->calcDist();
			//retangulo(this->x, this->y, 5.0, 5.0,{this->color[0], this->color[1], this->color[2]});
			//* 2 ganbiarra braba
			if(dist > 40.)
			{
				if(this->line_show)
					line(this->x*2, this->y*2, this->x_init*2, this->y_init*2);
			}
			this->x = this->x_init;
			this->y = this->y_init;
 			break;
		}
	}
}

#endif
