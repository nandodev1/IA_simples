#include "./IA/agente.h"
#include "./IA/sensor.hpp"
#include "./layout/layout.h"
#include "./layout/obstaculos.h"

void setup()
{
	
}


vector<Agente> agentes;

Agente * ag1 = new Agente(400, 200);

int i = 0;

vector<float> pos_ag1;

Layout map = Layout("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base.lay");


void loop()
{   
	map.update();
	ag1->update();
	pos_ag1 = ag1->getPosition();
	
    //adiciona agente
    
	if(i<50)
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
	}
}
