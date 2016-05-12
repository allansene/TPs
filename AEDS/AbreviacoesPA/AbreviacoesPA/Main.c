#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1100


int main(){

	char url[] = "D:\\in.txt";
	char* frase = (char*)calloc(MAX, sizeof(char));

	int numTestes;
	FILE *arq;
	int i, j;

	arq = fopen(url, "r");
	//arq = stdin;
	if (arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		fscanf(arq, "%d\n", &numTestes);
		for (i = 0; i < numTestes; i++)
		{
			while (fgets(frase, MAX, arq))
			{
				strtok(frase, "\n");
				//primeira condicao
				//letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita
				for (i = 0; i < strlen(frase); i++)
				{

					if (isalpha(frase[i]))
					{
						frase[i] += 3;
					}
				}
				//segunda condicao
				//inverte string
				inplace_reverse(frase);

				//terceira condicao
				//da metade em diante(truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII
				for (i = strlen(frase) / 2; i < strlen(frase); i++)
				{
					frase[i] -= 1;
				}

				printf("%s\n", frase);
				numTestes--;
			}

		}

	}
	free(frase);
	fclose(arq);

	return 0;
}