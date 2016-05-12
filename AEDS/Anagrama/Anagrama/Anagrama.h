#ifndef ANAGRAMA_H
#define ANAGRAMA_H

#include "Caractere.h"

typedef struct estrutura_anagrama{
	int tamanho;
	int combinacoes;
	Caractere *caracteres;
} ANAGRAMA;


ANAGRAMA CriaAnagrama(char *caracteres);
int Igual(ANAGRAMA a, ANAGRAMA b);
void DestroiAnagrama(ANAGRAMA* anagrama);

#endif