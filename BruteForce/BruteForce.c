#include "BruteForce.h"

int BruteForce(typeText text, long textSize, typePattern pattern, long patternSize, long *comp, long *desloc)
{
    long i, j, k, find = 0;
    for (i = 1; i <= (textSize - patternSize + 1); i++)
    {
        (*desloc)++;
        k = i;
        j = 1;
        (*comp)++;
        while (text[k - 1] == pattern[j - 1] && j <= patternSize)
        {
            (*comp)++;
            (*desloc)++;
            j++;
            k++;
        }
        if (j > patternSize)
        {
            printf(" - - Casamento na posicao %ld\n", i);
            find += 1;
        }
    }
    return find;
}
