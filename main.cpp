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

    h->setCartao("4242 4242 4242 4242");

    cout<<h->getCartao();
    delete h;

    return 0;

}
