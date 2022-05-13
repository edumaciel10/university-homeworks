#include <cstdlib>
#include <iostream>
#include "Cachorro.cpp"

using namespace std;

int main(int argc, char *argv[]){
        Cachorro *meuCachorro = new Cachorro("Boxer", "Malhado", "AuAu");
        Cachorro *seuCachorro = new Cachorro("Fila", "Pardo", "AuAuAu"); 
        meuCachorro->nome = "Rex";
        meuCachorro->som = "Au";
        seuCachorro->nome = "Fifi";
        seuCachorro->som = "Grrrr";
        meuCachorro->Latir();
        seuCachorro->Latir();
}
