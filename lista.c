/*
 * main.c
 * Classe de implemantação da ED Lista Dupla.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* iniciar() {

	Lista *l = malloc(sizeof(Lista));
	l->inicio = NULL;
	l->elemento_corrente = NULL;
	l->tamanho = 0;
	l->posicao_corrente = 0;

	return l;
}

void add(Lista *l, int numero) {

	if (empty(l)) {

		Elemento *e = malloc(sizeof(Elemento));
		e->valor = numero;
		e->proximo = NULL;
		e->anterior = NULL;

		l->inicio = e;
	} else {

		Elemento *e = malloc(sizeof(Elemento));
		Elemento *antigo_inicio = l->inicio;

		e->valor = numero;
		e->proximo = antigo_inicio;
		e->anterior = NULL;
		antigo_inicio->anterior = e;

		l->inicio = e;
	}

	l->tamanho = l->tamanho + 1;
}

void add_pos(Lista *l, int numero, int posicao) {

	if (empty(l)) {
		printf("Lista vazia. Add posicional não permitido!\n");
		return;
	}

	if (posicao > l->tamanho || posicao <= 0) {
		printf("Posição inválida!\n");
		return;
	}

	if (posicao == 1) {
		add(l, numero);
		return;
	}

	Elemento *e_atual = l->inicio;
	Elemento *e_anterior;

	Elemento *e = malloc(sizeof(Elemento));
	e->valor = numero;

	int i;
	for (i = 1; i < posicao; i++) {
		e_anterior = e_atual;
		e_atual = e_atual->proximo;
	}

	e_anterior->proximo = e;
	e->proximo = e_atual;

	e->anterior = e_anterior;
	e_atual->anterior = e;

	l->tamanho = l->tamanho + 1;
}

int empty(Lista *l) {
	return l->tamanho == 0;
}

int size(Lista *l) {
	return l->tamanho;
}

int get(Lista *l, int posicao) {

	if (empty(l)) {
		printf("Lista vazia.\n");
		return '\0';
	}

	if (posicao > l->tamanho || posicao <= 0) {
		printf("Posição inválida!\n");
		return '\0';
	}

	if (l->elemento_corrente == NULL) {
		l->elemento_corrente = l->inicio;
		l->posicao_corrente = 1;
	}

	if (posicao == l->posicao_corrente) {
		return l->elemento_corrente->valor;
	} else {

		if (posicao > l->posicao_corrente) {

			int i = l->posicao_corrente;
			Elemento *e = l->elemento_corrente;
			while (e != NULL) {

				if (i == posicao) {

					l->elemento_corrente = e;
					l->posicao_corrente = i;
					return e->valor;
				} else {

					e = e->proximo;
					i++;
				}
			}
		}

		if (posicao < l->posicao_corrente) {

			int i = l->posicao_corrente;
			Elemento *e = l->elemento_corrente;
			while (e != NULL) {

				if (i == posicao) {

					l->elemento_corrente = e;
					l->posicao_corrente = i;
					return e->valor;
				} else {

					e = e->anterior;
					i--;
				}
			}
		}
	}

	return -1;
}

void exibir(Lista *l) {

	if (empty(l)) {

		printf("Lista vazia!\n");
		return;
	}

	Elemento *e = l->inicio;

	while (e != NULL) {

		printf("%d", e->valor);
		e = e->proximo;
	}

	printf("\n");
}
