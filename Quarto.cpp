#include <string>
#include "Quarto.hpp"
#include <stdexcept>


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
    int num = stoi(numero);

    if(num > NUMERO_MAXIMO || num < NUMERO_MINIMO || numero.empty() || !is_enum(numero)){
       throw invalid_argument("Argumento inválido");
    }
}