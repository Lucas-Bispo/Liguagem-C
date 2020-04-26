#include<stdio.h>//biblioteca para entrada e saída de dados
#include<stdlib.h>//manipulação de memória

typedef struct st_no{//declaração de estrutura com definição de tipo atraves do typedef
    int valor;
    struct st_no *prox,*anter;//ponteiros para a propria estrutura
}NO;//nome do novo tipo de dado
void inserir_no_inicio(NO *inicio,NO **final){//
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));//alocação de memória no tamanho de NO
    printf("\nDigite um valor para inserir no inicio\n");
    scanf("%d",&novo->prox);
    novo->prox = inicio->prox;//por que inicio->prox está apontando para NULL
    novo->anter = inicio;
    if (inicio->prox != NULL)
    inicio->prox->anter = novo;

    else
    *final = novo;

    inicio->prox = novo;
}
void inserir_no_final(NO **final){
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    printf("\nDigite um valor para inserir no final\n");
    scanf("%d",&novo->prox);
    novo->prox = (*final)->prox;
    novo->anter = *final;
    (*final)->prox = novo;
    *final = novo;
}
void deletar(int valor2, NO *inicio){
    NO *busca;
    for (busca = inicio->prox; busca != NULL; busca = busca->prox){
        if(busca->valor == valor2){
            busca->anter->prox = busca->prox;
            if (busca->anter != NULL){
                inicio->prox->anter = busca->anter;
                free(busca);
                break;
            }
        }
    }
}
void buscar(NO *inicio){
    NO *aux;
    int valor_busca;
    printf("Informe o valor a ser buscado:");
    scanf("%d",&valor_busca);
    for(aux = inicio->prox; aux != NULL; aux = aux->prox){
        if(aux->valor == valor_busca){
            printf("Valor encontrado %d.",aux->valor);
        }
        else if (aux->prox == NULL){
            printf("Valor nao encontrado");
        }
    }

}
void listar_do_inicio(NO *inicio){
    NO *aux;
    for(aux = inicio->prox; aux != NULL; aux = aux->prox)
    printf ("%d ",aux->valor);
}
void listar_do_final(NO *final){
    NO *buscaa;
    for (buscaa = final; buscaa != NULL; buscaa = buscaa->anter){
        if (buscaa->anter == NULL){
            break;
        }
        else
        printf("%d ",buscaa->valor);
    }
}
int main() {
    NO *inicio,*final;//esses dois ponteiros são a lista e
    //ao mesmo tempo eles são a referência da lista ou se preferir 
    //eles são a lista porém com nome diferente.
    int escolha,valor;
    inicio = (NO*)malloc(sizeof(NO));
    inicio->prox = NULL;//inicialização da lista
    inicio->anter = NULL;

    do{
        printf("[1]-Inserir elemento no inicio\n[2]-Inserir elemento no final\n[3]-Imprimir do inicio\n[4]-Imprimir do final\n[5]-Buscar elemento\n[6]-Deletar elemento\n[-1]- Sair:");
        scanf("%d",&escolha);
        switch (escolha){
            case 1:{
            inserir_no_inicio(inicio,&final);
            break;
            }
            case 2:{
                inserir_no_final(&final);
                break;
            }
            case 3:{
                printf("\nListando valores do inicio\n");
                listar_do_inicio(inicio);
                break;
            }
            case 4:{
                printf("Listando do final\n");
                listar_do_final(final);
            }
            case 5:{
                buscar(inicio);
                break;
            }
            case 6:{
                printf("\nDigite um valor para deletar\n");
                scanf("%d",&valor);
                deletar(valor,inicio);
            }
            case -1:{
            free(inicio);
            break;
			}
        default:
            break;
        }

    }while(escolha != -1);

    return 0;
}
