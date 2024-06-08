#ifndef FORMAS_H
#define FORMAS_H

#include <vector>
#include <math.h>
#include <GL/glut.h>

#define PI_2 ((3.14159265 * 2)/100)

float TAMANHO_TELA_X = 0;
float TAMANHO_TELA_Y = 0;

void retangulo( float x, float y, float w, float h, vector<float> cor = { 0.0,0.0,0.0})
{

	w *= 2;
	h *= 2;

    glPushMatrix();
        glColor3f( cor[0]/255, cor[1]/255, cor[2]/255);
        glTranslatef(x/TAMANHO_TELA_X, y/TAMANHO_TELA_Y, 0);
        glBegin(GL_POLYGON);
            glVertex2f(x/TAMANHO_TELA_X, y/TAMANHO_TELA_Y);
            glVertex2f(( x + w)/TAMANHO_TELA_X, y/TAMANHO_TELA_Y);
            glVertex2f(( x + w)/TAMANHO_TELA_X, (y-h)/TAMANHO_TELA_Y);
            glVertex2f(x/TAMANHO_TELA_X, (y-h)/TAMANHO_TELA_Y);
        glEnd();
    glPopMatrix();
}

void circulo(float x, float y, float raio, vector<float> cor)
{
    float x_c = 0;
    float y_c = 0;

    glPushMatrix();
        glColor3f( cor[0]/255, cor[1]/255, cor[2]/255);
        //*2 é ganbiarra
        glTranslatef(x/TAMANHO_TELA_X*2, y/TAMANHO_TELA_Y*2, 0);
        glBegin(GL_POLYGON);
            for(int i = 0; i < 99; i++)
            {
                x_c = cos(i*PI_2);
                y_c = sin(i*PI_2);
                glVertex2f( (x_c*raio)/TAMANHO_TELA_X, (y_c*raio)/TAMANHO_TELA_Y);
            }
        glEnd();
    glPopMatrix();
}

void line(float x1, float y1, float x2, float y2){
    glPushMatrix();
        glColor3f (0.0, 0.0, 0.0);
        //glTranslatef(100/TAMANHO_TELA_X*2, 200/TAMANHO_TELA_Y*2, 0);
        glBegin(GL_LINES);
            glVertex2f(x1/TAMANHO_TELA_X, y1/TAMANHO_TELA_Y);
            glVertex2f(x2/TAMANHO_TELA_X, y2/TAMANHO_TELA_Y);
        glEnd();
    glPopMatrix();
}
void ponto(float x, float y, vector<float> cor){
    glPushMatrix();
        glColor3f( cor[0]/255, cor[1]/255, cor[2]/255);
        //glTranslatef(100/TAMANHO_TELA_X*2, 200/TAMANHO_TELA_Y*2, 0);
        glPointSize(300);
        glBegin(GL_POINT_SIZE);
            glVertex2f(x/TAMANHO_TELA_X, y/TAMANHO_TELA_Y);
        glEnd();
    glPopMatrix();
}
#endif
