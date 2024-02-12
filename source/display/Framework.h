#if !defined(FRAMEWORK_H)
#define FRAMEWORK_H

#include<GL/glut.h>
#include<string>

#include"Formas.h"
#include "../init.cpp"

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

	TAMANHO_TELA_X = largura;
	TAMANHO_TELA_Y = altura;
    glutInit( argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize( largura, altura);
     glutInitWindowPosition(200,100);
    glutCreateWindow( "IA_simples");
    inicializa();
    glutDisplayFunc( desenha) ;
    glutIdleFunc(redesenha);
    setup();
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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

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

    // Desenha tudo que estiver na função loop da loop.h
	glTranslatef( -1, -1, 0);
	glPushMatrix();
		loop();
    glPopMatrix();
    
    // Desenha um quadrado preenchido com a cor corrente

// Executa os comandos OpenGL
    glFlush();
}

#endif // FRAMEWORK_H