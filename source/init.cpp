#include "./IA/agente.h"
#include "./IA/sensor.h"

void setup()
{

}


vector<Agente> agentes;

Agente * ag1 = new Agente(400, 200);

Sensor * s1 = new Sensor( 400, 400);

int i = 0;

vector<float> pos_ag1;

void loop()
{    
	ag1->update();
	pos_ag1 = ag1->getPosition();
	
	s1->x = pos_ag1[0] + 30;
	s1->y = pos_ag1[1] + 30;
	
	s1->update();
	
    //adiciona agente
    /*
	if(i<150)
	{
		Agente ag = Agente(rand()%1300, rand()%910);
		ag.setColor({rand()%249, rand()%249, rand()%249});
		ag.setLimits({1285, 910});
		agentes.push_back(ag);
	}
	i++;
    ag1->update();
	ag1->setColor({255, 0, 0});
	for(int i = 0; i < agentes.size(); i++)
	{
		agentes[i].update();
	}*/
}
