#include <string>
#ifndef HOTEL_HPP_INCLUDED
#define HOTEL_HPP_INCLUDED


using namespace std;
class Gerente;
class Hotel{
    
    private:
        string nome;
        string endereco;
        string telefone;
        string codigo;
        Gerente* gerente;
        static const int LIMITE_TELEFONE = 14;
        static const int LIMITE_ENDERECO = 30;
        static const int MINIMO_ENDERECO = 5;
        static const int TAMANHO_CODIGO = 10;
        static const int TAM_MIN = 5;
        static const int LIMITE_NOME = 20;
        static const int LIMITE_PARTE_LOCAL = 64;
        static const int LIMITE_DOMINIO = 255;
       
        
    public:
        string getNome();
        string getEndereco();
        string getTelefone();
        string getCodigo();
        Gerente* getGerente()const;
        
        void setNome(string);
        void setEndereco(string);
        void setTelefone(string);
        void setCodigo(string);
        void setGerente(Gerente* gerente);

        void validar_telefone(string);
        void validar_Endereco(string);
        void validar_codigo(string);
        void validar_nome(string);
        
};

inline string Hotel::getNome(){
    return nome;
};

inline string Hotel::getEndereco(){
    return endereco;
};

inline string Hotel::getTelefone(){
    return telefone;
};

inline string Hotel::getCodigo(){
    return codigo;
};

inline Gerente* Hotel::getGerente() const{
    return gerente;
}


#endif //HOTEL_HPP_INCLUDED