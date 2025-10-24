#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
#include "Hospede.hpp"
using namespace std;


int main() {

    Hospede *h = new Hospede();

    h->setEndereco("Quadra 45 Conjunto H Casa 07");
    cout<<h->getEndereco();

    delete h;
    return 0;

}
