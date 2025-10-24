#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED
#pragma once

#include <string>

class Hotel;

class Quarto{
    
    private:
        string numero;
        string capacidade;
        int dinheiro;
        string ramal;
        Hotel* hotel;
        static const int NUMERO_MAXIMO = 999; 
        static const int NUMERO_MINIMO = 1;  
        static const int LIMITE_RAMAL = 2;
        
    public:
        void setRamal(string);
        void setNumero(string);
        void setCapacidade(string);
        void setDinheiro(int);
        void setHotel(Hotel* hotel);

        string getNumero();
        string getCapacidade();
        int getDinheiro();
        string getRamal();
        Hotel* getHotel() const;

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

inline Hotel* Quarto::getHotel() const{
    return hotel;
}

#endif //QUARTO_HPP_INCLUDED