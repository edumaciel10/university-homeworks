#include <string>
#include <iostream>

using namespace std;
class Cachorro{
      public:
             string raca;
             string cor;
             string som;
             string nome;
             
             Cachorro(string umaRaca, string umaCor, string umSom){
                raca = umaRaca;
                cor = umaCor;
                som = umSom;
             };
             void Latir(){
                  cout << som << "\n";
             };
};
