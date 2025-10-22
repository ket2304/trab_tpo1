#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
using namespace std;


int main() {

    Reserva r = new Reserva();

    r.validar_data("05MAI2025");


    return 0;

}
