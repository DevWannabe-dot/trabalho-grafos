/**
* @file     main.c
* @brief    Arquivo principal do programa
* @author   Bruna Santarelli, Marco T�lio Oliveira, Matheus Telles, Pedro Henrique
* @date     2023-07-02
*/

/* Proposta: Todos os her�is da Marvel e da DC, ou pelo menos grande parte deles, resolveram se juntar contra um grande vil�o para dar uma forcinha e fazer
um crossover divertido. Por�m isso acabou gerando um problema grave pois n�o sabemos mais quem luta com quem! V�rios her�is conversam entre si, enquanto
outros s�o completamente desconexos, o que pode atrapalhar a luta. O seu papel � encontrar quais s�o os grupos mais coesos para formarem essa frente de
batalha e derrotar o grande inimigo. */

// Inclus�es
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"
#include "fila.h"
#include "pilhas.h"
#include "grafos.h"

// Constantes
#define SUCESSO         (0)
#define VALOR_TESTE     (5)

// Tipos

// Fun��es
void encontrarGrupos(grafo_t* G) {
    for (int i = 0; i < (*G).nVertices; i++) {
        if (!G->herois[i].visitado) {
            printf("Grupo: ");
            grafo_DFS_LST(*G, i);
            puts("");
        }
    }
}


int main() {
    grafo_t* grafo = grafo_cria(VALOR_TESTE); // uso de ponteiro para permitir, na intera��o com usu�rio, criar v�rios "multiversos"?

    strcpy(grafo[0].herois[0].nome, "Batman");
    strcpy(grafo[0].herois[1].nome, "Superman");
    strcpy(grafo[0].herois[2].nome, "Homem de ferro");
    strcpy(grafo[0].herois[3].nome, "Aquaman");
    strcpy(grafo[0].herois[4].nome, "Viuva Negra");

    // Herois da DC
    grafo_adicionaAresta(grafo, 0, 1);
    grafo_adicionaAresta(grafo, 0, 3);
    grafo_adicionaAresta(grafo, 1, 3);
    // Herois da Marvel
    grafo_adicionaAresta(grafo, 2, 4);

    encontrarGrupos(&grafo[0]);

    return 0;
}