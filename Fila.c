#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	struct no *prox;
}No;

void InserirFila(No **fila, int num){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		novo->prox = NULL;
		if(*fila == NULL)
			*fila = novo;
		else {
			aux = *fila;
			while(aux->prox)
				aux = aux->prox;
			aux->prox = novo;
		}
	}
	else
		printf("Erro ao alocar memória.\n");
}

No* RemoverFila(No **fila){
	No *remover = NULL;
	
	if (*fila){
		remover = *fila;
		*fila = remover->prox;
	}
	else
		printf("\tFila vazia.\n");
	return remover;
}

void Imprimir(No *fila){
	printf("\t=========== FILA ===========\n\t");
	while(fila){
		printf("%d", fila->valor);
		fila = fila->prox;
	}
	printf("\n\t=========== FIM ============\n");
}

int main(){
	No *r, *fila = NULL;
	
	int opcao, valor;
	
	do{
		printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &valor);
				InserirFila(&fila, valor);
				break;
			case 2:
				r = RemoverFila(&fila);
				if(r){
					printf("Removido: %d\n", r->valor);
					free(r);
				}
				break;
			case 3:
				Imprimir(fila);
				break;
			default:
				if (opcao != 0)
					printf("Opção inválida");
		}
		
	}while(opcao != 0);
	
	setlocale(LC_ALL, "Portuguese");
	
	return 0;
}
