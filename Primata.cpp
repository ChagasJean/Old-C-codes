#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a estrutura Primata.
typedef struct {
    int num;
    char nome[50];
    int idade;
} Primata;

// Função para imprimir a lista de primatas.
void print_primata_list(Primata* primata_list, int primata_num) {
    printf("Ordem       \tNome\t\tIdade\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < primata_num; i++) {
        printf("%d\t\t%-10s\t%d\n", primata_list[i].num, primata_list[i].nome, primata_list[i].idade);
    }
    printf("-------------------------------------------\n");
}

// Fun��o para trocar dois primatas de lugar na lista.
void swap_primata(Primata* primata_list, int i, int j) {
    Primata temp = primata_list[i];
    primata_list[i] = primata_list[j];
    primata_list[j] = temp;
}

// Fun��o de ordena��o Bubble Sort
void bubble_sort_primata_list(Primata* primata_list, int primata_num) {
    for (int i = 0; i < primata_num - 1; i++) {
        for (int j = 0; j < primata_num - i - 1; j++) {
            if (primata_list[j].num > primata_list[j+1].num) {
                swap_primata(primata_list, j, j+1);
            }
        }
    }
}

// Fun��o para ler a lista de primatas de um arquivo bin�rio.
void read_primata_list_from_file(Primata* primata_list, int primata_num, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }
    fread(primata_list, sizeof(Primata), primata_num, file);
    fclose(file);
}

// Fun��o para escrever a lista de primatas em um arquivo bin�rio.
void write_primata_list_to_file(Primata* primata_list, int primata_num, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }
    fwrite(primata_list, sizeof(Primata), primata_num, file);
    fclose(file);
}

int main() {
    // Define a lista de primatas.
    Primata primata_list[] = {
        {1, "Bongo", 12},
        {3, "Bingbong", 6},
        {5, "Boris", 16},
        {7, "Chinzamp�", 7},
        {9, "Golias", 13},
        {11, "Gorillazz", 13},
        {13, "Laden", 14},
        {15, "Coron�rio", 12},
        {2, "Renatin", 11},
        {4, "Renaldin", 9},
        {6, "Jorge", 8},
        {8, "Germano", 10},
        {10, "Felix", 12},
        {12, "Davi", 19},
        {14, "Ferdinando", 4},
    };
    int primata_num = sizeof(primata_list) / sizeof(Primata);

    // Imprime o c�digo.
    printf("Antes da ordenada:\n");
	print_primata_list(primata_list, primata_num);
	
	write_primata_list_to_file(primata_list, primata_num, "lista_primata.bin");

// Ordena a lista de primatas pelo n�mero na "Ordem".
	bubble_sort_primata_list(primata_list, primata_num);

// Imprime a lista de primata ordenada
	printf("\n");
	printf("Ordenando...\n");
	printf("\n");
	print_primata_list(primata_list, primata_num);

// L� a lista de primata de um arquivo bin�rio
	Primata primata_list_file[primata_num];
	read_primata_list_from_file(primata_list_file, primata_num, "lista_primata.bin");

// Ordena a lista de primatas lida do arquivo bin�rio
	bubble_sort_primata_list(primata_list_file, primata_num);

// Escreve a lista de primata ordenada em um novo arquivo bin�rio
	write_primata_list_to_file(primata_list_file, primata_num, "n_lista_primata.bin");

return 0;

}
