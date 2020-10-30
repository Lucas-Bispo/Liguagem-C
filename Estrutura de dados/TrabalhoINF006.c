#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct st_no{
  int lp; 
  int tam;
  int peso;
  int gc;
  struct st_no *prox;
}NO;

NO *criar_no(){
  NO *novo = (NO*)malloc(sizeof(NO));
  return novo;
}

NO *inserir_Inicio(NO *lista, int lp2, int tam2, int peso2, int gc2){

  NO *novo_no = criar_no();

  //novo_no->num = valor;
  novo_no->lp = lp2;
  novo_no->tam = tam2;
  novo_no->peso = peso2;
  novo_no->gc = gc2;

  if (lista == NULL){
    lista = novo_no;
    novo_no->prox = NULL;
  }
  else{
    novo_no->prox = lista;
    lista = novo_no;
  }
  return lista;
}

NO *inserir_fim(NO *lista,int lp2, int tam2, int peso2, int gc2){

  NO *no = (NO*)malloc(sizeof(NO));
  //no->num = dado;
  no->lp = lp2;
  no->tam = tam2;
  no->peso = peso2;
  no->gc = gc2;
  
  if(lista == NULL){
    no->prox = NULL;
    lista = no; 
    }
  else{
    NO *aux = lista;
      
    while (aux->prox != NULL){
    aux = aux->prox;
    } 
      
    no->prox = NULL;
    aux->prox = no;
   
  }
  
  return lista;
}

NO *busca(NO *lista,int lp2, int tam2, int peso2, int gc2){

  NO *aux = lista;

  while(aux->prox != NULL){ 
    
    if((aux->lp == lp2) && (aux->tam == tam2) && (aux->peso == peso2) && (aux->gc == gc2)){
      
      return aux;      
      
    }
  
  aux = aux->prox;
  
  }
}

NO *deletar(NO *lista,int lp2, int tam2, int peso2, int gc2){
  NO *anterior,*proximo;
  proximo = lista->prox;
  anterior = lista;
  
  if ((anterior->lp == lp2) && (anterior->tam == tam2) && (anterior->peso == peso2) && (anterior->gc == gc2)){
    lista = proximo;
    
    printf("Valor apagado pois se encontra no inicio da lista.\n");
    free(anterior);
  }

  while (proximo != NULL){
    if((anterior->lp == lp2) && (anterior->tam == tam2) && (anterior->peso == peso2) && (anterior->gc == gc2)){

      anterior->prox = proximo->prox;
      printf("Valores Deletados\n");
      free(proximo);

      }

      anterior = proximo;
      proximo = proximo->prox;
    }
    return lista;

}

void imprimir_Lista(NO *lista){
  NO *aux;
  
  for (aux = lista; aux != NULL; aux = aux->prox){
    printf("Lp = %d|",aux->lp);
    printf("Tamanho = %d|",aux->tam);
    printf("Peso = %d|",aux->peso);
    printf("Gc = %d| ->",aux->gc);
    printf("\n");
  }
  printf("\n");
}

void linhaAlinha(NO *li){
  
  FILE *arq;
  int sLp2;
  int contador = 1;
  
  

  char nome[40], *resultado;

  arq = fopen("teste.txt", "r");

  if(arq){

    while(!feof(arq)){

      resultado = fgets(nome, 40, arq);
      
      if(resultado){
        //printf( " \n ");
        //printf("%s", nome);
        //printf("Conseguir caputurar a linha.");
        //printf( " \n");

        const char s[2] = ";";
        char *token;
   
        /* get the first token */
        token = strtok(nome, s);
   
        /* walk through other tokens */
        while( token != NULL ) {
          //printf( " %s\n", token );
          
          NO *no = (NO*)malloc(sizeof(NO));
          
          if(contador == 1){
          
          sLp2 = atoi(token);
          no->lp = sLp2;
          
          }
          else if(contador == 2){
          sLp2 = atoi(token);
          no->tam = sLp2;
          }
          else if(contador == 3){
          sLp2 = atoi(token);
          no->peso = sLp2;
          }
          else{
          sLp2 = atoi(token);
          no->gc = sLp2;
          }

          contador++;

          if(li == NULL){
          no->prox = NULL;
          li = no; 
          }
          else{
          NO *aux = li;
      
            while (aux->prox != NULL){
              aux = aux->prox;
            } 
      
          no->prox = NULL;
          aux->prox = no;
   
          }

            

          //printf( " \n ");
          //printf( " %d ", sLp2 );
          //printf("Conseguir separar e converter para inteiro.");
          //printf( " \n ");
          printf( "Informacoes sendo carregadas e lista sendo encadeada... \n");
          token = strtok(NULL, s);
        } 
      }
    }
  }
  //imprimir_Lista(li);
}



