#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
using namespace std;


int main() {

    Reserva* r = new Reserva();

    r->setChegada("01-JAN-98");

    cout<<r->getChegada();


    return 0;

}
