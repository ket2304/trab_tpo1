#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
using namespace std;


int main() {

    Quarto* q = new Quarto();
    
    
    q->setRamal("51");
    
    cout<<q->getRamal();


    return 0;

}
