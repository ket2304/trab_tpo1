#include <iostream>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <string>
#include "Gerente.hpp" // precisa conter validarSenhaOriginal
using namespace std;

void executarTeste(const string& endereco, const string& nome_teste, bool esperado_passar) {
    cout << "----------------------------------------------------------------" << endl;
    cout << "Teste: " << nome_teste << " (\"" << endereco << "\")" << endl;
    cout << "Esperado: " << (esperado_passar ? "PASSAR" : "FALHAR") << endl;
    Hotel* h = new Hotel();
    
    try {
        
        h->validar_Endereco(endereco);
        
        if (esperado_passar) {
            cout << "Resultado: PASSOU. (Correto)" << endl;
        } else {
            cout << "Resultado: PASSOU. (Falso Positivo - ERRO!)" << endl;
        }
        
    } catch (const invalid_argument& e) {
        
        if (!esperado_passar) {
            cout << "Resultado: FALHOU. (Correto)" << endl;
            cout << "Motivo do Erro: " << e.what() << endl;
        } else {
            cout << "Resultado: FALHOU. (Falso Negativo - ERRO!)" << endl;
            cout << "Motivo do Erro: " << e.what() << endl;
        }
    }

}


int main(){

    return 0;
}
