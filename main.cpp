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

    h->setTelefone("++551234567");


    cout<<h->getTelefone();

    delete h;

    return 0;
}