typedef struct {
    string itens;
    float valores;
    int quantidade;
} catalogo;
    
    //catalogo de estoque, divididos entre salgadinhos, lanches, bebidas e doces
    catalogo estoque[4][3] = {{{"1. Doritos - R$ 5,00", 5, 10}, {"2. Fatekitos - R$3,50", 3.50, 10}, {"3. Ruffles - R$5,00", 5, 10}},
    {{"1. Lanche de Frango - R$5,00", 5, 10}, {"2. Lanche de Presunto e Queijo - R$4,00", 5, 10}, {"3. Lanche de Peito de Peru - R$5,00", 5, 10}},
    {{"1. Coca-Cola - R$4,50", 4.5, 10}, {"2. Água - R$3,00", 3, 10}, {"3. Del Valle - R$4,00", 4, 10}},
    {{"1. Kit Kat - R$3,00", 3, 10}, {"2. Choquito - R$2,00", 2, 10}, {"3. Prestígio - R$2,00", 2, 10}}};
