#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;

} Calcular;


void jogar();
void mostrarInfo(Calcular calc);

int pontos = 0;


int main()
{
    jogar();

    return 0;
}

void jogar(){

}

void mostrarInfo(Calcular calc){
    char op[25];

    if (calc.operacao == 0)
    {
        sprintf(op, "Somar");
    }else if(calc.operacao == 1){
        sprintf(op, "Diminuir");
    }else if(calc.operacao == 2){
        sprintf(op, "Multiplicar");
    }else{
        sprintf(op, "Operação desconhecida");
    }
    printf("Valor 1: %d \nValor: %d \nDificuldade: %d \n Operação: %s",calc.valor1, calc.valor2, calc.dificuldade, op);
    
}

int somar(int reposta, Calcular calc){

}

int diminuir(int resposta, Calcular calc){

}

int multiplicar(int resposta, Calcular calc){

}