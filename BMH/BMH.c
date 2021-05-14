#include "BMH.h"


int *BMH_PreProccessing(long TextDimension, long PatternDimension, char *Pattern)
{
    int index = 0;
    int *d = (int *)malloc(MAXCHAR * sizeof(int));

    for (int i = 0; i < MAXCHAR; i++)
    {
        d[index] = PatternDimension;
        index++;
    }
    for (int j = 1; j < PatternDimension; j++)
    {
        d[Pattern[j - 1]] = PatternDimension - j;
    }

    return d;
}

int BMH(char *Text, char *Pattern, long TextSize, long PatternSize, long *comp, long *desloc)
{   
    long i, j, k;
    int *d = BMH_PreProccessing(TextSize, PatternSize, Pattern);
    i = PatternSize;
    int frequency = 0;

    while (i <= TextSize)
    {
        k = i;
        j = PatternSize;
        while (j > 0 && Pattern[j - 1] == Text[k - 1])
        {
            //printf("i = %ld | j = %ld | k = %ld | d[Text[%ld]] = %d \n", i, j, k, i, d[Text[i]]); 
            (*comp)++;
            k--;
            j--;
        }

        if (j == 0)
        {
            printf("Matching: %ld\n", k+1);
            frequency = 1;
        } 
        (*desloc)+= i;
        i += d[Text[i]];
    }
    return frequency;
}
