#include <string>
#include "Animal.cpp"

using namespace std;

class Aquaticos : public Animal{
   private:
    int iMinsDeFolego;

   public:
    Aquaticos(string saNome, int umMinsDeFolego) : Animal(saNome){
        iMinsDeFolego = umMinsDeFolego;
    };

    int getMinsDeFolego() {
        return iMinsDeFolego;
    };

};
