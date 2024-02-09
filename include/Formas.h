#include <vector>
#include <math.h>

float TAMANHO_TELA_X = 0;
float TAMANHO_TELA_Y = 0;

void retangulo( float x, float y, float w, float h, vector<float> cor = { 0.0,0.0,0.0})
{ 
	w *= 2;
	h *= 2;
	 
    glPushMatrix();
        glColor3f( cor[0]/255, cor[1]/255, cor[2]/255);
        glTranslatef( x/TAMANHO_TELA_X, y/TAMANHO_TELA_X, 0);
        glBegin(GL_POLYGON);
            glVertex2f( x/TAMANHO_TELA_X, y/TAMANHO_TELA_Y);
            glVertex2f( ( x+w)/TAMANHO_TELA_X, y/TAMANHO_TELA_Y);
            glVertex2f( ( x+ w)/TAMANHO_TELA_X, (y-h)/TAMANHO_TELA_Y);
            glVertex2f( x/TAMANHO_TELA_X, (y-h)/TAMANHO_TELA_Y);
        glEnd();
    glPopMatrix();
}

void circulo()
{
    glPushMatrix();
        glBegin(GL_POLYGON);
            //glVertex2f( -w/2, h/2);
            //glVertex2f( -w/2, -h/2);
            //glVertex2f( w/2, -h/2);
            //glVertex2f( w/2 , h/2);
        glEnd();
    glPopMatrix();
}
