#include "Grafo.h"
#include <stdlib.h>

void FLVazia(Lista *Lista)
{
	Lista->Primeiro = (Apontador)malloc(sizeof(Celula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

short Vazia(Lista Lista)
{
	return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(Item *x, Lista *Lista)
{ /*-- Insere depois do ultimo item da lista --*/
	Lista->Ultimo->Prox = (Apontador)malloc(sizeof(Celula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = *x;
	Lista->Ultimo->Prox = NULL;
}

void FazGrafoVazio(Grafo *Grafo)
{
	long i;
	for (i = 0; i < Grafo->NumVertices; i++) FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(ValorVertice *V1, ValorVertice *V2,
	Peso *Peso, Grafo *Grafo)
{
	Item x;
	x.Vertice = *V2;
	x.Peso = *Peso;
	Insere(&x, &Grafo->Adj[*V1]);
}

short ExisteAresta(ValorVertice Vertice1,
	ValorVertice Vertice2, Grafo *Grafo)
{
	Apontador Aux;
	short EncontrouAresta = FALSE;
	Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
	while (Aux != NULL && EncontrouAresta == FALSE)
	{
		if (Vertice2 == Aux->Item.Vertice) EncontrouAresta = TRUE;
		Aux = Aux->Prox;
	}
	return EncontrouAresta;
}

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(ValorVertice *Vertice, Grafo *Grafo)
{
	return (Grafo->Adj[*Vertice].Primeiro ==
		Grafo->Adj[*Vertice].Ultimo);
}

Apontador PrimeiroListaAdj(ValorVertice *Vertice,
	Grafo *Grafo)
{
	return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(ValorVertice *Vertice, Grafo *Grafo,
	ValorVertice *Adj, Peso *Peso,
	Apontador *Prox, short *FimListaAdj)
{ /* Retorna Adj e Peso do Item apontado por Prox */
	*Adj = (*Prox)->Item.Vertice;
	*Peso = (*Prox)->Item.Peso;
	*Prox = (*Prox)->Prox;
	if (*Prox == NULL) *FimListaAdj = TRUE;
}

void Retira(Apontador p, Lista *Lista, Item *Item)
{ /*--Obs.: item a ser retirado e o seguinte ao apontado por p--*/
	Apontador q;
	if (Vazia(*Lista) || p == NULL || p->Prox == NULL)
	{
		printf("Erro: Lista vazia ou posicao nao existe\n");
		return;
	}
	q = p->Prox;
	*Item = q->Item;
	p->Prox = q->Prox;
	if (p->Prox == NULL) Lista->Ultimo = p;
	free(q);
}

void RetiraAresta(ValorVertice *V1, ValorVertice *V2,
	Peso *Peso, Grafo *Grafo)
{
	Apontador AuxAnterior, Aux;
	short EncontrouAresta = FALSE;
	Item x;
	AuxAnterior = Grafo->Adj[*V1].Primeiro;
	Aux = Grafo->Adj[*V1].Primeiro->Prox;
	while (Aux != NULL && EncontrouAresta == FALSE)
	{
		if (*V2 == Aux->Item.Vertice)
		{
			Retira(AuxAnterior, &Grafo->Adj[*V1], &x);
			Grafo->NumArestas--;
			EncontrouAresta = TRUE;
		}
		AuxAnterior = Aux;
		Aux = Aux->Prox;
	}
}

void LiberaGrafo(Grafo *Grafo)
{
	int i;
	Apontador AuxAnterior, Aux;
	for (i = 0; i < Grafo->NumVertices; i++)
	{
		Aux = Grafo->Adj[i].Primeiro->Prox;
		free(Grafo->Adj[i].Primeiro);   /*Libera celula cabeca*/
		Grafo->Adj[i].Primeiro = NULL;
		while (Aux != NULL)
		{
			AuxAnterior = Aux;
			Aux = Aux->Prox;
			free(AuxAnterior);
		}
	}
	Grafo->NumVertices = 0;
}

void ImprimeGrafo(Grafo *Grafo)
{
	int i;
	Apontador Aux;
	for (i = 0; i < Grafo->NumVertices; i++)
	{
		printf("Vertice%2d:", i);
		if (!Vazia(Grafo->Adj[i]))
		{
			Aux = Grafo->Adj[i].Primeiro->Prox;
			while (Aux != NULL)
			{
				printf("%3d (%d)", Aux->Item.Vertice, Aux->Item.Peso);
				Aux = Aux->Prox;
			}
		}
		putchar('\n');
	}
}

void ImprimeLista(Lista Lista)
{
	Apontador Aux;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL)
	{
		printf("%3d (%12d)", Aux->Item.Vertice, Aux->Item.Peso);
		Aux = Aux->Prox;
	}
}
