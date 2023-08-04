/**
* @file     grafos.h
* @brief    Biblioteca de grafos, funções e macros
* @author   Bruna Santarelli, Marco Túlio Oliveira, Matheus Telles, Pedro Henrique
* @date     2023-07-02
*/

#pragma once
#ifndef __GRAFOS_h__
#define __GRAFOS_h__

// Inclusoes
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "listas.h"
#include "fila.h"
#include "pilhas.h"

// Constantes
#define FALHA 1
#define N_EXISTE (-1)

#define ARESTA 1

#define BRANCO 0
#define CINZA 1
#define PRETO 2

// Tipos
typedef struct grafo_s {
    int nVertices;
    int* verticesVisitados;
    Lista** listasAdjacencia; // array de listas de adjacência
} grafo_t;

// Funcoes
grafo_t* grafo_cria(int nVertices) {
    grafo_t* G = (grafo_t*)malloc(sizeof(grafo_t));

    G->nVertices = nVertices;
    G->listasAdjacencia = (Lista**)malloc(sizeof(Lista*) * nVertices);
    G->verticesVisitados = (int*)calloc(sizeof(int), nVertices);

    for (int i = 0; i < nVertices; i++) {
        G->listasAdjacencia[i] = NULL;
    }

    return G;
}

void grafo_adicionaAresta(grafo_t* G, int ini, int fim) {
    // cria aresta do vertice de inicio para o de fim
    Lista* novaLista = lista_insere(NULL, fim);
    novaLista->prox = G->listasAdjacencia[ini];
    G->listasAdjacencia[ini] = novaLista;

    // cria aresta do vertice do fim para o de inicio
    novaLista = lista_insere(NULL, ini);
    novaLista->prox = G->listasAdjacencia[fim];
    G->listasAdjacencia[fim] = novaLista;
}

void grafo_DFS_LST(grafo_t G, int vertice) {
    Lista* listaAdjacencia = G.listasAdjacencia[vertice];
    Lista* temp = listaAdjacencia;

    G.verticesVisitados[vertice] = 1;
    printf("Percorrido vertice %d\n", vertice);

    for (temp; temp != NULL; temp = temp->prox) {
        int verticeAtual = temp->info;

        if (G.verticesVisitados[verticeAtual] == 0) {
            grafo_DFS_LST(G, verticeAtual);
        }
    }
}


void grafo_BFS_LST(Lista** grafo_l, int source, int quant_vert) {

    Lista* tmp;
    FilaL* Fila_aux = fila_cria_l();

    int* origem, * distancia, * cor;
    int i, vertice, vert_ant = 0;

    //Inicializa cor como 0 (BRANCO)
    cor = (int*)calloc(quant_vert, sizeof(int));
    origem = (int*)malloc(quant_vert * sizeof(int));
    distancia = (int*)calloc(quant_vert, sizeof(int));

    fila_insere_l(Fila_aux, source);

    while (fila_vazia_l(Fila_aux) != FALHA) {

        vertice = fila_retira_l(Fila_aux);

        if (vertice == source) {
            cor[vertice] = CINZA;
            origem[vertice] = N_EXISTE;
        }
        else {
            vert_ant = origem[vertice];
            distancia[vertice] = distancia[vert_ant] + 1;
        }

        tmp = grafo_l[vertice]->prox;

        while (tmp != NULL) {

            if (cor[tmp->info] == BRANCO) {
                fila_insere_l(Fila_aux, tmp->info);
                origem[tmp->info] = vertice;
                cor[tmp->info] = CINZA;
            }

            tmp = tmp->prox;
        }

        cor[vertice] = PRETO;
    }

    printf(" Vértice | Antecessor  | Distância\n");
    for (i = 0; i < quant_vert; i++) {
        if (origem[i] != N_EXISTE) {
            printf(" %d\t | %d\t       | %d\n", i, origem[i], distancia[i]);
        }
        else {
            printf(" %d\t | --\t       | %d\n", i, distancia[i]);
        }
    }
}

#endif