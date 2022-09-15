void skip(){
  cout << "Pressione enter para continuar..." << endl;
  getchar();
  getchar();
}

// categoria de lanches
void menu() {
  system("clear");
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
      case 3: {
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

      case 4: {
        cout << "Pedido cancelado!" << endl;
        skip();
        system("clear");
        verifpg = 1;
        *valorpedido = 0;
        break;
      }

      default: {
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
  int qnt = 0;
  char novo = 's';
  int i, j;
  float valor = 0;
  system("clear");
  do {
    switch (categ) {
        case 1: {
          system("clear");
          cout << "Escolha o produto: " << endl;
          for(i = 0; i < 3; i++){
            cout << i+1 << " " << estoque[categ-1][i].itens << endl;
          }
          cin >> categ;
          cout << "Você escolheu o item: " << estoque[0][categ-1].itens << ". Ele custa: R$ " << estoque[0][categ-1].valores << endl;
          cout << "Existem " << estoque[0][categ-1].quantidade << " itens disponíveis no para compra" << endl;
          cout << "Quantos você quer comprar? " << endl;
          cin >> qnt;
          if(qnt <= estoque[0][categ-1].quantidade){
            *valorpedido += qnt*estoque[0][categ-1].valores;
            cout << "O valor total do seu pedido é: R$ " << *valorpedido << endl;
            estoque[0][categ-1].quantidade -= qnt;
          }
          else {
            cout << "Quantidade inválida!" << endl;
          }
          break;
        }

        case 2: {
          system("clear");
          cout << "Escolha o produto: " << endl;
          for(i = 0; i < 3; i++){
            cout << i+1 << " " << estoque[categ-1][i].itens << endl;
          }
          cin >> categ;
          cout << "Você escolheu o item: " << estoque[1][categ-1].itens << ". Ele custa: R$ " << estoque[1][categ-1].valores << endl;
          cout << "Existem " << estoque[1][categ-1].quantidade << " itens disponíveis no para compra" << endl;
          cout << "Quantos você quer comprar? " << endl;
          cin >> qnt;
          if(qnt <= estoque[1][categ-1].quantidade){
            *valorpedido += qnt*estoque[1][categ-1].valores;
            cout << "O valor total do seu pedido é: R$ " << *valorpedido << endl;
            estoque[1][categ-1].quantidade -= qnt;
          }
          else {
            cout << "Quantidade inválida!" << endl;
          }
          break;
        }

        case 3: {
          system("clear");
          cout << "Escolha o produto: " << endl;
          for(i = 0; i < 3; i++){
            cout << i+1 << " " << estoque[categ-1][i].itens << endl;
          }
          cin >> categ;
          cout << "Você escolheu o item: " << estoque[2][categ-1].itens << ". Ele custa: R$ " << estoque[2][categ-1].valores << endl;
          cout << "Existem " << estoque[2][categ-1].quantidade << " itens disponíveis no para compra" << endl;
          cout << "Quantos você quer comprar? " << endl;
          cin >> qnt;
          if(qnt <= estoque[2][categ-1].quantidade){
            *valorpedido += qnt*estoque[2][categ-1].valores;
            cout << "O valor total do seu pedido é: R$ " << *valorpedido << endl;
            estoque[2][categ-1].quantidade -= qnt;
          }
          else {
            cout << "Quantidade inválida!" << endl;
          }
          break;
        }

        case 4: {
          system("clear");
          cout << "Escolha o produto: " << endl;
          for(i = 0; i < 3; i++){
            cout << i+1 << " " << estoque[categ-1][i].itens << endl;
          }
          cin >> categ;
          cout << "Você escolheu o item: " << estoque[3][categ-1].itens << ". Ele custa: R$ " << estoque[3][categ-1].valores << endl;
          cout << "Existem " << estoque[3][categ-1].quantidade << " itens disponíveis no para compra" << endl;
          cout << "Quantos você quer comprar? " << endl;
          cin >> qnt;
          if(qnt <= estoque[3][categ-1].quantidade){
            *valorpedido += qnt*estoque[3][categ-1].valores;
            cout << "O valor total do seu pedido é: R$ " << *valorpedido << endl;
            estoque[3][categ-1].quantidade -= qnt;
          }
          else {
            cout << "Quantidade inválida!" << endl;
          }
          break;
        }

        default: {
          system("clear");
          cout << "Categoria inválida!" << endl;
          break;
        }
      }
      cout << "Deseja adicionar mais algum item ao carrinho? <s>im ou <n>ão" << endl;
      cin >> novo;
      if(novo == 's'){
        system("clear");
        menu();
        cout << "O valor do seu pedido atual é de: R$ " << *valorpedido << endl;
        cin >> categ;
      }
  } while (novo == 's'); 
  pagamento(valorpedido, total);
}

// menu de administrador do sistema
void administrador(int senha, int *shutd, float *total) {
  char adm;
  int menu, repos, i, j, qnt;
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
      cin >> menu;
      
      //inventário
      if(menu == 1){
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
      if(menu == 2){
        system("clear");
        cout << "Menu de reposição" << endl;
        cout << "Categorias:" << endl;
        cout << "1 - Salgadinhos" << endl;
        cout << "2- Lanches naturais" << endl;
        cout << "3 - Bebidas" << endl;
        cout << "4 - Doces" << endl;
        cin >> repos;

        switch (repos) {
          case 1: { // repor categoria salgadinhos
            cout << "Digite o produto para repor o estoque: " << endl;
            for(i = 0; i < 3; i++){
              cout << i+1 << " " << estoque[repos-1][i].itens << endl;
            }
            cin >> repos;
            cout << "Você deseja repor o item " << estoque[0][repos-1].itens << endl;
            cout << "Qual a quantidade que deseja repor? " << endl;
            cin >> qnt;
            estoque[0][repos-1].quantidade += qnt;
            cout << "A nova quantidade em estoque do item " << estoque[0][repos-1].itens << " é de " << estoque[0][repos-1].quantidade << endl;
            break;
          }

          case 2: { //repor categoria lanches naturais
            cout << "Digite o produto para repor o estoque: " << endl;
            for(i = 0; i < 3; i++){
              cout << i+1 << " " << estoque[repos-1][i].itens << endl;
            }
            cin >> repos;
            cout << "Você deseja repor o item " << estoque[1][repos-1].itens << endl;
            cout << "Qual a quantidade que deseja repor? " << endl;
            cin >> qnt;
            estoque[1][repos-1].quantidade += qnt;
            cout << "A nova quantidade em estoque do item " << estoque[1][repos-1].itens << " é de " << estoque[1][repos-1].quantidade << endl;
            break;
          }

          case 3: { //repor categoria bebidas
            cout << "Digite o produto para repor o estoque: " << endl;
            for(i = 0; i < 3; i++){
              cout << i+1 << " " << estoque[repos-1][i].itens << endl;
            }
            cin >> repos;
            cout << "Você deseja repor o item " << estoque[2][repos-1].itens << endl;
            cout << "Qual a quantidade que deseja repor? " << endl;
            cin >> qnt;
            estoque[2][repos-1].quantidade += qnt;
            cout << "A nova quantidade em estoque do item " << estoque[2][repos-1].itens << " é de " << estoque[2][repos-1].quantidade << endl;            
            break;
          }

          case 4: {
            cout << "Digite o produto para repor o estoque: " << endl;
            for(i = 0; i < 3; i++){
              cout << i+1 << " " << estoque[repos-1][i].itens << endl;
            }
            cin >> repos;
            cout << "Você deseja repor o item " << estoque[3][repos-1].itens << endl;
            cout << "Qual a quantidade que deseja repor? " << endl;
            cin >> qnt;
            estoque[3][repos-1].quantidade += qnt;
            cout << "A nova quantidade em estoque do item " << estoque[3][repos-1].itens << " é de " << estoque[3][repos-1].quantidade << endl;
            break;
          }

          default: {
            cout << "Opção inválida!" << endl;
            break;
          }
        }
        skip();
      }

      //faturamento atual
      if(menu == 3){
        system("clear");
        cout << "O faturamento atual da máquina é de:  R$ " << *total << endl;
        skip();
      }

      //potencial faturamento
      if(menu == 4){
        system("clear");
        for(i=0; i<4;i++){
          for(j=0;j<3;j++){
            potencial += estoque[i][j].quantidade * estoque[i][j].valores;
          }
        }
        cout << "O valor que a máquina ainda pode faturar é de: R$ " << potencial << endl;
        skip();
      }

      //alterar senha
      if(menu == 6){
        system("clear");
        cout << "Digite a nova senha: ";
        cin >> passw;
        cout << "Senha alterada com sucesso!" << endl;
        skip();
      }

      //desligar máquina
      if(menu == 0){
        *shutd = 0;
        adm = 'n';
      }

      if(menu >=7 || menu < 0) {
        cout << "Opção inválida!" << endl;
        skip();
      }

      if(menu != 0 && menu != 5){
        cout << "Deseja continuar no menu de administrador? <s>im ou <n>ão? ";
        cin >> adm;
      }
    }while (adm =='s');
  }
  else {
    cout << "Senha incorreta!" << endl;
  }
}