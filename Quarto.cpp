#include <string>
#include "Quarto.hpp"
#include <stdexcept>
#include <cctype>

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

void Quarto::validar_numero(string numero){
    int num;
    string num1 = numero;
    const char* cstr = num1.c_str();
    num = atoi(cstr);
    

    if(numero.empty() || num > NUMERO_MAXIMO || num < NUMERO_MINIMO ||  !isdigit(numero[0]) || !isdigit(numero[1]) || !isdigit(numero[2])){
       throw invalid_argument("Argumento inválido");
    }
    
    if (numero.size() > 3){throw invalid_argument("Argumento inválido");}
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