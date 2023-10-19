#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void CalSoma(){
	
	int a, b, som;
	float sub, prod, div;
	
	printf("Número 1: \n");
	scanf("%d", &a);
	printf("Número 2: \n");
	scanf("%d", &b);
	
	som = a + b;
	
	printf ("A soma resulta em %d\n", som);
}

void CalSub (){
	
	int a, b, som;
	float sub, prod, div;
	
	printf("Número 1: \n");
	scanf("%d", &a);
	printf("Número 2: \n");
	scanf("%d", &b);
	
	sub = a - b;
	
	printf("A subtração resulta em %2.f\n", sub);
}

void CalProd (){
	
	int a, b, som;
	float sub, prod, div;
	
	printf("Número 1: \n");
	scanf("%d", &a);
	printf("Número 2: \n");
	scanf("%d", &b);
	
	prod = a * b;
	
	printf("O produto resulta em %2.f\n", prod);
}

void CalDiv (){
	
	int a, b, som;
	float sub, prod, div;
	
	printf("Número 1: \n");
	scanf("%d", &a);
	printf("Número 2: \n");
	scanf("%d", &b);
	
	div = a / b;
	
	printf("A divisão resulta em %2.f\n", div);
}

int main(){

	setlocale(LC_ALL, "Portuguese");

	int casos;
	
	printf("CALCULADORA\n");
	
	do {
		printf("Digite a opção:\n");
		printf("0- Encerrar\n1- Soma\n2- Subtração\n3- Produto\n4- Divisão\n");
		scanf("%d", &casos);
		
		switch (casos){
			case 1:
				CalSoma();
				break;
			case 2:
				CalSub();
				break;
			case 3:
				CalProd();
				break;
			case 4:
				CalDiv();
				break;
			default:
				printf("ENCERRADO");
		}
	}
	while (casos != 0);
}



