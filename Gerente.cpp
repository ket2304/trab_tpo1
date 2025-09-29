#include "Gerente.hpp"
#include <iterator>
#include <cctype>
#include <cstdlib>
#include "Hotel.hpp"
#include <regex>


using namespace std;

void Gerente::setRamal(std::string ramal){
    validarRamal(ramal);
    this->ramal = ramal;
};

void Gerente::setSenha(std::string senha){
    validarSenha(senha);
    this->senha = senha;
}

void Gerente::setHotel(Hotel* hotel){
    this->hotel = hotel;
}

void Gerente::validarRamal(string ramal){
    int num;
    string ram = ramal;
    const char* cstr = ram.c_str();
    num = atoi(cstr);
    if(ramal.empty() || ramal.size() > LIMITE_RAMAL || (!isdigit(ramal[0]) || !isdigit(ramal[1]))|| (num < 0 || num > 50)){
        throw invalid_argument("argumento inválido");
    }
}


void Gerente::validarSenha(string senha){

    bool tem_maiscula = false, tem_minuscula = false, tem_digito = false, tem_especial = false;
    
    regex padrao_senha("^[A-Za-z0-9!$#%&?+\"]+$");

    if(senha.empty() || senha.size() != QUANTIDADE_SENHA || !regex_match(senha, padrao_senha)){
        throw invalid_argument("Senha inválida");
    }

    for (size_t i = 0; i < senha.size() - 1; i++){

        if (isalpha(senha[i]) && isalpha(senha[i+1])){
            throw invalid_argument("Senha inválida");
        }
        if(isdigit(senha[i]) && isdigit(senha[i+1])){
            throw invalid_argument("Senha inválida");
        }

        if(isupper(senha[i])){
                tem_maiscula = true;
            }
            if(islower(senha[i])){
                tem_minuscula =  true;
            }
            if(isdigit(senha[i])){
                tem_digito = true;
            }
            else{
                tem_especial = true;
            }
        
    }
    if(!tem_digito || !tem_maiscula || !tem_especial || !tem_minuscula){
        throw invalid_argument("Senha inválida");
    }
        
}
