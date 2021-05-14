#include "BMH.h"


void BMH_PreProccessing(long *d, long TextDimension, long PatternDimension, char *Pattern) 
{

    for (int i = 0; i <= MAXCHAR; i++)
    {
        d[i] = PatternDimension +1;
    }
    for (int j = 1; j <= PatternDimension; j++)
    {
        d[Pattern[j - 1]] = PatternDimension - j +1 ;
    }
   
}

int BMH(char *Text, char *Pattern, long TextSize, long PatternSize, long *comp, long *desloc)
{   
    long i, j, k, d[MAXCHAR + 1],frequency;
    BMH_PreProccessing(d,TextSize, PatternSize, Pattern);
    
    
    // for(j = 0; j <= MAXCHAR; j++){
    //     d[j] = PatternSize + 1;
    // }
    // for(j = 1; j <= PatternSize; j++){
    //     d[Pattern[j-1]] = PatternSize - j +1;
    // }
    
    i = PatternSize;

    while (i <= TextSize)
    {
        k = i;
        j = PatternSize; 
      
        
        
        while (j > 0 && Pattern[j - 1] == Text[k - 1])
        { 

            //printf("i = %ld | j = %ld | k = %ld | d[Text[%ld]] = %ld \n", i, j, k, i, d[Text[i]]); 
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


    // long i, j, k, d[MAXCHAR + 1], achou = 0;
    // for(j = 0; j <= MAXCHAR; j++){
    //     d[j] = PatternSize + 1;
    // }
    // for(j = 1; j <= PatternSize; j++){
    //     d[Pattern[j-1]] = PatternSize - j +1;
    // }
    // i = PatternSize;
    // while(i <= TextSize){
    //     k = i;
    //     j = PatternSize;
        
    //     while(Text[k-1] == Pattern[j-1] && j > 0){
    //         (*comp)++;
    //         k--;
    //         j--;
    //     }
    //     if(j == 0){
    //         printf(" - - Casamento na posicao %ld\n", k + 1);
    //         achou = 1;
    //     }
    //     (*desloc)+= i;
    //     i += d[Text[i]];
    // }
    // return achou;
}
