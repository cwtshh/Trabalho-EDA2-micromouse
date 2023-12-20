#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct No {
    int x;
    int y;
    int pesoFilho;
    int pesoPai;
    struct No *ant;
    struct No *prox;
} No;

typedef struct Pilha {
    char comando;
    struct Pilha *prox;
} Pilha;


typedef struct grafo {
    int n;
    No *adj;
} grafo;


typedef struct rato {
    int x;
    int y;
} rato;

int fazAcao(char acao) {
    printf("%c\n", acao);
    fflush(stdin);

    int retornoMoj;
    scanf("%d", &retornoMoj);
    fflush(stdin);

    return retornoMoj;
}

void cria_No(grafo *g, int x, int y, int pesoFilho, int pesoPai) {
    No *novo = calloc(1, sizeof(No));
    novo->x = x;
    novo->y = y;
    novo->pesoFilho = pesoFilho;
    novo->pesoPai = pesoPai;
    novo->prox = g->adj[x].prox;
    g->adj[x].prox = novo;
}

Pilha *cria_pilha() {
    Pilha *p = calloc(1, sizeof(Pilha));
    return p;
}

void empilha(Pilha *p, char comando) {
    Pilha *novo = cria_pilha();
    novo->comando = comando;
    novo->prox = p->prox;
    p->prox = novo;
}

char desempilha(Pilha *p) {
    Pilha *aux = p->prox;
    char comando = aux->comando;
    p->prox = aux->prox;
    free(aux);
    return comando;
}

/* 
O peso definirá o quanto o rato deve andar
para chegar até o próximo nó.
*/


int main() {
    int res;
    grafo *g = calloc(1, sizeof(grafo));
    g->adj = calloc(MAX_SIZE, sizeof(No));
    g->n = MAX_SIZE;
    Pilha *p = cria_pilha();

    // primeiro no
    cria_No(g, 0, 0, 0, 0);

    // explora a labirinto
    while(res != 2) {
        res = fazAcao('w');

        // bateu na parede
        if(res == 0) {
            // so cria um no quando mudar de direcao
            int resMoj = fazAcao('c');

            int frente = (resMoj & 0) & 1;
            int direita = (resMoj & 1) & 1;
            int tras = (resMoj & 2) & 1;
            int esquerda = (resMoj & 3) & 1;

            // se não tem parede na frente
            if(frente == 1) {
                res = fazAcao('w');
                continue;
            }

            // se não tem parede na direita
            if(direita == 1) {
                res = fazAcao('r');

                empilha(p, 'r');
                continue;
            }

            // se não tem parede na esquerda
            if(esquerda == 1) {
                res = fazAcao('l');
                empilha(p, 'l');
                continue;
            }

            




        }
    }


}