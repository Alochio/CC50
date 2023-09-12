#include <stdio.h>
#include <stdlib.h>
#include "substituicao.h"

int main()
{

    char chave[26];
    int analizeChave;

    printf("Digite a chave de criptografia: ");
    scanf("%s", chave);

    analizeChave = validaChave(chave);

    if(analizeChave == 1)
        auxConvert(chave);
    else
        printf("Fim do programa!\n");

    return 0;
}
