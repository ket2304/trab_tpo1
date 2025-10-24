#include "Reserva.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <iterator>
#include <regex>
#include <vector>
#include <algorithm> 
#include <stdexcept>
#include <cstdlib>
#include "Quarto.hpp"


using namespace std;

void Reserva::setChegada(string chegada){
    validar_data(chegada);
    this->chegada = chegada;
}

void Reserva::setPartida(string partida){
    validar_data(partida);
    this->partida = partida;
}

void Reserva::setCodigo(string codigo){
    validar_codigo(codigo);
    this->codigo = codigo;
}

void Reserva::setDinheiro(int dinheiro){
    validar_dinheiro(dinheiro);
    this->dinheiro = dinheiro;
}



void Reserva::validar_data(string data) {
    
    if (data.size() < 8 || data.size() > 11) {
        throw invalid_argument("data inválida!");
    }

    size_t pos1 = data.find('-');
    size_t pos2 = data.rfind('-');

    if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) {
        throw invalid_argument("formato de data inválido!");
    }

    string dia = data.substr(0, pos1);
    string mes = data.substr(pos1 + 1, pos2 - pos1 - 1);
    string ano = data.substr(pos2 + 1);

    if (dia.empty() || dia.size() > 2 || !all_of(dia.begin(), dia.end(), ::isdigit)) {
        throw invalid_argument("dia inválido!");
    }
    if (mes.empty() || mes.size() != 3) {
        throw invalid_argument("mes deve ter 3 letras!");
    }
    if (ano.empty() || ano.size() != 4 || !all_of(ano.begin(), ano.end(), ::isdigit)) {
        throw invalid_argument("ano inválido!");
    }

    int dia_int = stoi(dia);
    int ano_int = stoi(ano);

    validar_mes(mes);

    bool bissexto = (ano_int % 4 == 0 && ano_int % 100 != 0) || (ano_int % 400 == 0);

    if (mes == "FEV") {
        if (bissexto) {
            if (dia_int < 1 || dia_int > 29)
                throw invalid_argument("data inválida!");
        } else {
            if (dia_int < 1 || dia_int > 28)
                throw invalid_argument("data inválida!");
        }
    } else {
        if (dia_int < 1 || dia_int > 31)
            throw invalid_argument("dia fora do intervalo!");

        
        if ((mes == "ABR" || mes == "JUN" || mes == "SET" || mes == "NOV") && dia_int > 30) {
            throw invalid_argument("dia inválido para este mês!");
        }
    }

    if (ano_int < 2000 || ano_int > 2999) {
        throw invalid_argument("ano fora do intervalo (2000-2999)!");
    }
}


void Reserva::validar_dinheiro(int d){
    if (d < 0 || d > 1000000){
        throw invalid_argument("Argumento inválido");
    }
}

void Reserva::validar_codigo(string codigo){
    regex padrao_codigo("^[A-Za-z0-9]+$");

    if(codigo.size() != TAMANHO_CODIGO || !regex_match(codigo, padrao_codigo)){
        throw invalid_argument("Código inválido");
    }
}

void Reserva::validar_mes(string mes){
    vector <string> meses = {
        "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
        "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
    };

    auto it = find(meses.begin(), meses.end(), mes);

    if (it == meses.end()){
        throw invalid_argument("data inválida");
    }
}

void Reserva::setQuarto(Quarto* quarto){
    this->quarto = quarto;
}

void Reserva::setHospede(Hospede* hospede){
    this->hospede = hospede;
}