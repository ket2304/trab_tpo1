#include "Hospede.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <string>
#include <iterator>
#include <regex>

using namespace std;


void Hospede::validar_Endereco(string endereco){
    regex padrao ("^(?:[A-Z0-9 ,.]+|(?=.*[a-z])(?=.*[A-Z])[A-Za-z0-9 ,.]+)$");
    regex carac_valido ("^(?:[A-Z0-9 ]+|(?=.*[a-z])(?=.*[A-Z])[A-Za-z0-9 ]+)$");
    regex carac_let_digito("^[A-Za-z0-9]$");

    if (endereco.size() < MINIMO_ENDERECO || endereco.size() > LIMITE_ENDERECO || endereco.empty() || endereco.front() == ' ' || endereco.back() == ' ' || !regex_match(endereco, padrao) || endereco.front()== '.' || endereco.front() == ',' || endereco.back() == '.' || endereco.back() == ','){
        throw invalid_argument("Argumento inváido");
    }
    for (int i = 0; i < endereco.size()-1; i++){
        if (endereco[i] == ',' || endereco[i] == '.'){
            stringstream sstream;
            sstream<<endereco[i+1];
            string prox_letra = sstream.str();
            if(!regex_match(prox_letra, carac_valido)){throw invalid_argument("Argumento inváido");}
        }
        if (endereco[i] == ' '){
            stringstream sstream;
            sstream<<endereco[i+1];
            string prox_letra = sstream.str();
            if(!regex_match(prox_letra, carac_let_digito)){throw invalid_argument("Argumento inváido");}
        }
    }
}