//verificar retono da fucao linha linha 

int main() {
  int escolha,valor,lp2,tam2,peso2,gc2;
  NO *respostaBusca;
    
  NO *lista = NULL;

  linhaAlinha(lista);
    
  do{
    printf("\n");

    printf("Carregamento realizado com SUCESSO!\n");

    printf("Operacao manual funcionando !!\n");

    printf( " \n");
    printf("[1]-Inserir elemento\n[2]-Inserir no fim\n[3]-Busca de elementos\n[4]-Deletar elementos\n[5]-Imprimir lista\n[-1]-sair\n");
    scanf("%d",&escolha);

    switch (escolha){

      case 1:{
       printf("Digite o valor a colocar lp :");
       scanf("%d",&lp2);
       fflush(stdin);

       printf("Digite o valor a colocar tamanho :");
       scanf("%d",&tam2);
       fflush(stdin);

       printf("Digite o valor a colocar peso :");
       scanf("%d",&peso2);
       fflush(stdin);
       
       printf("Digite o valor a colocar gc :");
       scanf("%d",&gc2);
       fflush(stdin);

       

       lista = inserir_Inicio(lista,lp2,tam2,peso2,gc2);
        break;
      }

      case 2:{
       printf("Digite o valor a colocar lp :");
       scanf("%d",&lp2);
       fflush(stdin);

       printf("Digite o valor a colocar tamanho :");
       scanf("%d",&tam2);
       fflush(stdin);

       printf("Digite o valor a colocar peso :");
       scanf("%d",&peso2);
       fflush(stdin);
       
       printf("Digite o valor a colocar gc :");
       scanf("%d",&gc2);
       fflush(stdin);
        
       lista = inserir_fim(lista,lp2,tam2,peso2,gc2);
        break;
      }
            
      case 3:{
        printf("Digite o valor a colocar lp :");
       scanf("%d",&lp2);
       fflush(stdin);

       printf("Digite o valor a colocar tamanho :");
       scanf("%d",&tam2);
       fflush(stdin);

       printf("Digite o valor a colocar peso :");
       scanf("%d",&peso2);
       fflush(stdin);
       
       printf("Digite o valor a colocar gc :");
       scanf("%d",&gc2);
       fflush(stdin);

       respostaBusca = busca(lista,lp2,tam2,peso2,gc2);

       printf("Lp encontrado %d\n",respostaBusca->lp);

       printf("Tamanho encontrado %d\n",respostaBusca->tam);

       printf("Peso encontrado %d\n",respostaBusca->peso);

       printf("Gc encontrado %d\n",respostaBusca->gc);
       break;
      }
      
      case 4:{
       
       printf("Digite o valor a colocar lp :");
       scanf("%d",&lp2);
       fflush(stdin);

       printf("Digite o valor a colocar tamanho :");
       scanf("%d",&tam2);
       fflush(stdin);

       printf("Digite o valor a colocar peso :");
       scanf("%d",&peso2);
       fflush(stdin);
       
       printf("Digite o valor a colocar gc :");
       scanf("%d",&gc2);
       fflush(stdin);


        lista = deletar(lista,lp2,tam2,peso2,gc2);
        break;
      }
      
      case 5:{
        imprimir_Lista(lista);
				break;
			}

      case 6:{
        
      }

      case -1:
        free(lista);
        default:
        break;
    }

  }while (escolha != -1);

  return 0;
}
