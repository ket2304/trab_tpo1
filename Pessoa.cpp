#include "Pessoa.hpp"
#include <iterator>
#include <cctype>
#include <iostream>
#include <regex>


using namespace std;

void Pessoa::validarNome(string nome){
    
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

void Pessoa::validarEmail(std::string email){
   
    std::string local;
    std::string dominio;
    regex padrao_local("^[A-Za-z0-9._-]+$");
    regex padrao_dominio("^[A-Za-z0-9.-]+$");
    
    

    size_t posicao_arroba = email.find('@');
    if(posicao_arroba == string::npos){throw invalid_argument("Email deve conter @");}
    local = email.substr(0, posicao_arroba);
    dominio = email.substr(posicao_arroba + 1);
    

    if(email.empty()){throw invalid_argument("argumento inválido");}
    if(local.empty() || dominio.empty()){throw invalid_argument("argumento inválido");}
    if((dominio.find('.') == string::npos) || (email.find('@') == string::npos)){throw invalid_argument("argumento inválido");}
    if(!regex_match(dominio, padrao_dominio) || !regex_match(local, padrao_local)){throw invalid_argument("argumento inválido");}

    if ((local.size() > LIMITE_PARTE_LOCAL) || (local.front() == '-') || (local.front() == '.')
        || (local.back() == '-') || (local.back() == '.')){
            throw invalid_argument("argumento inválido");
    }else{
        for(size_t i = 1; i < local.size() - 1; i++){
            if ((local[i] == '.' || local[i] == '-') && (!isalnum(local[i+1]))){
                throw invalid_argument("argumento inválido");
            }
        }
    }

    if ((dominio.size() > LIMITE_DOMINIO) || (dominio.front() == '-') || (dominio.front() == '.')
        || (dominio.back() == '-') || (dominio.back() == '.')){
            throw invalid_argument("argumento inválido");
    }else{
        for(size_t i = 1; i < dominio.size() - 1; i++){
            if ((dominio[i] == '.' || dominio[i] == '-') && (!isalnum(dominio[i+1]))){
                throw invalid_argument("argumento inválido");
            }
        }
    }    
}


void Pessoa::setNome(std::string nome) {
    validarNome(nome);
    this->nome = nome;
   
}

void Pessoa::setEmail(std::string email){

    validarEmail(email);
    this->email = email;

}