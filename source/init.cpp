#include "./IA/agente.h"

void setup()
{

}

Agente * ag1 = new Agente(400, 200);
Agente * ag2 = new Agente(300, 200);
Agente * ag3 = new Agente(200, 200);

void loop()
{    
    //adiciona agente
    
    ag1->update();
    ag1->setColor({255, 0, 0});
  
    ag2->update();
    ag2->setColor({0, 250, 50});
    
    ag3->update();
    ag3->setColor({200, 250, 50});
}
    
