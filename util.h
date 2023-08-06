/**
* @file     util.h
* @brief    Biblioteca com funções auxiliares
* @author   Pedro Henrique
* @date     2023-01-26
*/

#pragma once
#ifndef __UTIL_h__
#define __UTIL_h__

// Inclusões
#include <stdio.h>
#include <string.h>
#include "util.h"

// Constantes
#define TAM_MAX_NOME    (100+1)

// Tipos

// Funcoes
void imprimirCadeiaDeCaracter(char caracter, int N) {
    for (int i = 0; i < N; i++) {
        printf("%c", caracter);
    }
}

void removeQuebraLinhaFinal(char dados[]) {
    int tamanho = (int) strlen(dados);

    if (tamanho && dados[tamanho - 1] == '\n') {
        dados[tamanho - 1] = '\0';
    }
}

#endif