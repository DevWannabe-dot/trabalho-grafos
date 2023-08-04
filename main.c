/**
* @file     main.c
* @brief    Arquivo principal do programa
* @author   Bruna Santarelli, Marco T�lio Oliveira, Matheus Telles, Pedro Henrique
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

/* Proposta: Todos os her�is da Marvel e da DC, ou pelo menos grande parte deles, resolveram se juntar contra um grande vil�o para dar uma forcinha e fazer
um crossover divertido. Por�m isso acabou gerando um problema grave pois n�o sabemos mais quem luta com quem! V�rios her�is conversam entre si, enquanto 
outros s�o completamente desconexos, o que pode atrapalhar a luta. O seu papel � encontrar quais s�o os grupos mais coesos para formarem essa frente de 
batalha e derrotar o grande inimigo. */

int main() {
    grafo_t* grafo = grafo_cria(VALOR_TESTE);

    printf("Hello World\n");
    return 0;
}