#ifndef fila_h
#define fila_h

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

Fila *cria_fila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void insere_fila(Fila *fila, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

No *retira_fila(Fila *fila) {
    if (fila->inicio == NULL) {
        return NULL;
    } else {
        No *aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        return aux;
    }
}

void destroi_fila(Fila *fila) {
    No *aux = fila->inicio;
    while (aux != NULL) {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(fila);
}


#endif /* fila_h */