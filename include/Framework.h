
#include<GL/glut.h>
#include<string>

//Referancia para criação da classe
// https://www.inf.pucrs.br/~manssour/OpenGL/PrimeiroPrograma.html
class Framework
{
    private:
        int largura;
        int altura;
    public:
        Framework(string titulo, int largura, int altura);
        ~Framework();
        void Desenha();
        void inicializa();
};

Framework::Framework(string titulo, int largura, int altura)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("IA_simple");
	glutDisplayFunc(this->Desenha);
	this->inicializa();
	glutMainLoop();
}

Framework::~Framework()
{
}


// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada para fazer o desenho
void Framework::Desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT);

	//Executa os comandos OpenGL 
	glFlush();
}
