#include <iostream>
#include <string>

using namespace std;

int passw = 123; 

#include "estoque.h"
#include "funcoes.h"

int main(){
  int cat, deslig = 1;
  float vendatotal = 0, valorpedido = 0;

  do {
    //função menu em funcoes.h
    menu();
    cin >> cat;
    if(cat == 0){
      //função administrador em funcoes.h
      administrador(passw, &deslig, &vendatotal);
    }

    if(cat>= 1 && cat <=4){
      //função pedido em funcoes.h
      pedido(cat, &vendatotal, &valorpedido);
    }
  } while (deslig == 1);

    return 0;
}
