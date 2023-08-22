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

void add(Nodo *n, int valor)
{
    if (valor < n->valor)
    {
        if (n->esq == NULL)
            n->esq = create(valor);
        else
            add(n->esq, valor);
    }

    else
    {
        if (n->dir == NULL)
            n->dir = create(valor);
        else
            add(n->dir, valor);
    }
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
    Nodo *root = create(5);

    add(root, 2);
    add(root, 1);
    add(root, 8);
    add(root, 4);

    imprimir(root);

    return 0;
}