#include <iostream>
#include "Pessoa.hpp"
#include "Gerente.hpp"
#include "Hotel.hpp"
using namespace std;


int main() {

    Hotel* h = new Hotel();
    h->validar_codigo("abcd1234567");
    


    return 0;

}
