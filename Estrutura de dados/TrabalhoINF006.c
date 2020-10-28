#include<stdio.h>
#include<stdlib.h>//Biblioteca que permite trabalhar com a memória.
#include <ctype.h>
#include <string.h>

typedef struct st_no{//redefinição do tipo de dado para NO.
    int num;
    int lp; 
  	int tam;
    int peso;
    int gc;
    struct st_no *prox;/*ponteiro para direcionamento para a estrutura 
    que tem a variável mais um ponteiro para a própria estrutura.*/
}NO;//tipo de dado redefinido.
//função que criar um nó
NO *criar_no(){//fução que retorna um ponteiro.
    NO *novo = (NO*)malloc(sizeof(NO));//retorna um ponteiro do tipo void.
    //porém é preciso fazer um cast, conversão do ponteiro vazio para o tipo NO.
    return novo;// retorno de ponteiro
}
/*
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
}*/
//rever a logica de inserção de elementos.
NO *inserir_fim(NO *lista,int lp2,int tam2,int peso2, int gc2){//recebe um ponteiro mais um valor são os parâmetros
    NO *no = (NO*)malloc(sizeof(NO));//recebe alocação de memória feita por malloc,é feito cast 
    // e o endereço é passado ao ponteiro no.
    no->lp = lp2;//recebe o valor que vem no parâmetro.
    no->tam = tam2;
    no->peso = peso2;
    no->gc = gc2;

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

NO *busca(NO *lista, int valor,int lp2,int tam2,int peso2, int gc2){//função que retorna o ponteiro encontrado na busca.
  NO *aux = lista;//é preciso criar uma variável auxiliar.
  //passa o endereço da lista para aux e realiza a busca.
  while(aux->prox != NULL){//enquanto aux não encontra NULL 
    
    if((aux->lp == lp2) && (aux->tam == tam2) && (aux->peso == peso2) && (aux->gc == gc2)){//a comparação entre o valor e os valores que estão na lista em num.
    return aux;//retorno do valor encontrado.
    }
    aux = aux->prox;//incremento 
  }

}

NO *deletar(NO *lista,int lp2,int tam2,int peso2, int gc2){
    NO *anterior,*proximo;
    proximo = lista->prox;//endereço passado para o proximo.
    anterior = lista;//mesma coisa acontece aqui pois é preciso criar auxiliares para não 
    //para não perder a lista.
    if ((anterior->lp == lp2) &&(anterior->tam == tam2) &&(anterior->peso == peso2) &&(anterior->gc == gc2)){//exceção caso o valor esteja no início.

        lista = proximo;//ajuste de ponteiro, pois proximo está com endereço de lista->prox.
        printf("Valor apagado pois se encontra no inicio da lista.\n");
        free(anterior);//liberação de memória.
    }
    while (proximo != NULL){//caso não esteja no início devesse realizar uma busca
    
        if((anterior->lp == lp2) &&(anterior->tam == tam2) &&(anterior->peso == peso2) &&(anterior->gc == gc2)){//vereficação para encontrar o valor

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
    for (aux = lista; aux->prox != NULL; aux = aux->prox){//percorre a lista 
        //aux recebe o endereço da lista, enquanto diferente NULL,e incremento.
        printf("LP = %d",aux->lp);//imprime a lista.
        printf("TAM = %d",aux->tam);
        printf("PESO = %d",aux->peso);
        printf("GC = %d",aux->gc);
    }
}

NO *linhaAlinha(NO *li){
  
  FILE *arq;
  NO *lii;

  char nome[40], *resultado;

  arq = fopen("teste.txt", "r");

  if(arq){

    while(!feof(arq)){

        resultado = fgets(nome, 40, arq);
      
        if(resultado){
        
            NO auxDados;
            char sLp[10];
            char sTam[10];
            char sPeso[10];
            char sGc[10];
            int sLp2,sTam2,sPeso2,sGc2;

            printf( " \n ");
            printf("%s", nome);
              

            NO *no = (NO*)malloc(sizeof(NO));

            const char s[2] = ";";
            char *token;
   
            /* get the first token */
            token = strtok(nome, s);
   
          /* walk through other tokens */
          while( token != NULL ) {
            //printf( " %s\n", token );
            
            sLp2 = atoi(token);
            

            printf( " \n ");
            printf( " %d ", sLp2 );
            
            printf( " \n ");

            token = strtok(NULL, s);
          }
            /*int i;        
            // Landing Pointer
            for (i = 0; nome[i] != ';'; i++){
            sLp[i] = nome[i];
           
            //printf("")
            }
            sLp[i] = '\0';
            
            sLp2 = atoi(sLp);

            li->lp = sLp2;
            //printf("%d\n", auxDados);
            
            

            i++;
            // Tamanho
            int j;
            int cont = 0;

            for (j = i; nome[j] != ';'; j++, cont++)
            sTam[cont] = nome[j];
                
            sTam[j] = '\0';
            sTam2 = atoi(sTam);
            //printf("%d",sTam2);
            j++;

            li->tam = sTam2;

            // peso
            int k;
            cont = 0;

            for (k=j; nome[k] != ';'; k++, cont++)
            sPeso[cont] = nome[k];

            sTam[k] ='\0';
            sPeso2 = atoi(sPeso);
            k++;

            li->peso = sPeso2;

            // iGc
            int l;
            cont = 0;
            
            for (l=k;  nome[l] != '\0'; l++, cont++)
            sGc[cont] = nome[l];

            sGc[l] = '\0';
            sGc2 = atoi(sGc);

            printf("%s", nome);
            
            li->gc = sGc2;*/


           if(li == NULL){//essa condição sempre acontecerá pelo menos uma vez.
                no->prox = NULL;//o campo prox aponta para NULL
                li = no; //lista aponta para o novo elemento que foi inserido na lista.
            }
            else{//para chegar realizar a inserção no fim, devesse realizar uma busca pelo campo NUUL
                NO *aux = li;//é preciso criasse variáveis auxiliares para não perder a referência da lista.
                while (aux->prox != NULL){// da para fazer com for.
                    aux = aux->prox;
                } //quando encontra NULL, o redirecionamento dos ponteiros são realizados
                no->prox = NULL;//o campo prox do novo elemento aponta para NULL
                aux->prox = no;// e aux que apontava para NULL aponta para o elemnto que será inserido.
            }
        
            //return li;

            

            //lii = inserir_fim(li, sLp2, sTam2, sPeso2, sGc2);
            // Insere na lista
            //insereNaListaInicio(&li, auxDados);
        }
    
    }
   }
return lii;
}




int main() {
    int escolha,valor;
    int  lp2,tam2, peso2, gc2;
    //inicialização da lista, podesse criar função.
    NO *lista = NULL;// e é tambem,*respostaBusca;
    NO *respostaBusca;
    NO *listaCarregada;

    listaCarregada = linhaAlinha(lista);


    do{//menu de interação com usuário
    
        printf("[2]-Inserir no fim\n[3]-Busca de elementos\n[4]-Deletar elementos\n[5]-Imprimir lista\n[-1]-sair\n");
        scanf("%d",&escolha);

        switch (escolha){//analise de casos de acordo com o que o usuário digitar.
            //case 1:{
                //printf("Digite o valor a colocar na lisrta:");
               // scanf("%d",&valor);
                //lista = inserir_Inicio(lista,valor);//por ser um função com retorno devesse jogar o retorno, ao mesmo tempo a função realizada.
                //break;//quebra de sequência de comandos 
            //}
            case 2:{
              printf("Infome o numero do landpoint que deseja inserir: ");
              scanf("%d",&lp2);
              fflush(stdin);

              printf("Infome o numero do tamnho que deseja inserir: ");
              scanf("%d",&tam2);
              fflush(stdin);

              printf("Infome o numero do peso que deseja inserir: ");
              scanf("%d",&peso2);
              fflush(stdin);

              printf("Infome o numero do gcc que deseja inserir: ");
              scanf("%d",&gc2);
              fflush(stdin);
              lista = inserir_fim(lista,lp2,tam2, peso2, gc2);//as variáveis que são passadas como argumentos por mais que tenham o mesmo nome 
              //não tem o endereço iguais
              break;//quebra de sequência de comandos
            }
            case 3:{
              
              printf("Infome o numero do landpoint que deseja buscar: ");
              scanf("%d",&lp2);
              fflush(stdin);

              printf("Infome o numero do tamnho que deseja buscar: ");
              scanf("%d",&tam2);
              fflush(stdin);

              printf("Infome o numero do peso que deseja buscar: ");
              scanf("%d",&peso2);
              fflush(stdin);

              printf("Infome o numero do gcc que deseja buscar: ");
              scanf("%d",&gc2);
              fflush(stdin);

              respostaBusca = busca(lista,valor,lp2,tam2, peso2, gc2);
              printf("Valores encontrados: lp = %d tam = %d peso = %d gc = %d",respostaBusca->lp,respostaBusca->peso,respostaBusca->gc);//como a resposta foi retornada o procedimento de impressão com struct
                //e ponteiros é usando -> "seta".
                break;//quebra de sequência de comandos
            }
            case 4:{//o mesmo se aplica em relação a função, retorno,parâmetros
               
                printf("Infome o numero do landpoint que deseja deletar: ");
                scanf("%d",&lp2);
                fflush(stdin);

                printf("Infome o numero do tamnho que deseja deletar: ");
                scanf("%d",&tam2);
                fflush(stdin);

                printf("Infome o numero do peso que deseja deletar: ");
                scanf("%d",&peso2);
                fflush(stdin);

                printf("Infome o numero do gcc que deseja deletar: ");
                scanf("%d",&gc2);
                fflush(stdin);



                lista = deletar(lista,lp2,tam2, peso2, gc2);
                break;
            }
            case 5:{
            	imprimir_Lista(lista);
				      break;
			      }
            case 6:{
              imprimir_Lista(listaCarregada);
            }

            case -1:
            free(lista);//liberação de memória por questão de segurança
            default://encerramento de programa 
            break;
        }
    }while (escolha != -1);
    
    return 0;
}
