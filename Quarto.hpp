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
        static const int NUMERO_MAXIMO = 999;   
        
    public:
        void setRamal(string);
        void setNumero(string);
        void setCapacidade(string);
        void setDinheiro(float);
        string getNumero();
        string getCapacidade();
        float getDinheiro();
        string getRamal();
        void validar_numero(string);
    
};

inline string Quarto::getNumero(){
    return numero;
}

inline string Quarto::getCapacidade(){
    return capacidade;
}

inline float Quarto::getDinheiro(){
    return dinheiro;
}

inline string Quarto::getRamal(){
    return ramal;
}


#endif //QUARTO_HPP_INCLUDED