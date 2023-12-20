#ifndef pilha_h
#define pilha_h

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

Pilha *cria_pilha() {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void insere_pilha(Pilha *pilha, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

No *retira_pilha(Pilha *pilha) {
    if (pilha->topo == NULL) {
        return NULL;
    } else {
        No *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        return aux;
    }
}

void destroi_pilha(Pilha *pilha) {
    No *aux = pilha->topo;
    while (aux != NULL) {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(pilha);
}

#endif