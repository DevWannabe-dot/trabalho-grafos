/**
* @file     main.c
* @brief    Arquivo principal do programa
* @author   Bruna Santarelli, Marco Túlio Oliveira, Matheus Telles, Pedro Henrique
* @date     2023-07-02
*/

/* Proposta: Todos os heróis da Marvel e da DC, ou pelo menos grande parte deles, resolveram se juntar contra um grande vilão para dar uma forcinha e fazer
um crossover divertido. Porém isso acabou gerando um problema grave pois não sabemos mais quem luta com quem! Vários heróis conversam entre si, enquanto
outros são completamente desconexos, o que pode atrapalhar a luta. O seu papel é encontrar quais são os grupos mais coesos para formarem essa frente de
batalha e derrotar o grande inimigo. */

// Inclusões
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
#define TAM_MAX_STRING_GENERICO (40+1)
#define N_GRUPOS_HEROIS         (7)

// Tipos
typedef struct grupos_herois_s {
    char nome[TAM_MAX_STRING_GENERICO];
    bool ehDaMarvel;
} grupos_t;

// Funções
void encontrarGrupos(grafo_t* G) {
    for (int i = 0; i < (*G).nVertices; i++) {
        int jaFoiImpresso = 0; // indica se um grupo está no processo de impressão (evitando a prática de variável global)
        if (!G->herois[i].visitado) {
            grafo_DFS_LST(*G, i, jaFoiImpresso); // passado uma cópia dos valores do grafo, uma vez que o único membro a ser modificado é herois_t* herois
        }
    }
}

int main(int argc, char** argv) {
    grafo_t* grafo = NULL;
    int nHerois = 0, op, h1, h2, nGruposHerois = 0;
    FILE* lista_herois = fopen("herois.txt", "r");
    char lixo, aux[TAM_MAX_STRING_GENERICO];

    // Acentuação em português (PODE CRASHAR NO CMD)
    setlocale(LC_CTYPE, "Portuguese");

    // Lê do arquivo os heróis
    if (lista_herois) {
        for (char c = getc(lista_herois); c != EOF; c = getc(lista_herois)) {
            if (c == '\n') nHerois++;
        }

        grafo = grafo_cria(nHerois);

        int i = 0;
        fseek(lista_herois, 0, SEEK_SET);
        while (!feof(lista_herois)) {
            fgets(aux, TAM_MAX_STRING_GENERICO, lista_herois);
            if (strcmp(aux, "---DC---") != 0) {
                strcpy(HEROIS_DADOS(grafo->herois, i), aux);
            }
            removeQuebraLinhaFinal(HEROIS_DADOS(grafo->herois, i));
            i++;
        }
    } else {
        printf("Erro ao abrir a lista de herois\n");
        return 1;
    }

    // Imprimir menu
    do {
        imprimirCadeiaDeCaracter('-', NUMERO_TRACINHOS);
        printf("\n(0) Finalizar e ver grupos\n(1) Nova relação entre dois heróis\n(2) Ver lista de heróis\n>> ");
        scanf("%i%c", &op, &lixo);
        imprimirCadeiaDeCaracter('-', NUMERO_TRACINHOS);
        puts("");

        switch (op) {
        case 0:
            encontrarGrupos(grafo);
            break;
        case 1:
            printf("Indique os dois heróis a partir de seus respectivos números na lista\nPrimeiro: ");
            scanf("%i%c", &h1, &lixo);
            printf("Segundo: ");
            scanf("%i%c", &h2, &lixo);
            grafo_adicionaAresta(grafo, h1, h2);
            break;
        case 2:
            printf("Herois da Marvel: \n");
            for (int i = 0; i < nHerois; i++) {
                if (i == 25) printf("\n\nHerois da DC: \n");
                printf("%i\t%s\n", i, HEROIS_DADOS(grafo->herois, i));
            }
            break;
        default:
            fprintf(stderr, "OPCAO INVALIDA\n");
            break;
        }
    } while (op);

    // Liberar ponteiros e fechar arquivos (PODE CRASHAR NO VISUAL STUDIO)
    for (int i = 1; i < GRAFO_UNICO(grafo).nVertices; i++) {
        free(GRAFO_UNICO(grafo).listasAdjacencia[i]);
    }
    free(GRAFO_UNICO(grafo).listasAdjacencia);
    free(GRAFO_UNICO(grafo).herois);
    free(grafo);
    fclose(lista_herois);

    return 0;
}