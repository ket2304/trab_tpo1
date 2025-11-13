#include <string>
#include "Quarto.hpp"
#include <stdexcept>
#include <cctype>
#include <iostream>

using namespace std;




void Quarto::setCapacidade(string capacidade){
    validar_capacidade(capacidade);
    this->capacidade = capacidade;
}

void Quarto::setNumero(string numero){
    validar_numero(numero);
    this->numero = numero;
}

void Quarto::setDinheiro(int dinheiro){
    validar_dinheiro(dinheiro);
    this->dinheiro = dinheiro;
}

void Quarto::setRamal(string ramal){
    validar_ramal(ramal);
    this->ramal = ramal;
}

void Quarto::setHotel(Hotel* hotel){
    this->hotel = hotel;
}


void Quarto::validar_numero(string numero){
    
    for (char c : numero) {
        if (!isdigit(c)) {
            throw invalid_argument("Número deve conter apenas dígitos.");
        }
    }
    
    int num;
    string num1 = numero;
    const char* cstr = num1.c_str();
    num = atoi(cstr);


    if(numero.empty() || num > NUMERO_MAXIMO || num < NUMERO_MINIMO 
){
       throw invalid_argument("Argumento inválido");
    }
    
    if (numero.size()!= 3){throw invalid_argument("Argumento inválido");}
}

void Quarto::validar_capacidade(string c){
    if(c.empty() || (c != "1" && c != "2" && c != "3" && c != "4")){throw invalid_argument("Argumento inválido");}
}

void Quarto::validar_dinheiro(int d){
    if (d < 0 || d > 1000000){
        throw invalid_argument("Argumento inválido");
    }
}

void Quarto::validar_ramal(string ramal){
    int num;
    string ram = ramal;
    const char* cstr = ram.c_str();
    num = atoi(cstr);
    if(ramal.empty() || ramal.size() > LIMITE_RAMAL || (!isdigit(ramal[0]) || !isdigit(ramal[1]))|| (num < 0 || num > 50)){
        throw invalid_argument("argumento inválido");
    }
}


