#include<GL/glut.h>
#include "Formas.h"

void setup()
{

}

float y = 0;
float x = 0;

void loop()
{   
    y += 0.0001;
    retangulo( x, y, 0.1, 0.1);
}