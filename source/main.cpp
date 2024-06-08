#include <iostream>
#include "Perceptron.h"
#include "Camada.hpp"
#include "Framework.h"
#include "obstaculos.h"
#include "agente.h"

Agente clonar(Agente agente);
Agente getBestScore(vector<Agente> lista_agentes);
vector<float> mutaCamada(Camada camada);
Agente clone_mutacao(Agente ag);
Agente load_melhor(Agente ag);
void addAgents();
void startEpoca();
void eliminaAgentes(void);

#define QUANT_AGENTES 100
#define TIME_EPOCA 1000
#define EPOCAS 500

vector<Agente> agentes;
vector<Agente> agentes_ranking;

int epoca = 0;
int tempoEpoca = 0;

Layout map = Layout("base2.lay");
Paredes wall = Paredes("base2.lay", 10, 10, 130, 70);

string pathLayout = "";

using namespace std;

int main( int argc, char * argv[])
{
	srand((unsigned)time(NULL)); //garante valores aleatórios a cada execução do programa.
    string titulo =  "Ai_simple";
	addAgents();
    Framework * fw = new Framework(titulo, 1300, 700, argc, argv);
}

void addAgents()
{

    int i = 0;
	while(i < QUANT_AGENTES)
	{
		Agente ag = Agente(rand()%1200, rand()%900, 10);
		char ch = wall.getCharacterMap(ag.getPosition()[0], ag.getPosition()[1]);
		while(ch == '#')
		{
			ag = Agente(rand()%1200, rand()%900, 10);
			ch = wall.getCharacterMap(ag.getPosition()[0], ag.getPosition()[1]);
		}
		ag.setColor({rand()%200, rand()%249, rand()%249});
		ag.setLimits({1300, 1300});
		//ag = load_melhor(ag);
		agentes.push_back(ag);
		i++;
	}
}

void startEpoca(void)
{
	//addAgents();
	Agente ag();
}

void exibeDados()
{
	//Exibe dados relevantes sobre a IA
	cout << " Epoca: " << epoca << endl;
	cout << " T_EPOCA: " << tempoEpoca << endl;
	cout << " Recorde: " << 0 << endl;
	cout << "+-------------------------------------------+" << endl;
}

void processaColisao()
{
	//Verifica se agenteds colidiu com paredes
	for(int j = 0; j < agentes.size(); j++)
	{
		char ch = wall.getCharacterMap(agentes[j].getPosition()[0], agentes[j].getPosition()[1]);
		if(ch == '#' /*|| agentes[j].getUpdat() > TIME_EPOCA*/)
		{
			agentes_ranking.push_back(clonar(agentes[j]));
			agentes.erase(agentes.begin() + j);
		}
		
	}

}

void eliminaAgentes(void)
{
}

void processaTempoEpoca(void)
{
	tempoEpoca ++;
	if(tempoEpoca >= TIME_EPOCA)
	{
		tempoEpoca = 0;
		agentes.clear();
		//Agente ag1 = clonar(agentes[0]);
		//ag1.setColor({rand()%200, rand()%249, rand()%249});
		//agentes.push_back(ag1);
	}
}

void loop()
{ 
	map.update();

	processaTempoEpoca();

	for(int i = 0; i < agentes.size(); i++)
	{
		agentes[i].update();
	}

	processaColisao();

	if(agentes.size() == 0)
	{
		 startEpoca();
	}

	exibeDados();

}

vector<float> mutaCamada(Camada * camada)
{
	vector<float> pesos = camada->get_pesos();
	for(int i = 0; i < pesos.size(); i++)
	{
		int numero_aleatorio = rand() % 100;
		if(numero_aleatorio < 40)
		{
			int dire = rand() % 2;
			if(dire < 1){
				pesos[i] += pesos[i] * (float)((rand() % 30) / 1000.);
			}
			else
			{
				pesos[i] -= pesos[i] * (float)((rand() % 30) / 1000.);
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
	Agente tmp_agente(rand()%1200, rand()%900, 10);

	Camada * camada1 = new Camada(10, 8, SAIDA_RELU_POSITIVA);
	Camada * camada1_2 = new Camada(8, 5, SAIDA_RELU_POSITIVA);
	Camada * camada2_3 = new Camada(5, 5, SAIDA_RELU_POSITIVA);
	Camada * camada2 = new Camada(5, 5, SAIDA_RELU);

	vector<float> pesos = mutaCamada(ag.camada1);
	camada1->set_pesos(pesos);
	pesos = mutaCamada(ag.camada1_2);
	camada1_2->set_pesos(pesos);
	camada2_3->set_pesos(ag.camada2_3->get_pesos());;
	pesos = mutaCamada(ag.camada2_3);
	camada2->set_pesos(pesos);

	tmp_agente.setColor({rand()%200, rand()%249, rand()%249});

	tmp_agente.setUpdat(0);

	tmp_agente.setScore(ag.getScore());

	tmp_agente.camada1 = camada1;
	tmp_agente.camada1 = camada1_2;
	tmp_agente.camada1 = camada2_3;
	tmp_agente.camada1 = camada2;

	return tmp_agente;

}

Agente clonar(Agente agente)
{
	Agente tmp_agente(rand()%1200, rand()%900, 10);

	Camada * camada1 = new Camada(10, 8, SAIDA_RELU_POSITIVA);
	Camada * camada1_2 = new Camada(8, 5, SAIDA_RELU_POSITIVA);
	Camada * camada2_3 = new Camada(5, 5, SAIDA_RELU_POSITIVA);
	Camada * camada2 = new Camada(5, 5, SAIDA_RELU);

	camada1->set_pesos(agente.camada1->get_pesos());
	camada1_2->set_pesos(agente.camada1_2->get_pesos());
	camada2_3->set_pesos(agente.camada2_3->get_pesos());
	camada2->set_pesos(agente.camada2->get_pesos());

	tmp_agente.setColor(agente.getColor());

	tmp_agente.setScore(agente.getScore());

	tmp_agente.camada1 = camada1;
	tmp_agente.camada1 = camada1_2;
	tmp_agente.camada1 = camada2_3;
	tmp_agente.camada1 = camada2;

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
  	ifstream melhor_agente ("melhor_agente.ag");

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
	melhor_agente.open ("melhor_agente.ag", ios::out);
	
	vector<float> pesos_c_1 = ag.camada1->get_pesos();
	vector<float> pesos_c_2 = ag.camada2->get_pesos();
	
	for(int i = 0; i < pesos_c_1.size(); i++)
	{
		melhor_agente << (int)pesos_c_1[i] << endl;
	}

	for(int i = 0; i < pesos_c_2.size(); i++)
	{
		melhor_agente << (int)pesos_c_2[i] << endl;
	}

	melhor_agente.close();

}

//devolve um clone do melhor agente e salva suas confogurações em disco.

Agente getBestScore(vector<Agente> lista_agentes)
{
	int record = 0;
	Agente clone_melhor_agente(rand()%1200, rand()%900, 10);
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
