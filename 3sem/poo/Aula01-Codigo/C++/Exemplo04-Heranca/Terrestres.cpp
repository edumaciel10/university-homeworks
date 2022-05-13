#include <string>
#include "Animal.cpp"

using namespace std;

class Terrestres : public Animal{
  public:    
    int iNrPatas;
    Terrestres(string saNome, int umNroPatas) : Animal(saNome){
        iNrPatas = umNroPatas;
    };

    int getiNrPatas() {
        return iNrPatas;
    };   
};
