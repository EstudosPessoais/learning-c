#include <stdio.h>
#include <stdlib.h>

struct prato
{
    char cor;
    struct prato *prox;
} typedef Prato;

Prato *pilha;

void add(char cor)
{
    Prato *p = (Prato *)malloc(sizeof(Prato));
    p->cor = cor;
    p->prox = pilha;
    pilha = p;
}

void imprime(Prato *p)
{
    if (p != NULL)
    {
        printf("\nCor do prato: %c", p->cor);
        imprime(p->prox);
    };
}

void removeStack()
{
    if (pilha == NULL)
    {
        printf("Pilha vazia");
    }
    else
    {
        pilha = pilha->prox;
    }
}

int main()
{
    add('b');
    add('r');
    add('g');
    removeStack();

    Prato *pilhaAux = pilha;
    imprime(pilhaAux);

    return 0;
}