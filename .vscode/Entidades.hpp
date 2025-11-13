#include "Hotel.hpp"
#include "Gerente.hpp"
#include <cctype>
#include <string>
#include <iterator>
#include <regex>
#include <string>
#include "Quarto.hpp"
#include <iostream>
#include <algorithm>

#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED


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

class Gerente;
class Quarto;

class Hotel{
    
    private:
        string nome;
        string endereco;
        string telefone;
        string codigo;
        Gerente* gerente;
        vector <Quarto*> quartos;
        static const int LIMITE_TELEFONE = 14;
        static const int LIMITE_ENDERECO = 30;
        static const int MINIMO_ENDERECO = 5;
        static const int TAMANHO_CODIGO = 10;
        static const int TAM_MIN = 5;
        static const int LIMITE_NOME = 20;
        static const int LIMITE_PARTE_LOCAL = 64;
        static const int LIMITE_DOMINIO = 255;
       
        
    public:
        string getNome();
        string getEndereco();
        string getTelefone();
        string getCodigo();
        Gerente* getGerente()const;
        
        void setNome(string);
        void setEndereco(string);
        void setTelefone(string);
        void setCodigo(string);
        void setGerente(Gerente* gerente);
        void adicionarQuarto(Quarto* quarto);
        
        vector<Quarto*> getQuartos() const;
        void validar_telefone(string);
        void validar_Endereco(string);
        void validar_codigo(string);
        void validar_nome(string);
        
};

inline string Hotel::getNome(){
    return nome;
};

inline string Hotel::getEndereco(){
    return endereco;
};

inline string Hotel::getTelefone(){
    return telefone;
};

inline string Hotel::getCodigo(){
    return codigo;
};

inline Gerente* Hotel::getGerente() const{
    return gerente;
}

inline vector <Quarto*> Hotel::getQuartos() const{
    return quartos;
}

class Gerente : public Pessoa{
    private:
        static const int LIMITE_RAMAL = 2;
        static const int QUANTIDADE_SENHA = 5;
        string ramal;
        string senha;
        
    public:
        string getRamal();
        string getSenha();
        void setRamal(string);
        void setSenha(string);
        void validarRamal(string);
        void validarSenha(string);
        
    };

inline string Gerente::getRamal(){
    return ramal;
};

inline string Gerente::getSenha(){
    return senha;
};


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

class Quarto;
class Hospede;

class Reserva{
    private:
        string chegada;
        string partida;
        string codigo;
        int dinheiro;
        Quarto* quarto;
        Hospede* hospede;
        static const int TAMANHO_CODIGO = 10;

    public:
        string getChegada();
        string getPartida();
        string getCodigo();
        int getDinheiro();
        Quarto* getQuarto() const;
        Hospede* getHospede() const;


        void setChegada(string);
        void setPartida(string);
        void setCodigo(string);
        void setDinheiro(int);
        void setQuarto(Quarto* quarto);
        void setHospede(Hospede* hospede);

        void validar_data(string);
        void validar_codigo(string);
        void validar_dinheiro(int);
        void validar_mes(string);
    

};

inline string Reserva::getChegada(){
    return chegada;
}

inline string Reserva::getPartida(){
    return partida;
}

inline string Reserva::getCodigo(){
    return codigo;
}

inline int Reserva::getDinheiro(){
    return dinheiro;
}

inline Quarto* Reserva::getQuarto() const{
    return quarto;
}

inline Hospede* Reserva::getHospede() const{
    return hospede;
}


class Hospede : public Pessoa{
    private:
        string endereco;
        string cartao;
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

#endif //ENTIDADES_HPP_INCLUDED