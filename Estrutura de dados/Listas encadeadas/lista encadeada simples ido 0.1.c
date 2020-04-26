#include<stdio.h>
#include<stdlib.h>//Biblioteca que permite trabalhar com a memória.
typedef struct st_no{//redefinição do tipo de dado para NO.
    int num;
    struct st_no *prox;/*ponteiro para direcionamento para a estrutura 
    que tem a variável mais um ponteiro para a própria estrutura.*/
}NO;//tipo de dado redefinido.
//função que criar um nó
NO *criar_no(){//fução que retorna um ponteiro.
    NO *novo = (NO*)malloc(sizeof(NO));//retorna um ponteiro do tipo void.
    //porém é preciso fazer um cast, conversão do ponteiro vazio para o tipo NO.
    return novo;// retorno de ponteiro
}
NO *inserir_Inicio(NO *lista,int valor){//recebe ponteiro como argumento e o valor
//porém pode fazer de outra maneira.
   NO *novo_no = criar_no();//chamada de função para criar e retornar um nó.
   novo_no->num = valor;//passagem de valor para a variável num dentro da estrutura.
   if (lista == NULL){//caso a lista esteja vazia, que no caso é quando é a primeira vez 
   //que ela será inicializada, que será realizada uma vez. 
       lista = novo_no;// recebe o endereço que está apontando para a alocação de memória criada.
       novo_no->prox = NULL;//direcionamento de ponteiro.
    }
   else{//após a lista passar pela inicialização na condição acima, acionará apenas o else
       novo_no->prox = lista;// por se tratar de uma inserção no início, novo->prox recebe a lista(//novo elemento no campo proximo 
       //aponta para onde a lista apontava.)
       //que por sua voz recebeu a alocação de memória que foi criada pela função criar, 
       lista = novo_no;// vai apontar ao novo elemento que foi criado.
    }
   return lista;//retorno da lista.
}
//rever a logica de inserção de elementos.
NO *inserir_fim(NO *lista,int dado){//recebe um ponteiro mais um valor são os parâmetros
    NO *no = (NO*)malloc(sizeof(NO));//recebe alocação de memória feita por malloc,é feito cast 
    // e o endereço é passado ao ponteiro no.
    no->num = dado;//recebe o valor que vem no parâmetro.
    if(lista == NULL){//essa condição sempre acontecerá pelo menos uma vez.
        no->prox = NULL;//o campo prox aponta para NULL
        lista = no; //lista aponta para o novo elemento que foi inserido na lista.
    }
    else{//para chegar realizar a inserção no fim, devesse realizar uma busca pelo campo NUUL
        NO *aux = lista;//é preciso criasse variáveis auxiliares para não perder a referência da lista.
        while (aux->prox != NULL){// da para fazer com for.
            aux = aux->prox;
        } //quando encontra NULL, o redirecionamento dos ponteiros são realizados
        no->prox = NULL;//o campo prox do novo elemento aponta para NULL
        aux->prox = no;// e aux que apontava para NULL aponta para o elemnto que será inserido.
    }
    return lista;// a lista é retornada
}

NO *busca(NO *lista, int valor){//função que retorna o ponteiro encontrado na busca.
    NO *aux = lista;//é preciso criar uma variável auxiliar.
    //passa o endereço da lista para aux e realiza a busca.
    while(aux->prox != NULL){//enquanto aux não encontra NULL 
        if(aux->num == valor){//a comparação entre o valor e os valores que estão na lista em num.
        return aux;//retorno do valor encontrado.
        }
        aux = aux->prox;//incremento 
    }
}

NO *deletar(NO *lista,int valor){
    NO *anterior,*proximo;
    proximo = lista->prox;//endereço passado para o proximo.
    anterior = lista;//mesma coisa acontece aqui pois é preciso criar auxiliares para não 
    //para não perder a lista.
    if (anterior->num == valor){//exceção caso o valor esteja no início.
        lista = proximo;//ajuste de ponteiro, pois proximo está com endereço de lista->prox.
        printf("Valor apagado pois se encontra no inicio da lista.\n");
        free(anterior);//liberação de memória.
    }
    while (proximo != NULL){//caso não esteja no início devesse realizar uma busca
        if(proximo->num == valor){//vereficação para encontrar o valor
           anterior->prox = proximo->prox;//ajuste de ponteiros para liberar a memória para que 
           //o elemento anterior ao que foi encontrado aponte para o ponteiro que aponto o elemento depois
           //do que foi encontrado.
           printf("Valor deletado\n");
           free(proximo);//assim devesse liberar memória no campo proximo e não, proximo->prox
        }//rever lógica de reajusta.
        anterior = proximo;// reajuste de ponteiro para que ao percorrer a lista possa realizar a lógica de remoção.
        proximo = proximo->prox;//incremento 
    }
    return lista;//lista retornada.

}

void imprimir_Lista(NO *lista){//recebe a lista 
    NO *aux;//auxiliar 
    for (aux = lista; aux != NULL; aux = aux->prox){//percorre a lista 
    //aux recebe o endereço da lista, enquanto diferente NULL,e incremento.
        printf("|%d|->",aux->num);//imprime a lista.
    }
}

int main() {
    int escolha,valor;
    //inicialização da lista, podesse criar função.
    NO *lista = NULL;// e é tambem,*respostaBusca;
    do{//menu de interação com usuário
        printf("[1]-Inserir elemento\n[2]-Inserir no fim\n[3]-Busca de elementos\n[4]-Deletar elementos\n[5]-Imprimir lista\n[-1]-sair\n");
        scanf("%d",&escolha);
        switch (escolha){//analise de casos de acordo com o que o usuário digitar.
            case 1:{
                printf("Digite o valor a colocar na lisrta:");
                scanf("%d",&valor);
                lista = inserir_Inicio(lista,valor);//por ser um função com retorno devesse jogar o retorno, ao mesmo tempo a função realizada.
                break;//quebra de sequência de comandos 
            }
            case 2:{
                printf("Digite o valor a colocar na lisrta:");
                scanf("%d",&valor);
                lista = inserir_fim(lista,valor);//as variáveis que são passadas como argumentos por mais que tenham o mesmo nome 
                //não tem o endereço iguais
                break;//quebra de sequência de comandos
            }
            case 3:{
                printf("Digite o valor para buscar:");
                scanf("%d",&valor);
                respostaBusca = busca(lista,valor);
                printf("Valor encontrado %d\n",respostaBusca->num);//como a resposta foi retornada o procedimento de impressão com struct
                //e ponteiros é usando -> "seta".
                break;//quebra de sequência de comandos
            }
            case 4:{//o mesmo se aplica em relação a função, retorno,parâmetros
                printf("Digite o valor para deletar:");
                scanf("%d",&valor);
                lista = deletar(lista,valor);
                break;
            }
            case 5:{
            	imprimir_Lista(lista);
				break;
			}
            case -1:
            free(lista);//liberação de memória por questão de segurança
            default://encerramento de programa 
            break;
        }
    }while (escolha != -1);
    
    return 0;
}

