#include <iostream>
#include <string>

using namespace std;

int passw = 123; 

#include "estoque.hpp"

//funções
void skip();
void menu();
void pagamento(float *valorpedido, float *total);
void pedido(int categ, float *total, float *valorpedido);
void administrador(int senha, int *shutd, float *total);


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

void skip(){
  cout << "Pressione enter para continuar..." << endl;
  getchar();
  getchar();
}

// categoria de lanches
void menu() {
  cout << "Digite a categoria desejada: " << endl;
  cout << "1 - Salgadinhos" << endl;
  cout << "2 - Lanches naturais" << endl;
  cout << "3 - Bebidas" << endl;
  cout << "4 - Doces" << endl;
}

//menu de pagamentos
void pagamento(float *valorpedido, float *total) {
  int menupg, verifpg, senha;
  float pago, troco;

  do {
    system("clear");
    cout << "Valor total do seu pedido: R$ " << *valorpedido << endl;
    cout << "Qual a forma de pagamento desejada?" << endl;
    cout << "1 - Dinheiro" << endl;
    cout << "2 - Cartão de débito" << endl;
    cout << "3 - Cartão de crédito" << endl;
    cout << "4 - Cancelar pedido" << endl;
    cin >> menupg;

    switch (menupg){
      case 1: { //pagamento em dinheiro
        cout << "Insira o dinheiro na máquina" << endl;
        cin >> pago;
        if(pago >= *valorpedido){
          troco = pago - *valorpedido;
          if (troco > 0){
            cout << "Seu troco é de: R$ " << troco << endl;
          }
          cout << "Obrigado pelo seu pedido! \n Retire seu produto =)" << endl;
          *total += *valorpedido;
          *valorpedido = 0;
          verifpg = 1;
          skip();
          system("clear");
        }
        else {
          cout << "Valor incorreto! Insira um valor compatível com a compra!" << endl;
          verifpg = 0;
          skip();
          system("clear");
        }
        break;
      }

      case 2: 
      case 3: { //pagamento em cartão
        cout << "Digite sua senha: ";
        cin >> senha;
        cout << "Processando ..." << endl;
        cout << "Aprovado!" << endl;
        cout << "Obrigado pelo seu pedido! \n Retire seu produto =)" << endl;
        *total += *valorpedido;
        *valorpedido = 0;
        verifpg = 1;
        skip();
        system("clear");
        break;
      }

      case 4: { //cancelar pedido
        cout << "Pedido cancelado!" << endl;
        skip();
        system("clear");
        verifpg = 1;
        *valorpedido = 0;
        break;
      }

      default: { //opção para entrada inválida
        cout << "Selecione uma opção válida!" << endl;
        skip();
        system("clear");
        verifpg = 0;
        break;
      }
    }
  } while (verifpg == 0);

}

//menu para fazer pedidos
void pedido(int categ, float *total, float *valorpedido) {
  int qnt = 0, item = 0;
  char novo = 's';
  int i, j;
  float valor = 0;

  do {
    system("clear");
    cout << "Escolha seu produto: " << endl;
    for(i = 0; i < 3; i++){
      cout << i+1 << " " << estoque[categ-1][i].itens << endl;
    }
    cin >> item;
    system("clear");
    cout << "Você escolheu o item: " << estoque[categ-1][item-1].itens << ". Ele custa: R$ " << estoque[categ-1][item-1].valores << endl;
    cout << "Existem " << estoque[categ-1][item-1].quantidade << " itens disponíveis no para compra" << endl;
    cout << "Quantos você quer comprar? " << endl;
    cin >> qnt;
    if(qnt <= estoque[categ-1][item-1].quantidade){
      *valorpedido += qnt*estoque[categ-1][item-1].valores;
      cout << "O valor total do seu pedido é: R$ " << *valorpedido << endl;
      estoque[categ-1][item-1].quantidade -= qnt;
    }
    else {
      cout << "Quantidade inválida!" << endl;
    }
    skip();
    system("clear");
    cout << "Deseja adicionar mais algum item ao carrinho? <s>im ou <n>ão" << endl;
    cin >> novo;
    if(novo == 's'){
      system("clear");
      menu();
      cout << "O valor do seu pedido atual é de: R$ " << *valorpedido << endl;
      cin >> categ;
    }
  } while (novo == 's'); 
  if(*valorpedido > 0){
    pagamento(valorpedido, total);
  }
  
}

// menu de administrador do sistema
void administrador(int senha, int *shutd, float *total) {
  char adm, reposi;
  int categ, repos,item, i, j, qnt;
  float potencial = 0;
  system("clear");
  cout << "Digite a senha do administrador: ";
  cin >> senha;
  if (senha == passw){
    do{
      system("clear");
      cout << "Menu administrador:" << endl;
      cout << "1 - Inventário" << endl;
      cout << "2 - Reposição de estoque" << endl;
      cout << "3 - Faturamento atual da máquina" << endl;
      cout << "4 - Potencial de faturamento da máquina" << endl;
      cout << "5 - Iniciar a máquina no modo de usuário" << endl;
      cout << "6 - Alterar senha" << endl;
      cout << "0 - Desligar máquina" << endl;
      cin >> categ;
      
      //inventário
      if(categ == 1){
        system("clear");
        cout << "Inventário: " << endl;
        for(i = 0; i<4; i++){
          for(j = 0; j<3; j++){
            cout << "Item: " << estoque[i][j].itens << " - Quantidade: " << estoque[i][j].quantidade << endl;
          }
          cout << "\n";
        }
        skip();
      }

      //reposição
      if(categ == 2){
        do{
          system("clear");
          menu();
          cin >> repos;
          system("clear");
          cout << "Digite o produto para repor o estoque: " << endl;
          for(i = 0; i < 3; i++){
            cout << i+1 << " " << estoque[repos-1][i].itens << endl;
          }
          cin >> item;
          cout << "Você deseja repor o item " << estoque[repos-1][item-1].itens << endl;
          cout << "Qual a quantidade que deseja repor? " << endl;
          cin >> qnt;
          estoque[repos-1][item-1].quantidade += qnt;
          cout << "A nova quantidade em estoque do item " << estoque[repos-1][item-1].itens << " é de " << estoque[repos-1][item-1].quantidade << endl;

          cout << "Deseja repor mais itens? <s>im ou <n>ão? ";
          cin >> reposi;
        } while (reposi == 's');
      }

      //faturamento atual
      if(categ == 3){
        system("clear");
        cout << "O faturamento atual da máquina é de:  R$ " << *total << endl;
        skip();
      }

      //potencial faturamento
      if(categ == 4){
        system("clear");
        for(i=0; i<4;i++){
          for(j=0;j<3;j++){
            potencial += estoque[i][j].quantidade * estoque[i][j].valores;
          }
        }
        cout << "O valor que a máquina ainda pode faturar é de: R$ " << potencial << endl;
        skip();
      }

      if(categ == 5) {
        adm = 'n';
      }

      //alterar senha
      if(categ == 6){
        system("clear");
        cout << "Digite a nova senha: ";
        cin >> passw;
        cout << "Senha alterada com sucesso!" << endl;
        skip();
      }

      //desligar máquina
      if(categ == 0){
        *shutd = 0;
        adm = 'n';
      }

      if(categ >=7 || categ < 0) {
        cout << "Opção inválida!" << endl;
        skip();
      }

      if(categ != 0 && categ != 5){
        cout << "Deseja continuar no menu de administrador? <s>im ou <n>ão? ";
        cin >> adm;
      }
    }while (adm =='s');
  }
  else {
    cout << "Senha incorreta!" << endl;
  }
}