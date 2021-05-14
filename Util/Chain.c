#include "Chain.h"

typeText rdText(char *arquivo)
{
    FILE *file = fopen(arquivo, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir %s\n", arquivo);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    int tam = ftell(file);
    rewind(file);
    typeText typeText = malloc(tam * sizeof(char));
    int pointer = 0;
    while (!feof(file))
    {
        typeText[pointer++] = getc(file);
    }
    return typeText;
}
