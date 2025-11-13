#include "Entidades.hpp"
#include <cctype>
#include <string>
#include <iterator>
#include <regex>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;


void Pessoa::validarNome(string nome){
    
    stringstream sstream;
    sstream<<nome[0];
    string letra = sstream.str();
    regex padrao("^[A-Za-z ]+$");
    regex maisculas("^[A-Z]+$");
    size_t tam_nome = nome.size();

    if (nome.empty()) throw invalid_argument("Nome vazio.");


    if (tam_nome < TAM_MIN || tam_nome > LIMITE_NOME) {
        throw invalid_argument("Nome inválido: tamanho fora do limite permitido.");
    }

    if (!regex_match(nome, padrao)) {
        throw invalid_argument("Nome inválido: contém caracteres não permitidos.");
    }

    if (!regex_match(letra, maisculas)) {
        throw invalid_argument("Nome inválido: deve começar com letra maiúscula.");
    }

    if (nome.back() == ' ') {
        throw invalid_argument("Nome inválido: não deve terminar com espaço.");
    }


    for (size_t i = 0; i < nome.size() - 1; i++) {
        if (nome[i] == ' ') {
            stringstream sst;
            sst << nome[i + 1];
            string let = sst.str();

            if (!regex_match(let, maisculas)) {
                throw invalid_argument("Nome inválido: cada palavra deve começar com letra maiúscula.");
            }
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
    

    if(email.empty()){throw invalid_argument("Argumento inválido");}
    if(local.empty() || dominio.empty()){throw invalid_argument("Argumento inválido");}
    if((dominio.find('.') == string::npos) || (email.find('@') == string::npos)){throw invalid_argument("Argumento inválido");}
    if(!regex_match(dominio, padrao_dominio) || !regex_match(local, padrao_local)){throw invalid_argument("Argumento inválido");}

    if ((local.size() > LIMITE_PARTE_LOCAL) || (local.front() == '-') || (local.front() == '.')
        || (local.back() == '-') || (local.back() == '.')){
            throw invalid_argument("Argumento inválido");
    }else{
        for(size_t i = 1; i < local.size() - 1; i++){
            if ((local[i] == '.' || local[i] == '-') && (!isalnum(local[i+1]))){
                throw invalid_argument("Argumento inválido");
            }
        }
    }

    if ((dominio.size() > LIMITE_DOMINIO) || (dominio.front() == '-') || (dominio.front() == '.')
        || (dominio.back() == '-') || (dominio.back() == '.')){
            throw invalid_argument("Argumento inválido");
    }else{
        for(size_t i = 1; i < dominio.size() - 1; i++){
            if ((dominio[i] == '.' || dominio[i] == '-') && (!isalnum(dominio[i+1]))){
                throw invalid_argument("Argumento inválido");
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

//Classe Hotel
void Hotel::setNome(string nome){
    validar_nome(nome);
    this->nome = nome;
}

void Hotel::setEndereco(string endereco){
    validar_Endereco(endereco);
    this->endereco = endereco;
}

void Hotel::validar_telefone(string telefone){

    
    size_t pos = telefone.find("+");
    size_t contagem = std::count(telefone.begin(), telefone.end(), '+');    
    if (telefone.empty()) throw invalid_argument("Telefone vazio após +");
    if(pos == std::string::npos){throw invalid_argument("Formato inválido, o número precisa começar com '+'")}

    if(pos != 0 || contagem > 1){
        throw invalid_argument("Formato de telefone inválido: deve começar com '+' e não pode ter mais de um '+'");
    }

    telefone.erase(0,1);

    if (telefone.size() > LIMITE_TELEFONE){
        throw invalid_argument("Código deve ter 6 caracteres alfanuméricos");
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
}

void Hotel::setCodigo(string codigo){
    validar_codigo(codigo);
    this->codigo = codigo;
}



void Hotel::validar_Endereco(string endereco){
    
    regex padrao ("^(?:[A-Z0-9 ,.]+|(?=.*[a-z])(?=.*[A-Z])[A-Za-z0-9 ,.]+)$");
    regex carac_valido ("^(?:[A-Z0-9 ]+|(?=.*[a-z])(?=.*[A-Z])[A-Za-z0-9 ]+)$");
    regex carac_let_digito("^[A-Za-z0-9]$");


    if (endereco.empty()) {
        throw invalid_argument("Endereço inválido: campo vazio");
    }

    if (endereco.size() < MINIMO_ENDERECO || endereco.size() > LIMITE_ENDERECO) {
        throw invalid_argument("Endereço inválido: tamanho fora dos limites permitidos");
        }

    if (endereco.front() == ' ' || endereco.back() == ' ') {
        throw invalid_argument("Endereço inválido: não pode começar ou terminar com espaço");
        }

    if (endereco.front() == '.' || endereco.front() == ',' || 
        endereco.back() == '.' || endereco.back() == ',') {
        throw invalid_argument("Endereço inválido: não pode começar ou terminar com ponto ou vírgula");
        }

    if (!regex_match(endereco, padrao)) {
        throw invalid_argument("Endereço inválido: contém caracteres não permitidos");
        }

    for (size_t i = 0; i < endereco.size()-1; i++){
        if (endereco[i] == ',' || endereco[i] == '.'){
            stringstream sstream;
            sstream<<endereco[i+1];
            string prox_letra = sstream.str();
            if(!regex_match(prox_letra, carac_valido)){throw invalid_argument("Argumento inválido");}
        }
        if (endereco[i] == ' '){
            stringstream sstream;
            sstream<<endereco[i+1];
            string prox_letra = sstream.str();
            if(!regex_match(prox_letra, carac_let_digito)){throw invalid_argument("Argumento inválido");}
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

    if (nome.empty()) throw invalid_argument("Nome vazio.");


    if (tam_nome < TAM_MIN || tam_nome > LIMITE_NOME || !regex_match(nome, padrao) || !regex_match(letra, maisculas) || nome.back() == ' '){
        throw invalid_argument("Argumento inválido");
    }

    for(size_t i = 0; i < nome.size() - 1; i++){
        if (nome[i] == ' '){
            stringstream sst; 
            sst<<nome[i+1];
            string let = sst.str();
            if (!regex_match(let, maisculas)){throw invalid_argument("Cada palavra do nome deve começar com letra maiúscula");}
        }
    }


}

void Hotel::setGerente(Gerente* gerente){
    this->gerente = gerente;
}

void Hotel::adicionarQuarto(Quarto* quarto) {
    if (quarto != nullptr) {
        this->quartos.push_back(quarto);
    }
}



//Classe Gerente 
void Gerente::setRamal(std::string ramal){
    validarRamal(ramal);
    this->ramal = ramal;
}

void Gerente::setSenha(std::string senha){
    validarSenha(senha);
    this->senha = senha;
}

void Gerente::validarRamal(string ramal) {
    
    if (ramal.empty()) {
        throw invalid_argument("Ramal não pode estar vazio");
    }

    if (ramal.size() > LIMITE_RAMAL) {
        throw invalid_argument("Ramal excede o tamanho máximo permitido");
    }

    
    int num;
    try {
        num = stoi(ramal);
    } catch (const exception&) {
        throw invalid_argument("Ramal inválido: deve conter apenas números");
    }

    if (!isdigit(ramal[0]) || (ramal.size() > 1 && !isdigit(ramal[1]))) {
        throw invalid_argument("Ramal deve começar com pelo menos dois dígitos");
    }

    
    if (num < 0 || num > 50) {
        throw invalid_argument("Ramal deve estar entre 0 e 50");
    }
}



void Gerente::validarSenha(string senha){

    bool tem_maiscula = false, tem_minuscula = false, tem_digito = false, tem_especial = false;
    
    regex padrao_senha("^[A-Za-z0-9!$#%&?+\"]+$");

    if (senha.empty()) {
        throw invalid_argument("Senha inválida: não pode estar vazia");
    }


    if (senha.size() != QUANTIDADE_SENHA) {
        throw invalid_argument("Senha inválida: deve conter exatamente " + to_string(QUANTIDADE_SENHA) + " caracteres");
    }

    if (!regex_match(senha, padrao_senha)) {
        throw invalid_argument("Senha inválida: contém caracteres não permitidos");
    }


    for (size_t i = 0; i < senha.size(); i++){

        if (isalpha(senha[i]) && isalpha(senha[i+1])){
            throw invalid_argument("Senha não pode ter duas letras seguidas");
        }
        if(isdigit(senha[i]) && isdigit(senha[i+1])){
            throw invalid_argument("Senha não pode ter dois números seguidos");
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
        throw invalid_argument("Senha inválida: deve conter letras maiúsculas, minúsculas, números e caracteres especiais");
    }
        
}


//Classe Quarto
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

void Quarto::setHotel(Hotel* hotel){
    this->hotel = hotel;
}


void Quarto::validar_numero(string numero){
    
    for (char c : numero) {
        if (!isdigit(c)) {
            throw invalid_argument("Número deve conter apenas dígitos.");
        }
    }
    
    int num;
    string num1 = numero;
    const char* cstr = num1.c_str();
    num = atoi(cstr);


    if(numero.empty() || num > NUMERO_MAXIMO || num < NUMERO_MINIMO ){
       throw invalid_argument("Número inválido ou fora do intervalo permitido");
    }
    
    if (numero.size()!= 3){throw invalid_argument("Número inválido: deve conter exatamente 3 dígitos");}
}

void Quarto::validar_capacidade(string c){
    if(c.empty() || (c != "1" && c != "2" && c != "3" && c != "4")){throw invalid_argument("Argumento inválido");}
}

void Quarto::validar_dinheiro(int d){
    if (d < 0 || d > 1000000){
        throw invalid_argument("Valor inválido: deve estar entre 0 e 1.000.000");
    }
}

void Quarto::validar_ramal(string ramal){
    int num;
    string ram = ramal;
    const char* cstr = ram.c_str();
    num = atoi(cstr);
    if (ramal.empty()) {
    throw invalid_argument("Ramal inválido: campo vazio");
    }

    if (ramal.size() > LIMITE_RAMAL) {
        throw invalid_argument("Ramal inválido: excede o tamanho máximo permitido");
    }

    if (!isdigit(ramal[0]) || !isdigit(ramal[1])) {
        throw invalid_argument("Ramal inválido: deve começar com dois dígitos numéricos");
    }

    if (num < 0 || num > 50) {
        throw invalid_argument("Ramal inválido: deve estar no intervalo de 0 a 50");
    }

}


//Classe Reserva
void Reserva::setChegada(string chegada){
    validar_data(chegada);
    this->chegada = chegada;
}

void Reserva::setPartida(string partida){
    validar_data(partida);
    this->partida = partida;
}

void Reserva::setCodigo(string codigo){
    validar_codigo(codigo);
    this->codigo = codigo;
}

void Reserva::setDinheiro(int dinheiro){
    validar_dinheiro(dinheiro);
    this->dinheiro = dinheiro;
}



void Reserva::validar_data(string data) {
    

    if(data.empty()){ throw invalid_argument("Data inválida: campo vazio");}
    if (data.size() < 8 || data.size() > 11) {
        throw invalid_argument("Data inválida: tamanho fora do formato esperado (ex: 12-MAI-2025)");
    }

    size_t pos1 = data.find('-');
    size_t pos2 = data.rfind('-');

    if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) {
        throw invalid_argument("Formato de data inválido: use o formato DD-MMM-AAAA (ex: 05-JUL-2024)");
    }

    string dia = data.substr(0, pos1);
    string mes = data.substr(pos1 + 1, pos2 - pos1 - 1);
    string ano = data.substr(pos2 + 1);

    if (dia.empty() || dia.size() > 2 || !all_of(dia.begin(), dia.end(), ::isdigit)) {
        throw invalid_argument("Dia inválido: deve conter até dois dígitos numéricos");
    }
    if (mes.empty() || mes.size() != 3) {
        throw invalid_argument("Mês inválido: deve ter exatamente 3 letras maiúsculas (ex: JAN, FEV, MAR)");
    }
    if (ano.empty() || ano.size() != 4 || !all_of(ano.begin(), ano.end(), ::isdigit)) {
        throw invalid_argument("Ano inválido: deve conter 4 dígitos numéricos");
    }

    int dia_int = stoi(dia);
    int ano_int = stoi(ano);

    validar_mes(mes);

    bool bissexto = (ano_int % 4 == 0 && ano_int % 100 != 0) || (ano_int % 400 == 0);

    if (mes == "FEV") {
        if (bissexto) {
            if (dia_int < 1 || dia_int > 29)
                throw invalid_argument("Data inválida: fevereiro bissexto possui apenas 29 dias");
        } else {
            if (dia_int < 1 || dia_int > 28)
                throw invalid_argument("Data inválida: fevereiro possui apenas 28 dias");
        }
    } else {
        if (dia_int < 1 || dia_int > 31)
            throw invalid_argument("Dia inválido: deve estar entre 1 e 31");

        if ((mes == "ABR" || mes == "JUN" || mes == "SET" || mes == "NOV") && dia_int > 30) {
            throw invalid_argument("Dia inválido: este mês possui apenas 30 dias");
        }
    }

    if (ano_int < 2000 || ano_int > 2999) {
        throw invalid_argument("Ano inválido: deve estar no intervalo entre 2000 e 2999");
    }

}


void Reserva::validar_dinheiro(int d){
    if (d < 0 || d > 1000000){
        throw invalid_argument("Valor inválido: deve estar entre 0 e 1.000.000");
    }
}

void Reserva::validar_codigo(string codigo){
    regex padrao_codigo("^[A-Za-z0-9]+$");

    if (codigo.size() != TAMANHO_CODIGO) {
        throw invalid_argument("Código inválido: tamanho incorreto");
    }
    if (!regex_match(codigo, padrao_codigo)) {
        throw invalid_argument("Código inválido: deve conter apenas letras e números");
    }
}

void Reserva::validar_mes(string mes){
    vector<string> meses = {
        "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
        "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
    };

    auto it = find(meses.begin(), meses.end(), mes);

    if (it == meses.end()){
        throw invalid_argument("Mês inválido: deve ser uma abreviação em maiúsculas (ex: JAN, FEV, MAR)");
    }
}


void Reserva::setQuarto(Quarto* quarto){
    this->quarto = quarto;
}

void Reserva::setHospede(Hospede* hospede){
    this->hospede = hospede;
}

//Classe Hospede
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

    for (size_t i = 0; i < endereco.size() - 1; i++) {
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
