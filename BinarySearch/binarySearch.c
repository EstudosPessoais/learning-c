#include <stdio.h>

int v[100];

int main()
{

    // Preenche vetor
    for (int i = 0; i < 100; i++)
    {
        v[i] = i + 1;
    }

    int comparacoes = 0;

    int continuar = 1;

    int num = 50;

    int ini = 0;

    int fim = 99;

    while (continuar == 1)
    {
        comparacoes++;
        int pivo = (ini + fim) / 2;
        if (v[pivo] == num)
        {
            printf("Elemento encontrado\n");
            continuar = 0;
        }
        else
        {
            if (num > v[pivo])
            {
                ini = pivo + 1;
            }
            else
            {
                fim = pivo - 1;
            }
        }

        if (fim < ini)
        {
            continuar = 0;
            printf("Elemento não encontrado!\n");
        }
    }

    printf("Comparações: %d", comparacoes);

    return 0;
}