#include "Driver.h"
#include "Chain.h"
#include "../BruteForce/BruteForce.h"
#include "../BMH/BMH.h" 
#include "../ShiftAndAP/ShiftAndAP.h"

//int main(int argc, char* argv[]){
int Driver()
{
    typeText typeText;
    clock_t begin, end, total;
    double time;
    int op;
    char nome[20];
    long comp = 0, desloc = 0, k = 0 ; 
    char FileWithPath[50] = "../StringMatching-/Data/";  
    long Match = 0;  
    short flag = 0, opSA;     


    printf("\n\n    ==========================Processamento de Chain de caracteres===================");
    typePattern typePattern = malloc(sizeof(char));
    printf("\n\n    * Entre com o padrao a ser pesquisado: ");
    scanf("%s", typePattern);
    printf("\n\n    * Entre com: \n(1) Para utilizar forca bruta \n(2) Para utilizar BMH \n(3) Para utilizar casamento aproximado");
    scanf("%d", &op);
    printf("\n\n    * Entre com o nome do arquivo de texto a ser analisado (sem .txt): ");
    scanf("%s", nome); 
    //MODO ANALISE
    if(ANALYSIS){
        flag = 1;
    }
   
    strcat(nome, ".txt"); 
    strcat(FileWithPath,nome);
   typeText = rdText(FileWithPath); //converte o texto para caracteres
 switch (op)
    {
    case 1:
    { //força bruta
        begin = clock();
        printf("\nMetodo Forca Bruta:\n"); 
        Match = BruteForce(typeText, strlen(typeText), typePattern, strlen(typePattern), &comp, &desloc);
        

        end = clock();
        total = end - begin;
        time = ((double)total) / CLOCKS_PER_SEC;
        if (flag ==1 )
            {
                printf("\n\n    =========================================RESULTADOS========================================="); 
                if(Match <= 0 ) 
                    printf("\n     PADRAO NAO ENCONTRADO                                                                   ");
                printf("\n     Metodo de casamento exato de Cadeias: Forca Bruta                                       ");
                printf("\n     Comparacoes entre os caracteres do texto e do padrao: %-7ld                           ", comp);
                printf("\n     Deslocamentos realizados na varredura de todo o texto: %-7ld                          ", desloc); 
                printf("\n     Numero de casamentos encontrados varrendo todo o texto: %ld                           ", Match); 
                printf("\n     Tempo de execucao do Forca Bruta: %.3f segundos.                                       ", time);
                printf("\n                                                                                             ");
                printf("\n    ============================================================================================\n\n");
            }
        
        break;
    }
    case 2:
    { //BMH 
        begin = clock();
        printf("\nBMH:\n");  
        Match = 0 ; 
        Match = BMH(typeText, typePattern, strlen(typeText), strlen(typePattern), &comp, &desloc); 
        end = clock();
        total = end - begin;
        time = ((double)total) / CLOCKS_PER_SEC;
        if (typePattern != NULL)
        {
            if (flag == 1)
            {
                printf("\n\n    =========================================RESULTADOS=========================================");
                printf("\n                                                                                             ");
                if(Match <= 0 ) 
                    printf("\n     PADRAO NAO ENCONTRADO                                                                   ");
                printf("\n     Metodo de casamento exato de Cadeias: BMH                                               ");
                printf("\n     Comparacoes entre os caracteres do texto e do padrao: %-7ld                           ", comp); 
                printf("\n     Deslocamentos realizados na varredura de todo o texto: %-7ld                          ", desloc);  
                printf("\n     Numero de casamentos encontrados varrendo todo o texto: %ld                           ", Match); 
                printf("\n     Tempo de execucao do BMH: %.3f segundos.                                               ", time); 
                printf("\n                                                                                             ");
                printf("\n    ============================================================================================\n\n");
            }
        } 
        Match = 0 ; 
        break;
        } 
    case 3: 
    { 
        begin = clock();
        printf("\nShift-And:\n");  
        printf("\n\n    * Entre com o valor da distância de edicao: ");   
        scanf("%ld",&k); 
        printf("\n\n    * Entre com o numero correspondente a operacao que deseja executar:"); 
        printf("\n\n    (1) Insercao");   
        printf("\n\n    (2) Remocao"); 
        printf("\n\n    (3) Substituição");  
        printf("\n\n    (4) Insercao e remocao"); 
        printf("\n\n    (5) Insercao e substituicao");  
        printf("\n\n    (6) Remocao e substituicao");  
        printf("\n\n    (7) tres operacoes\n");   
          
        
        scanf("%hd",&opSA);  
        printf("OP: %hd\n",opSA);
        
        Match = ShiftAndAP(typeText, typePattern, strlen(typeText), strlen(typePattern), k,opSA);
       
        end = clock();
        total = end - begin;
        time = ((double)total) / CLOCKS_PER_SEC;
        if (flag ==1 )
            {
                printf("\n\n    =========================================RESULTADOS=========================================");
                printf("\n                                                                                             "); 
                if(Match <= 0 ) 
                    printf("\n     PADRAO NAO ENCONTRADO                                                                   ");
                printf("\n     Metodo de casamento aproximado de Cadeias(Shift-And):                                   ");
                printf("\n     Distancia de edicao: %ld                                                              ",k); 
                printf("\n     Numero de casamentos encontrados varrendo todo o texto: %ld                           ", Match); 
                printf("\n     Tempo de execucao do Forca Bruta: %.3f segundos.                                       ", time);
                printf("\n                                                                                             ");
                printf("\n    ============================================================================================\n\n");
            }
        
        break;
    } 
    }
        free(typeText);
        free(typePattern);
        return 0;
    }
