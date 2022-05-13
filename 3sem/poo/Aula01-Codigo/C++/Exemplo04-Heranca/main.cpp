#include <cstdlib>
#include <iostream>
#include "Cachorro.cpp"
#include "Lambari.cpp"

using namespace std;

int main(int argc, char *argv[])
{
        Cachorro *umCao = new Cachorro("Dog",4);
        cout << umCao->getNome() << " - " << umCao->getiNrPatas() << "\n";

        Lambari *umPeixe = new Lambari("Nemo",10);
        cout << umPeixe->getNome() << " - " << umPeixe->getMinsDeFolego() << "\n";
}
