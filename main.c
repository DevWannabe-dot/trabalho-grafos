/**
* @file     main.c
* @brief    Arquivo principal do programa
* @author   Bruna Santarelli, Marco Túlio Oliveira, Matheus Telles, Pedro Henrique
* @date     2023-07-02
*/

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "fila.h"
#include "pilhas.h"
#include "grafos.h"

#define SUCESSO     (0)
#define VALOR_TESTE (5)

/* Proposta: Todos os heróis da Marvel e da DC, ou pelo menos grande parte deles, resolveram se juntar contra um grande vilão para dar uma forcinha e fazer
um crossover divertido. Porém isso acabou gerando um problema grave pois não sabemos mais quem luta com quem! Vários heróis conversam entre si, enquanto 
outros são completamente desconexos, o que pode atrapalhar a luta. O seu papel é encontrar quais são os grupos mais coesos para formarem essa frente de 
batalha e derrotar o grande inimigo. */

int main() {
    grafo_t* grafo = grafo_cria(VALOR_TESTE);

    printf("Hello World\n");
    return 0;
}