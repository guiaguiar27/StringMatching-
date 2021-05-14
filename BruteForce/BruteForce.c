#include "BruteForce.h"

int BruteForce(typeText texto, long tamTexto, typePattern padrao, long tamPadrao, long *comp, long *desloc)
{
    long i, j, k, find = 0;
    for (i = 1; i <= (tamTexto - tamPadrao + 1); i++)
    {
        (*desloc)++;
        k = i;
        j = 1;
        (*comp)++;
        while (texto[k - 1] == padrao[j - 1] && j <= tamPadrao)
        {
            (*comp)++;
            (*desloc)++;
            j++;
            k++;
        }
        if (j > tamPadrao)
        {
            printf(" - - Casamento na posicao %ld\n", i);
            find += 1;
        }
    }
    return find;
}
