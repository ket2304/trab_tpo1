#include <string>
#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED
#include "Hotel.hpp"


class Quarto: public Hotel{
    private:
        string numero;
        string capacidade;
        float dinheiro;
        string ramal;
        
    public:
        void setNumero(string);
        void setCapacidade(string);
        void setDinheiro(string);
        string getNumero();
        string getCapacidade();
        float getDinheiro();
        
};

inline string Quarto::getNumero(){
    return dinheiro;
}

inline string Quarto::getCapacidade(){
    return capacidade;
}

inline float Quarto::getDinheiro(){
    return dinheiro;
}

inline string Gerente::getRamal(){
    return ramal;
}


#endif //QUARTO_HPP_INCLUDED