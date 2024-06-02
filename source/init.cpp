#include "./IA/agente.h"
#include "./IA/sensor.hpp"
#include "./layout/layout.h"
#include "./layout/obstaculos.h"
#include "./IA/base/Camada.hpp"

using namespace std;

Agente clonar(Agente agente);
Agente getBestScore(vector<Agente> lista_agentes);
vector<float> mutaCamada(Camada camada);
Agente clone_mutacao(Agente ag);

#define QUANT_AGENTES 20
#define TIME_EPOCA 2000

void setup()
{
	
}


vector<Agente> agentes;
vector<Agente> agentes_ranking;

int i = 0;

int epoca = 0;

Layout map = Layout("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base.lay");
Paredes wall = Paredes("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base.lay", 10, 10, 130, 70);

void loop()
{ 
	map.update();
	//ag1->update();
	//pos_ag1 = ag1->getPosition();
	
    //adiciona agente
    
	if(i < QUANT_AGENTES)
	{
		Agente ag = Agente(rand()%1200, rand()%900);
		ag.setColor({rand()%200, rand()%249, rand()%249});
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
		if(ch == '#' || agentes[j].getUpdat() > TIME_EPOCA)
		{
			agentes_ranking.push_back(clonar(agentes[j]));
			agentes.erase(agentes.begin() + j);
			//Adiciona agentes desativados para vetor temporario
			//para futura ordenação.

			//i--;
		}
		
	}
	if(agentes.size() == 0)
	{
		epoca++;
		Agente cloneMelhor = getBestScore(agentes_ranking);
		agentes.push_back(cloneMelhor);
		for(int i = 0; i < QUANT_AGENTES; i++)
		{
			if(epoca < 300)
			{
				Agente cloneMutacao = clone_mutacao(cloneMelhor);
				agentes.push_back(cloneMutacao);
				//agentes.push_back(cloneMelhor);
			}
			else
			{
				cloneMelhor.setColor({255, 0, 0});
				agentes.push_back(cloneMelhor);
				break;
			}
		}
	}

}

vector<float> mutaCamada(Camada * camada)
{
	vector<float> pesos = camada->get_pesos();
	for(int i = 0; i < pesos.size(); i++)
	{
		int numero_aleatorio = rand() % 100;
		if(numero_aleatorio < 1)
		{
			int dire = rand() % 2;
			if(dire < 1){
				pesos[i] = pesos[i] * (float)((rand() % 10) / 100.);
			}
			else
			{
				pesos[i] = pesos[i] * -(float)((rand() % 10) / 100.);
			}
		}
	}
	return pesos;
}

Agente clone_mutacao(Agente ag)
{
	Agente tmp_agente(rand()%1200, rand()%900);

	vector<float> pesos = mutaCamada(ag.camada1);
	tmp_agente.camada1->set_pesos(pesos);
	pesos = mutaCamada(ag.camada1_2);
	tmp_agente.camada1_2->set_pesos(pesos);
	tmp_agente.camada2_3->set_pesos(ag.camada2_3->get_pesos());;
	pesos = mutaCamada(ag.camada2_3);
	tmp_agente.camada2->set_pesos(pesos);

	tmp_agente.setColor({rand()%200, rand()%249, rand()%249});

	tmp_agente.setUpdat(0);

	return tmp_agente;

}

Agente clonar(Agente agente)
{
	Agente tmp_agente(rand()%1200, rand()%900);
	tmp_agente.camada1->set_pesos(agente.camada1->get_pesos());
	tmp_agente.camada1_2->set_pesos(agente.camada1_2->get_pesos());
	tmp_agente.camada2_3->set_pesos(agente.camada2_3->get_pesos());
	tmp_agente.camada2->set_pesos(agente.camada2->get_pesos());

	tmp_agente.setScore(agente.getScore());

	tmp_agente.setColor(agente.getColor());

	return tmp_agente;
}

Agente getBestScore(vector<Agente> lista_agentes)
{
	int record = 0;
	Agente clone_melhor_agente(rand()%1200, rand()%900);
		for(int i = 0; i < lista_agentes.size(); i++)
		{
			int score_tmp = lista_agentes[i].getScore();
			if(score_tmp >= record)
			{
				record = score_tmp;
				clone_melhor_agente = clonar(lista_agentes[i]);
			}
		}

		return clone_melhor_agente;
}