#include <cstdlib>
#include <iostream>
#include "Pessoa.cpp"

using namespace std;

int main(int argc, char *argv[])
{
        Pessoa *umaPessoa = new Pessoa("Joao","10/10/2010","Branco");
        umaPessoa->Dormir();
        umaPessoa->Acordar();
        umaPessoa->Acordar();
        umaPessoa->Dormir();     
}
