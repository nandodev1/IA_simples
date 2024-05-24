#ifndef SENSOR_H
#define SENSOR_H


class Sensor
{
	private:
		vector<float> color = {0, 0, 0};
		
	public:
		float x;
		float y;
		Sensor(float x, float y);
		void update(void);
		void setColor(vector<int> color);
};

Sensor::Sensor(float x, float y)
{
	this->x = x;
	this->y = y;
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
    retangulo(this->x, this->y, 5.0, 5.0,{this->color[0], this->color[1], this->color[2]});
}

#endif