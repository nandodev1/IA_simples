#include "./IA/agente.h"

void setup()
{

}


vector<Agente> agentes;

Agente * ag1 = new Agente(400, 200);	

int i = 0;



void loop()
{    
    //adiciona agente
    
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
	}
}
