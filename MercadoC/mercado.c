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


static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main(){
    menu();
    return 0;
}

void infoProduto(Produto prod){
    printf("Código: %d \nNome: %s\nPreço: %.2f\n", prod.codigo,strtok(prod.nome, "\n"),prod.preco);
}