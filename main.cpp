#include <iostream>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <string>
#include "Gerente.hpp"
#include "Hotel.hpp" // precisa conter validarSenhaOriginal
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


int main() {
    cout << "--- Testes de Validação de Endereço Refatorado ---" << endl;
    cout << "Regras: 5-30 caracteres, sem bordas proibidas, sem sequências proibidas." << endl << endl;

    // Casos Válidos
    executarTeste("Rua A, 123", "V1: Endereço Válido", true);
    executarTeste("Av. B 45", "V2: Endereço Válido com Ponto", true);
    executarTeste("Rua A,1", "V3: Vírgula seguida por Dígito", true);
    
    // Falhas de Borda
    executarTeste(" Rua A", "F1: Começa com Espaço", false);
    executarTeste("Rua A ", "F2: Termina com Espaço", false);
    executarTeste(",Rua A", "F3: Começa com Vírgula", false);
    
    // Falhas de Sequência
    executarTeste("Rua,,A 1", "F4: Vírgula Dupla", false);
    executarTeste("Rua..A 1", "F5: Ponto Duplo", false);
    executarTeste("Rua  A 1", "F6: Espaço Duplo", false);
    executarTeste("Rua A! 1", "F7: Caractere Não Permitido", false);

    return 0;
}
