#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10

// 0000 
// 13 esq
// 14 dir
// 15 frente
// 16 tras

typedef struct MATRIX {
    int n;
    int **adj;
} MATRIX;

typedef struct Caminho_pilha {
    int x;
    struct Caminho_pilha *prox;
} Caminho_pilha;

enum vira {
    CIMA = 0,
    DIREITA = 1,
    BAIXO = 2,
    ESQUERDA = 3
};

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


// pilha de comandos
typedef struct {
    char *data;
    int top;
} CharStack;


CharStack *inicializa_pilha() {
    CharStack *p = calloc(1, sizeof(CharStack));
    p->data = calloc(100, sizeof(char));
    p->top = -1;

    return p;
}

char desempilha(CharStack *p) {
    if (p->top == -1) {
        printf("Pilha vazia\n");
        return 0;
    }

    char data = p->data[p->top];
    p->top--;

    return data;
}

void empilha(CharStack *p, char data) {
    if (p->top == 99) {
        printf("Pilha cheia\n");
        return;
    }

    p->top++;
    p->data[p->top] = data;
}

void printa_pilha(CharStack *p) {
    for (int i = 0; i <= p->top; i++) {
        printf("%c ", p->data[i]);
    }
    printf("\n");
}

// acoes rato
int action(char action) {
    printf("%c\n", action);
    fflush(stdout);

    int resultado;
    scanf("%d", &resultado);
    fflush(stdin);

    return resultado;
}

void print_matrix(MATRIX *matrix) {
    for(int i = 0; i < matrix->n; i++) {
        for(int j = 0; j < matrix->n; j++) {
            fprintf(stderr, "|  %d  ", matrix->adj[i][j]);
        }
        fprintf(stderr, "|\n");
    }
}

int verifica_se_tem_varios_caminhos(int retornoMoj) {
    int frente = (retornoMoj >> 0) & 1;
    int direita = (retornoMoj >> 1) & 1;
    int tras = (retornoMoj >> 2) & 1;
    int esquerda = (retornoMoj >> 3) & 1;

    int caminhos_possiveis = frente + direita + esquerda + tras;
    fprintf(stderr, "caminhos_possiveis: %d\n", caminhos_possiveis);

    if(caminhos_possiveis > 1) {
        return 1;
    }

    return 0;
}


int decide_direcao(int retornoMoj) {
    int frente = (retornoMoj >> 0) & 1;
    int direita = (retornoMoj >> 1) & 1;
    int tras = (retornoMoj >> 2) & 1;
    int esquerda = (retornoMoj >> 3) & 1;

    fprintf(stderr,"frente: %d\ndireita: %d\ntras: %d\nesquerda: %d\n", frente, direita, tras, esquerda);

    if(direita == 1) return 1;

    else if(esquerda == 1) return 2;

    else if(frente == 1) return 3;

    else if(tras == 1) return 4;

    return 0;
}

int check_next_move(MATRIX *matrix, Rato *rato) {
    if(rato->direction == NORTE) {
        if(matrix->adj[rato->x][rato->y - 1] != 0) {
            return 1;
        }
        return 0;
    }

    if(rato->direction == LESTE) {
        if(matrix->adj[rato->x + 1][rato->y] != 0) {
            return 1;
        }
        return 0;
    }

    if(rato->direction == SUL) {
        if(matrix->adj[rato->x][rato->y + 1] != 0) {
            return 1;
        }
        return 0;
    }

    if(rato->direction == OESTE) {
        if(matrix->adj[rato->x - 1][rato->y] != 0) {
            return 1;
        }
        return 0;
    }
}

void gira_esquerda(Rato *rato) {
    if(rato->direction == NORTE) {
        printf("%c\n", 'l');
        fflush(stdout);
        rato->direction = OESTE;

        return;
    }

    if(rato->direction == OESTE) {
        printf("%c\n", 'l');
        fflush(stdout);
        rato->direction = SUL;

        return;
    }

    if(rato->direction == SUL) {
        printf("%c\n", 'l');
        fflush(stdout);
        rato->direction = LESTE;

        return;
    }

    if(rato->direction == LESTE) {
        printf("%c\n", 'l');
        fflush(stdout);
        rato->direction = NORTE;

        return;
    }
}

