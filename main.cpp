#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
using namespace std;


int main() {

    Quarto* q = new Quarto();

    q->setCapacidade("2.5");

    cout<<q->getCapacidade();


    return 0;

}
