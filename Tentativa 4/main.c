#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3 * 3

typedef struct MATRIX {
    int n;
    int **adj;
} MATRIX;

typedef struct Caminho_pilha {
    int x;
    struct Caminho_pilha *prox;
} Caminho_pilha;

enum direcao{
    NORTE = 0,
    LESTE = 1,
    SUL = 2,
    OESTE = 3
};

typedef struct Rato {
    int x, y;
    enum direcao direction; // Add a variable name after the enum declaration.
} Rato;

int action(char action) {
    printf("%c\n", action);
    fflush(stdout);

    int resultado;
    scanf("%d", &resultado);
    fflush(stdin);

    return resultado;
}

int decide_lado() {
    int resultado = action('d');

    int frente = (resultado >> 0) & 1;
    int direita = (resultado >> 1) & 1;
    int tras = (resultado >> 2) & 1;
    int esquerda = (resultado >> 3) & 1;

    if(direita == 0 && esquerda == 0 && frente == 0 && tras == 1) {
        return 3;
    }

    if(frente == 1) {
        return 0;
    }

    if(direita == 1) {
        return 1;
    }
    else if (esquerda == 1) {
        return 2;
    }

    return -1;
}

void print_matrix(MATRIX *matrix) {
    for(int i = 0; i < matrix->n; i++) {
        for(int j = 0; j < matrix->n; j++) {
            fprintf(stderr, "|%d ", matrix->adj[i][j]);
        }
        fprintf(stderr, "|\n");
    }
}

void volta_caminho(MATRIX *matrix, Rato *rato) {
    // volta na matrix, em ordem decrescente 
    // até achar o 1
    enum direcao direcao_atual = rato->direction;


    
}

void procura_caminho(MATRIX *matrix, Rato *rato) {
    int retornoMoj = 0;
    int path = 1;

    while(retornoMoj != 2) {
        fprintf(stderr, "Tentando andar para frente...\n");
        retornoMoj = action('w');
        
        if(retornoMoj == 2) {
            fprintf(stderr, "Chegou no queijo!\n");
            break;
        }

        if(retornoMoj == 0) {
            fprintf(stderr, "bateu na parede... decide lado!\n");
            int lado_escolhido = decide_lado();

            if(lado_escolhido == 1) {
                fprintf(stderr, "decidiu ir para direita!\n");
                printf("%c\n", 'r');
                print_matrix(matrix);
                rato->direction = LESTE;
            }

            if(lado_escolhido == 2) {
                fprintf(stderr, "decidiu ir para esquerda!\n");
                printf("%c\n", 'l');
                print_matrix(matrix);
                rato->direction = OESTE;
            }
        }

        if(retornoMoj == 1 && rato->direction == NORTE) {
            fprintf(stderr, "andou para frente!\n");
            matrix->adj[rato->y][rato->x] = path;
            rato->y--;
            print_matrix(matrix);
            path++;
        }

        if(retornoMoj == 1 && rato->direction == SUL) {
            fprintf(stderr, "andou para frente!\n");
            matrix->adj[rato->y][rato->x] = path;
            rato->y++;
            print_matrix(matrix);
            path++;
        }

        if(retornoMoj == 1 && rato->direction == LESTE) {
            fprintf(stderr, "andou para frente!\n");
            matrix->adj[rato->y][rato->x] = path;
            rato->x++;
            print_matrix(matrix);
            path++;
        }

        if(retornoMoj == 1 && rato->direction == OESTE) {
            fprintf(stderr, "andou para frente!\n");
            matrix->adj[rato->y][rato->x] = path;
            rato->x--;
            print_matrix(matrix);
            path++;
        }
    }
}


int main() {
    // configs
    MATRIX *matrix = calloc(1, sizeof(MATRIX));
    matrix->n = MATRIX_SIZE;
    matrix->adj = calloc(matrix->n, sizeof(int*));

    for(int i = 0; i < matrix->n; i++) {
        matrix->adj[i] = calloc(matrix->n, sizeof(int));
    }

    Rato *rato = calloc(1, sizeof(Rato));
    rato->x = matrix->n / 2;
    rato->y = matrix->n / 2;

    int center = matrix->n / 2;
    matrix->adj[center][center] = -1;

    rato->x = center;
    rato->y = center;
    rato->direction = NORTE;





    // execucao
    print_matrix(matrix);
    procura_caminho(matrix, rato);







    // desaloca matrix
    for(int i = 0; i < matrix->n; i++) {
        free(matrix->adj[i]);
    }
    // desaloca rato
    free(matrix);
    free(rato);
    return 0;
}