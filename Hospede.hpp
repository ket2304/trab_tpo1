#ifndef HOSPODE_HPP_INCLUDED
#define HOSPODE_HPP_INCLUDED
#include "Pessoa.hpp"


class Hospede : public Pessoa{
    private:
        string endereco;
        static const int LIMITE_ENDERECO = 30;
        static const int MINIMO_ENDERECO = 5;

    public:
        string getEndereco();


        void setEndereco(string);

        void validar_endereco(string);


};


inline Hospede::getEndereco(){
    return endereco;
}

#endif //HOSPODE_HPP_INCLUDED