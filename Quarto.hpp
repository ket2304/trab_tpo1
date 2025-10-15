#include <string>
#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED
#include "Hotel.hpp"


class Quarto: public Hotel{
    private:
        string numero;
        string capacidade;
        int dinheiro;
        string ramal;
        static const int NUMERO_MAXIMO = 999; 
        static const int NUMERO_MINIMO = 1;  
        static const int LIMITE_RAMAL = 2;
    public:
        void setRamal(string);
        void setNumero(string);
        void setCapacidade(string);
        void setDinheiro(int);

        string getNumero();
        string getCapacidade();
        int getDinheiro();
        string getRamal();

        void validar_numero(string);
        void validar_capacidade(string);
        void validar_dinheiro (int);
        void validar_ramal(string);
    
};

inline string Quarto::getNumero(){
    return numero;
}

inline string Quarto::getCapacidade(){
    return capacidade;
}

inline int Quarto::getDinheiro(){
    return dinheiro;
}

inline string Quarto::getRamal(){
    return ramal;
}


#endif //QUARTO_HPP_INCLUDED