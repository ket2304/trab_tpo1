#include <string>
#include "Quarto.hpp"
#include <stdexcept>
#include <cctype>

void Quarto::setCapacidade(string capacidade){
    this->capacidade = capacidade;
}

void Quarto::setNumero(string numero){
    validar_numero(numero);
    this->numero = numero;
}

void Quarto::setDinheiro(float dinheiro){
    this->dinheiro = dinheiro;
}

void Quarto::setRamal(string ramal){
    getGerente()->validarRamal(ramal);
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