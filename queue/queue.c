#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
    int senha;
    struct pessoa *prox;
} typedef Pessoa;

Pessoa *fila;

void add(int senha)
{
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    p->senha = senha;
    p->prox = NULL;

    if (fila == NULL)
    {
        fila = p;
    }
    else
    {
        Pessoa *filaAux = fila;
        while (filaAux->prox != NULL)
        {
            filaAux = filaAux->prox;
        }
        filaAux->prox = p;
    }
}

void removeFila()
{
    if (fila == NULL)
    {
        printf("Fila Vazia");
    }
    else
    {
        fila = fila->prox;
    }
}

void imprime(Pessoa *f)
{
    if (f != NULL)
    {
        printf("\nSenha da pessoa %d", f->senha);
        imprime(f->prox);
    }
}

int main()
{
    add(5);
    add(10);
    add(20);
    removeFila();

    imprime(fila);

    return 0;
}