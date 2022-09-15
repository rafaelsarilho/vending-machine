#include <iostream>
#include <string>

using namespace std;

int passw = 123; 

#include "estoque.h"
#include "funcoes.h"

int main(){
  int cat;
  int novo = 1;
  do {
    //função menu em funcoes.h
    menu();
    cin >> cat;
    if(cat == 0){
      //função administrador em funcoes.h
      administrador(passw, &novo);
    }
    if(cat>= 1 && cat <=4){
      //função pedido em funcoes.h
      pedido();
    }
  } while (novo == 1);

    return 0;
}
