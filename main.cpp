#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
#include "Hospede.hpp"
using namespace std;


int main() {

    Reserva* r = new Reserva();

    r->getChegada("30-FEV-2000");

    cout<<r->getChegada();
    delete r;

    return 0;

}
