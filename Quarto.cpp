#include <string>
#include "Quarto.hpp"



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
    
}