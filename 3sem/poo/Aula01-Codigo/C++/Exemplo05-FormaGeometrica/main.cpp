#include <cstdlib>
#include <iostream>
#include "Quadrado.cpp"
#include "Circulo.cpp"

using namespace std;  

int main(int argc, char *argv[])
{
        FormaGeometrica *umQuad = new Quadrado("quarteirao", 10);
        FormaGeometrica *umCirc = new Circulo("balao", 4);
        umQuad->MostraNome();
        cout << umQuad->CalculaArea()  << "\n";
        umCirc->MostraNome();
        cout << umCirc->CalculaArea() << "\n"; 
}
