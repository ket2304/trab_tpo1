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

using namespace std;


void Reserva::validar_data(string data){
    
    string dia = data.substr(0, 2);
    string mes = data.substr(2, 3);
    string ano = data.substr(5);

    int dia_int = atoi(dia.c_str());
    int ano_int = atoi(ano.c_str());

    validar_mes(mes);

    if(dia.empty() || dia.size() < 1 || dia.size() < 2 || (dia_int < 1 || dia_int > 31) || mes.empty() || mes.size() != 3
        || ano.empty() || ano.size() != 4 || (ano_int < 2000 || ano_int > 2999)){
        throw invalid_argument("data inválida!");
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

