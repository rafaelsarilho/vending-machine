void skip(){
  cout << "Pressione enter para continuar..." << endl;
  getchar();
  getchar();
}

void menu() {
  cout << "Digite a categoria desejada: " << endl;
  cout << "1 - Salgadinhos" << endl;
  cout << "2 - Lanches naturais" << endl;
  cout << "3 - Bebidas" << endl;
  cout << "4 - Doces" << endl;
}
void pedido() {
  
}

// menu de administrador do sistema
void administrador(int senha, int *shutd) {
  char adm;
  int menu, repos, i, j, qnt;
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

        skip();

      }

      //potencial faturamento
      if(menu == 4){
        system("clear");

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
      }
      if(menu >=7 || menu < 0) {
        cout << "Opção inválida!" << endl;
        skip();
      }

      cout << "Deseja continuar no menu de administrador? <s>im ou <n>ão?";
      cin >> adm;
    }while (adm =='s');
  }
  else {
    cout << "Senha incorreta!" << endl;
  }
}