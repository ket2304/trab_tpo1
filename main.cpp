#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
using namespace std;


int main() {

    Quarto* q = new Quarto();

    q->setNumero("0005");

    cout<<q->getNumero();


    return 0;

}
