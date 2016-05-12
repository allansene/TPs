#ifndef GRAFO
#define GRAFO

/*IMPLEMENTAÇÃO NIVIO ZIVIANI - http://www2.dcc.ufmg.br/livros/algoritmos/cap7/codigo/c/7.4a7.5e7.8-grafolistaap.c */

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1

typedef int ValorVertice;
typedef int Peso;
typedef struct Item {
	ValorVertice Vertice;
	Peso Peso;
} Item;
typedef struct Celula *Apontador;
struct Celula {
	Item Item;
	Apontador Prox;
} Celula;
typedef struct Lista {
	Apontador Primeiro, Ultimo;
} Lista;
typedef struct Grafo {
	Lista Adj[MAXNUMVERTICES + 1];
	ValorVertice NumVertices;
	short NumArestas;
} Grafo;


/*--Entram aqui as operações de lista --*/
void FLVazia(Lista *Lista);

short Vazia(Lista Lista);

void Insere(Item *x, Lista *Lista);

/*-- Fim das operações de lista --*/
void FazGrafoVazio(Grafo *Grafo);

void InsereAresta(ValorVertice *V1, ValorVertice *V2,
	Peso *Peso, Grafo *Grafo);

short ExisteAresta(ValorVertice Vertice1,
	ValorVertice Vertice2, Grafo *Grafo);

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(ValorVertice *Vertice, Grafo *Grafo);

Apontador PrimeiroListaAdj(ValorVertice *Vertice,
	Grafo *Grafo);

void ProxAdj(ValorVertice *Vertice, Grafo *Grafo,
	ValorVertice *Adj, Peso *Peso,
	Apontador *Prox, short *FimListaAdj);

void Retira(Apontador p, Lista *Lista, Item *Item);

void RetiraAresta(ValorVertice *V1, ValorVertice *V2,
	Peso *Peso, Grafo *Grafo);

void LiberaGrafo(Grafo *Grafo);

void ImprimeGrafo(Grafo *Grafo);

void ImprimeLista(Lista Lista);
#endif