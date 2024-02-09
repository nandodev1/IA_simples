#include<GL/glut.h>
#include "Formas.h"

void setup()
{

}

float y = 0;

void loop()
{
    y += 0.1;
    retangulo( y, y, 25.0, 25.0, { 100, 250, 50});
	
}
