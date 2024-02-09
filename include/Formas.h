#include <vector>

void retangulo( float x, float y, float w, float h, vector<float> cor = { 0,0,0})
{ 
    glPushMatrix();
        glColor3f( cor[0], cor[1], cor[2]);
        glTranslatef( x, y, 0);
        glBegin(GL_POLYGON);
            glVertex2f( -w/2, h/2);
            glVertex2f( -w/2, -h/2);
            glVertex2f( w/2, -h/2);
            glVertex2f( w/2 , h/2);
        glEnd();
    glPopMatrix();
}

void circulo()
{
    
}