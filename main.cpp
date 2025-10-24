#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
#include "Hospede.hpp"
#include <vector>
using namespace std;


int main() {
    
    Hotel* h = new Hotel();
    h->setNome("Hotel Central");
    h->setEndereco("Avenida Principal,123");
    h->setTelefone("123456789");
    h->setCodigo("H001");

    Quarto* q1 = new Quarto();
    q1->setNumero("101");
    q1->setCapacidade("2");
    q1->setDinheiro(200);
    q1->setRamal("10");

    h->adicionarQuarto(q1); 
}