#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int a, b, c;
	
	printf("N�mero A: "); scanf("%d", &a);
	
	printf("N�mero B: "); scanf("%d", &b);
	
	printf("\n");
	
	c = a;
	a = b;
	b = c;
	
	printf("Novo valor do n�mero A: %d\n", a);
	printf("Novo valor do n�mero B: %d\n", b);
	
	return 0;
}
