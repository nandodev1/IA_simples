
#include<GL/glut.h>
#include<string>

using namespace std;

void desenha(void);
void altera_tamanho_janela(GLsizei w, GLsizei h);
void redesenha();

//Referancia para criação da classe
// https://www.inf.pucrs.br/~manssour/OpenGL/PrimeiroPrograma.html
// https://homepages.ecs.vuw.ac.nz/~roma/glut.pdf
class Framework
{
    private:
        int largura;
        int altura;
    public:
        Framework(string titulo, int largura, int altura, int * argc, char * argv[]);
        ~Framework();
        void inicializa();
};

Framework::Framework(string titulo, int largura, int altura, int * argc, char * argv[])
{
    
    glutInit( argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize( largura, altura);
     glutInitWindowPosition(100,100);
    glutCreateWindow( "IA_simples");
    inicializa();
    glutDisplayFunc( desenha) ;
    glutIdleFunc(redesenha);
    // glutFullScreen();
    glutMainLoop();
}
void redesenha()
{
    glutPostRedisplay();
}

// Função callback chamada quando o tamanho da janela é alterado 
void altera_tamanho_janela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_3D);
                   glLoadIdentity();

                //    // Estabelece a janela de seleção (left, right, bottom, top)
                //    if (w <= h) 
                //            gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                //    else 
                //            gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

Framework::~Framework()
{
}


// Inicializa parâmetros de rendering
void Framework::inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

float i = 0;

// Função callback chamada para fazer o desenho
void desenha(void)
{ 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                   
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é vermelha
    //         R     G     B
    glColor3f(1.0f, 0.0f, 0.0f);

    // Desenha um quadrado preenchido com a cor corrente
    
    // Desenha um quadrado preenchido com a cor corrente
    i += 3;
    glRotatef( i, 0, 0, -1);
    glPushMatrix();
        glTranslatef( 0.5, 0, 0);
        glRotated( i, 0, 1, 0);
        glutWireTeapot( 0.2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef( -0.5, 0, 0.7);
        glRotated( i+180, 0, 1, 0);
        glutWireTeapot( 0.2);
    glPopMatrix();

    glPushMatrix();
        glRotated( i, 0, 1, 0);
        glutWireTorus( 0.05, 0.15, 15, 15);
    glPopMatrix();

    for (int j=0; j< 1000; j++)
    {
    glPushMatrix();
        glColor3f( 0.0f, 1.0f, 0.0f);
        glTranslatef( 0, j / 10, 0);
        glRotated( i*2, 0, 0, 1);
        glBegin(GL_QUADS);
            glVertex2f( 0.2, 0.2);
            glVertex2f( -0.2, 0.2);
            glVertex2f( -0.2, -0.2);
            glVertex2f( 0.2, -0.2);
        glEnd();
    glPopMatrix();
    }

    glPushMatrix();
        glColor3f( 1.0f, 1.0f, 0.0f);
        glTranslatef( 0, -0.6, 0);
        glRotated( i*2, 0, 0, 1);
        glBegin(GL_QUADS);
            glVertex2f( 0.2, 0.2);
            glVertex2f( -0.2, 0.2);
            glVertex2f( -0.2, -0.2);
            glVertex2f( 0.2, -0.2);
        glEnd();
    glPopMatrix();

    // Executa os comandos OpenGL
    glFlush();
}
