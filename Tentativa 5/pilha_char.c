#include <stdlib.h>
#include <stdio.h>

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


int main() {
    CharStack *p = inicializa_pilha();

    empilha(p, 'a');
    empilha(p, 'b');
    empilha(p, 'c');

    printa_pilha(p);

    printf("%c", desempilha(p));

    free(p);

    return 0;
}