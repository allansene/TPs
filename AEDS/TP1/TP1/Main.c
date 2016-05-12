#define _CRT_SECURE_NO_WARNINGS

#include "Grafo.h"
#include <stdio.h>

int main(int argc, char *argv[])
{ 
	char url[] = "D:\\in.txt";

	int numTestes;
	FILE *entrada, *saida;
	int j;

	entrada = fopen(url, "r");
	saida = fopen(url, "w");
	//entrada = saida = stdin;
	int TEMP;
	int TEMP1;

	Apontador Aux;
	long i; short FimListaAdj;
	int  NArestas;
	ValorVertice V1, V2, Adj;
	Peso Peso;
	Grafo Grafo, GrafoT;
	ValorVertice NVertices;
	/* -- NumVertices: definido antes da leitura das arestas --*/
	/* -- NumArestas: inicializado com zero e incrementado a --*/
	/* -- cada chamada de InsereAresta                       --*/

	printf("No. vertices:");
	scanf("%d%*[^\n]", &TEMP);
	getchar();
	NVertices = TEMP;
	printf("No. arestas:");
	scanf("%d%*[^\n]", &NArestas);
	getchar();
	Grafo.NumVertices = NVertices;
	Grafo.NumArestas = 0;
	FazGrafoVazio(&Grafo);

	for (i = 0; i < NArestas; i++)
	{
		printf("Insere V1 -- V2 -- Peso:");
		scanf("%d%d%d%*[^\n]", &TEMP, &TEMP1, &Peso);
		getchar();
		V1 = TEMP;
		V2 = TEMP1;
		Grafo.NumArestas++;
		InsereAresta(&V1, &V2, &Peso, &Grafo);   /* 1 chamada g-direcionado    */
		/*InsereAresta(V2, V1, Peso, Grafo);*/
		/* 2 chamadas g-naodirecionado*/
	}
	ImprimeGrafo(&Grafo);
	scanf("%*[^\n]");
	getchar();
	
	scanf("%*[^\n]");
	getchar();
	printf("Insere V1 -- V2 -- Peso:");
	scanf("%d%d%d%*[^\n]", &V1, &V2, &Peso);
	if (ExisteAresta(V1, V2, &Grafo))
		printf("Aresta ja existe\n");
	else
	{
		Grafo.NumArestas++;
		InsereAresta(&V1, &V2, &Peso, &Grafo);
		/*InsereAresta(V2, V1, Peso, Grafo);*/
	}
	ImprimeGrafo(&Grafo);
	scanf("%*[^\n]");
	getchar();
	printf("Lista adjacentes de: ");
	scanf("%d*[^\n]", &TEMP);
	V1 = TEMP;
	if (!ListaAdjVazia(&V1, &Grafo))
	{
		Aux = PrimeiroListaAdj(&V1, &Grafo);
		FimListaAdj = FALSE;
		while (!FimListaAdj)
		{
			ProxAdj(&V1, &Grafo, &Adj, &Peso, &Aux, &FimListaAdj);
			printf("%2d (%d)", Adj, Peso);
		}
		putchar('\n');
		scanf("%*[^\n]");
		getchar();
	}
	printf("Retira aresta V1 -- V2:");
	scanf("%d %d", &V1, &V2);
	if (ExisteAresta(V1, V2, &Grafo))
	{
		Grafo.NumArestas--;
		RetiraAresta(&V1, &V2, &Peso, &Grafo);
		/*RetiraAresta(V2, V1, Peso, Grafo);*/
	}
	else printf("Aresta nao existe\n");
	ImprimeGrafo(&Grafo);
	scanf("%*[^\n]");
	getchar();
	printf("Existe aresta V1 -- V2:");
	/* scanf("%d%d%*[^\n]", &TEMP, &TEMP1); */
	scanf("%d*[^\n]", &TEMP);
	scanf("%d*[^\n]", &TEMP1);
	getchar();
	V1 = TEMP;
	V2 = TEMP1;
	if (ExisteAresta(V1, V2, &Grafo)) printf(" Sim\n");
	else printf(" Nao\n");
	LiberaGrafo(&Grafo);   /* Imprime sujeira normalmente */
	ImprimeGrafo(&Grafo);

	fclose(entrada);
	fclose(saida);

	return 0;
}