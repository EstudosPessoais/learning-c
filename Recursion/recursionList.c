#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    float x;
    float y;
    struct ponto *prox;
} typedef Ponto;

Ponto *listaPontos;

int lenght = 0;

// Adiciona no começo da Lista;
void addFirst(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;
    lenght++;
}

// Adiciona no final da Lista
void addLast(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = NULL;
    if (listaPontos == NULL)
    {
        listaPontos = p;
    }
    else
    {
        Ponto *listaAux = listaPontos;
        while (listaAux->prox != NULL)
        {
            listaAux = listaAux->prox;
        }
        listaAux->prox = p;
        lenght++;
    }
}

// Função adiciona em qualquer lugar da lista
void addIndex(float x, float y, int index)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;

    if (index > lenght)
    {
        printf("Posicao invalida");
    }
    else
    {
        if (index == 0)
        {
            p->prox = listaPontos;
            listaPontos = p;
        }
        else
        {
            Ponto *listaAux = listaPontos;
            int i = 0;
            while (i != index - 1)
            {
                listaAux = listaAux->prox;
                i++;
            }

            p->prox = listaAux->prox;
            listaAux->prox = p;
        }
        lenght++;
    }
}

// Função que imprime
void imprime(Ponto *p)
{

    if (p != NULL)
    {
        printf("\nPonto (%.1f,%.1f)", p->x, p->y);
        imprime(p->prox);
    }
}

// Main function
int main()
{
    addFirst(1, 5);
    addFirst(2, 7);
    addFirst(5, 3);
    addLast(1, 1);
    addLast(8, 8);
    addIndex(9, 9, 3);
    addIndex(10, 10, 3);

    Ponto *auxLista = listaPontos;

    imprime(auxLista);

    return 0;
};