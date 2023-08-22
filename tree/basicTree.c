#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
    struct nodo *esq;
    struct nodo *dir;
} typedef Nodo;

Nodo *create(int valor)
{
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    n->valor = 5;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

void imprimir(Nodo *n)
{
    if (n == NULL)
        return;
    imprimir(n->esq);
    printf("\n%d", n->valor);
    imprimir(n->dir);
}

int main()
{
    Nodo *nodo5 = create(5);
    Nodo *nodo2 = create(2);
    Nodo *nodo1 = create(1);
    Nodo *nodo8 = create(8);
    Nodo *nodo4 = create(4);

    nodo5->esq = nodo2;
    nodo2->esq = nodo1;
    nodo5->dir = nodo8;
    nodo2->dir = nodo4;

    imprimir(nodo5);

    return 0;
}