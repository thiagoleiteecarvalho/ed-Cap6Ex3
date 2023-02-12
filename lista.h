/*
 * fila.h
 * Header de definição da ED Lista Dupla.
 * Author: Thiago Leite
 */

#pragma once

typedef struct elemento {
	int valor;
	struct elemento *proximo;
	struct elemento *anterior;
} Elemento;

typedef struct lista {
	Elemento *inicio;
	Elemento *elemento_corrente;
	int posicao_corrente;
	int tamanho;
} Lista;

Lista* iniciar();
void add_pos(Lista *l, int numero, int posicao);
void add(Lista *l, int numero);
int empty(Lista *l);
int size(Lista *l);
int get(Lista *l, int posicao);
void exibir(Lista *l);
