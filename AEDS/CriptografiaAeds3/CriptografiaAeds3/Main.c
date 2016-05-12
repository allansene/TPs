#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1100

int ehAlfabetico(char letra){

	if ((letra > 64 && letra < 91) || (letra > 96 && letra < 123))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

// reverse the given null-terminated string in place
void inplace_reverse(char * str)
{
	if (str)
	{
		char * end = str + strlen(str) - 1;

		// swap the values in the two given variables
		// XXX: fails when a and b refer to same memory location
#   define XOR_SWAP(a,b) do\
		{\
		a ^= b; \
		b ^= a; \
		a ^= b; \
		} while (0)

		// walk inwards from both ends of the string, 
		// swapping until we get to the middle
		while (str < end)
		{
			XOR_SWAP(*str, *end);
			str++;
			end--;
		}
#   undef XOR_SWAP
	}
}

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
			fgets(frase, MAX, arq);

			strtok(frase, "\n");
			//primeira condicao
			//letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita
			for (j = 0; j < strlen(frase); j++)
			{

				if (ehAlfabetico(frase[j]))
				{
					frase[j] += 3;
				}
			}
			//segunda condicao
			//inverte string
			inplace_reverse(frase);

			//terceira condicao
			//da metade em diante(truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII
			for (j = strlen(frase) / 2; j < strlen(frase); j++)
			{
				frase[j] -= 1;
			}

			printf("%s\n", frase);
		}

	}
	free(frase);
	fclose(arq);

	return 0;
}