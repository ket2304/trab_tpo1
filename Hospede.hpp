#ifndef HOSPODE_HPP_INCLUDED
#define HOSPODE_HPP_INCLUDED
#include "Pessoa.hpp"


class Hospede : public Pessoa{
    private:
        string endereco;
        int cartao;
        static const int LIMITE_ENDERECO = 30;
        static const int MINIMO_ENDERECO = 5;
        static const int LIMITE_CARTAO = 16;
    public:
        string getEndereco();
        string getCartao();

        void setEndereco(string);
        void setCartao(string);

        void validar_endereco(string);
        void validar_cartao(string);

};


inline string Hospede::getEndereco(){
    return endereco;
}

inline string Hospede::getCartao(){
    return cartao;
}

#endif //HOSPODE_HPP_INCLUDED