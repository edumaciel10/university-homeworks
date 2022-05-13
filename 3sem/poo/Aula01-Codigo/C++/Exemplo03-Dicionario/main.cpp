#include <cstdlib>
#include <iostream>
#include "Dicionario.cpp"

using namespace std;

int main(int argc, char *argv[])
{
        MeuDicionario *umDicionario = new MeuDicionario();
        umDicionario->AdicionarPalavra("Carro");
        umDicionario->AdicionarPalavra("Gato");
        umDicionario->AdicionarPalavra("Livro");
        umDicionario->AdicionarPalavra("Constituição");
        umDicionario->MostraPalavras();
}
