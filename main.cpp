#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
using namespace std;


int main() {

    Quarto* q = new Quarto();

    q->validar_ramal("51");

    return 0;

}
