#include <string>
#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED


class Reserva{
    private:
        string chegada;
        string partida;
        string codigo;
        int dinheiro;

    public:
        string getChegada();
        string getPartida();
        string getCodigo();
        int getDinheiro();

        void setChegada(string);
        void setPartda(string);
};




#endif //RESERVA_HPP_INCLUDED
