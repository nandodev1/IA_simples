#include "./IA/agente.h"

void setup()
{

}

Agente * ag1 = new Agente(400, 200);

void loop()
{    
    //adiciona agente
    
    ag1->update();
    ag1->setColor({255, 0, 0});
}
    
