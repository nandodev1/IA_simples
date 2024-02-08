
#include<GL/glut.h>
#include<string>

using namespace std;

void desenha(void);
void altera_tamanho_janela(GLsizei w, GLsizei h);

//Referancia para criação da classe
// https://www.inf.pucrs.br/~manssour/OpenGL/PrimeiroPrograma.html
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
    glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("IA_simple");
    glutInitWindowSize( largura, altura);
    glutInitWindowPosition(10,10);
    glutReshapeFunc(altera_tamanho_janela);
	glutDisplayFunc(desenha);
	this->inicializa();
	glutMainLoop();
}

// Função callback chamada quando o tamanho da janela é alterado 
void altera_tamanho_janela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada para fazer o desenho
void desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     //         R     G     B
     glColor3f(1.0f, 0.0f, 0.0f);

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_QUADS);
               glVertex2i(100,150);
               glVertex2i(100,100);
               // Especifica que a cor corrente é azul
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(150,100);
               glVertex2i(150,150);               
     glEnd();

	//Executa os comandos OpenGL 
	glFlush();
}
