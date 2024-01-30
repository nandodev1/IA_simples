#ifndef PERCEPTRON_H
#define PERCEPTRON_H


class Perceptron
{
    public:
        Perceptron();
        virtual ~Perceptron();
        float somatorio( float * entradas);
        float ativacao_sigm( float somatorio);
        float ativacao_relu( float somatorio);
        float saida( float * entradas);
        void treinamento( float * entradas, float saida_esperada, taxa_de_aprendizagem);

    protected:

    private:
};

#endif // PERCEPTRON_H
