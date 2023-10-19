#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int a, b, c;
	
	printf("Número A: "); scanf("%d", &a);
	
	printf("Número B: "); scanf("%d", &b);
	
	printf("\n");
	
	c = a;
	a = b;
	b = c;
	
	printf("Novo valor do número A: %d\n", a);
	printf("Novo valor do número B: %d\n", b);
	
	return 0;
}
