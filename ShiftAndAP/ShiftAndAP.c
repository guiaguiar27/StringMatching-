#include "ShiftAndAP.h"


int ShiftAndAP(char *Text, char *Pattern, long TSize, long PSize, long k, short op){  
    long match = 0; 
    long  Mask[MAXCHAR], i , j , Ri, Rant, Rnew;  
    long R[MAXCHAR + 1];  
    for(i = 0 ; i < MAXCHAR; i++) 
        Mask[i] =0 ;  
    for(i = 0 ; i <= PSize; i++) 
        Mask[Pattern[i+1] + 127] |=1 << (PSize-i); 
    R[0] = 0;  
    Ri = 1 << (PSize -1); 
    for(j =1; j <= k ; j++) 
        R[j] = (1 << (PSize-j)) | R[j-1]; 
    
    for(i = 0; i < TSize;i++){ 
        Rant = R[0]; 
        Rnew= ((((unsigned long) Rant) >> 1)| Ri ) &Mask[Text[i] + 127]; 
        R[0] = Rnew;   
        for(j = 1; j <= k ; j++){  
            if(op == 1) 
                //insercao
                Rnew = ((((unsigned long)R[j]) >> 1) & Mask[Text[i] + 127]) | Rant ;  
            else if(op == 2)  
                //remocao
                Rnew = ((((unsigned long)R[j]) >> 1) & Mask[Text[i] + 127]) | (((unsigned long)Rant) >> 1);  
            else if(op == 3) 
                // substituicao  
                Rnew = ((((unsigned long)R[j]) >> 1) & Mask[Text[i] + 127]) | (((unsigned long)Rnew) >> 1);

            Rant = R[j];
            R[j] = Rnew | Ri; 
        } 
        if((Rnew & 1) != 0){ 
            printf("Matching: %ld\n", i +1); 
            match +=1;  
        }
    } 
    return match; 
}