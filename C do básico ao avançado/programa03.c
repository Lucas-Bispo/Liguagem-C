#include <sdtio.h>
//Estruturas de repetição, for, while, do..while
//						   para, enquanto, faça..enquanto

/*
Utilizando o For (para)

Faça um programa, no qual receba e soma os números
inteiros e apresente a soma no final;
*/

int main(){
	//variáveis
	int numero, soma = 0;

	//para o int i iniciando em 0; enquanto i < 5; incrementa o i em 1
	//inicialização, critério de parada, forma de incremento
	for(int i = 0; i < 5; i++){
		//entrada
		printf("Informe um número: ");
		scanf("%d", &numero);

		//processamento
		soma = soma + numero;
	}
	
	//saída
	printf("A soma é %d", soma);

	return 0;

}