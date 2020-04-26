#include <stdio.h>
//vetores - parte 1

// array uni-dimensional
// char nome[50];
int main(){
	//vetores e strings
	char nome[50];
	// "asdfa"
	printf("Qual seu nome? ");
	gets(nome);
	printf("Olá %s", nome);

	//vetores e caracteres
	char letras[26]; //0...25
	// 'b'
	int contador = 0;
	for(int i = 97; i <= 122; i++){
		letras[contador] = 1;
		contador = contador + 1;
	}

	//imprimindo as letras e seus valores em decimal
	for(int i = 0; i < 26; i++){
		printf("%d == %c\n", letras[i], letras[i]);
	}

	//char l = 'l';
	//char a = 97;

	//vetores de inteiros
	int numeros[10];

	//vetores e reais
	float valores[5];

	return 0;
}