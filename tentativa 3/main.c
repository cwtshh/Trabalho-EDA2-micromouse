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

GrafoMatrix *cria_grafo(int n) {
    GrafoMatrix *g = calloc(1, sizeof(GrafoMatrix));
    g->adj = calloc(n, sizeof(int*));
    g->n = n;
    for(int i = 0; i < g->n; i++) {
        g->adj[i] = calloc(n, sizeof(int));
    }
    return g;
}

int fazAcao(char action) {
    printf("%c\n", action);
    fflush(stdin);

    int resultado;
    scanf("%d", &resultado);
    fflush(stdin);

    return resultado;
}

int decide_lado(int retornoMoj) {
    int frente = (retornoMoj >> 0) & 1;
    int direita = (retornoMoj >> 1) & 1;
    int tras = (retornoMoj >> 2) & 1;
    int esquerda = (retornoMoj >> 3) & 1;

    if(direita == 1) {
        return 1;
    }
    else if (esquerda == 1) {
        return 2;
    }

    return -1;
}


int main() {
    GrafoMatrix *g = cria_grafo(MAX_SIZE);
    Rato *rato = calloc(1, sizeof(Rato));
    int pesoAtual = 0;
    rato->x = MAX_SIZE / 2;
    rato->y = MAX_SIZE / 2;

    int resMoj;

    fprintf(stderr, "Mapa Atual\n");
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            fprintf(stderr, "%d ", g->adj[i][j]);
        }
        fprintf(stderr, "\n");
    }

    while(resMoj != 2) {
        resMoj = fazAcao('w');

        switch (resMoj){
            case 0:
                resMoj = fazAcao('w');
                rato->y++;
                pesoAtual++;
                break;

            default:
                resMoj = fazAcao('c');
                
                switch(decide_lado(resMoj)) {
                    case 1:
                        resMoj = fazAcao('r');
                        rato->x++;
                        pesoAtual++;
                }



                printf("BATEU"); 

                break;
        }
    }


    // printa matriz
    /* for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    } */

    return 0;
}

