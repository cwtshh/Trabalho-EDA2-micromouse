#ifndef grafo_h
#define grafo_h

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int x, y;
    int peso;
    struct No *cima, *esq, *dir, *baixo;
} No;

typedef struct Grafo {
    int n;
    No *adj;
} Grafo;




#endif /* grafo_h */
