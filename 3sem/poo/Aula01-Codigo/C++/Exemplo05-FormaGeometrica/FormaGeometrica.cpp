#ifndef formageometrica
#define formageometrica

#include <iostream>
#include <string>
using namespace std;

class FormaGeometrica {
   public:
    string sNome;
    float fParam;
    
    FormaGeometrica(string umNome, float umParam) {
        sNome = umNome;
        fParam = umParam;
    };

    void MostraNome(){
        cout << sNome << "\n";
    };
    
    virtual float CalculaArea() = 0;
};
#endif
