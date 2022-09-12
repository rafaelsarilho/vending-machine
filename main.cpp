/*
O usuário pode acessar o menu administrador entrando com o código de acesso 0,
no menu de categorias, a senha padrão de acesso é 123, podendo ser alterada
quando quiser.
*/
#include <iostream>

using namespace std;

int main() {
	// Declarando variáveis
	float somapedido = 0, somatotal = 0, troco = 0, dinheiro = 0,
		  faturamento = 0, fpotencial = 0, somafpotencial;
	int senha, produto, categoria, quantidade, i, formpag, senhac, menuadm, j,
		verificapag, cartao, novopedcat, verificaestoque,
		menuadministrador = 1, novopedido = 1, reposicao = 1,
		verificasenha = 123;

	// Matriz criada para elaboração do cardápio
	// Primeira coluna (0): categorias de produtos;
	// Colunas 1, 2 e 3: produtos de acordo com as categorias
	string nomes[4][4] = {{"1. Salgadinhos;",
						   "1. Doritos - R$ 5,00",
						   "2. Fatekitos - R$3,50",
						   "3. Ruffles - R$5,00"},
						  {"2. Lanches;",
						   "1. Lanche de Frango - R$5,00",
						   "2. Lanche de Presunto e Queijo - R$4,00",
						   "3. Lanche de Peito de Peru - R$5,00"},
						  {"3. Bebidas;",
						   "1. Coca-Cola - R$4,50",
						   "2. Água - R$3,00",
						   "3. Del Valle - R$4,00"},
						  {"4. Doces.",
						   "1. Kit Kat - R$3,00",
						   "2. Choquito - R$2,00",
						   "3. Prestígio - R$2,00"}};

	// Matriz criada para precificar os produtos
	// Primeira coluna (0): apenas para sobrepor a coluna das categorias -
	// coluna null Colunas 1, 2 e 3: valor dos produtos de acordo com as
	// categorias
	float valores[4][4] = {{0, 5.00, 3.50, 5.00},
						   {0, 5.00, 4.00, 5.00},
						   {0, 4.50, 3.00, 4.00},
						   {0, 3.00, 2.00, 2.00}};

	// Matriz para definir a quantidade incial de produtos na máquina
	int estoque[4][4] = {
		{0, 10, 10, 10}, {0, 10, 10, 10}, {0, 10, 10, 10}, {0, 10, 10, 10}};

	cout << "\n\t Digite 0 para entrar no modo administrador, senha padrão "
			"para acesso: 123.\n\t (esta opção ficaria oculta do usuário)\n"
		 << endl;

	do {
		cout << "\nMENU " << endl;
		cout << "\nDigite o número da categoria desejada: \n " << endl;

		// Exibir categorias da matriz
		for (i = 0; i < 4; i++) {
			cout << nomes[i][0] << endl;
		}

		// escolha do produto de acordo com a categoria selecionada
		cin >> categoria;

		if (categoria >= 1 || categoria <= 4) {
			novopedcat = 1;
		}
		if (categoria < 0 || categoria > 4) {
			do {
				cout << "\n\nMENU\n " << endl;
				cout << "Digite uma categoria válida!" << endl;
				// Exibir categorias da matriz

				for (i = 0; i < 4; i++) {
					cout << nomes[i][0] << endl;
				}

				// escolha do produto de acordo com a categoria selecionada
				cin >> categoria;
			} while (categoria >= 5 || categoria <= 0);
		}

		// ADMINISTRADOR
		// if dos comandos do administrador
		if (categoria == 0) {
			cout << "Insira sua senha:" << endl;
			cin >> senha;
			if (senha != verificasenha) {
				cout << "Última tentativa para inserir a senha! \nCaso a senha "
						"esteja incorreta a máquina retornará para o menu "
						"principal."
					 << endl;
				cin >> senha;
			}
			if (senha != verificasenha) {
				menuadministrador = 2;
				novopedcat = 0;
			}

			if (senha == verificasenha) {
				do {
					novopedido = '1';
					cout << "\nMenu do administrador\n" << endl;
					cout << "Selecione uma opção desejada: " << endl;
					cout << " 1. Inventário; \n 2. Reposição; \n 3. "
							"Faturamento; \n 4. Potencial de faturamento; \n "
							"5. Iniciar máquina no modo de usuário; \n 6. "
							"Desligar máquina; \n 7. Alterar senha.\n "
						 << endl;
					cin >> menuadm;
					if (menuadm == 1) {
						cout << "\nEstoque\n" << endl;
						for (i = 0; i < 4; i++) {
							for (int j = 1; j < 4; j++) {
								cout << "Produto: " << nomes[i][j]
									 << ". Quantidade: " << estoque[i][j]
									 << endl;
							}
						}
						cout << "Deseja continuar no modo administrador? SIM "
								"(1), NÃO (2)"
							 << endl;
						cin >> menuadministrador;

						system("clear");
					}
					if (menuadm == 2) {
						do {
							cout << "Selecione o produto que deseja repor o "
									"estoque"
								 << endl;
							for (i = 0; i < 4; i++) {
								cout << nomes[i][0] << endl;
							}
							cin >> categoria;
							if (categoria == 1) {
								for (i = 0; i < 4; i++) {
									cout << nomes[0][i] << endl;
								}
								cin >> produto;
								cout << "Digite quantas unidades irão ser "
										"repostas no estoque"
									 << endl;
								cin >> quantidade;
								estoque[0][produto] =
									estoque[0][produto] + quantidade;
							}
							if (categoria == 2) {
								for (i = 0; i < 4; i++) {
									cout << nomes[1][i] << endl;
								}
								cin >> produto;
								cout << "Digite quantas unidades irão ser "
										"repostas no estoque"
									 << endl;
								cin >> quantidade;
								estoque[1][produto] =
									estoque[1][produto] + quantidade;
							}
							if (categoria == 3) {
								for (i = 0; i < 4; i++) {
									cout << nomes[2][i] << endl;
								}
								cin >> produto;
								cout << "Digite quantas unidades irão ser "
										"repostas no estoque"
									 << endl;
								cin >> quantidade;
								estoque[2][produto] =
									estoque[2][produto] + quantidade;
							}
							if (categoria == 4) {
								for (i = 0; i < 4; i++) {
									cout << nomes[3][i] << endl;
								}
								cin >> produto;
								cout << "Digite quantas unidades irão ser "
										"repostas no estoque"
									 << endl;
								cin >> quantidade;
								estoque[3][produto] =
									estoque[3][produto] + quantidade;
							}
							cout << "Deseja repor mais itens? SIM (1), NÃO (2)."
								 << endl;
							cin >> reposicao;
						} while (reposicao == 1);
						cout << "Deseja continuar no modo administrador? SIM "
								"(1), NÃO (2)"
							 << endl;
						cin >> menuadministrador;
						categoria = 6;
						system("clear");
					}

					if (menuadm == 3) {
						cout << "O faturamento atual da máquina é de: R$ "
							 << faturamento << endl;
						cout << "Deseja continuar no modo administrador? SIM "
								"(1), NÃO (2)"
							 << endl;
						cin >> menuadministrador;
						system("clear");
					}

					if (menuadm == 4) {
						for (i = 0; i < 4; i++) {
							for (j = 0; j < 4; j++) {
								fpotencial = (estoque[i][j] * valores[i][j]);
								somafpotencial = somafpotencial + fpotencial;
							}
						}
						cout << "A máquina ainda pode faturar: R$"
							 << somafpotencial << endl;
						somafpotencial = 0;
						fpotencial = 0;
						cout << "Deseja continuar no modo administrador? SIM "
								"(1), NÃO (2)"
							 << endl;
						cin >> menuadministrador;
						system("clear");
					}
					if (menuadm == 5) {
						menuadministrador = 2;
						system("clear");
					}
					if (menuadm == 6) {
						return 0;
					}
					if (menuadm == 7) {
						cout << "Insira uma nova senha (numérica): " << endl;
						cin >> verificasenha;
					}
					if (menuadm >= 8 || menuadm <= 0) {
						cout << "Digite uma opção válida!" << endl;
						cout << "Deseja continuar no modo administrador? SIM "
								"(1), NÃO (2)"
							 << endl;
						cin >> menuadministrador;
						system("clear");
					}
					verificapag = 0;
					novopedcat = 0;
				} while (menuadministrador == 1);
			}
		}
		// fim do if do administrador

		// CLIENTE
		// categoria de produtos

		while (novopedcat == 1) {
			if (categoria == 1) {
				cout << "Digite o número do produto desejado: " << endl;
				for (i = 1; i < 4; i++) {
					cout << nomes[0][i] << endl;
				}
				// Receber o produto escolhido
				cin >> produto;
				if (produto >= 4 || produto <= 0) {
					do {
						cout << "\nComando inválido! Por favor insira abaixo "
								"um valor de acordo com o menu.\n"
							 << endl;
						cin >> produto;
					} while (produto <= 0 || produto >= 4);
				}
				cout << "Existem " << estoque[0][produto]
					 << " unidades deste produto. \n Digite a quantidade "
						"desejada: "
					 << endl;
				cin >> quantidade;
				// verificação da quantidade do produto no estoque
				if (estoque[0][produto] >= quantidade) {
					estoque[0][produto] = estoque[0][produto] - quantidade;
					somapedido = valores[0][produto] * quantidade;
					somatotal += somapedido;
					somapedido = 0;
					verificapag = 1;
				} else { // mensagem de erro caso não haja a quantidade do
						 // produto na máquina
					cout << "\n A quantidade informada é maior que o estoque."
						 << endl;
					verificapag = 0;
					verificaestoque = 0;
				}
			}

			if (categoria == 2) {
				cout << "Digite o número do produto desejado: " << endl;
				for (i = 1; i < 4; i++) {
					cout << nomes[1][i] << endl;
				}
				// Receber o produto escolhido
				cin >> produto;
				if (produto >= 4 || produto <= 0) {
					do {
						cout << "\nComando inválido! Por favor insira abaixo "
								"um valor de acordo com o menu.\n"
							 << endl;
						cin >> produto;
					} while (produto <= 0 || produto >= 4);
				}
				cout << "Existem " << estoque[1][produto]
					 << " unidades deste produto. \n Digite a quantidade "
						"desejada: "
					 << endl;
				cin >> quantidade;
				// verificação da quantidade do produto no estoque
				if (estoque[1][produto] >= quantidade) {
					estoque[1][produto] = estoque[1][produto] - quantidade;
					somapedido = valores[1][produto] * quantidade;
					somatotal += somapedido;
					somapedido = 0;
					verificapag = 1;

				} else { // mensagem de erro caso não haja a quantidade do
						 // produto na máquina
					cout << "\n A quantidade informada é maior que o estoque."
						 << endl;
					verificapag = 0;
					verificaestoque = 0;
				}
			}

			if (categoria == 3) {
				cout << "Digite o número do produto desejado: " << endl;
				for (i = 1; i < 4; i++) {
					cout << nomes[2][i] << endl;
				}
				// Receber o produto escolhido
				cin >> produto;
				if (produto >= 4 || produto <= 0) {
					do {
						cout << "\nComando inválido! Por favor insira abaixo "
								"um valor de acordo com o menu.\n"
							 << endl;
						cin >> produto;
					} while (produto <= 0 || produto >= 4);
				}
				cout << "Existem " << estoque[2][produto]
					 << " unidades deste produto. \n Digite a quantidade "
						"desejada: "
					 << endl;
				cin >> quantidade;
				// verificação da quantidade do produto no estoque
				if (estoque[2][produto] >= quantidade) {
					estoque[2][produto] = estoque[2][produto] - quantidade;
					somapedido = valores[2][produto] * quantidade;
					somatotal += somapedido;
					somapedido = 0;
					verificapag = 1;

				} else { // mensagem de erro caso não haja a quantidade do
						 // produto na máquina
					cout << "\n A quantidade informada é maior que o estoque."
						 << endl;
					verificapag = 0;
					verificaestoque = 0;
				}
			}

			if (categoria == 4) {
				cout << "Digite o número do produto desejado: " << endl;
				for (i = 1; i < 4; i++) {
					cout << nomes[3][i] << endl;
				}
				// Receber o produto escolhido
				cin >> produto;
				if (produto >= 4 || produto <= 0) {
					do {
						cout << "\nComando inválido! Por favor insira abaixo "
								"um valor de acordo com o menu.\n"
							 << endl;
						cin >> produto;
					} while (produto <= 0 || produto >= 4);
				}
				cout << "Existem " << estoque[3][produto]
					 << " unidades deste produto. \n Digite a quantidade "
						"desejada: "
					 << endl;
				cin >> quantidade;
				// verificação da quantidade do produto no estoque
				if (estoque[3][produto] >= quantidade) {
					estoque[3][produto] = estoque[3][produto] - quantidade;
					somapedido = valores[3][produto] * quantidade;
					somatotal += somapedido;
					somapedido = 0;
					verificapag = 1;

				} else { // mensagem de erro caso não haja a quantidade do
						 // produto na máquina
					cout << "\n A quantidade informada é maior que o estoque."
						 << endl;
					verificapag = 0;
					verificaestoque = 0;
				}
			}

			cout << "(1) Deseja continuar pedindo; \n(2) Encerrar o pedido"
				 << endl;
			cin >> novopedcat;
			if (novopedcat == 2) {
				verificapag = 1;
			}
			if (novopedcat == 1) {
				for (i = 0; i < 4; i++) {
					cout << nomes[i][0] << endl;
				}

				// escolha do produto de acordo com a categoria selecionada
				cin >> categoria;
				if (categoria == 0) {
					cout << "Finalize o pedido primeiro para entrar no modo "
							"administrador"
						 << endl;
				}
				if (categoria < 0 || categoria >= 5) {
					cout << "Digite uma categoria válida" << endl;
					cin >> categoria;
				}
			}
			// caso usuario compre algo que nao tenha no estoque, o programa irá
			// direto para o pagamento
			if (verificaestoque == 0) {
				verificapag = 1;
			}
		}
		// fim da categoria de produtos

		// Pagamento
		if (somatotal > 0) {
			while (verificapag == 1) {
				cout << "Total do pedido: R$" << somatotal << endl;
				cout << "Forma de pagamento: \n 1. Dinheiro; \n 2. Cartão."
					 << endl;
				cin >> formpag;
				// verificacao de forma de pagamento errada
				if (formpag < 1 || formpag > 2) {
					do {
						cout << "Digite uma forma de pagamento válida:" << endl;
						cin >> formpag;
					} while (formpag < 1 || formpag > 2);
				}
				if (formpag == 1) {
					cout << "Insira o valor na máquina. \n Digite o valor "
							"inserido no campo abaixo:"
						 << endl;
					cin >> dinheiro;

					if (dinheiro < somatotal) {
						do {
							cout << "Dinheiro devolvido!! \nPor favor, insira "
									"o valor de acordo com o pedido!"
								 << endl;
							cin >> dinheiro;
						} while (dinheiro < somatotal);
					}
					troco = dinheiro - somatotal;

					if (troco > 0) {
						cout << "Retire o seu troco: R$ " << troco << endl;
					}
					cout << "Retire o seu produto!\n" << endl;
				}
				if (formpag == 2) {
					cout << "Insira o cartão na máquina: \n Selecione o tipo "
							"de cartão: \n 1. Crédito; \n 2. Débito; \n 3. "
							"Alimentação."
						 << endl; // apenas para simular, não temos como acessar
								  // o mecanismo para processar o cartão e nem
								  // como verificar se o cartão foi inserido
					cin >> cartao;
					while (cartao >= 4 || cartao <= 0) {
						cout << "Opção inválida, selecione uma opção válida!"
							 << endl;
						cin >> cartao;
					}
					if (cartao <= 3 || cartao >= 1) {
						cout << "Insira a sua senha no teclado da maquininha:"
							 << endl;
						cin >> senhac;
						cout << "Processando ...\n...\n...\n..." << endl;
						cout << "Transação autorizada! \n\n Retire o seu "
								"produto!\n\n"
							 << endl;
					}
				}
				faturamento += somatotal;
				somatotal = 0;
				verificapag = 0;
			}
		}
		novopedido = 1;
	} while (novopedido == 1);
}