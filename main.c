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
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include "util.h"
#include "listas.h"
#include "fila.h"
#include "pilhas.h"
#include "grafos.h"

// Constantes
#define SUCESSO                 (0)
#define NUMERO_TRACINHOS        (30)
#define TAM_MAX_STRING_GENERICO (20+1)

// Tipos

// Fun��es
void encontrarGrupos(grafo_t* G) {
    for (int i = 0; i < (*G).nVertices; i++) {
        if (!G->herois[i].visitado) {
            grafo_DFS_LST(*G, i); // passado uma c�pia dos valores do grafo, uma vez que o �nico membro a ser modificado � herois_t* herois
            puts("");
        }
    }
}

int main(int argc, char** argv) {
    grafo_t* grafo = NULL;
    int nHerois = 0, i, op, h1, h2;
    FILE* lista_herois = fopen("herois.txt", "r");
    char lixo;
    char aux[TAM_MAX_STRING_GENERICO];

    // Acentua��o em portugu�s
    setlocale(LC_CTYPE, "Portuguese");

    // L� do arquivo os her�is
    if (lista_herois) {
        while (!feof(lista_herois)) {
            grafo = grafo_cria(nHerois);

            fgets(aux, TAM_MAX_NOME, lista_herois);
            if (!isupper((int)aux[3 - 1])) {
                strcpy(HEROIS_DADOS(grafo->herois, nHerois), aux);
                removeQuebraLinhaFinal(HEROIS_DADOS(grafo->herois, i));
            }
            nHerois++;
        }
    } else {
        printf("Erro ao abrir a lista de herois\n");
        return 1;
    }

    // Imprimir menu
    do {
        imprimirCadeiaDeCaracter('-', NUMERO_TRACINHOS);
        printf("\n(0) Finalizar e ver grupos\n(1) Nova rela��o entre dois her�is\n(2) Ver lista de her�is\n>> ");
        scanf("%i%c", &op, &lixo);
        imprimirCadeiaDeCaracter('-', NUMERO_TRACINHOS);
        puts("");

        switch (op) {
        case 0:
            encontrarGrupos(grafo);
            break;
        case 1:
            printf("Indique os dois her�is a partir de seus respectivos n�meros na lista\nPrimeiro: ");
            scanf("%i%c", &h1, &lixo);
            printf("Segundo: ");
            scanf("%i%c", &h2, &lixo);
            grafo_adicionaAresta(grafo, h1, h2);
            break;
        case 2:
            for (i = 0; i < nHerois; i++) {
                printf("%i\t%s\n", i, HEROIS_DADOS(grafo->herois, i));
            }
            break;
        default:
            fprintf(stderr, "OPCAO INVALIDA\n");
            break;
        }
    } while (op);

    // Liberar ponteiros e fechar arquivos
    for (int i = 0; i < GRAFO_UNICO(grafo).nVertices; i++) {
        free(GRAFO_UNICO(grafo).listasAdjacencia[i]);
    }
    free(GRAFO_UNICO(grafo).listasAdjacencia);
    free(GRAFO_UNICO(grafo).herois);
    free(grafo);
    fclose(lista_herois);

    return 0;
}