#include <iostream>
#include <list>
using namespace std;

class MeuDicionario {
  private:
      list<string> *listaDePalavras;
      list<string>::iterator item;
      
      bool ValidarPalavra(string umaPalavra){
        if(umaPalavra.length() > 10)
            return false;
        return true;
      };
      
   public:      
    MeuDicionario(){
        listaDePalavras = new list<string>();
    };

    void AdicionarPalavra(string umaPalavra){
        if(ValidarPalavra(umaPalavra))
            listaDePalavras->push_back(umaPalavra);
        else
            cout << "Palavra " << umaPalavra << " inválida, pois tem mais do que 10 caracteres" << "\n";
    };
    void MostraPalavras(){
        string palavra;
        int i = 0;
        for (item =  listaDePalavras->begin(); item != listaDePalavras->end(); ++item){            
            palavra = *item;
            cout << "Item " << i << " : " << palavra << "\n";
            i++;
        };
    };
};
