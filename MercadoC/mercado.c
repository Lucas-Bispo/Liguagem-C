#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //no linux ou mac
//#include <windons.h>

typedef struct  
{
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct
{
    Produto produto;
    int quantidade;
} Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNOCArrinho(int codigo);
void fecharPedido();
