#include <stdio.h>
//Estrutura de repetição
//do..while (faça..enquanto)

/*
Utilizado quando você precisa de um loop
onde não se tenha um número fixo de elementos
mas que tenha um critério de parada e é checada
após a primeira execução.

Problema:
Faça um programa, no qual receba e soma números
inteiros até que o número de entrada seja 0
e apresente a soma no final;
*/
int main(){

	int numero, soma = 0;

	do{
		//entrada
		printf("Informe um número: ");
		scanf("%d", &numero);

		//processamento
		soma = soma + numero;
	}while(numero != 0);

	printf("A soma é %d", soma);

	return 0;
}
