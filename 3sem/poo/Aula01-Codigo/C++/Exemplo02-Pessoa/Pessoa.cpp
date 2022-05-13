#include <string>
#include <iostream>

using namespace std;

class Pessoa {
 public:
    string nome;
    string DataNasc;
    string cor;
    bool bDormindo;

    Pessoa(string umNome, string umaDataNasc, string umaCor) {
        nome = umNome;
        DataNasc = umaDataNasc;
        cor = umaCor;
        bDormindo = false;
    };

    void Acordar(){
        if(!bDormindo){
            cout << "Ja estou acordado" << "\n";
        }else{
            bDormindo = false;
            cout << "Acordei, eba" << "\n";
        };
    };
    void Dormir(){
        if(bDormindo){
            cout << "Ja estou dormindo" << "\n";
        } else {
            bDormindo = true;
            cout << "Dormi, zzz" << "\n";
        };
    };
};
