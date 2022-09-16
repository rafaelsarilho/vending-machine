#include <iostream>
#include <string>

using namespace std;

int passw = 123; 

#include "estoque.h"
#include "funcoes.h"

int main(){
  int cat, deslig = 1;
  float vendatotal = 0, valorpedido = 0;
  cout << "A máquina possui a função de administrador que pode ser acessado a qualquer momento apertando 0 na tela de categorias." << endl;
  cout << "A senha padrão é 123 que deve ser alterada assim que possível!" << endl; 
  cout << "Pressione enter para continuar..." << endl;
  getchar();
  do {

    //função menu em funcoes.h
    system("clear");
    cout << "Seja bem-vindo(a) a vending machine Fatekita =)" << endl;
    menu();
    cin >> cat;

    switch (cat){
      case 0: { //entrar na função administrador
        administrador(passw, &deslig, &vendatotal);
        break;
      }
      case 1:
      case 2:
      case 3:
      case 4: { //entrar na função pedido
        pedido(cat, &vendatotal, &valorpedido);
        break;
      }

      default: { //opção default para entrada inválida
        cout << "Digite uma categoria válida!" << endl;
        skip();
        deslig = 1;
        break;
      }
    }
  } while (deslig == 1);

    return 0;
}
