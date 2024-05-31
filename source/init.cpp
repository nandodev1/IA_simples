#include "./IA/agente.h"
#include "./IA/sensor.hpp"
#include "./layout/layout.h"
#include "./layout/obstaculos.h"

void setup()
{
	
}


vector<Agente> agentes;

int i = 0;

Layout map = Layout("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base.lay");
Paredes wall = Paredes("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base.lay", 10, 10, 130, 70);

void loop()
{   
	map.update();
	//ag1->update();
	//pos_ag1 = ag1->getPosition();
	
    //adiciona agente
    
	if(i<200)
	{
		Agente ag = Agente(rand()%1200, rand()%900);
		ag.setColor({rand()%249, rand()%249, rand()%249});
		ag.setLimits({1300, 1300});
		agentes.push_back(ag);
		i++;
	}
    //ag1->update();
	//ag1->setColor({255, 0, 0});
	for(int i = 0; i < agentes.size(); i++)
	{
		agentes[i].update();
	}
	for(int j = 0; j < agentes.size(); j++)
	{
		char ch = wall.getCharacterMap(agentes[j].getPosition()[0], agentes[j].getPosition()[1]);
		if(ch == '#')
		{
			agentes.erase(agentes.begin() + j);
			i--;
		}
		
	}
}
