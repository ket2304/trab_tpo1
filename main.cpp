#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
#include "Hospede.hpp"
#include <vector>
using namespace std;

void testar(const string& data, Reserva& r) {
    try {
        r.validar_data(data);
        cout << "✅ OK: " << data << endl;
    } catch (const exception& e) {
        cout << "❌ ERRO: " << data 
             << " -> " << e.what() << endl;
    }
}

int main() {
    
    Reserva r;
    vector<string> testes = {
        "01-JAN-2000", "29-FEV-2020", "31-ABR-2024", "29-FEV-2021",
        "32-JAN-2024", "00-MAR-2024", "10-AAA-2024", "10-MAR-3000",
        "10/FEV/2024", "2024-FEV-10", "1-1-2024", "31-DEZ-2999"
    };

    for (const auto& t : testes) {
        testar(t, r);
    }
}