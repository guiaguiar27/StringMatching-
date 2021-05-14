#include "Driver.h"
#include "Cadeia.h"
#include "../ForcaBruta/ForcaBruta.h"
#include "../BMH/BMH.h"

//int main(int argc, char* argv[]){
int Driver()
{
    TipoTexto tipoTexto;
    clock_t inicio, fim, total;
    double tempo;
    int op;
    char nome[20];
    long comp = 0, desloc = 0;

    // if(argc<4 || argc>5){
    //     printf("\nFormato de entrada via linha de comando invalido!\n");
    //     printf("Formato esperado: <executavel> <metodo> <texto> <padrao> [-P](opcional)\n\n");
    //     return 0;
    // }

    printf("\n\n    ==========================Processamento de cadeia de caracteres===================");
    TipoPadrao tipoPadrao = malloc(sizeof(char));
    printf("\n\n    * Entre com o padrão a ser pesquisado: ");
    scanf("%s", tipoPadrao);
    printf("\n\n    * Entre com (1) para utilizar forca bruta - (2) para utilizar BMH: ");
    scanf("%d", &op);
    printf("\n\n    * Entre com o nome do arquivo de texto a ser analisado (sem .txt): ");
    scanf("%s", nome);

    strcat("/Data/", nome);
    strcat(nome, ".txt"); 
    printf("Arquivo: %s",nome);
    tipoTexto = lerTexto(nome); //converte o texto para caracteres

    //padrão a ser pesquisado

    //avalia qual método vai ser usado
    switch (op)
    {
    case 1:
    { //força bruta
        inicio = clock();
        printf("\nMetodo Forca Bruta:\n");
        if (!ForcaBruta(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao), &comp, &desloc))
        {
            printf("\nPadrao nao encontrado\n");
        }

        fim = clock();
        total = fim - inicio;
        tempo = ((double)total) / CLOCKS_PER_SEC;
        if (tipoPadrao != NULL)
        {
            if (strcmp(tipoPadrao, "-P") == 0 || strcmp(tipoPadrao, "-p") == 0)
            {
                printf("\n\n    =========================================RESULTADOS=========================================");
                printf("\n   ||                                                                                          ||");
                printf("\n   ||  Metodo de casamento exato de cadeias: Forca Bruta                                       ||");
                printf("\n   ||  Comparacoes entre os caracteres do texto e do padrao: %-7ld                           ||", comp);
                printf("\n   ||  Deslocamentos realizados na varredura de todo o texto: %-7ld                          ||", desloc);
                printf("\n   ||  Tempo de execucao do Forca Bruta: %.3f segundos.                                       ||", tempo);
                printf("\n   ||                                                                                          ||");
                printf("\n    ============================================================================================\n\n");
            }
        }
        break;
    }
    case 2:
    { //força bruta
        inicio = clock();
        printf("\nBMH:\n");
        if (!BMH(tipoTexto, tipoPadrao, strlen(tipoTexto), strlen(tipoPadrao), &comp, &desloc))
        {
            printf("\nPadrao nao encontrado\n");
        }

        fim = clock();
        total = fim - inicio;
        tempo = ((double)total) / CLOCKS_PER_SEC;
        if (tipoPadrao != NULL)
        {
            if (strcmp(tipoPadrao, "-P") == 0 || strcmp(tipoPadrao, "-p") == 0)
            {
                printf("\n\n    =========================================RESULTADOS=========================================");
                printf("\n   ||                                                                                          ||");
                printf("\n   ||  Metodo de casamento exato de cadeias: BMH                                       ||");
                printf("\n   ||  Comparacoes entre os caracteres do texto e do padrao: %-7ld                           ||", comp);
                printf("\n   ||  Deslocamentos realizados na varredura de todo o texto: %-7ld                          ||", desloc);
                printf("\n   ||  Tempo de execucao do Forca Bruta: %.3f segundos.                                       ||", tempo);
                printf("\n   ||                                                                                          ||");
                printf("\n    ============================================================================================\n\n");
            }
        }
        break;
        } 
    }
        free(tipoTexto);
        free(tipoPadrao);
        return 0;
    }
