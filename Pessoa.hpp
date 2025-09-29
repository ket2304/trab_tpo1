#include <string>
#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED




using namespace std;

class Pessoa{
    private:
        string nome;
        string email;
        static const int TAM_MIN = 5;
        static const int LIMITE_NOME = 20;
        static const int LIMITE_PARTE_LOCAL = 64;
        static const int LIMITE_DOMINIO = 255;
    public:
        void validarNome(string);
        void validarEmail(string);
        string getNome();
        string getEmail();
        void setEmail(string);
        void setNome(string);

    };

inline string Pessoa::getNome(){
    return nome;
};

inline string Pessoa::getEmail(){
    return email;
};

#endif //PESSOA_HPP_INCLUDED