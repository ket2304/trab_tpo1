#include "Hotel.hpp"
#include <cctype>
#include <string>
#include <iterator>
#include <regex>
#include <string>



void Hotel::setNome(string nome){
    validar_nome(nome);
    this->nome = nome;
};

void Hotel::setEndereco(string endereco){
    validar_Endereco(endereco);
    this->endereco = endereco;
};

void Hotel::validar_telefone(string telefone){

    if(telefone.empty()){throw invalid_argument("Argumento inválido");}

    if (telefone.size() > LIMITE_TELEFONE){
        throw invalid_argument("Argumento inválido");
    }
    for (char c : telefone){
            if (!isdigit(c)){
                throw invalid_argument("Argumento inválido");
            }
        }

}


void Hotel::setTelefone(string telefone){
    
    validar_telefone(telefone);
    this->telefone = telefone;
};

void Hotel::setCodigo(string codigo){
    validar_codigo(codigo);
    this->codigo = codigo;
};



void Hotel::validar_Endereco(string endereco){
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

void Hotel::validar_codigo(string codigo){
    regex padrao_codigo("^[A-Za-z0-9]+$");

    if(codigo.size() != TAMANHO_CODIGO || !regex_match(codigo, padrao_codigo)){
        throw invalid_argument("Código inválido");
    }

}

void Hotel::validar_nome(string nome){
    
    stringstream sstream;
    sstream<<nome[0];
    string letra = sstream.str();
    regex padrao("^[A-Za-z ]+$");
    regex maisculas("^[A-Z]+$");
    int tam_nome = nome.size();

    if (tam_nome < TAM_MIN || tam_nome > LIMITE_NOME || !regex_match(nome, padrao) || !regex_match(letra, maisculas) || nome.back() == ' '){
        throw invalid_argument("argumento inválido");
    }

    for(int i = 0; i < nome.size() - 1; i++){
        if (nome[i] == ' '){
            stringstream sst; 
            sst<<nome[i+1];
            string let = sst.str();
            if (!regex_match(let, maisculas)){throw invalid_argument("argumento inválido");}
        }
    }


}