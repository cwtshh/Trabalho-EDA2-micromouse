#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3 * 3

enum direcao {
    NORTE = 0,
    LESTE = 1,
    SUL = 2,
    OESTE = 3
};


typedef struct Rato {
    int x, y;
    enum direcao direction;
} Rato;


void gira_esquerda(Rato *rato) {
    if(rato->direction == NORTE) {
        rato->direction = OESTE;
        return;
    }

    if(rato->direction == OESTE) {
        rato->direction = SUL;
        return;
    }

    if(rato->direction == SUL) {
        rato->direction = LESTE;
        return;
    }

    if(rato->direction == LESTE) {
        rato->direction = NORTE;
        return;
    }
}

void gira_direita(Rato *rato) {
    if(rato->direction == NORTE) {
        rato->direction = LESTE;
        return;
    }

    if(rato->direction == LESTE) {
        rato->direction = SUL;
        return;
    }

    if(rato->direction == SUL) {
        rato->direction = OESTE;
        return;
    }

    if(rato->direction == OESTE) {
        rato->direction = NORTE;
        return;
    }
}

void print_direcao(Rato *r) {
    if(r->direction == NORTE) {
        printf("NORTE\n");
        return;
    }

    if(r->direction == LESTE) {
        printf("LESTE\n");
        return;
    }

    if(r->direction == SUL) {
        printf("SUL\n");
        return;
    }

    if(r->direction == OESTE) {
        printf("OESTE\n");
        return;
    }

}

int action(char action) {
    printf("%c\n", action);
    fflush(stdout);

    int resultado;
    scanf("%d", &resultado);
    fflush(stdin);

    return resultado;
}


int main() {
    Rato *rato = calloc(1, sizeof(Rato));
    rato->direction = NORTE;
    rato->x = 1;
    rato->y = 1;

    

    free(rato);
    return 0;
}