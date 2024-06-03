#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* strtof */

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
void keyboard(unsigned char key, int x, int y);
Agente load_melhor(Agente ag);

#define QUANT_AGENTES 100
#define TIME_EPOCA 4000
#define EPOCAS 500

void setup()
{
	
}


vector<Agente> agentes;
vector<Agente> agentes_ranking;

int i = 0;

int epoca = 0;

Layout map = Layout("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base2.lay");
Paredes wall = Paredes("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/source/layout/base2.lay", 10, 10, 130, 70);

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
		ag = load_melhor(ag);
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
			if(epoca < EPOCAS)
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
		agentes_ranking.clear();
	}

}

vector<float> mutaCamada(Camada * camada)
{
	vector<float> pesos = camada->get_pesos();
	for(int i = 0; i < pesos.size(); i++)
	{
		int numero_aleatorio = rand() % 100;
		if(numero_aleatorio < 10)
		{
			int dire = rand() % 2;
			if(dire < 1){
				pesos[i] = pesos[i] * (float)((rand() % 5) / 100.);
			}
			else
			{
				pesos[i] = pesos[i] * -(float)((rand() % 5) / 100.);
			}
		}
	}
	return pesos;
}

void keyboard(unsigned char key, int x, int y)
{
     switch (key) 
    {    
       case 27 :      break;
       case 100 : printf("GLUT_KEY_LEFT %d\n",key);   break;
       case 102: printf("GLUT_KEY_RIGHT %d\n",key);  ;  break;
       case 101   : printf("GLUT_KEY_UP %d\n",key);  ;  break;
       case 103 : printf("GLUT_KEY_DOWN %d\n",key);  ;  break;
    }
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

int stringToint(string valor)
{
	bool negativo = false;
	int convercao = 0;

	int decimal = 1;

	for(int i = valor.size() -1; i >= 0 ; i--)
	{
		char tmp_valor = valor[i];
		if( tmp_valor == '-')
		{
			negativo = true;
			break;
		}
		tmp_valor -= 48;
		convercao += tmp_valor * decimal;
		decimal *= 10;
	}
	if(negativo)
		convercao *= -1;
	return convercao;
}

Agente load_melhor(Agente ag)
{
  	string line;
  	ifstream melhor_agente ("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/bin/melhor_agente.ag");

	vector<float> peso_c_1;
	vector<float> peso_c_2;

  	if (melhor_agente.is_open())
  	{
    	for(int i = 0; i <  ag.camada1->get_pesos().size(); i++)
    	{
			getline (melhor_agente,line);
			peso_c_1.push_back(stringToint(line));
    	}
    	for(int i = 0; i <  ag.camada2->get_pesos().size(); i++)
    	{
			getline (melhor_agente,line);
			peso_c_2.push_back(stringToint(line));
    	}
    	melhor_agente.close();


	ag.camada1->set_pesos(peso_c_1);
	ag.camada2->set_pesos(peso_c_2);

	return ag;

  }


 	 else cout << "Unable to open file"; 

  	return ag;
}

void salva_melhor(Agente ag)
{
	ofstream melhor_agente;
	melhor_agente.open ("/media/pc/0237209b-a718-4850-99b1-fc52166addd4/home/pc/projeto_IA/simples_ia/IA_simples/bin/melhor_agente.ag", ios::out);
	
	vector<float> pesos_c_1 = ag.camada1->get_pesos();
	vector<float> pesos_c_2 = ag.camada2->get_pesos();
	
	for(int i = 0; i < pesos_c_1.size(); i++)
	{
		melhor_agente << pesos_c_1[i] << endl;
	}

	for(int i = 0; i < pesos_c_2.size(); i++)
	{
		melhor_agente << pesos_c_2[i] << endl;
	}

	melhor_agente.close();

}

//devolve um clone do melhor agente e salva suas confogurações em disco.

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
		salva_melhor(clone_melhor_agente);
		return clone_melhor_agente;
}