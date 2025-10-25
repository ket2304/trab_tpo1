#include <iostream>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <string>
#include "Gerente.hpp"
#include "Hotel.hpp" 
#include "Quarto.hpp"
using namespace std;

void executarTeste(const string& numero, const string& nome_teste, bool esperado_passar) {
    Quarto* q = new Quarto();
    cout << "----------------------------------------------------------------" << endl;
    cout << "Teste: " << nome_teste << " (\"" << numero << "\")" << endl;
    cout << "Esperado: " << (esperado_passar ? "PASSAR" : "FALHAR") << endl;
    
    try {
        q->validar_numero(numero);
        
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

// --- CASOS DE TESTE PRINCIPAIS ---
int main() {
    cout << "--- Testes de Validação de Número de Quarto (Corrigido) ---" << endl;
    cout << "Regras: 3 dígitos, entre 001 e 999." << endl << endl;

    // Casos Válidos
    executarTeste("001", "V1: Mínimo Válido", true);
    executarTeste("999", "V2: Máximo Válido", true);
    executarTeste("123", "V3: Meio Válido", true);
    
    // Falhas de Tamanho
    executarTeste("1", "F1: Tamanho 1", false);
    executarTeste("01", "F2: Tamanho 2", false);
    executarTeste("1000", "F3: Tamanho 4", false);
    
    // Falhas de Limite
    executarTeste("000", "F4: Abaixo do Mínimo", false);
    
    // Falhas de Caractere
    executarTeste("A01", "F5: Contém Letra (Início)", false);
    executarTeste("0A1", "F6: Contém Letra (Meio)", false);
    executarTeste("10A", "F7: Contém Letra (Fim)", false);

    


    return 0;
}
