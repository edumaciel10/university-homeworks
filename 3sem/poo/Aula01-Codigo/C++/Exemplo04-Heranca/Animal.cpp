#ifndef animal
#define animal
#include <string>

using namespace std;
class Animal {
   private:
    string sNome;

   public:
    Animal(string umNome){
        sNome = umNome;
    };          
    string getNome() {
        return sNome;
    };
};
#endif
