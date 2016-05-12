#ifndef CARACTERE_H
#define CARACTERE_H

typedef struct estrutura_caractere{
	int numeroDeOcorrencias;
	char caracter;
} Caractere;

Caractere CriaCaractere();
void DestroiCaractere(Caractere *caractere);

#endif