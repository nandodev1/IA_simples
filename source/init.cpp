#include "IA/Agente.h"

void setup()
{

}

float y = 0;
Agente * ag1 = new Agente();

void loop()
{
    y += 0.1;
    
    retangulo( 100, y+ 50, 15.0, 15.0, { 100, 50, 50});
    retangulo( y, y+ 50, 15.0, 15.0, { 100, 150, 50});
	
}
    
