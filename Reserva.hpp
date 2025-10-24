#include <string>
#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED
using namespace std;

class Quarto;

class Reserva{
    private:
        string chegada;
        string partida;
        string codigo;
        int dinheiro;
        Quarto* quarto;
        static const int TAMANHO_CODIGO = 10;

    public:
        string getChegada();
        string getPartida();
        string getCodigo();
        int getDinheiro();
        Quarto* getQuarto() const;

        void setChegada(string);
        void setPartida(string);
        void setCodigo(string);
        void setDinheiro(int);
        void setQuarto(Quarto* quarto);
        
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

inline Quarto* Reserva::getQuarto()const{
    return quarto;
}

#endif //RESERVA_HPP_INCLUDED
