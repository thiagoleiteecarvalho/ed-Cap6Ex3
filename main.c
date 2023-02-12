/*
 * main.c
 * Resposta do exercício 3 do capítulo 6.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

void verifica_palindromo(Lista *lista) {

	int tamanho_lista = size(lista);

	int numero[tamanho_lista];
	int j = 0;

	int i;
	for (i = 1; i <= tamanho_lista; i++) {
		numero[j++] = get(lista, i);
	}

	bool palindromo = true;

	j = 0;
	for (i = tamanho_lista; i >= 1; i--) {

		int n1 = get(lista, i);

		if (n1 != numero[j++]) {

			printf("não é palindromo.\n");
			palindromo = false;
			break;
		}
	}

	if (palindromo) {
		printf("é palindromo.\n");
	}

}

int main(void) {

	/*Número 159951*/
	Lista *l1 = iniciar();

	add(l1, 1);
	add(l1, 5);
	add(l1, 9);
	add(l1, 9);
	add(l1, 5);
	add(l1, 1);

	/*Número 157963*/
	Lista *l2 = iniciar();

	add(l2, 1);
	add(l2, 5);
	add(l2, 7);
	add(l2, 9);
	add(l2, 6);
	add(l2, 3);

	printf("159951 ");
	verifica_palindromo(l1);

	printf("157963 ");
	verifica_palindromo(l2);

	return 0;
}
