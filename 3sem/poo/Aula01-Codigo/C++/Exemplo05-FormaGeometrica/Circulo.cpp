#include <iostream>
#include <string>
#include <cmath>
#include "FormaGeometrica.cpp"
using namespace std;

class Circulo : public FormaGeometrica {
  public:
    Circulo(string umNome, float umParam) : FormaGeometrica(umNome, umParam){

    };

    void MostraNome(){
        cout << sNome << " diz: - Meu nome eu não sei, mas desce redondo." << "\n";
    };

    float CalculaArea(){
        return (float) (M_PI * fParam * fParam);
    };
};
