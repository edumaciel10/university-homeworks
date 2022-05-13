#include <iostream>
#include <string>
#include "FormaGeometrica.cpp"
using namespace std;

class Quadrado : public FormaGeometrica {
  public:
    Quadrado(string umNome, float umParam) : FormaGeometrica(umNome, umParam){

    };

    void MostraNome(){
        cout << sNome << " diz: - Quadrado mesmo." << "\n";
    };

    float CalculaArea(){
        return (float) (fParam * fParam);
    };
};
