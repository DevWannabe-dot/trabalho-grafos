/**
* @file     listas.h
* @brief    Biblioteca de listas pela profa. Dra. Virgínia Mota
* @author   Virgínia Fernandes Mota
* @date     2023-03-10
*/

#pragma once
#ifndef __LISTAS_h__
#define __LISTAS_h__

#include <stdio.h>
#include <stdlib.h>

// Tipos
typedef struct Lista {
	int info;
	struct Lista* prox;
} Lista;

//Funcoes de lista encadeada

Lista* lista_cria() {
	return NULL;
}

Lista* lista_insere(Lista* l, int i) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));

	novo->info = i;
	novo->prox = l;

	return novo;
}

void lista_imprime(Lista* l) {
	Lista* p;

	for (p = l; p != NULL; p = p->prox) {
		printf("Valor: %d\n", p->info);
	}
}

int lista_vazia(Lista* l) {
	if (l == NULL)
		return 1;

	else
		return 0;
}

Lista* lista_busca(Lista* l, int v) {
	Lista* p;

	for (p = l; p != NULL; p = p->prox) {
		if (p->info == v) {
			return p;
		}
	}

	printf("Elemento não encontrado\n");

	return NULL;
}

Lista* lista_retira(Lista* l, int v) {
	Lista* p = l;
	Lista* ant = NULL;

	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}

	if (p == NULL) {
		printf("Elemento nÃ£o encontrado\n");
		return l;
	}

	if (ant == NULL) {
		l = p->prox;
	}

	else {
		ant->prox = p->prox;
	}

	free(p);
	return l;
}

void lista_libera(Lista* l) {
	Lista* p = l;

	while (p != NULL) {
		Lista* t = p->prox;
		free(p);
		p = t;
	}
}

Lista* lista_insere_ordenado(Lista* l, int v) {
	Lista* novo;

	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;

	Lista* ant = NULL;
	Lista* p = l;

	while (p != NULL && p->info < v) {
		ant = p;
		p = p->prox;
	}

	if (ant == NULL) {
		novo->prox = l;

		return novo;
	}

	else {
		ant->prox = novo;
		novo->prox = p;

		return l;
	}
}

int lista_tamanho(Lista* l) {
	Lista* p = l;
	int tam = 0;

	for (p = l; p != NULL; p = p->prox) {
		tam++;
	}

	return tam;
}

int lista_igual(Lista* l1, Lista* l2) {
	Lista* p1;
	Lista* p2;
	int tam1 = 0, tam2 = 0;

	//calculando o tamanho
	tam1 = lista_tamanho(l1);
	tam2 = lista_tamanho(l2);

	p1 = l1;
	p2 = l2;

	if (tam1 != tam2) {
		return 0; //diferente
	}

	else {
		while (p1 != NULL) {
			if (p1->info == p2->info) {
				p1 = p1->prox;
				p2 = p2->prox;
			}

			else return 0; //diferente
		}
	}

	return 1; //igual
}

#endif