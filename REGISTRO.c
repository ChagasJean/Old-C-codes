#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct {
    char nome[50];
    int idade;
    float peso;
    char especie[50];
    }registro;

void imprimirBinTerminal(FILE *arquivo, registro macaco){
    int i = 0;
    while(fread(&macaco, sizeof(macaco), 1, arquivo)){
    	printf("\n");
        printf("%d - %s, %s, %d ano(s), %.f\ KG\n", i+1, macaco.nome, macaco.especie, macaco.idade, macaco.peso);
        printf("\n");
        i++;
    }
}

void escritaBin (char *nomeDoArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeDoArquivo, "ab");

    registro macaco;
	
	printf("\n");
    printf("Digite o registro de um primata: \n");

        printf("Digite o nome do primata: ");
        fgets(macaco.nome, 50, stdin);
        strtok(macaco.nome, "\n");
        
        printf("Digite a espécie do primata: ");
    	fgets(macaco.especie, 50, stdin);
        strtok(macaco.especie, "\n");

        printf("Digite a idade do primata: ");
        scanf("%d", &macaco.idade);

        printf("Digite o peso do primata: ");
        scanf("%f", &macaco.peso);
        
        fwrite(&macaco, sizeof(macaco), 1, arquivo);
        while(getchar() != '\n');

        fclose(arquivo);
}

void leituraBin(char *nomeDoArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeDoArquivo, "rb");

    registro macaco;

    imprimirBinTerminal(arquivo, macaco);

    fclose(arquivo);
}

void edicaoBin(char *nomeDoArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeDoArquivo, "rb+");

    registro macaco;

    imprimirBinTerminal(arquivo, macaco);

    int i;
    printf("Digite o identificador do primata que deseja editar: \n");
        scanf("%d", &i);
        i = i-1;
        getchar();
    printf("Digite o nome do primata: ");
        scanf("%s", macaco.nome);
    printf("Digite a espécie do primata: ");
    	scanf("%s", macaco.especie);
    printf("Digite a idade do primata: ");
        scanf("%d", &macaco.idade);
    printf("Digite o peso do primata: ");
        scanf("%f", &macaco.peso);
    

    fseek(arquivo, i * sizeof(macaco), SEEK_SET);
    fwrite(&macaco, sizeof(macaco), 1, arquivo);

    fclose(arquivo);
}

void deletarBin(char *nomeDoArquivo){
	
    registro macaco;
    
    FILE *arquivo, *arquivoDel;
	arquivo = fopen(nomeDoArquivo, "rb");
	

    imprimirBinTerminal(arquivo, macaco);
    
    fclose(arquivo);

    int d;
    printf("Qual registro voce gostaria de deletar?");
    scanf("%d", &d);

    d = d-1;
    arquivo = fopen(nomeDoArquivo, "rb");
    arquivoDel = fopen("arqDeletado.txt", "wb");


    if(arquivoDel){
	int j = 0;
	   while(fread(&macaco, sizeof(macaco), 1, arquivo)){
	       if (j != d){
	    		fwrite(&macaco, sizeof(macaco), 1, arquivoDel);
	    	}
		j++;
		}

	remove(nomeDoArquivo);
    }
    else{
        printf("Ero ao criar arquivo");
    }

    fclose(arquivoDel);

    arquivo = fopen(nomeDoArquivo, "wb");
    arquivoDel = fopen("arqDeletado.txt", "rb");

    if (arquivo){
        int j = 0;
        while(fread(&macaco, sizeof(macaco), 1, arquivoDel)){
            fwrite(&macaco, sizeof(macaco), 1, arquivo);
            j++;
        }
    }
    else{
        printf("Erro ao abrir arquivo");
        }

    remove("arqDeletado.txt");
    fclose(arquivo);
}

int main(){
    char nomeDoArquivo[] = "alunos.txt";

    int opcao;
    do {
    	printf("==================\n");
    	printf("REGISTRO DE PRIMATAS\n");
    	printf("==================\n");
    	printf("\n");
        printf("Digite a opcao desejada:\n");
        printf("0 - Encerrar\n1 - Registrar primata\n2 - Ver primatas registrados\n3 - Editar registro\n4 - Deletar entrada\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
            case 1:
                escritaBin(nomeDoArquivo);
                break;
            case 2:
                leituraBin(nomeDoArquivo);
                break;
            case 3:
                edicaoBin(nomeDoArquivo);
                break;
            case 4:
                deletarBin(nomeDoArquivo);
                break;
            default:
                printf("\nFIM DO REGISTRO\n");
        }
    }
    while (opcao != 0);
}


