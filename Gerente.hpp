#include <string>
#include "Pessoa.hpp"
#ifndef GERENTE_HPP_INCLUDED
#define GERENTE_HPP_INCLUDED

using namespace std;

class Hotel;

class Gerente : public Pessoa{
    private:
        static const int LIMITE_RAMAL = 2;
        static const int QUANTIDADE_SENHA = 5;
        string ramal;
        string senha;
        Hotel *hotel;
    public:
        string getRamal();
        string getSenha();
        void setRamal(string);
        void setSenha(string);
        void validarRamal(string);
        void validarSenha(string);
        Hotel* getHotel() const;
        void setHotel(Hotel* hotel);
        
    };

inline string Gerente::getRamal(){
    return ramal;
};

inline string Gerente::getSenha(){
    return senha;
};

inline Hotel* Gerente::getHotel()const{
    return hotel;
}


#endif //GERENTE_HPP_INCLUDED