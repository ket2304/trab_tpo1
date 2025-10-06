#include <string>
#include "Quarto.hpp"



void Quarto::setCapacidade(string capacidade){
    this->capacidade = capacidade;
}

void Quarto::setNumero(string numero){
    this->numero = numero;
}

void Quarto::setDinheiro(string dinheiro){
    this->dinheiro = dinheiro;
}

void Quarto::setRamal(string ramal){
    getGerente()->validarRamal(ramal);
    this->ramal = ramal;
}