#include "Hospede.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <string>
#include <iterator>
#include <regex>
#include <vector>
#include <algorithm>

using namespace std;

void Hospede::setCartao(string cartao) {
    validar_cartao(cartao);
    this->cartao = cartao;
}

void Hospede::setEndereco(string endereco) {
    validar_endereco(endereco);
    this->endereco = endereco;
}

void Hospede::validar_endereco(string endereco) {
    regex padrao("^(?:[A-Z0-9 ,.]+|(?=.*[a-z])(?=.*[A-Z])[A-Za-z0-9 ,.]+)$");
    regex carac_valido("^(?:[A-Z0-9 ]+|(?=.*[a-z])(?=.*[A-Z])[A-Za-z0-9 ]+)$");
    regex carac_let_digito("^[A-Za-z0-9]$");

    if (endereco.empty()) {
        throw invalid_argument("Endereço inválido: campo vazio");
    }

    if (endereco.size() < MINIMO_ENDERECO || endereco.size() > LIMITE_ENDERECO) {
        throw invalid_argument("Endereço inválido: tamanho fora do limite permitido");
    }

    if (endereco.front() == ' ' || endereco.back() == ' ') {
        throw invalid_argument("Endereço inválido: não deve começar ou terminar com espaço");
    }

    if (endereco.front() == '.' || endereco.front() == ',' ||
        endereco.back() == '.' || endereco.back() == ',') {
        throw invalid_argument("Endereço inválido: não deve começar ou terminar com ponto ou vírgula");
    }

    if (!regex_match(endereco, padrao)) {
        throw invalid_argument("Endereço inválido: formato incorreto ou contém caracteres não permitidos");
    }

    for (int i = 0; i < endereco.size() - 1; i++) {
        if (endereco[i] == ',' || endereco[i] == '.') {
            stringstream sstream;
            sstream << endereco[i + 1];
            string prox_letra = sstream.str();
            if (!regex_match(prox_letra, carac_valido)) {
                throw invalid_argument("Endereço inválido: caractere inválido após vírgula ou ponto");
            }
        }

        if (endereco[i] == ' ') {
            stringstream sstream;
            sstream << endereco[i + 1];
            string prox_letra = sstream.str();
            if (!regex_match(prox_letra, carac_let_digito)) {
                throw invalid_argument("Endereço inválido: caractere incorreto após espaço");
            }
        }
    }
}



void Hospede::validar_cartao(string cartao) {
    
    auto it = remove(cartao.begin(), cartao.end(), ' ');
    cartao.erase(it, cartao.end());

    if (cartao.empty()) {
        throw invalid_argument("Número de cartão inválido: campo vazio");
    }

    if (cartao.length() != LIMITE_CARTAO) {
        throw invalid_argument("Número de cartão inválido: deve conter exatamente " + to_string(LIMITE_CARTAO) + " dígitos");
    }

    for (char c : cartao) {
        if (!isdigit(static_cast<unsigned char>(c))) {
            throw invalid_argument("Número de cartão inválido: deve conter apenas dígitos numéricos");
        }
    }

    
    int soma = 0;
    int cod_verif = cartao.back() - '0';
    cartao.pop_back();

    for (int i = cartao.length() - 1, j = 0; i >= 0; --i, ++j) {
        int n = cartao[i] - '0';
        if (j % 2 == 0) {
            n *= 2;
            if (n > 9) n -= 9;
        }
        soma += n;
    }

    if ((soma + cod_verif) % 10 != 0) {
        throw invalid_argument("Número de cartão inválido: falha na validação do dígito verificador");
    }
}
