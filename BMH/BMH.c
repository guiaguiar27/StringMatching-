#include "BMH.h"
char *BMH_getString(char *path)
{
    FILE *fl;
    fl = fopen(path, "r");
    char *ch = (char *)malloc(sizeof(char));
    int ch_aux, index = 0;

    do
    {
        ch_aux = fgetc(fl);
        ch[index] = ch_aux;
        //printf("%c",ch[index]);
        if (feof(fl))
            break;
        index++;
    } while (1);
}

long BMH_getTextSize(char *T)
{
    return (long)strlen(T);
}

int BMH_GetPatternSize(char *PString)
{
    printf("String: ");
    scanf("%s", PString);

    int index = 0;
    while (PString[index] != NULL)
    {
        index++;
    }
    return index;
}

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

int BMH(char *Text, char *Pattern, long TextSize, long PatternSize, long *comp, long *deslo)
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
            printf("i = %ld | j = %ld | k = %ld | d[Text[%ld]] = %d \n", i, j, k, i, d[Text[i]]);
            k--;
            j--;
        }

        if (j == 0)
        {
            printf("Matching: %ld\n", k);
            frequency++;
        }
        i += d[Text[i]];
    }
    return frequency;
}
int main()
{
    char *T = (char *)malloc(sizeof(char));
    //T = BMH_getString("teste.txt");
    T = "aabbaabbcdefaabb";
    long n = BMH_getTextSize(T);
    char *PString = malloc(sizeof(char));
    long m = BMH_GetPatternSize(PString);

    BMH(T, PString, n, m);
    return 0;
}