#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128 * 128

typedef struct GrafoMatrix {
    int n;
    int **adj;
} GrafoMatrix;

typedef struct Rato {
    int x;
    int y;
} Rato;


int main() {
    int retornoMoj;
    GrafoMatrix *g = calloc(1, sizeof(GrafoMatrix));
    g->adj = calloc(MAX_SIZE, sizeof(int*));
    g->n = MAX_SIZE;
    for(int i = 0; i < g->n; i++) {
        g->adj[i] = calloc(MAX_SIZE, sizeof(int));
    }

    scanf("%d", &retornoMoj);

    // printa matriz
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }

    free(g->adj);
    free(g);
    return 0;
}