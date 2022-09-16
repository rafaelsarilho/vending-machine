typedef struct {
    string itens;
    float valores;
    int quantidade;
} catalogo;
    
    //catalogo de estoque, divididos entre salgadinhos, lanches, bebidas e doces
    catalogo estoque[4][3] = {{{"Doritos", 5, 10}, {"Fatekitos", 3.50, 10}, {"Ruffles", 5, 10}},
    {{"Lanche de Frango", 5, 10}, {"Lanche de Presunto e Queijo", 5, 10}, {"Lanche de Peito de Peru", 5, 10}},
    {{"Coca-Cola", 4.5, 10}, {"Água", 3, 10}, {"Del Valle", 4, 10}},
    {{"Kit Kat", 3, 10}, {"Choquito", 2, 10}, {"Prestígio", 2, 10}}};