void gira_direita(Rato *rato) {
    if(rato->direction == NORTE) {
        printf("%c\n", 'r');
        fflush(stdout);

        rato->direction = LESTE;
        return;
    }

    if(rato->direction == SUL) {
        printf("%c\n", 'r');
        fflush(stdout);

        rato->direction = OESTE;
        return;
    }

    if(rato->direction == LESTE) {
        printf("%c\n", 'r');
        fflush(stdout);

        rato->direction = SUL;
        return;
    
    }

    if(rato->direction == OESTE) {
        printf("%c\n", 'r');
        fflush(stdout);

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

int ja_foi_visitado(MATRIX *matrix, Rato *rato) {
    if(rato->direction == NORTE) {
        if(matrix->adj[rato->y - 1][rato->x] != 0) {
            return 1;
        }
        return 0;
    }

    if(rato->direction == LESTE) {
        if(matrix->adj[rato->y][rato->x + 1] != 0) {
            return 1;
        }
        return 0;
    }

    if(rato->direction == SUL) {
        if(matrix->adj[rato->y + 1][rato->x] != 0) {
            return 1;
        }
        return 0;
    }

    if(rato->direction == OESTE) {
        if(matrix->adj[rato->y][rato->x - 1] != 0) {
            return 1;
        }
        return 0;
    }
}

void volta_ate_ultimo(MATRIX *matrix, Rato *rato, CharStack *pilha, int destino) {
    fprintf(stderr, "posicao atual: (%d, %d)\n", rato->x, rato->y);

}

void acha_caminho(MATRIX *matrix, Rato *rato, CharStack *pilha) {
    int retornoMoj = 0;
    int path = 1;
    int first_backtrack = -1;

    while(retornoMoj != 2) {
        retornoMoj = action('w');

        if(retornoMoj == 2) break;

        // muda a direcao do rato
        if(retornoMoj == 0) {
            int sensor_res = action('c');
            fprintf(stderr, "sensor_res: %d\n", sensor_res);

            // verifica se a casa tem mais de um caminho
            if(verifica_se_tem_varios_caminhos(sensor_res) == 1) {
                fprintf(stderr, "tem varios caminhos\n");
                first_backtrack = path;
            }

            // se nao tiver nenhum caminho volta até o first_backtrack
            if(verifica_se_tem_varios_caminhos(sensor_res) == 0) {
                fprintf(stderr, "nao tem caminhos possiveis\n");
                break;
            }

            /* fprintf(stderr, "sensor_res: %d\n", sensor_res); */
            int nova_direcao = decide_direcao(sensor_res);
            /* fprintf(stderr, "nova_direcao: %d\n", nova_direcao); */
            
            switch (nova_direcao) {
                case 1:
                    gira_direita(rato);
                    empilha(pilha, 'r');
                    break;

                case 2:
                    gira_esquerda(rato);
                    empilha(pilha, 'l');
                    break;

                case 3:
                    break;

                case 4:
                    gira_direita(rato);
                    gira_direita(rato);
                    empilha(pilha, 'r');
                    empilha(pilha, 'r');
                    break;
            }
            continue;
        }

        if(ja_foi_visitado(matrix, rato)) {
            if(first_backtrack != -1) {
                volta_ate_ultimo(matrix, rato, pilha, first_backtrack);
            }
            break;
        }

        // anda com o rato
        if(rato->direction == NORTE) {
            matrix->adj[rato->y - 1][rato->x] = path;
            rato->y--;
            path++;
            print_matrix(matrix);
            empilha(pilha, 'w');
        }

        if(rato->direction == OESTE) {
            matrix->adj[rato->y][rato->x - 1] = path;
            rato->x--;
            path++;
            print_matrix(matrix);
            empilha(pilha, 'w');
        }

        if(rato->direction == LESTE) {
            matrix->adj[rato->y][rato->x + 1] = path;
            rato->x++;
            path++;
            print_matrix(matrix);
            empilha(pilha, 'w');
        }

        if(rato->direction == SUL) {
            matrix->adj[rato->y + 1][rato->x] = path;
            rato->y++;
            path++;
            print_matrix(matrix);
            empilha(pilha, 'w');
        }

    }

    printa_pilha(pilha);
}


int main() {
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

    CharStack *pilha = inicializa_pilha();


    print_matrix(matrix);
    acha_caminho(matrix, rato, pilha);





    
    for(int i = 0; i < matrix->n; i++) {
        free(matrix->adj[i]);
    }
    free(matrix->adj);
    free(matrix);
    free(rato);

    return 0;
}