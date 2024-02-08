
#include<GL/glut.h>

class Framework
{
private:
    int largura;
    int altura;
public:
    Framework(int largura, int altura);
    ~Framework();
    void Desenha();
};

Framework::Framework( int largura, int altura)
{

}

Framework::~Framework()
{
}

// Função callback chamada para fazer o desenho
void Framework::Desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT);

	//Executa os comandos OpenGL 
	glFlush();
}
